    #ifndef TREE_BUILD_H
    #define TREE_BUILD_H
 
    #include "tree_nodes.h"
    
    // --------------Выражения----------------
    struct ExprNode  *new_expr(enum ExprType type, int line);
    struct ExprNode  *mk_unary(enum ExprType type, struct ExprNode *left, int line);
    struct ExprNode  *mk_binary(enum ExprType type, struct ExprNode *left, struct ExprNode *right, int line);
    struct ExprNode  *mk_ternary(enum ExprType type, struct ExprNode *cond,  struct ExprNode *left, struct ExprNode *right, int line);

    // --------------Список выражений----------------
    struct ExprList  *list_new(struct ExprNode *expr);
    struct ExprList  *list_append(struct ExprList *list, struct ExprNode *expr);
   
    // ---------------Список имен------------------------
    struct IdentNode *ident_new(char *name, int line);
    struct IdList    *idlist_new(char *name, int line);
    struct IdList    *idlist_append(struct IdList *list, char *name, int line);

    #endif