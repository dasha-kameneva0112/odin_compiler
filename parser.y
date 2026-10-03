%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}


%union{
	long long int_val;
	char *str_val;
	struct Statement *stmt_val;
}

struct Statement {
	char *id;
	long long value;
};

struct Statement *create_statement(char *name, long long value) {
    struct Statement *stmt = malloc(sizeof(struct Statement));

    stmt->name = name;
    stmt->value = value;

    return stmt;
}

%token <int_val> INT_LIT
%token <str_val> ID

%token TRUE
%token FALSE
%token IF
%token FOR

%type <stmt_val> stmt

%%
program: 
		stmt ';'
	   ;

stmt:
	ID '=' INT_LIT ';'
	{
		$$ = create_statement($1, $3);
	}
	;

%%

void yyerror(const char *s) {
	fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
	return yyparse();
}

