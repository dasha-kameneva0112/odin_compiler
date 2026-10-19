    #ifndef TREE_BUILD_H
    #define TREE_BUILD_H
 
    #include "tree_nodes.h"
    
    // --------------Выражения----------------
    struct Expression *new_expr(enum ExprType type, int line)
    struct Expression *mk_unary(enum ExprType type, struct Expression *left, int line);
    struct Expression *mk_binary(enum ExprType type, struct Expression *left, struct Expression *right, int line);
    struct Expression *mk_ternary(enum ExprType type, struct Expression *cond,struct Expression *left, struct Expression *right, int line);

    // --------------Список выражений----------------
    struct ExprList *list_new(struct Expression *expr);
    struct ExprList *list_append(struct ExprList *list, struct Expration *expr);
   
    // ---------------Список имен------------------------
    struct Ident *idlist_new(char *name, int line);
    struct IdList *idlist_new(char *name, int line);
    struct IdList *idlist_append(struct IdList *list, char *name, int line);

    #endif