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
    struct {
            double value;
            char unit;
            } imag_val;   /* 3.5i -> {3.5, 'i'} */
}

%locations
%define parse.error verbose

// Ключевые слова языка  
%token AUTO_CAST BREAK CASE CAST
%token CONTINUE DEFER DO DYNAMIC ELSE ENUM FALLTHROUGH
%token FOR IF IMPORT IN OR_BREAK OR_CONTINUE
%token OR_ELSE OR_RETURN PACKAGE PROC RETURN STRUCT SWITCH
%token USING WHEN

%token BOOL INT F32 F64 STRING RUNE

%token <int_val>   INT_LIT BOOL_LIT
%token <float_val> FLOAT_LIT
%token <str_val>   ID STRING_LIT RAW_STRING_LIT 
%token <imag_val>  IMAGINARY_LIT
%token <rune_val>  RUNE_LIT
%token NIL UNDEFINED

%token OP_ADD_ASSIGN OP_SUB_ASSIGN OP_MUL_ASSIGN OP_DIV_ASSIGN
%token OP_MOD_ASSIGN OP_MOD2_ASSIGN 
%token OP_LOG_AND_ASSIGN OP_LOG_OR_ASSIGN
%token OP_LOG_AND OP_LOG_OR 
%token OP_EQ OP_NE OP_LE OP_GE
%token OP_EXPAND OP_RANGE OP_RANGE_INCLUSIVE OP_RANGE_EXCLUSIVE
%token OP_ARROW OP_DECL_TYPED OP_DECL_INFERRED OP_MOD2

%token LEX_ERROR

// Приоритеты и ассоциативность  
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
// Верхний уровень (программа) 
//  package main
//  import "core:fmt"
//  main :: proc() { }    
program:
       package_clause top_list 
       ;

package_clause: PACKAGE ID ';'
              ;

top_list: %empty
        | top_list top_item
        ;

top_item: import_decl
        | base_decl optional_semicolon
        ;

optional_semicolon: %empty
                  | ';'
                  ;

// import fmt "core:fmt"   /    import "core:fmt"
import_decl: IMPORT STRING_LIT ';'
           | IMPORT ID STRING_LIT ';'
           ;

base_decl: var_decl
        | const_decl
        | proc_decl
        ;

// Процедуры 
/*   main :: proc() { }
     add  :: proc(a: int, b: int) -> int { }
     divm :: proc(a, b: int) -> (int, int) { }
     foo  :: proc { foo_int, foo_str }          (группа перегрузок)   */    
proc_decl: id_list OP_DECL_TYPED PROC '(' param_list_opt ')' return_type block
         | id_list OP_DECL_TYPED PROC '{' id_list '}'
         ;

// Список пораметров  
param_list_opt: %empty                 
              | param_list              
              | param_list ','
              ;

param_list: param                      
          | param_list ',' param       
          ;

param: id_list ':' type_expr          
     ;

// Список имен                       
id_list: ID                  
       | id_list ',' ID          
       ;
       
// Тип возвращаемого значения 
return_type: %empty                               
           | OP_ARROW type_expr                     
           | OP_ARROW '(' return_type_list ')'     
           ;

return_type_list: type_expr                         
                | return_type_list ',' type_expr  
                ;

// Переменные 
//  x: int = 5   x: int   x := 5   x, y := 1, 2   MAX: int : 100  a: [3]int = {1, 2, 3}
var_decl: id_list ':' type_expr '=' expr_list 
        | id_list ':' type_expr
        | id_list OP_DECL_INFERRED expr_list
        ;

// Константа 
//   MAX   :: 100
//   NAME  :: "hello"
//   MyMyInt :: MyInt
//   MAX: int : 100   
//   C, D, E: f32 : 1.0, 2.0, 3.0
//   A, B :: 10, 20                
const_decl: id_list OP_DECL_TYPED expr_list 
          | id_list OP_DECL_TYPED type_core
          | id_list  ':' type_expr ':' expr_list
          ;

// Тип - имя или составной  
type_expr: ID    
         | ID '.' ID                                        
         | type_core                              
         ;

// Составные типы  
type_core: base_type                                
         | array_type                       
         | PROC '(' param_list_opt ')' return_type   
         | STRUCT '{' field_list_opt '}'
         | ENUM '{' enum_body_opt '}'          
         ;

/* [N]T   [?]T   []T (срез)   [dynamic]T */   
array_type: '[' expr ']' type_expr
          | '[' '?' ']' type_expr
          | '[' ']' type_expr
          | '[' DYNAMIC ']' type_expr
          ;

base_type: BOOL                          
         | INT                            
         | F32                            
         | F64                    
         | STRING                            
         | RUNE                           
         ;

// Поля структуры 
field_list_opt: %empty                
              | field_list          
              | field_list ','            
              | field_list ';'            
              ;

field_list: field_decl                   
          | field_list ',' field_decl      
          ;

field_decl: id_list ':' type_expr   
          | USING id_list ':' type_expr
          ;

// Поля enum 
enum_body_opt: %empty                               
             | enum_body                       
             | enum_body ','                         
             | enum_body ';'                         
             ;

enum_body: enum_item                                  
         | enum_body ',' enum_item                 
         ;

enum_item: ID                                        
         | ID '=' expr                            
         ;


// Блоки кода 
block: '{' stmt_list_opt '}'
     ;

// Список операторов, ';' после последнего необязательна 
stmt_list_opt: %empty
             | stmt_list
             | stmt_list ';'
             ;

stmt_list: stmt
         | stmt_list ';' stmt 
         ;
             
// Один оператор 
stmt: simple_stmt 
    | block
    | if_stmt
    | for_stmt
    | switch_stmt
    | when_stmt
    | RETURN
    | RETURN expr_list
    | DEFER stmt
    | USING expr
    | BREAK
    | CONTINUE
    | expr_list OP_DECL_TYPED type_core                                      /* локальный struct/enum */
    | expr_list OP_DECL_TYPED PROC '(' param_list_opt ')' return_type block  /* локальная процедура   */
    | expr_list OP_DECL_TYPED PROC '{' id_list '}'                           /* группа перегрузок     */
    ;

// Простые операторы-выражения 
//    x = 5, 
//    x, y = 1, 2, 
//    x := 5, 
//    x: int, 
//    x: int = 5,
//    x: int : 5 (const), 
//    x += 1, 
//    f()             
simple_stmt: expr_list '=' expr_list
           | expr_list OP_DECL_INFERRED expr_list
           | expr_list OP_DECL_TYPED expr_list
           | expr_list ':' type_expr
           | expr_list ':' type_expr '=' init_list
           | expr_list ':' type_expr ':' expr_list
           | expr OP_ADD_ASSIGN expr      /* += */
           | expr OP_SUB_ASSIGN expr      /* -= */
           | expr OP_MUL_ASSIGN expr      /* *= */
           | expr OP_DIV_ASSIGN expr      /* /= */
           | expr OP_MOD_ASSIGN expr      /* %= */
           | expr OP_MOD2_ASSIGN expr     /* %%= */
           | expr                                     
           ;

// Необязательный простой оператор 
simple_stmt_opt: %empty
               | simple_stmt
               ;

// Необязательное выражение 
expr_opt: %empty
        | expr
        ;

// Условные операторы if 
//  if x > 0 { } 
//    if x > 0 { } else { } 
//    if x > 0 { } else if y > 0 { } else { }
//    if x := f(); x > 0 { }      
if_stmt: IF expr block
       | IF expr block ELSE block
       | IF expr block ELSE if_stmt
       | IF simple_stmt ';' expr block
       | IF simple_stmt ';' expr block ELSE block
       | IF simple_stmt ';' expr block ELSE if_stmt
       ;

when_stmt: WHEN expr block
         | WHEN expr block ELSE block
         | WHEN expr block ELSE when_stmt
         ;

// for { } 
//    for x < 10 { } 
//    for x in arr { } 
//    for k, v in m { }
//    for i := 0; i < n; i += 1 { } 
//    ... do stmt     
for_stmt: FOR block
        | FOR expr block
        | FOR expr_list IN expr block
        | FOR simple_stmt_opt ';' expr_opt ';' simple_stmt_opt block
        | FOR expr DO stmt
        | FOR expr_list IN expr DO stmt
        | FOR simple_stmt_opt ';' expr_opt ';' simple_stmt_opt DO stmt
        ;

// switch x { } 
//    switch { } 
//    switch y := f(); y { } 
//    switch y := f(); { }    */
switch_stmt: SWITCH switch_body
           | SWITCH expr switch_body
           | SWITCH simple_stmt ';' expr switch_body
           | SWITCH simple_stmt ';' switch_body
           ;

// Тело оператора switch 
switch_body: '{' case_list '}'
           ;

// Список ветвей case 
case_list: %empty
         | case_list case_clause
         ;

case_clause: CASE expr_list ':' case_body
           | CASE ':' case_body
           ;


// switvh (x) { case 1: if (1) { fallthrough} fjskjflsj case 2: kfsj 
case_body: stmt_list_opt
         | fall_tail
         | stmt_list ';' fall_tail
         ;

fall_tail: FALLTHROUGH
         | FALLTHROUGH ';' 
         ;


// Список выражений 
expr_list: expr                  
         | expr_list ',' expr 
         ;

// Выражения 
expr: ID                               
    | INT_LIT                             
    | FLOAT_LIT                          
    | STRING_LIT                       
    | RAW_STRING_LIT                     
    | IMAGINARY_LIT                  
    | RUNE_LIT                            
    | NIL                                 
    | UNDEFINED                          
    | BOOL_LIT                            
    | '(' expr ')'                       

// унарные (приоритет UNARY) 
    | '+' expr %prec UNARY               
    | '-' expr %prec UNARY               
    | '!' expr %prec UNARY            
    | AUTO_CAST expr %prec UNARY          

// бинарные: логика 
    | expr OP_LOG_OR expr                 
    | expr OP_LOG_AND expr

// сравнения 
    | expr OP_EQ expr                   
    | expr OP_NE expr                   
    | expr '<' expr                       
    | expr '>' expr                      
    | expr OP_LE expr                     
    | expr OP_GE expr                      

// арифметика и битовые 
    | expr '+' expr                        
    | expr '-' expr                        
    | expr '*' expr                       
    | expr '/' expr                       
    | expr '%' expr                        
    | expr OP_MOD2 expr                   
    | expr OP_AND_NOT expr                
    | expr OP_SHL expr                    
    | expr OP_SHR expr                   

// or_else и диапазоны 
    | expr OR_ELSE expr                    
    | expr OP_RANGE expr                  
    | expr OP_RANGE_INCLUSIVE expr        
    | expr OP_RANGE_EXCLUSIVE expr        

// тернарные формы 
    | expr '?' expr ':' expr  %prec '?'  
    | expr WHEN expr ELSE expr %prec WHEN  
    | expr IF expr ELSE expr %prec IF      

// постфиксные 
    | expr OR_RETURN                      
    | expr OR_BREAK                        
    | expr OR_CONTINUE                    
    | expr '(' arg_list_op ')'  
    | base_type '(' arg_list_opt ')'          /* int(x), f64(x) — явное приведение */           
    | expr '[' expr ']'                    
    | expr '.' ID              
    | '.' ID                                  /* неявный селектор enum: .Red */          

// приведение типа 
    | CAST '(' type_expr ')' expr %prec UNARY 
    
    /* литерал массива: [3]int{1, 2, 3}   []int{}   [dynamic]int{} */
    | array_type '{' elem_list_opt '}'
    ;

arg_list_op: %empty                       
           | arg_list                      
           | arg_list ','
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
