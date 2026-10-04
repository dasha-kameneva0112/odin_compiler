%option noyywrap
%option never-interactive

%x COMMENT
%x STRING
%x CHAR
%x RAW_STRING

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.tab.h"

char *strip_us(const char *src, char *dest);
void append_utf8(char *dest, unsigned int codepoint);
%}

DIGIT       [0-9]
LETTER      [a-zA-Z]
BIN_DIGIT   [01]
OCT_DIGIT   [0-7]
DOZ_DIGIT   [0-9abAB]
HEX_DIGIT   [0-9a-fA-F]

DECIMAL_LIT     (0|[1-9](_?{DIGIT})*)
BINARY_LIT      0b{BIN_DIGIT}(_?{BIN_DIGIT})*
OCTAL_LIT       0o{OCT_DIGIT}(_?{OCT_DIGIT})*
DOZENAL_LIT     0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*
HEX_LIT         0x{HEX_DIGIT}(_?{HEX_DIGIT})*
EX_DECIMAL_LIT  0d{DIGIT}(_?{DIGIT})*
EXPONENT        (e|E)[+-]?{DIGIT}+

INT_LIT     ({DECIMAL_LIT}|{BINARY_LIT}|{OCTAL_LIT}|{DOZENAL_LIT}|{HEX_LIT}|{EX_DECIMAL_LIT})
FLOAT_LIT   ({DECIMAL_LIT})?"."{DECIMAL_LIT}({EXPONENT})?|{DECIMAL_LIT}{EXPONENT}
ESC_OCTAL   \\[0-7]{3}
ESC_HEX     \\x{HEX_DIGIT}{2}
ESC_UNICODE \\u{HEX_DIGIT}{4}
ESC_UNICODE32 \\U{HEX_DIGIT}{8}


%%
%{
    int comment_depth = 0;
    char comment[20480];
    char string[20480];
    char charbuf[32];
    char *buf = string;
%}

"//"[^\n]*                       { /* ничего не возвращаем */ }

"/*"                             { comment_depth = 1; comment[0] = '\0'; strcat(comment, yytext); BEGIN(COMMENT); }
<COMMENT>"/*"                    { comment_depth++; strcat(comment, yytext); }
<COMMENT>\n                      { strcat(comment, yytext); }
<COMMENT>.                       { strcat(comment, yytext); }
<COMMENT><<EOF>>                 { printf("ERROR: unclosed comment\n"); return 1; }
<COMMENT>"*/"                    { strcat(comment, yytext); comment_depth--; if (comment_depth == 0) { printf("COMMENT: %s\n", comment); BEGIN(INITIAL); } }

\"                               { buf = string; BEGIN(STRING); string[0]='\0'; }
<STRING>[^\\\"\n]+               { strcat(string, yytext); }
<STRING>\\\n                     { /* продолжение строки на следующей строке */ }
<STRING>\n                       { printf("Error: end of line in string \n"); BEGIN(INITIAL); return 1; }
<STRING><<EOF>>                  { printf("Error: unclosed string\n"); return 1; }
<STRING>\"                       { printf("STRING_LIT: %s\n", string); BEGIN(INITIAL); }

\'                               { buf = charbuf; BEGIN(CHAR); charbuf[0] = '\0'; }
<CHAR>[^\\'\n]+                  { strcat(charbuf, yytext); }
<CHAR>\n                         { printf("ERROR: end of line in rune literal\n"); return 1; }
<CHAR><<EOF>>                    { printf("ERROR: unclosed rune literal\n"); return 1; }
<CHAR>\'                         {
                                    int count = 0;
                                    for (unsigned char *p = (unsigned char *)charbuf; *p; p++)
                                        if ((*p & 0xC0) != 0x80) count++;   /* считаем символы UTF-8, а не байты */

                                    if (count == 1)
                                        printf("RUNE_LIT: %s\n", charbuf);
                                    else if (count == 0)
                                        printf("ERROR: empty rune literal\n");
                                    else
                                        printf("ERROR: rune literal must contain exactly one character: '%s'\n", charbuf);

                                    BEGIN(INITIAL);
                                   }


<STRING,CHAR>\\n                   { strcat(buf, "\n"); }
<STRING,CHAR>\\a                   { strcat(buf, "\a"); }
<STRING,CHAR>\\b                   { strcat(buf, "\b"); }
<STRING,CHAR>\\e                   { strcat(buf, "\e"); }
<STRING,CHAR>\\f                   { strcat(buf, "\f"); }
<STRING,CHAR>\\r                   { strcat(buf, "\r"); }
<STRING,CHAR>\\t                   { strcat(buf, "\t"); }
<STRING,CHAR>\\v                   { strcat(buf, "\v"); }
<STRING,CHAR>\\\\                  { strcat(buf, "\\"); }
<STRING,CHAR>\\\"                  { strcat(buf, "\""); }
<STRING,CHAR>\\'                   { strcat(buf, "'"); }
<STRING,CHAR>{ESC_OCTAL}           { char code[2]={0}; code[0]=(char)strtol(yytext+1, NULL, 8); strcat(buf, code); }
<STRING,CHAR>{ESC_HEX}             { char code[2] = {0}; code[0] = (char)strtol(yytext + 2, NULL, 16); strcat(buf, code); }
<STRING,CHAR>{ESC_UNICODE}         { unsigned int cp = (unsigned int)strtol(yytext+2, NULL, 16); append_utf8(buf, cp); }
<STRING,CHAR>{ESC_UNICODE32}       { unsigned int cp = (unsigned int)strtol(yytext+2, NULL, 16); append_utf8(buf, cp); }


`                                { BEGIN(RAW_STRING); string[0] = '\0'; }
<RAW_STRING>[^`]+                { strcat(string, yytext); }
<RAW_STRING><<EOF>>              { printf("ERROR: unclosed raw string\n"); return 1; }
<RAW_STRING>`                    { printf("RAW_STRING_LIT: %s\n", string); BEGIN(INITIAL); }

"true"                    { return TRUE; }
"false"                   { return FALSE; }
"asm"                     { return ASM; }
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
"foreign"                 { return FOREIGN; }
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
"transmute"               { return TRANSMUTE; }
"typeid"                  { return TYPEID; }
"union"                   { return UNION; }
"using"                   { return USING; }
"when"                    { return WHEN; }
"where"                   { return WHERE; }

"nil"                     { return NIL; }
"---"                     { return UNDEFINED; }
"?"                       { return '?'; }

0b{BIN_DIGIT}(_?{BIN_DIGIT})*    { yylval.int_val = strtoll(c+2, NULL, 2);  return INT_LIT; }
0o{OCT_DIGIT}(_?{OCT_DIGIT})*    { yylval.int_val = strtoll(c+2, NULL, 8);  return INT_LIT; }
0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*    { yylval.int_val = strtoll(c+2, NULL, 12); return INT_LIT; }
0x{HEX_DIGIT}(_?{HEX_DIGIT})*    { yylval.int_val = strtoll(c+2, NULL, 16); return INT_LIT; }
0d{DIGIT}(_?{DIGIT})*            { yylval.int_val = strtoll(c+2, NULL, 10); return INT_LIT; }
0|[1-9](_?{DIGIT})*              { char c[128]; strip_us(yytext, c); yylval.int_val = strtoll(c, NULL, 10); return INT_LIT; }

{FLOAT_LIT}                        { char c[128]; yylval.float_val = strtod(strip_us(yytext, c), NULL); return FLOAT_LIT; }
({DECIMAL_LIT}|{FLOAT_LIT})[ijk]   { char c[128]; strip_us(yytext, c); c[strlen(c) - 1] = '\0'; printf("IMAGINARY_LIT: %g%c\n", strtod(c, NULL), yytext[yyleng - 1]); }

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
"i128"            { return I128; }
"uint"            { return UINT; }
"u8"              { return U8; }
"u16"             { return U16; }
"u32"             { return U32; }
"u64"             { return U64; }
"u128"            { return U128; }
"uintptr"         { return UINTPTR; }
"f16"             { return F16; }
"f32"             { return F32; }
"f64"             { return F64; }
"complex32"       { return COMPLEX32; }
"complex64"       { return COMPLEX64; }
"complex128"      { return COMPLEX128; }
"quaternion64"    { return QUATERNION64; }
"quaternion128"   { return QUATERNION128; }
"quaternion256"   { return QUATERNION256; }
"string"          { return STRING; }
"cstring"         { return CSTRING; }
"byte"            { return BYTE; }
"rune"            { return RUNE; }
"rawptr"          { return RAWPTR; }
"any"             { return ANY; }

"@"({LETTER}|_)({LETTER}|{DIGIT}|_)*  { yylval.str_val = strdup(yytext); return ATTRIBUTE; }
"@"                                   { return AT; }

"#+"({LETTER}|_)[A-Za-z_-]*           { yylval.str_val = strdup(yytext); return BUILD_DIRECTIVE; }
"#"({LETTER}|_)({LETTER}|{DIGIT}|_)*  { yylval.str_val = strdup(yytext); return DIRECTIVE; }

({LETTER}|_)({LETTER}|{DIGIT}|_)*   { yylval.str_val = strdup(yytext); return ID; }
[ \t\r\n]+                          { /* пропускаем пробелы */ }
<*>.                                { fprintf(stderr, "Lex error: unknown symbol '%s' at %d:%d\n", yytext, yylloc.first_line, yylloc.first_column); return LEX_ERROR; }

%%

char *strip_us(const char *src, char *dest)
{
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


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: lexer <input_file>\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");

    if (yyin == NULL)
    {
        printf("Cannot open file: %s\n", argv[1]);
        return 1;
    }

    yylex();

    fclose(yyin);

    return 0;
}