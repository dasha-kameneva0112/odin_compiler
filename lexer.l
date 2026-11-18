%option noyywrap
%option never-interactive

%x ST_COMMENT
%x ST_STRING
%x ST_CHAR
%x ST_RAW_STRING

%{
#define YY_DECL int odin_lex(void)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.tab.h"

char *strip_us(const char *src, char *dest);
void append_utf8(char *dest, unsigned int codepoint);
unsigned int first_codepoint(const unsigned char *s);
static int comment_seen = 0;   // показывает, встречался ли комментарий между токенами
static int comment_depth = 0;  // хранит глубину вложенных многострочных комментариев

static int cur_line = 1, cur_col = 1;   // текущий номер строки и столбца
// для отслеживания позиции
#define YY_USER_ACTION                                              \
    yylloc.first_line = cur_line; yylloc.first_column = cur_col;    \
    for (int i_ = 0; i_ < yyleng; i_++) {                           \
        if (yytext[i_] == '\n') { cur_line++; cur_col = 1; }        \
        else cur_col++;                                             \
    }                                                               \
    yylloc.last_line = cur_line; yylloc.last_column = cur_col;

%}

DIGIT       [0-9]
LETTER      [a-zA-Z\x80-\xFF]
BIN_DIGIT   [01]
OCT_DIGIT   [0-7]
DOZ_DIGIT   [0-9abAB]
HEX_DIGIT   [0-9a-fA-F]

DECIMAL_LIT     {DIGIT}(_?{DIGIT})*
EXPONENT        (e|E)[+-]?{DIGIT}+
BINARY_LIT      0b{BIN_DIGIT}(_?{BIN_DIGIT})*
OCTAL_LIT       0o{OCT_DIGIT}(_?{OCT_DIGIT})*
DOZENAL_LIT     0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*
HEX_LIT         0x{HEX_DIGIT}(_?{HEX_DIGIT})*
EX_DECIMAL_LIT  0d{DIGIT}(_?{DIGIT})*

INT_LIT     ({DECIMAL_LIT}|{BINARY_LIT}|{OCTAL_LIT}|{DOZENAL_LIT}|{HEX_LIT}|{EX_DECIMAL_LIT})
FLOAT_LIT   ({DECIMAL_LIT})?"."{DECIMAL_LIT}({EXPONENT})?|{DECIMAL_LIT}"."({DECIMAL_LIT})?({EXPONENT})?|{DECIMAL_LIT}{EXPONENT}

ESC_OCTAL   \\[0-7]{3}
ESC_HEX     \\x{HEX_DIGIT}{2}
ESC_UNICODE \\u{HEX_DIGIT}{4}
ESC_UNICODE32 \\U{HEX_DIGIT}{8}
%%

%{
    char string[20480];   // буфер для обычных и сырых строк
    char charbuf[32];     // буфер для символьного литерала
    char *buf = string;   // указатель на тот буфер, с которым сейчас работает лексер
%}

"//"[^\n]*                          { comment_seen = 1; }

"/*"                                 { comment_depth = 1; comment_seen = 1; BEGIN(ST_COMMENT); }
<ST_COMMENT>"/*"                    { comment_depth++; }
<ST_COMMENT>\n                      { return '\n'; }   /* перевод строки внутри комментария */
<ST_COMMENT>.                       { }
<ST_COMMENT><<EOF>>                 { fprintf(stderr, "Lex error: unclosed comment\n"); BEGIN(INITIAL); return LEX_ERROR; }
<ST_COMMENT>"*/"                    { comment_depth--; if (comment_depth == 0) { BEGIN(INITIAL); } }

\"                                  { buf = string; BEGIN(ST_STRING); string[0]='\0'; }
<ST_STRING>[^\\\"\n]+               { strcat(string, yytext); }
<ST_STRING>\n                       { fprintf(stderr, "Lex error: newline in string\n"); BEGIN(INITIAL); return LEX_ERROR; }
<ST_STRING><<EOF>>                  { fprintf(stderr, "Lex error: unclosed string\n"); BEGIN(INITIAL); return LEX_ERROR; }
<ST_STRING>\"                       { BEGIN(INITIAL); yylval.str_val = strdup(string); return STRING_LIT; }

\'                                  { buf = charbuf; BEGIN(ST_CHAR); charbuf[0] = '\0'; }
<ST_CHAR>[^\\'\n]+                  { strcat(charbuf, yytext); }
<ST_CHAR>\n                         { fprintf(stderr, "Lex error: newline in rune literal\n"); BEGIN(INITIAL); return LEX_ERROR; }
<ST_CHAR><<EOF>>                    { fprintf(stderr, "Lex error: unclosed rune literal\n"); BEGIN(INITIAL); return LEX_ERROR; }
<ST_CHAR>\'                         {
                                    int count = 0;
                                    for (unsigned char *p = (unsigned char *)charbuf; *p; p++)
                                        if ((*p & 0xC0) != 0x80) count++;   /* считаем символы UTF-8, а не байты */

                                     BEGIN(INITIAL);
                                    if (count == 1){
                                       yylval.rune_val = first_codepoint((unsigned char *)charbuf); return RUNE_LIT; }
                                       fprintf(stderr, "Lex error: rune literal must contain exactly one character\n"); return LEX_ERROR;}


<ST_STRING,ST_CHAR>\\n                   { strcat(buf, "\n"); }
<ST_STRING,ST_CHAR>\\a                   { strcat(buf, "\a"); }
<ST_STRING,ST_CHAR>\\b                   { strcat(buf, "\b"); }
<ST_STRING,ST_CHAR>\\e                   { strcat(buf, "\e"); }
<ST_STRING,ST_CHAR>\\f                   { strcat(buf, "\f"); }
<ST_STRING,ST_CHAR>\\r                   { strcat(buf, "\r"); }
<ST_STRING,ST_CHAR>\\t                   { strcat(buf, "\t"); }
<ST_STRING,ST_CHAR>\\v                   { strcat(buf, "\v"); }
<ST_STRING,ST_CHAR>\\\\                  { strcat(buf, "\\"); }
<ST_STRING,ST_CHAR>\\\"                  { strcat(buf, "\""); }
<ST_STRING,ST_CHAR>\\'                   { strcat(buf, "'"); }
<ST_STRING,ST_CHAR>{ESC_OCTAL}           { char code[2]={0}; code[0]=(char)strtol(yytext+1, NULL, 8); strcat(buf, code); }
<ST_STRING,ST_CHAR>{ESC_HEX}             { char code[2] = {0}; code[0] = (char)strtol(yytext + 2, NULL, 16); strcat(buf, code); }
<ST_STRING,ST_CHAR>{ESC_UNICODE}         { unsigned int cp = (unsigned int)strtol(yytext+2, NULL, 16); append_utf8(buf, cp); }
<ST_STRING,ST_CHAR>{ESC_UNICODE32}       { unsigned int cp = (unsigned int)strtol(yytext+2, NULL, 16); append_utf8(buf, cp); }


<ST_STRING,ST_CHAR>\\(.|\n)             { fprintf(stderr, "Lex error: invalid escape sequence\n"); BEGIN(INITIAL); return LEX_ERROR; }

`                                   { BEGIN(ST_RAW_STRING); string[0] = '\0'; }
<ST_RAW_STRING>[^`]+                { strcat(string, yytext); }
<ST_RAW_STRING><<EOF>>              { fprintf(stderr, "Lex error: unclosed raw string\n");  BEGIN(INITIAL); return LEX_ERROR; }
<ST_RAW_STRING>`                    { BEGIN(INITIAL); yylval.str_val = strdup(string); return RAW_STRING_LIT; }

"true"                    { yylval.int_val = 1; return BOOL_LIT; }
"false"                   { yylval.int_val = 0; return BOOL_LIT; }
"nil"                     { return NIL; }
"---"                     { return UNDEFINED; }
"?"                       { return '?'; }

    /* ключевые слова */
"package"                 { return PACKAGE; }
"import"                  { return IMPORT; }
"proc"                    { return PROC; }
"return"                  { return RETURN; }
"struct"                  { return STRUCT; }
"enum"                    { return ENUM; }
"using"                   { return USING; }
"defer"                   { return DEFER; }
"dynamic"                 { return DYNAMIC; }

"if"                      { return IF; }
"else"                    { return ELSE; }
"for"                     { return FOR; }
"do"                      { return DO; }
"in"                      { return IN; }
"switch"                  { return SWITCH; }
"case"                    { return CASE; }
"fallthrough"             { return FALLTHROUGH; }
"break"                   { return BREAK; }
"continue"                { return CONTINUE; }

"auto_cast"               { return AUTO_CAST; }
"cast"                    { return CAST; }
"or_break"                { return OR_BREAK; }
"or_continue"             { return OR_CONTINUE; }
"or_else"                 { return OR_ELSE; }
"or_return"               { return OR_RETURN; }

    
    /* числовые литералы */
0b{BIN_DIGIT}(_?{BIN_DIGIT})*    { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c+2, NULL, 2);  return INT_LIT; }
0o{OCT_DIGIT}(_?{OCT_DIGIT})*    { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c+2, NULL, 8);  return INT_LIT; }
0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*    { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c+2, NULL, 12); return INT_LIT; }
0x{HEX_DIGIT}(_?{HEX_DIGIT})*    { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c+2, NULL, 16); return INT_LIT; }
0d{DIGIT}(_?{DIGIT})*            { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c+2, NULL, 10); return INT_LIT; }
{DECIMAL_LIT}/".."               { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c, NULL, 10); return INT_LIT; }   /* 0..<10: точка принадлежит диапазону */
{DECIMAL_LIT}                    { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c, NULL, 10); return INT_LIT; }
{FLOAT_LIT}                      { char c[128]; yylval.float_val = strtod(strip_us(yytext, c), NULL); return FLOAT_LIT; }
({INT_LIT}|{FLOAT_LIT})[ijk]     { char c[128]; 
                                    strip_us(yytext, c); 
                                    yylval.imag_val.unit  = c[strlen(c) - 1];      /* 'i', 'j' или 'k' */
                                    c[strlen(c) - 1] = '\0';
                                    yylval.imag_val.value = strtod(c, NULL);
                                    return IMAGINARY_LIT; }

    
    /* ---- операторы ---- */
    /* составное присваивание */
"&&="       { return OP_LOG_AND_ASSIGN; }
"||="       { return OP_LOG_OR_ASSIGN; }
"+="        { return OP_ADD_ASSIGN; }
"-="        { return OP_SUB_ASSIGN; }
"*="        { return OP_MUL_ASSIGN; }
"/="        { return OP_DIV_ASSIGN; }
"%="        { return OP_MOD_ASSIGN; }
"%%="       { return OP_MOD2_ASSIGN; }

    /* диапазоны (for i in 0..<n, case 1..=5) */
"..="       { return OP_RANGE_INCLUSIVE; }
"..<"       { return OP_RANGE_EXCLUSIVE; }

".."        { return OP_RANGE; }
"->"        { return OP_ARROW; }

    /* логические и сравнения */
"&&"        { return OP_LOG_AND; }
"||"        { return OP_LOG_OR; }
"=="        { return OP_EQ; }
"!="        { return OP_NE; }
"<="        { return OP_LE; }
">="        { return OP_GE; }
"%%"        { return OP_MOD2; }

    /* объявления */
"::"        { return OP_DECL_TYPED; }
":="        { return OP_DECL_INFERRED; }

"+"         { return '+'; }
"++"        { return OP_INC; }
"-"         { return '-'; }
"--"        { return OP_DEC; }
"*"         { return '*'; }
"/"         { return '/'; }
"%"         { return '%'; }
"="         { return '='; }
"!"         { return '!'; }
"<"         { return '<'; }
">"         { return '>'; }
"("         { return '('; }
")"         { return ')'; }
"["         { return '['; }
"]"         { return ']'; }
"{"         { return '{'; }
"}"         { return '}'; }
","         { return ','; }
";"         { return ';'; }
"."         { return '.'; }
":"         { return ':'; } 

"bool"            { return BOOL; }
"int"             { return INT; }
"f32"             { return F32; }
"f64"             { return F64; }
"string"          { return STRING; }
"rune"            { return RUNE; }

    /* идентификаторы и пробелы */
({LETTER}|_)({LETTER}|{DIGIT}|_)*   { yylval.str_val = strdup(yytext); return ID; }
[ \t\r]+                            { /* пропускаем пробелы */ }
\n                                  { return '\n'; }
"\\"[ \t\r]*\n                       { /* \ поглощает перевод строки */ }
<*>.                                { fprintf(stderr, "Lex error: unknown symbol '%s' at %d:%d\n", yytext, yylloc.first_line, yylloc.first_column); return LEX_ERROR; }

%%

char *strip_us(const char *src, char *dest) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++)
    {
        if (src[i] != '_')
        {
            dest[j++] = src[i];
        }
    }
    dest[j] = '\0';
    return dest;
}

unsigned int first_codepoint(const unsigned char *s) {
    if (s[0] < 0x80) return s[0];
    if ((s[0] & 0xE0) == 0xC0) return ((s[0] & 0x1F) << 6) | (s[1] & 0x3F);
    if ((s[0] & 0xF0) == 0xE0)
        return ((s[0] & 0x0F) << 12) | ((s[1] & 0x3F) << 6) | (s[2] & 0x3F);
    return ((s[0] & 0x07) << 18) | ((s[1] & 0x3F) << 12)
         | ((s[2] & 0x3F) << 6)  |  (s[3] & 0x3F);
}

void append_utf8(char *dest, unsigned int codepoint) {
    char utf8[5] = {0};
    int n = 0;
    if (codepoint <= 0x7F) {
        utf8[0] = (char)codepoint; n = 1;
    } else if (codepoint <= 0x7FF) {
        utf8[0] = (char)(0xC0 | (codepoint >> 6));
        utf8[1] = (char)(0x80 | (codepoint & 0x3F));
        n = 2;
    } else if (codepoint <= 0xFFFF) {
        utf8[0] = (char)(0xE0 | (codepoint >> 12));
        utf8[1] = (char)(0x80 | ((codepoint >> 6) & 0x3F));
        utf8[2] = (char)(0x80 | (codepoint & 0x3F));
        n = 3;
    } else {
        utf8[0] = (char)(0xF0 | (codepoint >> 18));
        utf8[1] = (char)(0x80 | ((codepoint >> 12) & 0x3F));
        utf8[2] = (char)(0x80 | ((codepoint >> 6) & 0x3F));
        utf8[3] = (char)(0x80 | (codepoint & 0x3F));
        n = 4;
    }
    utf8[n] = '\0';
    strcat(dest, utf8);
}

int odin_lex(void);

static int  last_token = 0;     // какой токен вернули в прошлый раз
static char bracket_stack[256]; // стек открытых скобок: '(', '[', '{', 'P' (параметры proc), 'T' (тип)
static int  bracket_top = 0;    // 

/* Ждём '{' тела: заголовок if/for/switch или сигнатура proc (-> T {).
   Такая '{' это блок, а не составной литерал Pair{...}. */
enum { BLK_NONE, BLK_HEADER, BLK_PROC };
static int block_kind  = BLK_NONE;
static int block_depth = 0;   // уровень скобок, на котором ждём '{' 

/* один токен обратной подстановки (подглядывание вперёд) */
static int has_back = 0, back_tok = 0; // флаг есть ли что-то в кармане? и номер отложенного токена 
static YYSTYPE back_val;    // значение отложенного токена
static YYLTYPE back_loc;    // позиция отложенного токена

static int raw_next(void)
{
    if (has_back) {
        has_back = 0;
        yylval = back_val; 
        yylloc = back_loc;

        return back_tok;
    }
    return odin_lex();
}

static void unget(int tok)
{
    back_tok = tok; 
    back_val = yylval; 
    back_loc = yylloc; 
    has_back = 1;
}

/* После каких токенов Odin вставляет ; */
static int can_end_stmt(int tok)
{
    switch (tok) {
        case ID:
        case INT_LIT: case FLOAT_LIT: case STRING_LIT:
        case RAW_STRING_LIT: case RUNE_LIT: case IMAGINARY_LIT:
        case BOOL_LIT: case NIL: case UNDEFINED:
        case BREAK: case CONTINUE: case FALLTHROUGH: case RETURN:
        case OR_RETURN: case OR_BREAK: case OR_CONTINUE:
        case BOOL: case INT: case F32: case F64:
        case STRING: case RUNE:
        case '?': case ')': case ']': case '}':
            return 1;
        default:
            return 0;
    }
}

/* токены, после которых может начинаться оператор */
static int stmt_start(int t)
{
    return t == 0 || t == AUTO_SEMI || t == ';' || t == '{' || t == LIT_LBRACE
        || t == '}' || t == ELSE || t == DO || t == ':';
}

/* после '}' на той же строке может сразу идти оператор (без ;) */
static int stmt_after_rbrace(int t)
{
    switch (t) {
        case ID: case FOR: case SWITCH:
        case RETURN: case BREAK: case CONTINUE: case DEFER: case USING:
            return 1;
        default:
            return 0;
    }
}

/* внутри ( ) или [ ] переводы строк не разделяют операторы */
static int in_brackets(void)
{
    return bracket_top > 0 &&
           (bracket_stack[bracket_top - 1] == '(' || bracket_stack[bracket_top - 1] == '[');
}

int yylex(void)
{
    static int at_eof = 0; // означает, что лексер уже достиг конца файла
    if (at_eof) return 0;

    for (;;) {
        int tok = raw_next();

        if (tok == '\n') {
            if (last_token == DO) {
                fprintf(stderr, "Lex error: the body of 'do' must be on the same line as 'do'\n");
                return LEX_ERROR;
            }
            if (in_brackets() || !can_end_stmt(last_token))
                continue;

            YYLTYPE nl = yylloc;                          /* позиция перевода строки */
            int after_rbrace = (last_token == '}');
            int after_sig = (block_kind == BLK_PROC);
            int after_hdr = (block_kind == BLK_HEADER && bracket_top == block_depth);

            if (after_rbrace || after_sig || after_hdr) {
                comment_seen = 0;
                int nt;
                do { 
                    nt = raw_next(); 
                } while (nt == '\n');
                unget(nt);

                /* '}' <перевод строки> else   или   proc() <перевод строки> '{' (строго следующая строка) */
                if ((after_rbrace && nt == ELSE && !comment_seen) ||
                    (after_sig && nt == '{' && back_loc.first_line == nl.last_line) ||
                    (after_hdr && nt == '{'))             /* if/for/switch cond <перевод строки> '{' */
                    continue;                             /* здесь перевод строки не заканчивает оператор */
            }

            yylloc = nl;
            last_token = AUTO_SEMI;
            if (!after_hdr) {
                block_kind = BLK_NONE;      /* терминатор внутри заголовка if/switch: '{' тела ещё впереди */
            }
            return AUTO_SEMI;
        }

        if (tok == 0) {
            at_eof = 1;
            if (can_end_stmt(last_token)) {
                last_token = AUTO_SEMI;
                return AUTO_SEMI;
            }
            return 0;
        }

        /* '}' и сразу за ней на той же строке оператор: вставляем AUTO_SEMI */
        if (last_token == '}' && stmt_after_rbrace(tok) && !in_brackets()) {
            unget(tok);
            last_token = AUTO_SEMI;
            return AUTO_SEMI;
        }

        /* ждём '{' тела блока */
        if ((tok == IF && stmt_start(last_token)) || tok == FOR || tok == SWITCH) {
            block_kind = BLK_HEADER; 
            block_depth = bracket_top;
        } 
        else if (tok == PROC) {
            block_kind = BLK_PROC;   
            block_depth = bracket_top;
        } 
        else if (tok == DO || (tok == ';' && block_kind == BLK_PROC)) {
            block_kind = BLK_NONE;
        }

        if (tok == '{') {
            if (block_kind != BLK_NONE && bracket_top == block_depth)
                block_kind = BLK_NONE;                    /* '{' тела: блок */
            else if (last_token == ID)
                tok = LIT_LBRACE;                         /* Pair{...} */
        }

        /* стек открытых скобок; '(' сразу после proc помечаем 'P' (список параметров) */
        if (tok == '(' || tok == '[' || tok == '{' || tok == LIT_LBRACE) {
            if (bracket_top < 256) {
                char c = (tok == LIT_LBRACE) ? '{' : (char)tok;
                if (tok == '(' && last_token == PROC) {
                    c = 'P';   /* параметры proc */
                }
                else if (tok == '[' && !can_end_stmt(last_token)) {
                     c = 'T';   /* скобки типа [N]T */
                }
                bracket_stack[bracket_top++] = c;
            }
        } else if (tok == ')' || tok == ']' || tok == '}') {
            if (bracket_top > 0) 
                bracket_top--;
        }

        last_token = tok;
        return tok;
    }
}