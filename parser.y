%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%code requires {
    #include "tree_nodes.h"
}

%union {
    long long    int_val;  /* целочисленный литерал   */
    double       float_val;  /* вещественный литерал    */
    char        *str_val;   /* ID, строки, директивы   */
    unsigned int rune_val;   /* символьный (rune) литерал */
    struct {
            double value;
            char unit;
            } imag_val;   /* 3.5i -> {3.5, 'i'} */

 /* Узлы синтаксического дерева */
    struct ExprNode  *expr_node;                       /* Указатель на выражение */
    struct ExprList    *expr_list_node;                  /* Список выражений */
    struct TypeNode    *type_expr_node;                  /* Указатель на описание типа */
    struct IdList      *id_list_node;                    /* Cписок имен */
    struct FieldNode   *field_decl_node;                 /* Одно объявление полей или параметров */
    struct FieldList   *field_list_node;                 /* Список таких объявлений */
    struct TypeList    *type_list_node;                  /* Список типов */
    struct EnumItemNode    *enum_item_node;                  /* Один элемент enum */
    struct EnumItemList *enum_item_list_node;            /* Список элементов enum */
}

%code {
        #include "tree_creators.h"
        #include "tree_print.h"
}

%locations
%define parse.error verbose

/* --- Ключевые слова языка --- */
%token ASM AUTO_CAST BIT_FIELD BIT_SET BREAK CASE CAST
%token CONTEXT CONTINUE DEFER DISTINCT DO DYNAMIC ELSE ENUM FALLTHROUGH
%token FOR FOREIGN IF IMPORT IN MAP MATRIX NOT_IN OR_BREAK OR_CONTINUE
%token OR_ELSE OR_RETURN PACKAGE PROC RETURN STRUCT SWITCH
%token TYPEID UNION USING WHEN WHERE

%token BOOL B8 B16 B32 B64 INT I8 I16 I32 I64 I128
%token UINT U8 U16 U32 U64 U128 UINTPTR
%token F16 F32 F64 COMPLEX32 COMPLEX64 COMPLEX128
%token QUATERNION64 QUATERNION128 QUATERNION256
%token STRING CSTRING BYTE RUNE RAWPTR ANY

%token <int_val>   INT_LIT BOOL_LIT
%token <float_val> FLOAT_LIT
%token <str_val>   ID STRING_LIT RAW_STRING_LIT 
%token <imag_val>  IMAGINARY_LIT
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

/* --- Нетерминалы--- */
%type <expr_node> expr            
%type <expr_list_node> expr_list arg_list arg_list_op   
%type <id_list_node> id_list
%type <type_expr_node> type_expr type_core base_type 

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

package_clause: PACKAGE ID ';'
              ;

/* --- Список импортов --- */
import_list: %empty
           | import_list import_decl
           ;

import_decl: IMPORT STRING_LIT ';'
           ;

/* --- Список объявлений верхнего уровня --- */
decl_list: %empty
         | decl_list decl
         ;

decl: decl_core ';'
    ;

decl_core: proc_decl
         | var_decl
         | const_decl
         | foreign_decl
         | attribute decl_core
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

param: id_list ':' type_expr
     ;

/* --- Список имен --- */
                                    /* @1.first_line — строка именно этого токена (в отличие от @$, который относится ко всему правилу). */
id_list: ID                         { $$ = idlist_new($1, @1.first_line); }
       | id_list ',' ID             { $$ = idlist_append($1, $3, @3.first_line); }
       ;
       
/* --- Тип возвращаемого значения --- */
return_type: %empty
           | OP_ARROW type_expr
           | OP_ARROW '(' return_type_list ')'
           ;

return_type_list:type_expr
                | return_type_list ',' type_expr
                ;

/* ---- Переменные и типизированные константы (общий префикс id_
list ':') ----
  x: int = 5   x: int   x := 5   x, y := 1, 2   MAX: int : 100 */
var_decl:id_list ':' type_expr '=' expr_list 
        | id_list ':' type_expr
        | id_list OP_DECL_INFERRED expr_list
        ;

/* ---- Константа ----   
  MAX   :: 100
  NAME  :: "hello"
  MyMyInt :: MyInt
  MAX: int : 100   
  C, D, E: f32 : 1.0, 2.0, 3.0    */
const_decl:ID OP_DECL_TYPED expr 
          | ID OP_DECL_TYPED type_core
          | id_list  ':' type_expr ':' expr_list
          ;

/* --- Тип - имя или составной --- */
type_expr:ID                                           { $$ = mk_type_name($1, @1.first_line); }     
         | type_core                                   { $$ = $1; }
         ;

/* --- Составные типы --- */
type_core:base_type                                    { $$ = $1; }
         | '^' type_expr                               { $$ = mk_type_elem(TY_POINTER,$2,@1.first_line); }
         | '[' ']' type_expr                           { $$ = mk_type_elem(TY_SLICE,$3,@1.first_line); }
         | '[' expr ']' type_expr                      { $$ = mk_type_array($2,$4,@1.first_line); }
         | '[' DYNAMIC ']' type_expr                   { $$ = mk_type_elem(TY_DYN_ARRAY,$4,@1.first_line); }
         | MAP '[' type_expr ']' type_expr             { $$ = mk_type_map($3,$5,@1.first_line); }
         | PROC '(' param_list_opt ')' return_type     { /* ЗАГЛУШКА*/ }
         | STRUCT '{' field_list_opt '}'               {  /* ЗАГЛУШКА*/ }
         | ENUM '{' enum_body_opt '}'                  {  /* ЗАГЛУШКА*/ }
         | UNION '{' field_list_opt '}'                {  /* ЗАГЛУШКА*/ }
         | BIT_SET '[' type_expr ']'                   { $$ = mk_type_elem(TY_BIT_SET,$3,@1.first_line); }
         | DISTINCT type_expr                          { $$ = mk_type_elem(TY_DISTINCT,$2,@1.first_line); }
         | MATRIX '[' expr ',' expr ']' type_expr      { $$ = mk_type_matrix($3,$5,$7,@1.first_line); }
         ;

/* ---- Поля структуры ---- */
field_list_opt: %empty
              | field_list
              | field_list ','
              | field_list ';'
              ;

field_list: field_decl
          | field_list ',' field_decl
          ;

field_decl: id_list ':' type_expr
          ;

  /* ---- Объявление функций/переменных из внешних библиотек ---- */
foreign_decl:FOREIGN IMPORT ID STRING_LIT
            | FOREIGN block
            ;

/* ---------- ВСТРОЕННЫЕ ТИПЫ ---------- */
base_type: BOOL                              {$$ = mk_type_base(BT_BOOL, @1.first_line);}
         | B8                                {$$ = mk_type_base(BT_B8, @1.first_line);}
         | B16                               {$$ = mk_type_base(BT_B16, @1.first_line);}
         | B32                               {$$ = mk_type_base(BT_B32, @1.first_line);}
         | B64                               {$$ = mk_type_base(BT_B64, @1.first_line);}
         | INT                               {$$ = mk_type_base(BT_INT, @1.first_line);}
         | I8                                {$$ = mk_type_base(BT_I8, @1.first_line);}
         | I16                               {$$ = mk_type_base(BT_I16, @1.first_line);}
         | I32                               {$$ = mk_type_base(BT_I32, @1.first_line);}
         | I64                               {$$ = mk_type_base(BT_I64, @1.first_line);}
         | I128                              {$$ = mk_type_base(BT_I128, @1.first_line);}
         | UINT                              {$$ = mk_type_base(BT_UINT, @1.first_line);}
         | U8                                {$$ = mk_type_base(BT_U8, @1.first_line);}
         | U16                               {$$ = mk_type_base(BT_U16, @1.first_line);}
         | U32                               {$$ = mk_type_base(BT_U32, @1.first_line);}
         | U64                               {$$ = mk_type_base(BT_U64, @1.first_line);}
         | U128                              {$$ = mk_type_base(BT_U128, @1.first_line);}
         | UINTPTR                           {$$ = mk_type_base(BT_UINTPTR, @1.first_line);}
         | F16                               {$$ = mk_type_base(BT_F16, @1.first_line);}
         | F32                               {$$ = mk_type_base(BT_F32, @1.first_line);}
         | F64                               {$$ = mk_type_base(BT_F64, @1.first_line);}
         | COMPLEX32                         {$$ = mk_type_base(BT_COMPLEX32, @1.first_line);}
         | COMPLEX64                         {$$ = mk_type_base(BT_COMPLEX64, @1.first_line);}
         | COMPLEX128                        {$$ = mk_type_base(BT_COMPLEX128, @1.first_line);}
         | QUATERNION64                      {$$ = mk_type_base(BT_QUATERNION64, @1.first_line);}
         | QUATERNION128                     {$$ = mk_type_base(BT_QUATERNION128, @1.first_line);}
         | QUATERNION256                     {$$ = mk_type_base(BT_QUATERNION256, @1.first_line);}
         | STRING                            {$$ = mk_type_base(BT_STRING, @1.first_line);}
         | CSTRING                           {$$ = mk_type_base(BT_CSTRING, @1.first_line);}
         | BYTE                              {$$ = mk_type_base(BT_BYTE, @1.first_line);}
         | RUNE                              {$$ = mk_type_base(BT_RUNE, @1.first_line);}
         | RAWPTR                            {$$ = mk_type_base(BT_RAWPTR, @1.first_line);}
         | ANY                               {$$ = mk_type_base(BT_ANY, @1.first_line);}
         ;

/* ---- Поля enum ---- */
enum_body_opt: %empty
             | enum_body
             | enum_body ','
             | enum_body ';'
             ;

enum_body: enum_item
         | enum_body ',' enum_item
         ;

enum_item:
         ID
         | ID '=' expr
         ;

/* ---- Блоки кода ---- */
block: '{' stmt_list_opt '}'
     ;

/* Список операторов, ';' после последнего необязательна */
stmt_list_opt: %empty
             | stmt_list
             | stmt_list ';'
             ;

stmt_list: stmt
         | stmt_list ';' stmt 
         ;
             
/* ---- Один оператор ---- */
stmt: simple_stmt 
    | block
    | if_stmt
    | for_stmt
    | switch_stmt
    | when_stmt
    | expr_list ':' labelable           
    | RETURN
    | RETURN expr_list
    | DEFER stmt
    | DIRECTIVE stmt    /* #partial switch x { ... } */
    | USING expr
    | BREAK
    | BREAK ID                        
    | CONTINUE
    | CONTINUE ID                       
    ;

/* ---- Метка ---- */
/* На что можно навесить метку */
labelable: block
         | if_stmt
         | for_stmt
         | switch_stmt
         ;

/* ---- Простые операторы-выражения ----
   x = 5, 
   x, y = 1, 2, 
   x := 5, 
   x: int, 
   x: int = 5,
   x: int : 5 (const), 
   x += 1, 
   f()              */
simple_stmt: expr_list '=' expr_list
           | expr_list OP_DECL_INFERRED expr_list
           | expr_list OP_DECL_TYPED expr_list
           | expr_list ':' type_expr
           | expr_list ':' type_expr '=' expr_list
           | expr_list ':' type_expr ':' expr_list
           | expr OP_ADD_ASSIGN expr      /* += */
           | expr OP_SUB_ASSIGN expr      /* -= */
           | expr OP_MUL_ASSIGN expr      /* *= */
           | expr OP_DIV_ASSIGN expr      /* /= */
           | expr OP_MOD_ASSIGN expr      /* %= */
           | expr OP_MOD2_ASSIGN expr     /* %%= */
           | expr OP_OR_ASSIGN expr       /* |= */
           | expr OP_NOT_ASSIGN expr      /* ~= */
           | expr OP_AND_ASSIGN expr      /* &= */
           | expr OP_AND_NOT_ASSIGN expr  /* &~= */
           | expr OP_SHL_ASSIGN expr      /* <<= */
           | expr OP_SHR_ASSIGN expr      /* >>= */
           | expr OP_LOG_AND_ASSIGN expr  /* &&= */
           | expr OP_LOG_OR_ASSIGN expr   /* ||= */
           | expr                                     { print_expr($1); }  /* ---- ЗАГЛУШКА ---- */
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
/* if x > 0 { } 
   if x > 0 { } else { } 
   if x > 0 { } else if y > 0 { } else { }
   if x := f(); x > 0 { }      */
if_stmt: IF expr block
       | IF expr block ELSE block
       | IF expr block ELSE if_stmt
       | IF simple_stmt ';' expr block
       | IF simple_stmt ';' expr block ELSE block
       | IF simple_stmt ';' expr block ELSE if_stmt
       ;

/* for { } 
   for x < 10 { } 
   for x in arr { } 
   for k, v in m { }
   for i := 0; i < n; i += 1 { } 
   ... do stmt     */
for_stmt: FOR block
        | FOR expr block
        | FOR expr_list IN expr block
        | FOR simple_stmt_opt ';' expr_opt ';' simple_stmt_opt block
        | FOR expr DO stmt
        | FOR expr_list IN expr DO stmt
        | FOR simple_stmt_opt ';' expr_opt ';' simple_stmt_opt DO stmt
        ;

/* switch x { } 
   switch { } 
   switch y := f(); y { } 
   switch y := f(); { }    */
switch_stmt: SWITCH switch_body
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
           CASE expr_list ':' case_body
           | CASE ':' case_body
           ;

case_body: stmt_list_opt
         | fall_tail
         | stmt_list ';' fall_tail
         ;

fall_tail: FALLTHROUGH
         | FALLTHROUGH ';' 
         ;

/* ---- Список выражений ---- */
expr_list: expr                     { $$ = list_new($1); }
         | expr_list ',' expr       { $$ = list_append($1, $3); }
         ;

/* ---- Условные операторы when ---- */
when_stmt:
         WHEN expr block
         | WHEN expr block ELSE when_stmt
         | WHEN expr block ELSE block
         ;

/* ---- Атрибут  @private (одно слово — токен ATTRIBUTE)
  @(link_name="foo", export)  ---- */
attribute: ATTRIBUTE 
         | AT ID
         | AT ID '(' attr_list ')'
         ;

attr_list: attr
         | attr_list ',' attr
         ;

attr: ID
    | ID '=' expr
    ;

/* ---- Выражения ---- */
expr: ID                                   { $$ = new_expr(E_ID, @$.first_line); $$->Str = $1; }
    | INT_LIT                              { $$ = new_expr(E_INT, @$.first_line); $$->IntVal = $1; }
    | FLOAT_LIT                            { $$ = new_expr(E_FLOAT, @$.first_line); $$->FloatVal = $1; }
    | STRING_LIT                           { $$ = new_expr(E_STRING, @$.first_line); $$->Str = $1; }
    | RAW_STRING_LIT                       { $$ = new_expr(E_RAW_STRING, @$.first_line); $$->Str = $1; }
    | IMAGINARY_LIT                        { $$ = new_expr(E_IMAG, @$.first_line); $$->FloatVal = $1.value; $$->ImagUnit = $1.unit; }
    | RUNE_LIT                             { $$ = new_expr (E_RUNE, @$.first_line); $$->RuneVal = $1; }
    | NIL                                  { $$ = new_expr(E_NIL, @$.first_line);}
    | UNDEFINED                            { $$ = new_expr(E_UNDEF, @$.first_line);}
    | BOOL_LIT                             { $$ = new_expr(E_BOOL, @$.first_line); $$->IntVal = $1;}
    | '(' expr ')'                         { $$ = $2;}

/* ---- унарные (приоритет UNARY) ---- */
    | '+' expr %prec UNARY                 { $$ = mk_unary(E_UPLUS, $2, @$.first_line); }
    | '-' expr %prec UNARY                 { $$ = mk_unary(E_UMINUS, $2, @$.first_line); }
    | '!' expr %prec UNARY                 { $$ = mk_unary(E_NOT, $2, @$.first_line); }
    | '~' expr %prec UNARY                 { $$ = mk_unary(E_BIT_NOT, $2, @$.first_line); }
    | '&' expr %prec UNARY                 { $$ = mk_unary(E_ADDR, $2, @$.first_line); }
    | AUTO_CAST expr %prec UNARY           { $$ = mk_unary(E_AUTO_CAST, $2, @$.first_line); }

/* ---- бинарные: логика ---- */
    | expr OP_LOG_OR expr                  { $$ = mk_binary(E_LOG_OR, $1, $3, @$.first_line); }
    | expr OP_LOG_AND expr                 { $$ = mk_binary(E_LOG_AND, $1, $3, @$.first_line); }
/* ---- сравнения ---- */
    | expr OP_EQ expr                      { $$ = mk_binary(E_EQ, $1, $3, @$.first_line); }
    | expr OP_NE expr                      { $$ = mk_binary(E_NE, $1, $3, @$.first_line); }
    | expr '<' expr                        { $$ = mk_binary(E_LT, $1, $3, @$.first_line); }
    | expr '>' expr                        { $$ = mk_binary(E_GT, $1, $3, @$.first_line); }
    | expr OP_LE expr                      { $$ = mk_binary(E_LE, $1, $3, @$.first_line); }
    | expr OP_GE expr                      { $$ = mk_binary(E_GE, $1, $3, @$.first_line); }

/* ---- арифметика и битовые ---- */
    | expr '+' expr                        { $$ = mk_binary(E_ADD, $1, $3, @$.first_line); }
    | expr '-' expr                        { $$ = mk_binary(E_SUB, $1, $3, @$.first_line); }
    | expr '|' expr                        { $$ = mk_binary(E_BIT_OR, $1, $3, @$.first_line); }
    | expr '~' expr                        { $$ = mk_binary(E_BIT_XOR, $1, $3, @$.first_line); }
    | expr '*' expr                        { $$ = mk_binary(E_MUL, $1, $3, @$.first_line); }
    | expr '/' expr                        { $$ = mk_binary(E_DIV, $1, $3, @$.first_line); }
    | expr '%' expr                        { $$ = mk_binary(E_MOD, $1, $3, @$.first_line); }
    | expr OP_MOD2 expr                    { $$ = mk_binary(E_MOD2, $1, $3, @$.first_line); }
    | expr '&' expr                        { $$ = mk_binary(E_BIT_AND, $1, $3, @$.first_line); }
    | expr OP_AND_NOT expr                 { $$ = mk_binary(E_AND_NOT, $1, $3, @$.first_line); }
    | expr OP_SHL expr                     { $$ = mk_binary(E_SHL, $1, $3, @$.first_line); }
    | expr OP_SHR expr                     { $$ = mk_binary(E_SHR, $1, $3, @$.first_line); }

  /* ---- or_else и диапазоны ---- */
    | expr OR_ELSE expr                    { $$ = mk_binary(E_OR_ELSE, $1, $3, @$.first_line); }
    | expr OP_RANGE expr                   { $$ = mk_binary(E_RANGE, $1, $3, @$.first_line); }
    | expr OP_RANGE_INCLUSIVE expr         { $$ = mk_binary(E_RANGE_INCL, $1, $3, @$.first_line); }
    | expr OP_RANGE_EXCLUSIVE expr         { $$ = mk_binary(E_RANGE_EXCL, $1, $3, @$.first_line); }

/* ---- тернарные формы ---- */
    | expr '?' expr ':' expr  %prec '?'    { $$ = mk_ternary(E_TERNARY_Q, $1, $3, $5, @$.first_line); }
    | expr WHEN expr ELSE expr %prec WHEN  { $$ = mk_ternary(E_TERNARY_WHEN, $3, $1, $5, @$.first_line); }
    | expr IF expr ELSE expr %prec IF      { $$ = mk_ternary(E_TERNARY_IF, $3, $1, $5, @$.first_line); }

/* ---- постфиксные ---- */
    | expr '^'                             { $$ = mk_unary(E_DEREF, $1, @$.first_line); }
    | expr OR_RETURN                       { $$ = mk_unary(E_OR_RETURN, $1, @$.first_line); }
    | expr OR_BREAK                        { $$ = mk_unary(E_OR_BREAK, $1, @$.first_line); }
    | expr OR_CONTINUE                     { $$ = mk_unary(E_OR_CONTINUE, $1, @$.first_line); }
    | expr '(' arg_list_op ')'             { $$ = mk_unary(E_CALL, $1, @$.first_line); $$->Args = $3; }
    | expr '[' expr ']'                    { $$ = mk_binary(E_INDEX, $1, $3, @$.first_line); }
    | expr '.' ID                          { $$ = mk_unary(E_SELECTOR, $1, @$.first_line); $$ -> Str = $3;}

/* ---- приведение типа ---- */
    | CAST '(' type_expr ')' expr %prec UNARY  { $$ = mk_unary(E_CAST, $5, @$.first_line);  $$ -> CastType = $3; }
    ;

/* ---- аргументы вызова функции ---- */
arg_list_op: %empty                        { $$ = NULL;}
           | arg_list                      { $$ = $1;}
           ;

arg_list: expr                             { $$ = list_new($1);}
        | arg_list ',' expr                { $$ = list_append($1, $3);}
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
