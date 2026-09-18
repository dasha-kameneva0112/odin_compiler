%option noyywrap
%option never-interactive

%x COMMENT
%x STRING

%{
#include <stdio.h>
int comment_depth = 0;
%}

DIGIT   [0-9]
BIN_DIGIT   [01]
OCT_DIGIT   [0-7]
DOZ_DIGIT  [0-9abAB]
HEX_DIGIT  [0-9a-fA-F]
  
LETTER      [a-zA-Z]
ID_START    ({LETTER}|_)
ID_CHAR     ({LETTER}|{DIGIT}|_)

%%
"//"[^\n]*

"/*"                             { comment_depth = 1; BEGIN(COMMENT); }
<COMMENT>"/*"                    { comment_depth++; }
<COMMENT>\n                      {  }
<COMMENT>.                       {  }
<COMMENT><<EOF>>                 { printf("ERROR: unclosed quoted\n"); return 1; }
<COMMENT>"*/"                    { comment_depth--; if (comment_depth == 0) BEGIN(INITIAL); }

"true"|"false"                   { printf("BOOL_LIT: %s\n", yytext); }
"package"|"import"|"proc"|"asm"|"matrix"|"not_in"|"or_break"|"or_continue"|"or_else"|"or_return"|"return"|"struct"|"switch"|"transmute"|"typeid"|"union"|"using"|"when"|"where"|"auto_cast"|"bit_field"|"bit_set"|"break"|"case"|"cast"|"context"|"continue"|"defer"|"distinct"|"do"|"dynamic"|"else"|"enum"|"fallthrough"|"for"|"foreign"|"if"|"in"|"map"                  { printf("KEYWORD: %s\n", yytext); }

"nil"                            { printf("NIL_LIT: %s\n",yytext); }
"---"                            { printf("UNDEFINED_LIT: %s\n",yytext); }
"{}"                             { printf("ZERO_COMPOUND_LIT: %s\n",yytext); }
"?"                              { printf("AUTO_LEN: %s\n", yytext); }

0|[1-9](_?{DIGIT})*              { printf("DECIMAL_LIT: %s\n", yytext); }
0b{BIN_DIGIT}(_?{BIN_DIGIT})*    { printf("BINARY_LIT: %s\n", yytext); }
0o{OCT_DIGIT}(_?{OCT_DIGIT})*    { printf("OCTAL_LIT: %s\n", yytext); }
0z{DOZ_DIGIT}(_?{DOZ_DIGIT})*    { printf("DOZENAL_LIT: %s\n", yytext); }
0x{HEX_DIGIT}(_?{HEX_DIGIT})*    { printf("HEX_LIT: %s\n", yytext); }
0d{DIGIT}(_?{DIGIT})*            { printf("EX_DECIMAL_LIT: %s\n", yytext); }

({DIGIT}(_?{DIGIT})*)?\.({DIGIT}_?{DIGIT}*)?(_?[eE]?[-+]?{DIGIT}+)+|({DIGIT}(_?{DIGIT})*)\.      { printf("FLOAT_LIT: %s\n", yytext); }



{ID_START}{ID_CHAR}*             { printf("IDENTIFIER: %s\n", yytext); }
[ \t\n]+                         { /* пропускаем пробелы */ }
.                                { printf("SYMBOL: %s\n", yytext); }

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