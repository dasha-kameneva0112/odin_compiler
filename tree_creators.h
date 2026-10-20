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
   
    
    struct IdentNode *ident_new(char *name, int line);
    struct IdList    *idlist_new(char *name, int line);
    struct IdList    *idlist_append(struct IdList *list, char *name, int line);


    // ---------------Типы-----------------------
    struct TypeNode* new_type(enum TypeKind kind, int line);
    struct TypeNode *mk_type_name(char *name, int line);
    struct TypeNode* mk_type_base(enum BaseType base, int line);
    struct TypeNode* mk_type_elem(enum TypeKind kind, struct TypeNode* elem, int line);
    struct TypeNode* mk_type_array(struct ExprNode* len, struct TypeNode* elem, int line);
    struct TypeNode* mk_type_map(struct TypeNode* key, struct TypeNode* elem, int line);
    struct TypeNode* mk_type_matrix(struct ExprNode* rows, struct ExprNode* cols, struct TypeNode* elem, int line);
    #endif