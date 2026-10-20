 #include <stdio.h>
 #include <stdlib.h>
 #include "tree_creators.h"
 
 /* Функции построения синтаксического дерева */
 struct ExprNode *new_expr(enum ExprType type, int line)
 {
    struct ExprNode *expr = calloc(1, sizeof *expr);

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
 struct ExprNode *mk_unary(enum ExprType type, struct ExprNode *left, int line)
 {
    struct ExprNode *expr = new_expr(type, line);
    expr->Left = left;
    return expr;
 }

 /* Два операнда -> Left и Right */
 struct ExprNode *mk_binary(enum ExprType type, struct ExprNode *left, struct ExprNode *right, int line)
 {
    struct ExprNode *expr = new_expr(type, line);
    expr->Left = left;
    expr->Right = right;
    return expr;
 } 
 
 /* Три части: Cond, Left, Right */
 struct ExprNode *mk_ternary(enum ExprType type, struct ExprNode *cond,struct ExprNode *left, struct ExprNode *right, int line)
 {
    struct ExprNode *expr = new_expr(type, line);
    expr->Cond = cond;
    expr->Left = left;
    expr->Right = right;
    return expr;
 }


 struct ExprList *list_new(struct ExprNode *expr)
 {
   struct ExprList *list = calloc(1, sizeof *list);
   if (!list)
   {
    fprintf(stderr, "out of memory\n"); 
    exit(1);
   } 

   list->First = expr;
   list->Last = expr;
   return list;
 }

 /* Добавляет в конец: связь идёт через поле Next самого выражения */
 struct ExprList *list_append(struct ExprList *list, struct ExprNode *expr)
 {
    list->Last->Next = expr;
    list->Last = expr;
    return list;
 }

 /* ---- Список имён: a, b, c ---- */
 struct IdentNode *ident_new(char *name, int line)
 {
   struct IdentNode *id = calloc (1, sizeof *id);
   if(!id)
   {
      fprintf(stderr, "out of memory\n"); 
      exit(1);
   }

   id->Name = name;
   id->Line = line;
   return id;
 }

 struct IdList *idlist_new(char *name, int line)
 {
   struct IdList *list = calloc(1, sizeof *list);
   if (!list)
   {
       fprintf(stderr, "out of memory\n"); 
       exit(1);
   }
   list->First = ident_new(name, line);
   list->Last = list->First;
   return list;
 }

 struct IdList *idlist_append(struct IdList *list, char *name, int line)
 {
   struct IdentNode *id = ident_new(name, line);
   list->Last->Next = id;
   list->Last = id;
   return list;
 }
