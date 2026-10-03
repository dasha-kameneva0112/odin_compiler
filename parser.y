%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token INT_LIT
%token ID
%token TRUE
%token FALSE
%token IF
%token FOR

%%
program: 
		stmt ';'
	   ;

stmt:
	ID '=' INT_LIT ';'
	;

%%

void yyerror(const char *s) {
	fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
	return yyparse();
}

