%option noyywrap
%option never-interactive

%{
#include <stdio.h>
%}

%%

[0-9]+          { printf("NUMBER: %s\n", yytext); }
[A-Za-z_][A-Za-z0-9_]*  { printf("IDENTIFIER: %s\n", yytext); }
[ \t\n]+        { /* пропускаем пробелы */ }
.               { printf("SYMBOL: %s\n", yytext); }

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