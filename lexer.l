%option noyywrap
%option never-interactive

%{
#include <stdio.h>
%}

DIGIT   [0-9]
BIN_DIGIT   [01]
OCT_DIGIT   [0-7]
DOZ_DIGIT	[0-9abAB]
HEX_DIGIT	[0-9a-fA-F]
	
LETTER      [a-zA-Z]
ID_START    ({LETTER}|_)
ID_CHAR     ({LETTER}|{DIGIT}|_)

%%

"package"   { printf("KEYWORD: package\n");}

{ID_START}{ID_CHAR}*  { printf("IDENTIFIER: %s\n", yytext); }

0|[1-9](_?{DIGIT})*   { printf("DECIMAL_LIT: %s\n", yytext); }
0b{BIN_DIGIT}(_?{BIN_DIGIT})*    { printf("BINARY_LIT: %s\n", yytext); }
0o{OCT_DIGIT}(_?{OCT_DIGIT})*    { printf("OCTAL_LIT: %s\n", yytext); }


[ \t\n]+        { /* пропускаем пробелы */ }
. { printf("SYMBOL: %s\n", yytext); }

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