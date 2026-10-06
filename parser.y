%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%union {
    long long    int_val;  /* целочисленный литерал   */
    double       float_val;  /* вещественный литерал    */
    char        *str_val;   /* ID, строки, директивы   */
    unsigned int rune_val;   /* символьный (rune) литерал */
}

%locations
%define parse.error verbose

/* --- Ключевые слова языка --- */
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
%token AT 

%token OP_ADD_ASSIGN OP_SUB_ASSIGN OP_MUL_ASSIGN OP_DIV_ASSIGN
%token OP_MOD_ASSIGN OP_MOD2_ASSIGN OP_OR_ASSIGN OP_NOT_ASSIGN
%token OP_AND_ASSIGN OP_AND_NOT_ASSIGN OP_SHL_ASSIGN OP_SHR_ASSIGN
%token OP_LOG_AND_ASSIGN OP_LOG_OR_ASSIGN
%token OP_LOG_AND OP_LOG_OR OP_AND_NOT OP_SHL OP_SHR
%token OP_EQ OP_NE OP_LE OP_GE
%token OP_RANGE OP_RANGE_INCLUSIVE OP_RANGE_EXCLUSIVE
%token OP_ARROW OP_DECL_TYPED OP_DECL_INFERRED OP_MOD2 OP_DOLLAR

%token LEX_ERROR

/* --- Приоритеты и ассоциативность --- */
%right '?' IF WHEN
%left OR_ELSE
%left OP_RANGE OP_RANGE_INCLUSIVE OP_RANGE_EXCLUSIVE
%left OP_LOG_OR
%left OP_LOG_AND
%left OP_EQ OP_NE '<' '>' OP_LE OP_GE
%left '+' '-' '|' '~'
%left '*' '/' '%' OP_MOD2 '&' OP_AND_NOT OP_SHL OP_SHR
%precedence UNARY
%precedence '(' '[' '.' '^' OR_RETURN OR_BREAK OR_CONTINUE 

%%
/* ---- Верхний уровень (программа) ----
  package main
  import "core:fmt"
  main :: proc() { }                        */
program:
       package_clause import_list decl_list
       ;

package_clause:PACKAGE ID
              | PACKAGE ID ';'
              ;

/* --- Список импортов --- */
import_list: %empty
           | import_list import_decl
           ;

import_decl: IMPORT STRING_LIT
           | IMPORT STRING_LIT ';'
           ;

/* --- Список объявлений верхнего уровня --- */
decl_list: %empty
         | decl_list decl
         ;

decl: decl_core
    | decl_core ';'
    ;

decl_core: proc_decl
         | var_decl
         | const_decl
         | type_decl
         | foreign_decl
         ;

/* ---- Процедура ----
  main :: proc() { }
  add  :: proc(a: int, b: int) -> int { }
  foo  :: proc { foo_int, foo_str }        */
proc_decl: ID OP_DECL_TYPED PROC '(' param_list_opt ')' return_type block
         | ID OP_DECL_TYPED PROC '{' id_list '}'
         ;

/* --- Список пораметров --- */
param_list_opt: %empty
              | param_list
              ;

param_list:param
          | param_list ',' param
          ;

param:expr_list ':' type_expr
     ;

/* --- Список имен --- */
id_list: ID
       | id_list ',' ID
       ;
       
/* --- Тип возвращаемого значения --- */
return_type: %empty
           | OP_ARROW type_expr
           | OP_ARROW '(' return_type_list ')'
           ;

return_type_list:type_expr
                | return_type_list ',' type_expr
                ;

/* ---- Переменные и типизированные константы (общий префикс id_list ':') ----
  x: int = 5   x: int   x := 5   x, y := 1, 2   MAX: int : 100 *           /
var_decl:id_list ':' type_expr '=' expr_list 
        | id_list ':' type_expr
        | id_list OP_DECL_INFERRED expr_list
        ;

/* ---- Константа ----   
  MAX :: 100 
  MAX: int : 100   
  C, D, E: f32 : 1.0, 2.0, 3.0    */
const_decl:ID OP_DECL_TYPED expr 
          | id_list  ':' type_expr ':' expr_list
          ;

/* ---- Объявление типа ----
   MyInt :: int
   Point :: struct { x, y: int } */
type_decl:ID OP_DECL_TYPED type_expr
         ;

/* --- Тип - имя или составной --- */
type_expr:ID
         | type_core
         ;

/* --- Составные типы --- */
type_core:base_type
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

/* ---- Поля структуры ---- */
field_list_opt: %empty
              | field_list
              ;

field_list: field_decl
          | field_list ',' field_decl
          ;

field_decl: expr_list ':' type_expr
          ;

  /* ---- Объявление функций/переменных из внешних библиотек ---- */
foreign_decl:FOREIGN IMPORT ID STRING_LIT
            | FOREIGN block
            ;

/* ---------- ВСТРОЕННЫЕ ТИПЫ ---------- */
base_type: BOOL 
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

/* ---- Поля enum ---- */
enum_body_opt: %empty
             | enum_body
             ;

enum_body: enum_item
         | enum_body ',' enum_item
         ;

enum_item:
         ID
         | ID '=' expr
         ;

/* ---- Блоки кода ---- */
block: '{' stmts '}'
     ;

/* Внутри блока: список операторов, где ПОСЛЕДНИЙ может быть term_stmt */
stmts: stmt_list
      | stmt_list term_stmt
      ;

/* Список операторов с обязательной ';' после каждого term_stmt */
stmt_list: %empty
         | stmt_list stmt
         ;

/* ---- Один оператор:
     - составной (блок, if, for, ...) — уже оканчивается '}', ';' не нужна
     - составной с ';' — тоже допустимо
     - term_stmt (простой) — требует ';' после себя ---- */
stmt:compound_stmt
    | compound_stmt ';'
    | term_stmt ';'
    ;

/* ---- Составные операторы — не требуют ';' после себя ---- */
compound_stmt: block
             | if_stmt
             | for_stmt
             | switch_stmt
             | when_stmt
             | label_stmt
             | DEFER compound_stmt
             | DIRECTIVE compound_stmt
             ;

/* ---- Метка ---- */
label_stmt:expr_list ':' labe_lable_stmt
          ;

/*---- На что можно навесить метку ----*/
labe_lable_stmt: block
               | if_stmt
               | for_stmt
               | switch_stmt
               ;

/* --------Простые операторы — требуют ';' после себя -------*/
term_stmt:simple_stmt
         | for_do_stmt
         | return_stmt
         | BREAK
         | CONTINUE
         | FALLTHROUGH    
         | USING expr
         | DEFER term_stmt
         | DIRECTIVE term_stmt
         ;

/* ----------Простые операторы-выражения:
   x = 5, x, y = 1, 2, x := 5, x: int, x: int = 5,
   x: int : 5 (const), x += 1, f()  -------------------*/
simple_stmt: expr_list '=' expr_list
           | expr_list OP_DECL_INFERRED expr_list
           | expr_list ':' type_expr
           | expr_list ':' type_expr '=' expr_list
           | expr_list ':' type_expr ':' expr_list
           | expr assign_op expr
           | expr
           ;

/* ---- Операторы составного присваивания +=, -=, *=, /= ...---- */
assign_op:OP_ADD_ASSIGN 
         | OP_SUB_ASSIGN 
         | OP_MUL_ASSIGN 
         | OP_DIV_ASSIGN
         | OP_MOD_ASSIGN 
         | OP_MOD2_ASSIGN 
         | OP_OR_ASSIGN 
         | OP_NOT_ASSIGN
         | OP_AND_ASSIGN 
         | OP_AND_NOT_ASSIGN 
         | OP_SHL_ASSIGN 
         | OP_SHR_ASSIGN
         | OP_LOG_AND_ASSIGN 
         | OP_LOG_OR_ASSIGN
         ;

/* ---- Необязательный простой оператор ---- */
simple_stmt_opt: %empty
               | simple_stmt
               ;

/* ---- Необязательное выражение ---- */
expr_opt: %empty
        | expr
        ;

/* ---- Условные операторы if ---- */
if_stmt:
       IF expr block
       | IF expr block ELSE block
       | IF expr block ELSE if_stmt
       | IF simple_stmt ';' expr block
       | IF simple_stmt ';' expr block ELSE block
       | IF simple_stmt ';' expr block ELSE if_stmt
       ;

/* ---- Циклы for ---- */
for_stmt:
        FOR block
        | FOR expr block
        | FOR expr_list IN expr block
        | FOR simple_stmt_opt ';' expr_opt ';' simple_stmt_opt block
        ;

/* ---- Циклы for с оператором DO ---- */
for_do_stmt:
           FOR expr DO term_stmt    
           | FOR expr_list IN expr DO term_stmt
           | FOR simple_stmt_opt ';' expr_opt ';' simple_stmt_opt DO term_stmt
           ;

/* ---- Операторы выбора switch ---- */
switch_stmt:
           SWITCH switch_body
           | SWITCH expr switch_body
           | SWITCH simple_stmt ';' expr switch_body
           | SWITCH simple_stmt ';' switch_body
           ;

/* ---- Тело оператора switch ---- */
switch_body: '{' case_list '}'
           ;

/* ---- Список ветвей case ---- */
case_list: %empty
         | case_list case_clause
         ;

case_clause:
           CASE expr_list ':' stmts
           | CASE ':' stmts
           ;

/* ---- Список выражений ---- */
expr_list: expr
         | expr_list ',' expr
         ;

/* ---- Условные операторы when ---- */
when_stmt:
         WHEN expr block
         | WHEN expr block ELSE when_stmt
         | WHEN expr block ELSE block
         ;

/* ---- Оператор возврата return ---- */
return_stmt:
           RETURN
           | RETURN expr_list
           ;

/* ---- Выражения ---- */
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

/* ---- унарные (приоритет UNARY) ---- */
    | '+' expr %prec UNARY
    | '-' expr %prec UNARY
    | '!' expr %prec UNARY
    | '~' expr %prec UNARY
    | '&' expr %prec UNARY
    | AUTO_CAST expr %prec UNARY

/* ---- бинарные: логика ---- */
    | expr OP_LOG_OR expr
    | expr OP_LOG_AND expr
/* ---- сравнения ---- */
    | expr OP_EQ expr
    | expr OP_NE expr
    | expr '<' expr
    | expr '>' expr
    | expr OP_LE expr
    | expr OP_GE expr
/* ---- арифметика и битовые ---- */
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

  /* ---- or_else и диапазоны ---- */
    | expr OR_ELSE expr
    | expr OP_RANGE expr
    | expr OP_RANGE_INCLUSIVE expr
    | expr OP_RANGE_EXCLUSIVE expr

/* ---- тернарные формы ---- */
    | expr '?' expr ':' expr  %prec '?'
    | expr WHEN expr ELSE expr %prec WHEN
    | expr IF expr ELSE expr %prec IF

/* ---- постфиксные ---- */
    | expr '^'
    | expr OR_RETURN
    | expr OR_BREAK
    | expr OR_CONTINUE
    | expr '(' arg_list_op ')'
    | expr '[' expr ']'
    | expr '.' ID

/* ---- приведение типа ---- */
    | CAST '(' type_expr ')' expr %prec UNARY
    | TRANSMUTE '(' type_expr ')' expr %prec UNARY
    ;

/* ---- аргументы вызова функции ---- */
arg_list_op: %empty
           | arg_list
           ;

arg_list: expr
        | arg_list ',' expr
        ;

%%

extern FILE *yyin;

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylloc.first_line, s);
}

int main(int argc, char **argv) {
    if (argc < 2) { fprintf(stderr, "Usage: %s <file>\n", argv[0]); return 1; }
    yyin = fopen(argv[1], "r");
    if (!yyin) { perror(argv[1]); return 1; }
    int r = yyparse();
    fclose(yyin);
    if (r == 0) printf("Good\n");
    return r;
}
