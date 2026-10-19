#ifndef TREE_NODES_H
#define TREE_NODES_H

// Узлы синтаксического дерева языка Odin 
struct Expression;
struct ExprList;
struct TypeExpr;
struct TypeList;
struct FieldList;
struct EnumItemList;
struct Ident;
struct IdList;
struct FieldDecl;
struct EnumItem;
struct Statement;
struct StmtList;
struct CaseClause;
struct CaseList;

#pragma region ВЫРАЖЕНИЯ
// Список видов выражений
enum ExprType {
    // виды делятся на 3 группы: 
    // 1) листья - внутри них ничего нет, это просто значение
    E_ID,              // x -> Str (где лежит)
    E_INT,             // 42, 0xFF -> IntVal 
    E_FLOAT,           // 3.14 -> FloatVal       
    E_STRING,          // "abc" -> Str
    E_RAW_STRING,      // `abc` -> Str 
    E_IMAG,            // 3.5i -> FloatVal + ImagUnit 
    E_RUNE,            // 'a' -> RuneVal 
    E_BOOL,            // true / false -> IntVal (0 или 1) 
    E_NIL,             //  nil                        
    E_UNDEF,           //  ---    

    // 2) унарные - один операнд лежит в Left
    E_UPLUS,           // +x   
    E_UMINUS,          // -x   
    E_NOT,             // !x   
    E_BIT_NOT,         // ~x   
    E_ADDR,            // &x   
    E_AUTO_CAST,       // auto_cast x 

    // 3) бинарные - два операнда, левый в Left и правый в Right  
    E_LOG_OR,          // ||  
    E_LOG_AND,         // &&  
    E_EQ,              // ==  
    E_NE,              // !=  
    E_LT,              // <   
    E_GT,              // >   
    E_LE,              // <=  
    E_GE,              // >=  
    E_ADD,             // +   
    E_SUB,             // -   
    E_BIT_OR,          // |   
    E_BIT_XOR,         // ~  (бинарная) 
    E_MUL,             // *   
    E_DIV,             // /   
    E_MOD,             // %   
    E_MOD2,            // %%  
    E_BIT_AND,         // &   
    E_AND_NOT,         // &~  
    E_SHL,             // <<  
    E_SHR,             // >>  
    E_OR_ELSE,         // a or_else b 
    E_RANGE,           // a .. b   (токен OP_RANGE)           
    E_RANGE_INCL,      // a ..= b  (токен OP_RANGE_INCLUSIVE) 
    E_RANGE_EXCL,      // a ..< b  (токен OP_RANGE_EXCLUSIVE) 

    // 3) тернарные: Cond ? Left : Right  
    E_TERNARY_Q,       // c ? a : b            Cond=c Left=a Right=b 
    E_TERNARY_IF,      // a if c else b        Cond=c Left=a Right=b 
    E_TERNARY_WHEN,    // a when c else b      Cond=c Left=a Right=b 

    // 4) постфиксные
    E_DEREF,           // p^           Left=p                 
    E_OR_RETURN,       // x or_return  Left=x                 
    E_OR_BREAK,        // x or_break   Left=x                 
    E_OR_CONTINUE,     // x or_continue Left=x                
    E_CALL,            // f(a, b)      Left=f   Args=a,b      
    E_INDEX,           // a[i]         Left=a   Right=i       
    E_SELECTOR,        // a.name       Left=a   Str=name      

    // 5) приведение типа 
    E_CAST,            // cast(T) x       CastType=T Left=x    
};

// Встроенные типы (правило: используется, когда Kind == base_type) 
enum BaseType {
    BT_BOOL, BT_B8, BT_B16, BT_B32, BT_B64,
    BT_INT, BT_I8, BT_I16, BT_I32, BT_I64, BT_I128,
    BT_UINT, BT_U8, BT_U16, BT_U32, BT_U64, BT_U128, BT_UINTPTR,
    BT_F16, BT_F32, BT_F64,
    BT_COMPLEX32, BT_COMPLEX64, BT_COMPLEX128,
    BT_QUATERNION64, BT_QUATERNION128, BT_QUATERNION256,
    BT_STRING, BT_CSTRING, BT_BYTE, BT_RUNE, BT_RAWPTR, BT_ANY
};

// Вид типа 
enum TypeKind {
    TY_NAME,        // MyType -> Name                       
    TY_BASE,        // int, f32, string... -> Base
    TY_POINTER,     // ^T -> Elem      
    TY_SLICE,       // []T -> Elem                       
    TY_ARRAY,       // [N]T -> Len, Elem                  
    TY_DYN_ARRAY,   // [dynamic]T -> Elem                       
    TY_MAP,         // map[K]V -> Key, Elem (значение V)     
    TY_PROC,        // proc(a: int) -> int  -> Params, Results            
    TY_STRUCT,      // struct { ... } -> Fields                     
    TY_ENUM,        // enum { A, B = 5 } -> Items                      
    TY_UNION,       // union { ... } -> Fields                     
    TY_BIT_SET,     // bit_set[T] -> Elem                       
    TY_DISTINCT,    // distinct T -> Elem                       
    TY_MATRIX       // matrix[R, C]T -> Len (R), Cols (C), Elem    
};

struct Expression {
    enum ExprType Type; // что за вид выражения

    // значения листьев 
    long long     IntVal;      
    double        FloatVal;     
    char          ImagUnit;    // 'i', 'j' или 'k' для E_IMAG 
    unsigned int  RuneVal;     // E_RUNE 
    char         *Str;         

    // операнды 
    struct Expression *Left;   // указатель на левого "ребёнка"
    struct Expression *Right;  // указатель на правого "ребёнка"
    struct Expression *Cond;   // условие для тернарной формы, тк надо 3 части  

    struct TypeExpr   *CastType;  // cast(T) x: тип лежит в CastType, а x в Left 
    struct ExprList   *Args;      // E_CALL; NULL, если аргументов нет 

    struct Expression *Next;   // следующий элемент, если выражение входит в список 
    int Line;   // номер строки в исходнике, чтобы потом выдавать понятные сообщения об ошибках 
};



// Список выражений: expr_list, arg_list (например, аргументы f(a, b, c))
// Для них связный список - храним First и Last, а обращение к следующему по полю Next
struct ExprList {
    struct Expression *First;
    struct Expression *Last;
};

struct Ident {
    char *Name;
    struct Ident *Next;
    int Line;
};

// Это список имен 
// аналогичный ExprList список 
struct IdList {
    struct Ident *First;
    struct Ident *Last;
};

// для типов, которые пишутся после двоеточия (x: int, arr: [10]int, m: map[string]int и тд)
struct TypeExpr {
    enum TypeKind Kind;          // что за тип (имя, срез, массив и тд)
 
    char             *Name;      // TY_NAME 
    enum BaseType     Base;      // TY_BASE 
 
    struct TypeExpr  *Elem;      // тип, на который ссылается указатель, срез, массив и т.д. 
    struct TypeExpr  *Key;       // TY_MAP: тип ключа 
    struct Expression *Len;      // TY_ARRAY: длина; TY_MATRIX: число строк 
    struct Expression *Cols;     // TY_MATRIX: число столбцов 
 
    struct FieldList    *Fields; // TY_STRUCT, TY_UNION 
    struct EnumItemList *Items;  // TY_ENUM 
 
    struct FieldList *Params;    // TY_PROC: параметры 
    struct TypeList  *Results;   // TY_PROC: возвращаемые типы; NULL, если ничего не возвращает 
 
    struct TypeExpr *Next;       // следующий элемент, если тип входит в список (TypeList) 
    int Line;
};

// это список типов (например, return_type_list -> (int, string) ) 
struct TypeList {
    struct TypeExpr *First;
    struct TypeExpr *Last;
};
 
// Объявление типа "имена : тип"
// Внутри список имен и тип
// Испольщуется для структур на три правила с одинаковой формой:
// param (параметр процедуры), field_decl (поле struct/union)
// и далее пригодится для объявлений переменных
// a, b: int -> Names = [a, b], Type = int                         
struct FieldDecl {
    struct IdList    *Names;
    struct TypeExpr  *Type;
    struct FieldDecl *Next;
    int Line;
};
 
struct FieldList {
    struct FieldDecl *First;
    struct FieldDecl *Last;
};
 
// один элемент enum:  Red   или   Green = 5 
struct EnumItem {
    char              *Name;
    struct Expression *Value;    // мб NULL
    struct EnumItem   *Next;
    int Line;
};
 
// это список значений enum
struct EnumItemList {
    struct EnumItem *First;
    struct EnumItem *Last;
};
#pragma endregion


#pragma region ОПЕРАТОРЫ

// вид оператора
enum StmtKind {
    ST_EXPR,        // f() - Expr=f()
    ST_ASSIGN,      // a, b = 1, 2 - Lhs=a,b  Rhs=1,2
    ST_OP_ASSIGN,   // x += 1 - Lhs=x (один элемент)  Rhs=1 (один элемент)  Op=AOP_ADD
    ST_DECL,        // x := 5 / x: int = 5 / x: int / x :: 5 / x: int : 5
    ST_BLOCK,       // { ... } - Block=список операторов
    ST_RETURN,      // return a, b - Rhs=a,b (NULL, если return пустой)
    ST_BREAK,       // break / break label - Label (NULL, если метки нет)
    ST_CONTINUE,    // continue / continue label  Label
    ST_DEFER,       // defer stmt  -  Body=stmt
    ST_USING,       // using x  -  Expr=x
 
    ST_IF,          // if [init;] cond {..} [else ..]   Init, Cond, Block, ElseBranch
    ST_WHEN,        // when cond {..} [else ..]         Cond, Block, ElseBranch
    ST_FOR,         // for {} / for cond {} / for init; cond; post {}   Init, Cond, Post, Block
    ST_FOR_IN,      // for k, v in m {..}               Lhs=k,v  Expr=m  Block
    ST_SWITCH,      // switch [init;] [cond] { case ... }   Init, Cond, Cases
    ST_LABELED,     // outer: for ...                   Label=outer  Body=for
    ST_DIRECTIVE    // #partial switch ...              Directive="#partial"  Body=switch
};

// Какой именно составной знак присваивания (+=, -=, ...)
enum AssignOp {
    AOP_ADD, AOP_SUB, AOP_MUL, AOP_DIV,
    AOP_MOD, AOP_MOD2,
    AOP_OR, AOP_XOR, AOP_AND, AOP_AND_NOT,
    AOP_SHL, AOP_SHR,
    AOP_LOG_AND, AOP_LOG_OR
};
 
// Одна ветка switch:  case 1, 2: ...   или   case: ...  (default)
struct CaseClause {
    struct ExprList   *Values;       // значения после case / NULL для "case:" (ветка по умолчанию)
    struct StmtList   *Body;         // операторы ветки (может быть пустым)
    int                Fallthrough;  // 1, если в конце ветки написан fallthrough
    struct CaseClause *Next;
    int Line;
};
 
struct CaseList {
    struct CaseClause *First;
    struct CaseClause *Last;
};

struct Statement {
    enum StmtKind Kind;  // вид оператора 
 
    struct Expression *Expr;      
 
    struct ExprList   *Lhs;       // слева от =, :=, ::, ':' (левая часть присваивания)
    struct ExprList   *Rhs;       // справа от =, :=, :: ; значения в return / NULL (правая часть присваивания)
    enum AssignOp      Op;        // ST_OP_ASSIGN: какой знак
 
    struct TypeExpr   *DeclType;  // тип после ':' / NULL
    int                IsConst;   // 1 для констант (::), 0 для переменных
 
    struct StmtList   *Block;     // тело - ST_BLOCK, ST_IF...
    struct Statement  *Body;      // один вложенный оператор (для ST_DEFER, ST_LABELED, ST_DIRECTIVE)
    char              *Label;     // имя метки у ST_BREAK, ST_CONTINUE, ST_LABELED
    
    // части if / for / switch
    struct Statement  *Init;       // оператор до ';'
    struct Expression *Cond;       // условие
    struct Statement  *Post;       // оператор после второго ';' 
    struct Statement  *ElseBranch; // что после else (else {..}) 
    struct CaseList   *Cases;      // ветки switch
    char              *Directive;  // ST_DIRECTIVE: текст директивы
 
    struct Statement  *Next;       // следующий оператор в списке
    int Line;                      // номер строки
};

// Список операторов (тело блока, тело функции)
struct StmtList {
    struct Statement *First;
    struct Statement *Last;
};
#pragma endregion

#endif 