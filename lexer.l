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
#define MAX_FILE_TAGS 64
char *file_tags[MAX_FILE_TAGS];
int file_tag_count = 0;

char *strip_us(const char *src, char *dest);
void append_utf8(char *dest, unsigned int codepoint);
unsigned int first_codepoint(const unsigned char *s);


static int cur_line = 1, cur_col = 1;
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
BINARY_LIT      0b{BIN_DIGIT}(_?{BIN_DIGIT})*
OCTAL_LIT       0o{OCT_DIGIT}(_?{OCT_DIGIT})*
DOZENAL_LIT     0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*
HEX_LIT         0x{HEX_DIGIT}(_?{HEX_DIGIT})*
EX_DECIMAL_LIT  0d{DIGIT}(_?{DIGIT})*
EXPONENT        (e|E)[+-]?{DIGIT}+

INT_LIT     ({DECIMAL_LIT}|{BINARY_LIT}|{OCTAL_LIT}|{DOZENAL_LIT}|{HEX_LIT}|{EX_DECIMAL_LIT})
FLOAT_LIT   ({DECIMAL_LIT})?"."{DECIMAL_LIT}({EXPONENT})?|{DECIMAL_LIT}"."({DECIMAL_LIT})?({EXPONENT})?|{DECIMAL_LIT}{EXPONENT}
ESC_OCTAL   \\[0-7]{3}
ESC_HEX     \\x{HEX_DIGIT}{2}
ESC_UNICODE \\u{HEX_DIGIT}{4}
ESC_UNICODE32 \\U{HEX_DIGIT}{8}


%%
%{
    int comment_depth = 0;
    char string[20480];
    char charbuf[32];
    char *buf = string;
%}

"//"[^\n]*                          { /* ничего не возвращаем */ }

"/*"                                { comment_depth = 1; BEGIN(ST_COMMENT); }
<ST_COMMENT>"/*"                    { comment_depth++; }
<ST_COMMENT>\n                      { }
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

`                                { BEGIN(ST_RAW_STRING); string[0] = '\0'; }
<ST_RAW_STRING>[^`]+                { strcat(string, yytext); }
<ST_RAW_STRING><<EOF>>              { fprintf(stderr, "Lex error: unclosed raw string\n");  BEGIN(INITIAL); return LEX_ERROR; }
<ST_RAW_STRING>`                    { BEGIN(INITIAL); yylval.str_val = strdup(string); return RAW_STRING_LIT; }

"true"                    { yylval.int_val = 1; return BOOL_LIT; }
"false"                   { yylval.int_val = 0; return BOOL_LIT; }
"auto_cast"               { return AUTO_CAST; }
"bit_field"               { return BIT_FIELD; }
"bit_set"                 { return BIT_SET; }
"break"                   { return BREAK; }
"case"                    { return CASE; }
"cast"                    { return CAST; }
"context"                 { return CONTEXT; }
"continue"                { return CONTINUE; }
"defer"                   { return DEFER; }
"distinct"                { return DISTINCT; }
"do"                      { return DO; }
"dynamic"                 { return DYNAMIC; }
"else"                    { return ELSE; }
"enum"                    { return ENUM; }
"fallthrough"             { return FALLTHROUGH; }
"for"                     { return FOR; }
"if"                      { return IF; }
"import"                  { return IMPORT; }
"in"                      { return IN; }
"map"                     { return MAP; }
"matrix"                  { return MATRIX; }
"not_in"                  { return NOT_IN; }
"or_break"                { return OR_BREAK; }
"or_continue"             { return OR_CONTINUE; }
"or_else"                 { return OR_ELSE; }
"or_return"               { return OR_RETURN; }
"package"                 { return PACKAGE; }
"proc"                    { return PROC; }
"return"                  { return RETURN; }
"struct"                  { return STRUCT; }
"switch"                  { return SWITCH; }
"typeid"                  { return TYPEID; }
"union"                   { return UNION; }
"when"                    { return WHEN; }
"where"                   { return WHERE; }

"nil"                     { return NIL; }
"---"                     { return UNDEFINED; }
"?"                       { return '?'; }

0b{BIN_DIGIT}(_?{BIN_DIGIT})*    { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c+2, NULL, 2);  return INT_LIT; }
0o{OCT_DIGIT}(_?{OCT_DIGIT})*    { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c+2, NULL, 8);  return INT_LIT; }
0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*    { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c+2, NULL, 12); return INT_LIT; }
0x{HEX_DIGIT}(_?{HEX_DIGIT})*    { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c+2, NULL, 16); return INT_LIT; }
0d{DIGIT}(_?{DIGIT})*            { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c+2, NULL, 10); return INT_LIT; }
{DECIMAL_LIT}/".."               { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c, NULL, 10); return INT_LIT; }   /* 0..<10: точка принадлежит диапазону */
{DECIMAL_LIT}                     { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c, NULL, 10); return INT_LIT; }

{FLOAT_LIT}                        { char c[128]; yylval.float_val = strtod(strip_us(yytext, c), NULL); return FLOAT_LIT; }
({INT_LIT}|{FLOAT_LIT})[ijk]   { char c[128]; 
                                     strip_us(yytext, c); 
                                     yylval.imag_val.unit  = c[strlen(c) - 1];      /* 'i', 'j' или 'k' */
                                     c[strlen(c) - 1] = '\0';
                                     yylval.imag_val.value = strtod(c, NULL);
                                     return IMAGINARY_LIT; }

"&&="       { return OP_LOG_AND_ASSIGN; }
"||="       { return OP_LOG_OR_ASSIGN; }
"<<="       { return OP_SHL_ASSIGN; }
">>="       { return OP_SHR_ASSIGN; }
"&~="       { return OP_AND_NOT_ASSIGN; }
"+="        { return OP_ADD_ASSIGN; }
"-="        { return OP_SUB_ASSIGN; }
"*="        { return OP_MUL_ASSIGN; }
"/="        { return OP_DIV_ASSIGN; }
"%="        { return OP_MOD_ASSIGN; }
"%%="       { return OP_MOD2_ASSIGN; }
"|="        { return OP_OR_ASSIGN; }
"~="        { return OP_NOT_ASSIGN; }
"&="        { return OP_AND_ASSIGN; }

"..="       { return OP_RANGE_INCLUSIVE; }
"..<"       { return OP_RANGE_EXCLUSIVE; }
".."        { return OP_RANGE; }
"->"        { return OP_ARROW; }

"&&"        { return OP_LOG_AND; }
"||"        { return OP_LOG_OR; }
"&~"        { return OP_AND_NOT; }
"<<"        { return OP_SHL; }
">>"        { return OP_SHR; }
"=="        { return OP_EQ; }
"!="        { return OP_NE; }
"<="        { return OP_LE; }
">="        { return OP_GE; }
"%%"        { return OP_MOD2; }

"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"%"         { return '%'; }
"="         { return '='; }
"!"         { return '!'; }
"<"         { return '<'; }
">"         { return '>'; }
"&"         { return '&'; }
"|"         { return '|'; }
"^"         { return '^'; }
"~"         { return '~'; }
"("         { return '('; }
")"         { return ')'; }
"["         { return '['; }
"]"         { return ']'; }
"{"         { return '{'; }
"}"         { return '}'; }
","         { return ','; }
";"         { return ';'; }
"."         { return '.'; }
"$"         { return OP_DOLLAR; }

":"         { return ':'; }
"::"        { return OP_DECL_TYPED; }
":="        { return OP_DECL_INFERRED; }

"bool"            { return BOOL; }
"b8"              { return B8; }
"b16"             { return B16; }
"b32"             { return B32; }
"b64"             { return B64; }
"int"             { return INT; }
"i8"              { return I8; }
"i16"             { return I16; }
"i32"             { return I32; }
"i64"             { return I64; }
"uint"            { return UINT; }
"u8"              { return U8; }
"u16"             { return U16; }
"u32"             { return U32; }
"u64"             { return U64; }
"uintptr"         { return UINTPTR; }
"f32"             { return F32; }
"f64"             { return F64; }
"complex64"       { return COMPLEX64; }
"complex128"      { return COMPLEX128; }
"string"          { return STRING; }
"cstring"         { return CSTRING; }
"byte"            { return BYTE; }
"rune"            { return RUNE; }
"rawptr"          { return RAWPTR; }

"@"({LETTER}|_)({LETTER}|{DIGIT}|_)*  { yylval.str_val = strdup(yytext); return ATTRIBUTE; }
"@"                                   { return AT; }

"#+"[^\n]*                            { if (file_tag_count < MAX_FILE_TAGS) file_tags[file_tag_count++] = strdup(yytext + 2); }
"#!"[^\n]*                           { /* shebang: комментарий */ }
"#"[ \t]*({LETTER}|_)({LETTER}|{DIGIT}|_)*  { char *p = yytext + 1; while (*p == ' ' || *p == '\t') p++; yylval.str_val = malloc(strlen(p) + 2); sprintf(yylval.str_val, "#%s", p); return DIRECTIVE; }

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
static int last_token = 0;
static int in_attr = 0, attr_depth = 0;

/* После каких токенов Odin вставляет ; */
static int can_end_stmt(int tok)
{
    switch (tok) {
        case ID: 
        case CONTEXT: 
        case TYPEID:
        case INT_LIT: case FLOAT_LIT: case STRING_LIT:
        case RAW_STRING_LIT: case RUNE_LIT: case IMAGINARY_LIT:
        case BOOL_LIT: case NIL: case UNDEFINED:
        case BREAK: case CONTINUE: case FALLTHROUGH:
        case RETURN: case OR_RETURN: case OR_BREAK: case OR_CONTINUE:
        case BOOL: case B8: case B16: case B32: case B64:
        case INT: case I8: case I16: case I32: case I64: 
        case UINT: case U8: case U16: case U32: case U64: case UINTPTR:
        case F32: case F64:
        case COMPLEX64: case COMPLEX128:
        case STRING: case CSTRING: case BYTE: case RUNE: case RAWPTR:
        case BUILD_DIRECTIVE:
        case '^': case '?':
        case ')': case ']': case '}':
            return 1;
        default:
            return 0;
    }
}

static char bracket_stack[256];
static int  bracket_top = 0;

/* внутри ( ) или [ ] переводы строк не разделяют операторы */
static int in_brackets(void)
{
    return bracket_top > 0 && (bracket_stack[bracket_top - 1] == '(' || bracket_stack[bracket_top - 1] == '[');
}

int yylex(void)
{
    static int at_eof = 0;
    if (at_eof) return 0;

    for (;;) {
        int tok = odin_lex();
        if (tok == '\n') {
            if (in_brackets()) continue;      /* внутри скобок ';' не нужна */
            if (can_end_stmt(last_token)) {
                last_token = ';';
                return ';';
            }
            continue;
        }

        if (tok == 0) {
            at_eof = 1;
            if (can_end_stmt(last_token)) {
                last_token = ';';
                return ';';
            }
            return 0;
        }

        /* стек открытых скобок */
        if (tok == '(' || tok == '[' || tok == '{') {
            if (bracket_top < 256) bracket_stack[bracket_top++] = (char)tok;
        } else if (tok == ')' || tok == ']' || tok == '}') {
            if (bracket_top > 0) bracket_top--;
        }

        if (tok == AT) {
            in_attr = 1; attr_depth = 0;
        } else if (in_attr && attr_depth == 0 && tok != '(') {
            in_attr = 0;
        } else if (in_attr && tok == '(') {
            attr_depth++;
        } else if (in_attr && tok == ')') {
            attr_depth--;
            if (attr_depth == 0) {
                in_attr = 0;
                last_token = ATTRIBUTE;
                return tok;
            }
        }

        last_token = tok;
        return tok;
    }
}
