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

%}

DIGIT       [0-9]
BIN_DIGIT   [01]
OCT_DIGIT   [0-7]
DOZ_DIGIT   [0-9abAB]
HEX_DIGIT   [0-9a-fA-F]
  
LETTER      [a-zA-Z]
ID_START    ({LETTER}|_)
ID_CHAR     ({LETTER}|{DIGIT}|_)
TAG_CHAR    [A-Za-z_-]

ESC_OCTAL   \\[0-7]{1,3}
ESC_HEX     \\x{HEX_DIGIT}{2}
ESC_UNICODE \\u{HEX_DIGIT}{4}
ESC_UNICODE32 \\U{HEX_DIGIT}{8}

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
<STRING,CHAR>{ESC_UNICODE}            { unsigned int cp = (unsigned int)strtol(yytext+2, NULL, 16); append_utf8(buf, cp); }
<STRING,CHAR>{ESC_UNICODE32}          { unsigned int cp = (unsigned int)strtol(yytext+2, NULL, 16); append_utf8(buf, cp); }


`                                { BEGIN(RAW_STRING); string[0] = '\0'; }
<RAW_STRING>[^`\n]+              { strcat(string, yytext); }
<RAW_STRING>\n                   { strcat(string, "\n"); }
<RAW_STRING><<EOF>>              { printf("ERROR: unclosed raw string\n"); return 1; }
<RAW_STRING>`                    { printf("RAW_STRING_LIT: %s\n", string); BEGIN(INITIAL); }

"true"                           { printf("TRUE: true\n"); }
"false"                          { printf("FALSE: false\n"); }
"asm"                            { printf("ASM: asm\n"); }
"auto_cast"                      { printf("AUTO_CAST: auto_cast\n"); }
"bit_field"                      { printf("BIT_FIELD: bit_field\n"); }
"bit_set"                        { printf("BIT_SET: bit_set\n"); }
"break"                          { printf("BREAK: break\n"); }
"case"                           { printf("CASE: case\n"); }
"cast"                           { printf("CAST: cast\n"); }
"context"                        { printf("CONTEXT: context\n"); }
"continue"                       { printf("CONTINUE: continue\n"); }
"defer"                          { printf("DEFER: defer\n"); }
"distinct"                       { printf("DISTINCT: distinct\n"); }
"do"                             { printf("DO: do\n"); }
"dynamic"                        { printf("DYNAMIC: dynamic\n"); }
"else"                           { printf("ELSE: else\n"); }
"enum"                           { printf("ENUM: enum\n"); }
"fallthrough"                    { printf("FALLTHROUGH: fallthrough\n"); }
"for"                            { printf("FOR: for\n"); }
"foreign"                        { printf("FOREIGN: foreign\n"); }
"if"                             { printf("IF: if\n"); }
"import"                         { printf("IMPORT: import\n"); }
"in"                             { printf("IN: in\n"); }
"map"                            { printf("MAP: map\n"); }
"matrix"                         { printf("MATRIX: matrix\n"); }
"not_in"                         { printf("NOT_IN: not_in\n"); }
"or_break"                       { printf("OR_BREAK: or_break\n"); }
"or_continue"                    { printf("OR_CONTINUE: or_continue\n"); }
"or_else"                        { printf("OR_ELSE: or_else\n"); }
"or_return"                      { printf("OR_RETURN: or_return\n"); }
"package"                        { printf("PACKAGE: package\n"); }
"proc"                           { printf("PROC: proc\n"); }
"return"                         { printf("RETURN: return\n"); }
"struct"                         { printf("STRUCT: struct\n"); }
"switch"                         { printf("SWITCH: switch\n"); }
"transmute"                      { printf("TRANSMUTE: transmute\n"); }
"typeid"                         { printf("TYPEID: typeid\n"); }
"union"                          { printf("UNION: union\n"); }
"using"                          { printf("USING: using\n"); }
"when"                           { printf("WHEN: when\n"); }
"where"                          { printf("WHERE: where\n"); }

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

"bool"          { printf("BOOL: bool\n"); }
"b8"            { printf("B8: b8\n"); }
"b16"           { printf("B16: b16\n"); }
"b32"           { printf("B32: b32\n"); }
"b64"           { printf("B64: b64\n"); }
"int"           { printf("INT: int\n"); }
"i8"            { printf("I8: i8\n"); }
"i16"           { printf("I16: i16\n"); }
"i32"           { printf("I32: i32\n"); }
"i64"           { printf("I64: i64\n"); }
"i128"          { printf("I128: i128\n"); }
"uint"          { printf("UINT: uint\n"); }
"u8"            { printf("U8: u8\n"); }
"u16"           { printf("U16: u16\n"); }
"u32"           { printf("U32: u32\n"); }
"u64"           { printf("U64: u64\n"); }
"u128"          { printf("U128: u128\n"); }
"uintptr"       { printf("UINTPTR: uintptr\n"); }
"f16"           { printf("F16: f16\n"); }
"f32"           { printf("F32: f32\n"); }
"f64"           { printf("F64: f64\n"); }
"complex32"     { printf("COMPLEX32: complex32\n"); }
"complex64"     { printf("COMPLEX64: complex64\n"); }
"complex128"    { printf("COMPLEX128: complex128\n"); }
"quaternion64"  { printf("QUATERNION64: quaternion64\n"); }
"quaternion128" { printf("QUATERNION128: quaternion128\n"); }
"quaternion256" { printf("QUATERNION256: quaternion256\n"); }
"string"        { printf("STRING: string\n"); }
"cstring"       { printf("CSTRING: cstring\n"); }
"byte"          { printf("BYTE: byte\n"); }
"rune"          { printf("RUNE: rune\n"); }
"rawptr"        { printf("RAWPTR: rawptr\n"); }
"any"           { printf("ANY: any\n"); }

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