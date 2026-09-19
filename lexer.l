%option noyywrap
%option never-interactive

%x COMMENT
%x STRING
%x CHAR
%x RAW_STRING

%{
#include <stdio.h>
int comment_depth = 0;
char string[1000]; 
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

%%
"//"[^\n]*                       { printf("ONE_LINE_COMMENT: %s\n",yytext); }

"/*"                             { comment_depth = 1; BEGIN(COMMENT); }
<COMMENT>"/*"                    { comment_depth++; }
<COMMENT>\n                      {  }
<COMMENT>.                       {  }
<COMMENT><<EOF>>                 { printf("ERROR: unclosed quoted\n"); return 1; }
<COMMENT>"*/"                    { comment_depth--; if (comment_depth == 0) BEGIN(INITIAL); }

\"                               { BEGIN(STRING); string[0]=0; }
<STRING> [^\\\"\n]+              { strcat(string, yytext); }
<STRING> \\n                     { strcat(string, "\n"); }
<STRING> \\\\                    { strcat(string, "\\"); }
<STRING> \\\"                    { strcat(string, "\""); }
<STRING> \\\n                    {}
<STRING> \\[0-7]{1,3}            { char code[2]={0}; code[0]=(char)strtol(yytext+1, null, 8); strcat(string, code); }
<STRING> \"                      { printf("%s", string); BEGIN(INITIAL); }
<STRING> \n                      { printf("Error: end of line in string"); }
<STRING> <<EOF>>                 { printf("Error: unclosed string\n"); }

"true"|"false"                   { printf("BOOL_LIT: %s\n", yytext); }
"package"|"import"|"proc"|"asm"|"matrix"|"not_in"|"or_break"|"or_continue"|"or_else"|"or_return"|"return"|"struct"|"switch"|"transmute"|"typeid"|"union"|"using"|"when"|"where"|"auto_cast"|"bit_field"|"bit_set"|"break"|"case"|"cast"|"context"|"continue"|"defer"|"distinct"|"do"|"dynamic"|"else"|"enum"|"fallthrough"|"for"|"foreign"|"if"|"in"|"map"                  { printf("KEYWORD: %s\n", yytext); }

"nil"                            { printf("NIL_LIT: %s\n",yytext); }
"---"                            { printf("UNDEFINED_LIT: %s\n",yytext); }
"{}"                             { printf("ZERO_COMPOUND_LIT: %s\n",yytext); }
"?"                              { printf("QUESTION: %s\n", yytext); }

0|[1-9](_?{DIGIT})*              { printf("DECIMAL_LIT: %s\n", yytext); }
0b{BIN_DIGIT}(_?{BIN_DIGIT})*    { printf("BINARY_LIT: %s\n", yytext); }
0o{OCT_DIGIT}(_?{OCT_DIGIT})*    { printf("OCTAL_LIT: %s\n", yytext); }
0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*    { printf("DOZENAL_LIT: %s\n", yytext); }
0x{HEX_DIGIT}(_?{HEX_DIGIT})*    { printf("HEX_LIT: %s\n", yytext); }
0d{DIGIT}(_?{DIGIT})*            { printf("EX_DECIMAL_LIT: %s\n", yytext); }

({DIGIT}(_?{DIGIT})*)?\.({DIGIT}_?{DIGIT}*)?(_?[eE]?[-+]?{DIGIT}+)+|({DIGIT}(_?{DIGIT})*)\.      { printf("FLOAT_LIT: %s\n", yytext); }
((0|[1-9](_?{DIGIT})*)|(0b{BIN_DIGIT}(_?{BIN_DIGIT})*)|(0o{OCT_DIGIT}(_?{OCT_DIGIT})*)|(0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*)|(0x{HEX_DIGIT}(_?{HEX_DIGIT})*)|(0d{DIGIT}(_?{DIGIT})*)|(({DIGIT}(_?{DIGIT})*)?\.({DIGIT}_?{DIGIT}*)?(_?[eE]?[-+]?{DIGIT}+)+|({DIGIT}(_?{DIGIT})*)\.))[ijk] {  printf("IMAGINARY_LIT: %s\n", yytext); }

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

"#"{ID_START}{ID_CHAR}*           { printf("DIRECTIVE: %s\n", yytext); }
"#+"{ID_START}{TAG_CHAR}*        { printf("BUILD_DIRECTIVE: %s\n", yytext); }

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