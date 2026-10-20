 #include <stdio.h>
 #include <stdlib.h>
 #include "tree_creators.h"
 
 /* Единая проверка выделения памяти. calloc обнуляет поля узла/списка. */
 static void *checked_calloc(size_t count, size_t size)
 {
   void *ptr = calloc(count, size);
   if (ptr == NULL) {
      fprintf(stderr, "out of memory\n");
      exit(EXIT_FAILURE);
   }
   return ptr;
 }

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
 
 
 
 /* ---------------- Операторы и их списки ---------------- */
 struct StmtNode *stmt_new(enum StmtKind kind, int line)
 {
   struct StmtNode *stmt = checked_calloc(1, sizeof *stmt);
   stmt->Kind = kind;
   stmt->Line = line;
   return stmt;
 }

 /* создать список */
 struct StmtList *stmtlist_new(struct StmtNode *stmt)
 {
   struct StmtList *list = checked_calloc(1, sizeof *list);
   list->First = list->Last = stmt;
   return list;
 }
 
 struct StmtList *stmtlist_append(struct StmtList *list, struct StmtNode *stmt)
 {
   // если список еще не создан
   if (list == NULL) return stmtlist_new(stmt);

   // новый оператор равен NULL (ниче не добавляем)
   if (stmt == NULL) return list;

   // список существует и тогда связываем последний оператор с новым
   if (list->First == NULL) list->First = list->Last = stmt;
   else {
      list->Last->Next = stmt;
      list->Last = stmt;
   }
   return list;
 } 

 /* Оператор, содержащий одно выражение */
 struct StmtNode *stmt_expr(struct ExprNode *expr, int line)
 {
   struct StmtNode *stmt = stmt_new(ST_EXPR, line);
   stmt->Expr = expr;
   return stmt;
 }

 /* Оператор return */
 struct StmtNode *stmt_return(struct ExprList *values, int line)
 {
   struct StmtNode *stmt = stmt_new(ST_RETURN, line);
   stmt->Rhs = values;
   return stmt;
 }

 /* Оператор break или continue */
 struct StmtNode *stmt_jump(enum StmtKind kind, char *label, int line)
 {
   struct StmtNode *stmt = stmt_new(kind, line);
   stmt->Label = label;
   return stmt;
 }

 /* Оператор defer */
 struct StmtNode *stmt_defer(struct StmtNode *body, int line)
 {
   struct StmtNode *stmt = stmt_new(ST_DEFER, line);
   stmt->Body = body;
   return stmt;
 }

 /* Оператор using */
 struct StmtNode *stmt_using(struct ExprNode *expr, int line)
 {
   struct StmtNode *stmt = stmt_new(ST_USING, line);
   stmt->Expr = expr;
   return stmt;
 }

 /* Присваивание: x = 10 */
 struct StmtNode *stmt_assign(struct ExprList *lhs,
                           struct ExprList *rhs,
                           int line)
 {
   struct StmtNode *stmt = stmt_new(ST_ASSIGN, line);
   stmt->Lhs = lhs;
   stmt->Rhs = rhs;
   return stmt;
 }

 /* Составное присваивание: x += 5 */
 struct StmtNode *stmt_op_assign(struct ExprList *lhs,
                              enum AssignOp op,
                              struct ExprList *rhs,
                              int line)
 {
   struct StmtNode *stmt = stmt_new(ST_OP_ASSIGN, line);
   stmt->Lhs = lhs;
   stmt->Op = op;
   stmt->Rhs = rhs;
   return stmt;
 }

 /* Объявление переменной */
 struct StmtNode *stmt_decl(struct ExprList *names,
                        struct TypeNode *type,
                        int is_const,
                        struct ExprList *values,
                        int line)
 {
   struct StmtNode *stmt = stmt_new(ST_DECL, line);
   stmt->Lhs = names;
   stmt->DeclType = type;
   stmt->IsConst = is_const;
   stmt->Rhs = values;
   return stmt;
 }

 /* Блок команд */
 struct StmtNode *stmt_block(struct StmtList *block, int line)
 {
   struct StmtNode *stmt = stmt_new(ST_BLOCK, line);
   stmt->Block = block;
   return stmt;
 }
 
 /* Условие if */
 struct StmtNode *stmt_if(struct ExprNode *cond,
                     struct StmtList *block,
                     struct StmtNode *else_branch,
                     int line)
 {
   struct StmtNode *stmt = stmt_new(ST_IF, line);
   stmt->Cond = cond;
   stmt->Block = block;
   stmt->ElseBranch = else_branch;
   return stmt;
 }
 
 /* Цикл for */
 struct StmtNode *stmt_for(struct StmtNode *init,
                        struct ExprNode *cond,
                        struct StmtNode *post,
                        struct StmtList *block,
                        int line)
 {
   struct StmtNode *stmt = stmt_new(ST_FOR, line);
   stmt->Init = init;
   stmt->Cond = cond;
   stmt->Post = post;
   stmt->Block = block;
   return stmt;
 }

 /* Перебор for-in */
 struct StmtNode *stmt_for_in(struct ExprList *lhs,
                           struct ExprNode *expr,
                           struct StmtList *block,
                           int line)
 {
   struct StmtNode *stmt = stmt_new(ST_FOR_IN, line);
   stmt->Lhs = lhs;
   stmt->Expr = expr;
   stmt->Block = block;
   return stmt;
 } 

 /* Условие when */
 struct StmtNode *stmt_when(struct ExprNode *cond,
                        struct StmtList *block,
                        struct StmtNode *else_branch,
                        int line)
 {
   struct StmtNode *stmt = stmt_new(ST_WHEN, line);
   stmt->Cond = cond;
   stmt->Block = block;
   stmt->ElseBranch = else_branch;
   return stmt;
 }

 /* Switch */
 struct StmtNode *stmt_switch(struct StmtNode *init,
                           struct ExprNode *cond,
                           struct CaseList *cases,
                           int line)
 {
   struct StmtNode *stmt = stmt_new(ST_SWITCH, line);
   stmt->Init = init;
   stmt->Cond = cond;
   stmt->Cases = cases;
   return stmt;
 }

 /* Оператор с меткой */
 struct StmtNode *stmt_labeled(char *label,
                           struct StmtNode *body,
                           int line)
 {
   struct StmtNode *stmt = stmt_new(ST_LABELED, line);
   stmt->Label = label;
   stmt->Body = body;
   return stmt;
 }

 /* Директива */
 struct StmtNode *stmt_directive(char *directive,
                              struct StmtNode *body,
                              int line)
 {
   struct StmtNode *stmt = stmt_new(ST_DIRECTIVE, line);
   stmt->Directive = directive;
   stmt->Body = body;
   return stmt;
 }

 /* Ветки switch/case */
 struct CaseNode *case_new(struct ExprList *values, 
                        struct StmtList *body,
                        int fallthrough, 
                        int line)
 {
   struct CaseNode *node = checked_calloc(1, sizeof *node);
   node->Values = values;
   node->Body = body;
   node->Fallthrough = fallthrough;
   node->Line = line;

   return node;
 }

 /* создание списка веток */
 struct CaseList *caselist_new(struct CaseNode *node)
 {
   struct CaseList *list = checked_calloc(1, sizeof *list);
   list->First = node;
   list->Last = node;
   
   return list;
 }

 struct CaseList *caselist_append(struct CaseList *list, struct CaseNode *item)
 {
   if (list == NULL) return caselist_new(item);
   if (item == NULL) return list;
   if (list->First == NULL) list->First = list->Last = item;
   else {
      list->Last->Next = item;
      list->Last = item;
   }
   return list;
 }
 
 /* ---------------- Элементы enum ---------------- */
 struct EnumItemNode *enum_item_new(char *name, struct ExprNode *value, int line)
 {
   struct EnumItemNode *item = checked_calloc(1, sizeof *item);
   item->Name = name;
   item->Value = value;
   item->Line = line;
   return item;
 }

 struct EnumItemList *enumlist_new(struct EnumItemNode *item)
 {
   struct EnumItemList *list = checked_calloc(1, sizeof *list);
   list->First = list->Last = item;
   return list;
 }

 struct EnumItemList *enumlist_append(struct EnumItemList *list,
                                 struct EnumItemNode *item)
 {
   if (list == NULL) return enumlist_new(item);
   if (item == NULL) return list;
   if (list->First == NULL) {
      list->First = list->Last = item;
   } else {
      list->Last->Next = item;
      list->Last = item;
   }
   return list;
 }

 
 /* ---------------- Атрибуты ---------------- */

 struct AttrNode *attr_new(char *name, struct ExprNode *value, int line)
 {
   struct AttrNode *attr = checked_calloc(1, sizeof *attr);
   attr->Name = name;
   attr->Value = value;
   attr->Line = line;
   return attr;
 }

 struct AttrList *attrlist_new(struct AttrNode *attr)
 {
   struct AttrList *list = checked_calloc(1, sizeof *list);
   list->First = list->Last = attr;
   return list;
 }

 struct AttrList *attrlist_append(struct AttrList *list, struct AttrNode *attr)
 {
   if (list == NULL) return attrlist_new(attr);
   if (attr == NULL) return list;
   if (list->First == NULL) {
      list->First = list->Last = attr;
   } else {
      list->Last->Next = attr;
      list->Last = attr;
   }
   return list;
 }




 

