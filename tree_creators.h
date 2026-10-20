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

    /* ---------------- Операторы и их списки ---------------- */
    struct StmtNode *stmt_new(enum StmtKind kind, int line)
    struct StmtList *stmtlist_new(struct StmtNode *stmt);
    struct StmtList *stmtlist_append(struct StmtList *list, struct StmtNode *stmt);
    
    struct StmtNode *stmt_expr(struct ExprNode *expr, int line);
    struct StmtNode *stmt_return(struct ExprList *values, int line);
    struct StmtNode *stmt_jump(enum StmtKind kind, char *label, int line);
    struct StmtNode *stmt_defer(struct StmtNode *body, int line);
    struct StmtNode *stmt_using(struct ExprNode *expr, int line);
    
    struct StmtNode *stmt_assign(struct ExprList *lhs,
                           struct ExprList *rhs,
                           int line);
                           
    struct StmtNode *stmt_op_assign(struct ExprList *lhs,
                              enum AssignOp op,
                              struct ExprList *rhs,
                              int line);
                              
    struct StmtNode *stmt_decl(struct ExprList *names,
                        struct TypeNode *type,
                        int is_const,
                        struct ExprList *values,
                        int line);

    struct StmtNode *stmt_block(struct StmtList *block, int line);
 
    struct StmtNode *stmt_if(struct ExprNode *cond,
                     struct StmtList *block,
                     struct StmtNode *else_branch,
                     int line);
    
    struct StmtNode *stmt_for(struct StmtNode *init,
                        struct ExprNode *cond,
                        struct StmtNode *post,
                        struct StmtList *block,
                        int line);

    struct StmtNode *stmt_for_in(struct ExprList *lhs,
                           struct ExprNode *expr,
                           struct StmtList *block,
                           int line); 

    struct StmtNode *stmt_when(struct ExprNode *cond,
                        struct StmtList *block,
                        struct StmtNode *else_branch,
                        int line);

    struct StmtNode *stmt_switch(struct StmtNode *init,
                           struct ExprNode *cond,
                           struct CaseList *cases,
                           int line);

    struct StmtNode *stmt_labeled(char *label,
                           struct StmtNode *body,
                           int line);
    
    struct StmtNode *stmt_directive(char *directive,
                              struct StmtNode *body,
                              int line);

    struct CaseNode *case_new(struct ExprList *values, 
                        struct StmtList *body,
                        int fallthrough, 
                        int line);
 
    struct CaseList *caselist_new(struct CaseNode *node);
    struct CaseList *caselist_append(struct CaseList *list, struct CaseNode *item);
 
    #endif