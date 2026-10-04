%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%union {
    long long    int_val;
    double       float_val;
    char        *str_val;
    unsigned int rune_val;
}

%token TRUE FALSE ASM AUTO_CAST BIT_FIELD BIT_SET BREAK CASE CAST
%token CONTEXT CONTINUE DEFER DISTINCT DO DYNAMIC ELSE ENUM FALLTHROUGH
%token FOR FOREIGN IF IMPORT IN MAP MATRIX NOT_IN OR_BREAK OR_CONTINUE
%token OR_ELSE OR_RETURN PACKAGE PROC RETURN STRUCT SWITCH TRANSMUTE
%token TYPEID UNION USING WHEN WHERE

%token BOOL B8 B16 B32 B64 INT I8 I16 I32 I64 I128
%token UINT U8 U16 U32 U64 U128 UINTPTR
%token F16 F32 F64 COMPLEX32 COMPLEX64 COMPLEX128
%token QUATERNION64 QUATERNION128 QUATERNION256
%token STRING CSTRING BYTE RUNE RAWPTR ANY

%token <int_val>   INT_LIT
%token <float_val> FLOAT_LIT
%token <str_val>   ID STRING_LIT RAW_STRING_LIT IMAGINARY_LIT
%token <rune_val>  RUNE_LIT
%token NIL UNDEFINED

%token <str_val> ATTRIBUTE BUILD_DIRECTIVE DIRECTIVE
%token AT QUESTION

%token OP_ADD_ASSIGN OP_SUB_ASSIGN OP_MUL_ASSIGN OP_DIV_ASSIGN
%token OP_MOD_ASSIGN OP_MOD2_ASSIGN OP_OR_ASSIGN OP_NOT_ASSIGN
%token OP_AND_ASSIGN OP_AND_NOT_ASSIGN OP_SHL_ASSIGN OP_SHR_ASSIGN
%token OP_LOG_AND_ASSIGN OP_LOG_OR_ASSIGN
%token OP_LOG_AND OP_LOG_OR OP_AND_NOT OP_SHL OP_SHR
%token OP_EQ OP_NE OP_LE OP_GE
%token OP_RANGE OP_RANGE_INCLUSIVE OP_RANGE_EXCLUSIVE
%token OP_ARROW OP_DECL_TYPED OP_DECL_INFERRED OP_MOD2 OP_DOLLAR

%token LEX_ERROR

%right QUESTION IF WHEN
%left OR_ELSE
%left OP_RANGE OP_RANGE_INCLUSIVE OP_RANGE_EXCLUSIVE
%left OP_LOG_OR
%left OP_LOG_AND
%left OP_EQ OP_NE '<' '>' OP_LE OP_GE
%left '+' '-' '|' '~'
%left '*' '/' '%' OP_MOD2 '&' OP_AND_NOT OP_SHL OP_SHR
%right UNARY
%left '(' '[' '.' '^' OR_RETURN OR_BREAK OR_CONTINUE 

%%
program: 
	   package_clause import_list decl_list 
	   ;

package_clause: 
			  PACKAGE ID 
              ;

import_list:
		   /* empty */
		   | import_list import_decl
		   ;

import_decl:
		   IMPORT STRING_LIT
		   ;

decl_list:
		 /* empty */
		 | decl_list decl
		 ;

decl: 
	proc_decl
	| var_decl
	| const_decl
	| type_decl
	| foreign_decl
	;

/* ---- Процедура ----
   main :: proc() { }
   add  :: proc(a: int, b: int) -> int { }
   foo  :: proc { foo_int, foo_str }        */
proc_decl:
		 ID OP_DECL_TYPED PROC '(' param_list_opt ')' return_type block
		 | ID OP_DECL_TYPED PROC '{' id_list '}'
		 ;

param_list_opt:
              /* empty */
              | param_list
              ;

param_list:
          param
          | param_list ',' param
          ;

param:
	 id_list ':' type_expr
	 ;

id_list: 
	   ID
	   | id_list ',' ID 
	   ;

return_type: /* empty */
           | OP_ARROW type_expr
           | OP_ARROW '(' type_list ')'
           ;


/* ---- Переменная ----
   x: int = 5
   x: int
   x := 5    */
var_decl:
		ID ':' type_expr '=' expr 
		| ID ':' type_expr
		| ID OP_DECL_INFERRED expr
		;


/* ---- Константа ----   
    	MAX :: 100 
        MAX: int : 100    */
const_decl:
		  ID OP_DECL_TYPED expr 
          | ID ':' type_expr ':' expr
		  ;


/* ---- Объявление типа ----
   MyInt  :: int
   Point  :: struct { x, y: int }   */
type_decl: 
         ID OP_DECL_TYPED type_expr 
         ;

type_expr: 
         ID    
         | type_core 
         ;

/* MyType / ^T / []T (срез) / [N]T (массив)
   [dynamic]T / map[K]V / proc(...)->T 
   кортеж  (int, string) / анонимный struct/enum/union
   bit_set[T] / distinct T / matrix[R,C]T */
type_core: 
         base_type
         | '^' type_expr
         | '[' ']' type_expr
         | '[' expr ']' type_expr
         | '[' DYNAMIC ']' type_expr
         | MAP '[' type_expr ']' type_expr
         | PROC '(' param_list_opt ')' return_type
         | STRUCT '{' field_list_opt '}'
         | ENUM '{' enum_body_opt '}'
         | UNION '{' field_list_opt '}'
         | BIT_SET '[' type_expr ']'
         | DISTINCT type_expr
         | MATRIX '[' expr ',' expr ']' type_expr
         ;

field_list_opt:
              /* empty */
              | field_list
              ;

field_list:
          field_decl
          | field_list ',' field_decl
          ;

field_decl:
		  id_list ':' type_expr
		  ;


/* ---- Foreign ----
   foreign import foo "lib"
   foreign { ... }            */
foreign_decl:
		  	FOREIGN IMPORT ID STRING_LIT 
			| FOREIGN block 
            ;

base_type:
         BOOL
         | B8  
         | B16 
         | B32 
         | B64    
         | INT 
         | I8  
         | I16 
         | I32 
         | I64 
         | I128    
         | UINT 
         | U8 
         | U16 
         | U32 
         | U64 
         | U128    
         | UINTPTR    
         | F16 
         | F32 
         | F64
         | COMPLEX32 
         | COMPLEX64 
         | COMPLEX128
         | QUATERNION64 
         | QUATERNION128 
         | QUATERNION256
         | STRING 
         | CSTRING 
         | BYTE 
         | RUNE 
         | RAWPTR 
         | ANY
         ;

type_list:
         type_expr
         | type_list ',' type_expr
         ;

enum_body_opt:
             /* empty */
             | enum_body
             ;

enum_body:
         enum_item
         | enum_body ',' enum_item
         ;

enum_item:
         ID
         | ID '=' expr
         ;

block: '{' stmt_list '}'
     ;

stmt_list: /* empty */
         | stmt_list stmt
         ;

stmt: /*  x = 5 / x := 5 / x: int = 5 / x: int  */
    simple_stmt
    | block
    | if_stmt
    | for_stmt 
    | return_stmt
    | defer_stmt
    | BREAK
    | CONTINUE
    | FALLTHROUGH
    ;

simple_stmt:
           ID '=' expr 
           | ID OP_DECL_INFERRED expr 
           | ID ':' type_expr '=' expr
           | ID ':' type_expr 

           | ID OP_ADD_ASSIGN expr
           | ID OP_SUB_ASSIGN expr 
           | ID OP_MUL_ASSIGN expr
           | ID OP_DIV_ASSIGN expr
           | ID OP_MOD_ASSIGN expr
           | ID OP_AND_ASSIGN expr
           | ID OP_OR_ASSIGN expr
           | ID OP_SHL_ASSIGN expr
           | ID OP_SHR_ASSIGN expr
           | expr
           ;


/* if x > 0 { }
   if x > 0 { } else { }
   if x > 0 { } else if y > 0 { } else { } */
if_stmt:
       IF expr block 
       | IF expr block ELSE block
       | IF expr block ELSE if_stmt
       ;


/* for { }
   for x < 10 { }
   for x in arr { }
   for k, v in m { }
   for i := 0; i < n; i += 1 { }
   for i := 0; i < 10; i += 1 do x += 1  */
for_stmt:
        FOR block
        | FOR expr block

        | FOR expr IN expr block 
        | FOR expr ',' expr IN expr block 
        
        | FOR simple_stmt ';' expr ';' simple_stmt block 
        
        | FOR expr DO simple_stmt
        | FOR expr IN expr DO simple_stmt
        | FOR expr ',' expr IN expr DO simple_stmt
        | FOR simple_stmt ';' expr ';' simple_stmt DO simple_stmt
        ;


/* return
   return x + 1 */
return_stmt: 
           RETURN 
           | RETURN expr
           ;


/* defer f()
   defer fmt.println("done")
   defer { n = 456 }         */
defer_stmt:
          DEFER stmt 
          ;


expr: ID
    | INT_LIT
    | FLOAT_LIT
    | STRING_LIT
    | RAW_STRING_LIT
    | IMAGINARY_LIT
    | RUNE_LIT
    | NIL
    | UNDEFINED
    | TRUE
    | FALSE
    | '(' expr ')'

	/* ---- unary ---- */
    | '+' expr %prec UNARY
    | '-' expr %prec UNARY
    | '!' expr %prec UNARY
    | '~' expr %prec UNARY
    | '&' expr %prec UNARY
    | AUTO_CAST expr %prec UNARY

	/* ---- binary ---- */
    | expr OP_LOG_OR expr
    | expr OP_LOG_AND expr
    | expr OP_EQ expr
    | expr OP_NE expr
    | expr '<' expr
    | expr '>' expr
    | expr OP_LE expr
    | expr OP_GE expr
    | expr '+' expr
    | expr '-' expr
    | expr '|' expr
    | expr '~' expr
    | expr '*' expr
    | expr '/' expr
    | expr '%' expr
    | expr OP_MOD2 expr
    | expr '&' expr
    | expr OP_AND_NOT expr
    | expr OP_SHL expr
    | expr OP_SHR expr

    /* ---- or_else и диапазоны (.., ..=, ..<) ---- */
    | expr OR_ELSE expr
    | expr OP_RANGE expr
    | expr OP_RANGE_INCLUSIVE expr
    | expr OP_RANGE_EXCLUSIVE expr

     /* ---- тернарные формы ---- */
    |expr '?' expr ':' expr  %prec QUESTION
    |expr WHEN expr ELSE expr %prec WHEN
    |expr IF expr ELSE expr %prec IF

    /* ---- постфиксные  ---- */
    | expr '^'
    | expr OR_RETURN
    | expr OR_BREAK
    /* | expr OR_BREAK ID */
    | expr OR_CONTINUE
    /* | expr OR_CONTINUE ID */
    | expr '(' arg_list_op ')'
    | expr '[' expr ']'
    | expr '.' ID
         
    /* ---- приведения типа ---- 
    cast(i64) x */
    |CAST '(' type_expr ')' expr %prec UNARY
    /* ---- приведения типа ---- 
    transmute(u32) 1.5 */
    |TRANSMUTE '(' type_expr ')' expr %prec UNARY
    ;


arg_list_op: /* empty */
           | arg_list 
           ;

arg_list: expr
        | arg_list ',' expr
        ;


%%

void yyerror(const char *s) {
	fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
	return yyparse();
}

