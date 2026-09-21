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

int comment_depth = 0;
char string[1000];
char charbuf[16];
char *buf; 

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

%}

DIGIT   [0-9]
BIN_DIGIT   [01]
OCT_DIGIT   [0-7]
DOZ_DIGIT  [0-9abAB]
HEX_DIGIT  [0-9a-fA-F]
  
LETTER      [a-zA-Z]
ID_START    ({LETTER}|_)
ID_CHAR     ({LETTER}|{DIGIT}|_)
TAG_CHAR    [A-Za-z_-]

ESC_OCTAL   \\[0-7]{1,3}
ESC_HEX     \\x[0-9A-Fa-f]{2}
ESC_UNICODE \\u[0-9A-Fa-f]{4}
ESC_UNICODE32 \\U[0-9A-Fa-f]{8}

%%
"//"[^\n]*                       {  }

"/*"                             { comment_depth = 1; BEGIN(COMMENT); }
<COMMENT>"/*"                    { comment_depth++; }
<COMMENT>\n                      {  }
<COMMENT>.                       {  }
<COMMENT><<EOF>>                 { printf("ERROR: unclosed comment\n"); return 1; }
<COMMENT>"*/"                    { comment_depth--; if (comment_depth == 0) BEGIN(INITIAL); }

\"                               { buf = string; BEGIN(STRING); string[0]='\0'; }
<STRING>[^\\\"\n]+               { strcat(string, yytext); }
<STRING>\\\n                     { /* продолжение строки на следующей строке */ }
<STRING>\n                       { printf("Error: end of line in string"); BEGIN(INITIAL); return 1; }
<STRING><<EOF>>                  { printf("Error: unclosed string\n"); return 1; }
<STRING>\"                       { printf("STRING_LIT: %s\n", string); BEGIN(INITIAL); }

\'                               { buf = charbuf; BEGIN(CHAR); charbuf[0] = '\0'; }
<CHAR>[^\\'\n]                   { strcat(charbuf, yytext); }
<CHAR>\n                         { printf("ERROR: end of line in rune literal\n"); return 1; }
<CHAR><<EOF>>                    { printf("ERROR: unclosed rune literal\n"); return 1; }
<CHAR>\'                         { printf("RUNE_LIT: %s\n", charbuf); BEGIN(INITIAL); }


<STRING,CHAR>\\n                      { strcat(buf, "\n"); }
<STRING,CHAR>\\a                      { strcat(buf, "\a"); }
<STRING,CHAR>\\b                      { strcat(buf, "\b"); }
<STRING,CHAR>\\e                      { strcat(buf, "\e"); }
<STRING,CHAR>\\f                      { strcat(buf, "\f"); }
<STRING,CHAR>\\r                      { strcat(buf, "\r"); }
<STRING,CHAR>\\t                      { strcat(buf, "\t"); }
<STRING,CHAR>\\v                      { strcat(buf, "\v"); }
<STRING,CHAR>\\\\                     { strcat(buf, "\\"); }
<STRING,CHAR>\\\"                     { strcat(buf, "\""); }
<STRING,CHAR>\\'                      { strcat(buf, "'"); }
<STRING,CHAR>{ESC_OCTAL}              { char code[2]={0}; code[0]=(char)strtol(yytext+1, NULL, 8); strcat(buf, code); }
<STRING,CHAR>{ESC_HEX}                { char code[2] = {0}; code[0] = (char)strtol(yytext + 2, NULL, 16); strcat(buf, code); }
<STRING,CHAR>{ESC_UNICODE}            { strcat(buf, yytext); }
<STRING,CHAR>{ESC_UNICODE32}          { strcat(buf, yytext); }


`                                { BEGIN(RAW_STRING); string[0] = '\0'; }
<RAW_STRING>[^`\n]+              { strcat(string, yytext); }
<RAW_STRING>\n                   { strcat(string, "\n"); }
<RAW_STRING><<EOF>>              { printf("ERROR: unclosed raw string\n"); return 1; }
<RAW_STRING>`                    { printf("RAW_STRING_LIT: %s\n", string); BEGIN(INITIAL); }

"true"|"false"                   { printf("BOOL_LIT: %s\n", yytext); }
"package"|"import"|"proc"|"asm"|"matrix"|"not_in"|"or_break"|"or_continue"|"or_else"|"or_return"|"return"|"struct"|"switch"|"transmute"|"typeid"|"union"|"using"|"when"|"where"|"auto_cast"|"bit_field"|"bit_set"|"break"|"case"|"cast"|"context"|"continue"|"defer"|"distinct"|"do"|"dynamic"|"else"|"enum"|"fallthrough"|"for"|"foreign"|"if"|"in"|"map"                  { printf("KEYWORD: %s\n", yytext); }

"nil"                            { printf("NIL_LIT: %s\n",yytext); }
"---"                            { printf("UNDEFINED_LIT: %s\n",yytext); }
"{}"                             { printf("ZERO_COMPOUND_LIT: %s\n",yytext); }
"?"                              { printf("AUTO_LEN: %s\n", yytext); }

0|[1-9](_?{DIGIT})*              { char c[128]; printf("DECIMAL_LIT: %ld\n", strtol(strip_us(yytext,c), NULL, 10)); }
0b{BIN_DIGIT}(_?{BIN_DIGIT})*    { char c[128]; printf("BINARY_LIT: %ld\n", strtol(strip_us(yytext,c)+2, NULL, 2)); }
0o{OCT_DIGIT}(_?{OCT_DIGIT})*    { char c[128]; printf("OCTAL_LIT: %ld\n", strtol(strip_us(yytext,c)+2, NULL, 8)); }
0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*    { char c[128]; printf("DOZENAL_LIT: %ld\n", strtol(strip_us(yytext,c)+2, NULL, 12)); }
0x{HEX_DIGIT}(_?{HEX_DIGIT})*    { char c[128]; printf("HEX_LIT: %ld\n", strtol(strip_us(yytext,c)+2, NULL, 16)); }
0d{DIGIT}(_?{DIGIT})*            { char c[128]; printf("EX_DECIMAL_LIT: %ld\n", strtol(strip_us(yytext,c)+2, NULL, 10)); }

({DIGIT}(_?{DIGIT})*)?\.({DIGIT}_?{DIGIT}*)?(_?[eE]?[-+]?{DIGIT}+)+|({DIGIT}(_?{DIGIT})*)\.      { char c[128]; printf("FLOAT_LIT: %g\n", strtod(strip_us(yytext,c), NULL)); }
((0|[1-9](_?{DIGIT})*)|(0b{BIN_DIGIT}(_?{BIN_DIGIT})*)|(0o{OCT_DIGIT}(_?{OCT_DIGIT})*)|(0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*)|(0x{HEX_DIGIT}(_?{HEX_DIGIT})*)|(0d{DIGIT}(_?{DIGIT})*)|(({DIGIT}(_?{DIGIT})*)?\.({DIGIT}_?{DIGIT}*)?(_?[eE]?[-+]?{DIGIT}+)+|({DIGIT}(_?{DIGIT})*)\.))[ijk] { char c[128]; strip_us(yytext,c); c[strlen(c)-1]='\0'; printf("IMAGINARY_LIT: %g%c\n", strtod(c, NULL), yytext[yyleng-1]); }

"+="    { printf("OP_ADD_ASSIGN: %s\n", yytext); }
"-="    { printf("OP_SUB_ASSIGN: %s\n", yytext); }
"*="    { printf("OP_MUL_ASSIGN: %s\n", yytext); }
"/="    { printf("OP_DIV_ASSIGN: %s\n", yytext); }
"%="    { printf("OP_MOD_ASSIGN: %s\n", yytext); }
"%%="   { printf("OP_MOD2_ASSIGN: %s\n", yytext); }
"|="    { printf("OP_OR_ASSIGN: %s\n", yytext); }
"~="    { printf("OP_NOT_ASSIGN: %s\n", yytext); }
"&="    { printf("OP_AND_ASSIGN: %s\n", yytext); }
"&~="   { printf("OP_AND_NOT_ASSIGN: %s\n", yytext); }
"<<="   { printf("OP_SHL_ASSIGN: %s\n", yytext); }
">>="   { printf("OP_SHR_ASSIGN: %s\n", yytext); }
"&&="   { printf("OP_LOG_AND_ASSIGN: %s\n", yytext); }
"||="   { printf("OP_LOG_OR_ASSIGN: %s\n", yytext); }

"="     { printf("OP_ASSIGN: %s\n", yytext); }
"$"     { printf("OP_DOLLAR: %s\n", yytext); }

"&&"    { printf("OP_LOG_AND: %s\n", yytext); }
"||"    { printf("OP_LOG_OR: %s\n", yytext); }
"!"     { printf("OP_NOT: %s\n", yytext); }

"|"     { printf("OP_BIT_OR: %s\n", yytext); }
"&~"    { printf("OP_AND_NOT: %s\n", yytext); }
"~"     { printf("OP_BIT_NOT: %s\n", yytext); }
"^"     { printf("OP_DEREF: %s\n", yytext); }
"&"     { printf("OP_ADDRESS: %s\n", yytext); }
"<<"    { printf("OP_SHL: %s\n", yytext); }
">>"    { printf("OP_SHR: %s\n", yytext); }

"=="    { printf("OP_EQ: %s\n", yytext); }
"!="    { printf("OP_NE: %s\n", yytext); }
"<="    { printf("OP_LE: %s\n", yytext); }
">="    { printf("OP_GE: %s\n", yytext); }
"<"     { printf("OP_LT: %s\n", yytext); }
">"     { printf("OP_GT: %s\n", yytext); }

"+"     { printf("OP_PLUS: %s\n", yytext); }
"-"     { printf("OP_MINUS: %s\n", yytext); }
"*"     { printf("OP_MUL: %s\n", yytext); }
"/"     { printf("OP_DIV: %s\n", yytext); }
"%"     { printf("OP_MOD: %s\n", yytext); }
"%%"    { printf("OP_MOD2: %s\n", yytext); }

"..="   { printf("OP_RANGE_INCLUSIVE: %s\n", yytext); }
"..<"   { printf("OP_RANGE_EXCLUSIVE: %s\n", yytext); }
".."    { printf("OP_RANGE: %s\n", yytext); }

"."     { printf("OP_DOT: %s\n", yytext); }
"->"    { printf("OP_ARROW: %s\n", yytext); }

"::"    { printf("OP_DECL_TYPED: %s\n", yytext); }
":="    { printf("OP_DECL_INFERRED: %s\n", yytext); }
":"     { printf("COLON: %s\n", yytext); }

"("     { printf("LPAREN: %s\n", yytext); }
")"     { printf("RPAREN: %s\n", yytext); }
"{"     { printf("LBRACE: %s\n", yytext); }
"}"     { printf("RBRACE: %s\n", yytext); }
"["     { printf("LBRACKET: %s\n", yytext); }
"]"     { printf("RBRACKET: %s\n", yytext); }
","     { printf("COMMA: %s\n", yytext); }
";"     { printf("SEMICOLON: %s\n", yytext); }

"bool"|"b8"|"b16"|"b32"|"b64"|"int"|"i8"|"i16"|"i32"|"i64"|"i128"|"uint"|"u8"|"u16"|"u32"|"u64"|"u128"|"uintptr"|"f16"|"f32"|"f64"|"complex32"|"complex64"|"complex128"|"quaternion64"|"quaternion128"|"quaternion256"|"string"|"cstring"|"byte"|"rune"|"rawptr"|"any"      { printf("BUILTIN_TYPE: %s\n", yytext); }

"@"{ID_START}{ID_CHAR}*          { printf("ATTRIBUTE: %s\n", yytext); }
"@"                              { printf("AT: %s\n", yytext); }

"#+"{ID_START}{TAG_CHAR}*        { printf("BUILD_DIRECTIVE: %s\n", yytext); }
"#"{ID_START}{ID_CHAR}*          { printf("DIRECTIVE: %s\n", yytext); }

{ID_START}{ID_CHAR}*             { printf("IDENTIFIER: %s\n", yytext); }
[ \t\r\n]+                       { /* пропускаем пробелы */ }

.       { printf("SYMBOL: %s\n", yytext); }

%%

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