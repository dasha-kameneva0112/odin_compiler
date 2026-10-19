 #include <stdio.h>
 #include <stdlib.h>
 #include "tree_build.h"
 
 /* Функции построения синтаксического дерева */
 struct Expression *new_expr(enum ExprType type, int line)
 {
    struct Expression *expr = calloc(1, sizeof *expr);

    if(!expr)
    {
        fprintf(stderr, "out of memory");
        exit (1);
    }

    expr->Type = type;
    expr->Line = line;
    return expr;
 }
 
 /* Один операнд -> Left */
 struct Expression *mk_unary(enum ExprType type, struct Expression *left, int line);
 {
    struct Expression *expr = new_expr(type, line);
    expr->Left = left;
    return expr;
 }

 /* Два операнда -> Left и Right */
 struct Expression *mk_binary(enum ExprType type, struct Expression *left, struct Expression *right, int line);
 {
    struct Expression *expr = new_expr(type, line);
    expr->Left = left;
    expr->Right = right;
    return expr;
 } 
 
 /* Три части: Cond, Left, Right */
 struct Expression *mk_ternary(enum ExprType type, struct Expression *cond,struct Expression *left, struct Expression *right, int line);
 {
    struct Expression *expr = new_expr(type, line);
    expr->Cond = cond;
    expr->Left = left;
    expr->Right = right;
    return expr;
 }


//  struct ExprList *list_new(struct Expression *expr)
//  {
//    struct ExprList *list = calloc(1, sizeof *list);
//    if (!list)
//    {
//     fprintf(stderr, "out of memory\n"); 
//     exit(1);
//    } 

//    list->First = expr;
//    list->Last = expr;
//    return list;
//  }

 struct ExprList *list_append(struct ExprList *list, struct Expration *expr);
   

 struct Ident *idlist_new(char *name, int line);
 struct IdList *idlist_new(char *name, int line);
 struct IdList *idlist_append(struct IdList *list, char *name, int line);
