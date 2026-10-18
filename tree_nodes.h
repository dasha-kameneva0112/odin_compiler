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

// Список видов выражений
enum ExprType {
    // листья
    E_ID,              // x -> Str 
    E_INT,             // 42, 0xFF -> IntVal 
    E_FLOAT,           // 3.14 -> FloatVal       
    E_STRING,          // "abc" -> Str
    E_RAW_STRING,      // `abc` -> Str 
    E_IMAG,            // 3.5i -> FloatVal + ImagUnit 
    E_RUNE,            // 'a' -> RuneVal 
    E_BOOL,            // true / false -> IntVal (0 или 1) 
    E_NIL,             //  nil                        
    E_UNDEF,           //  ---    

    // --- унарные: операнд в Left --- 
    E_UPLUS,           // +x   
    E_UMINUS,          // -x   
    E_NOT,             // !x   
    E_BIT_NOT,         // ~x   
    E_ADDR,            // &x   
    E_AUTO_CAST,       // auto_cast x 

    // --- бинарные: Left и Right --- 
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
    E_BIT_XOR,         // ~   (бинарная) 
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

    // --- тернарные: Cond ? Left : Right --- 
    E_TERNARY_Q,       // c ? a : b            Cond=c Left=a Right=b 
    E_TERNARY_IF,      // a if c else b        Cond=c Left=a Right=b 
    E_TERNARY_WHEN,    // a when c else b      Cond=c Left=a Right=b 

    // --- постфиксные --- 
    E_DEREF,           // p^           Left=p                 
    E_OR_RETURN,       // x or_return  Left=x                 
    E_OR_BREAK,        // x or_break   Left=x                 
    E_OR_CONTINUE,     // x or_continue Left=x                
    E_CALL,            // f(a, b)      Left=f   Args=a,b      
    E_INDEX,           // a[i]         Left=a   Right=i       
    E_SELECTOR,        // a.name       Left=a   Str=name      

    // --- приведение типа --- 
    E_CAST,            // cast(T) x       CastType=T Left=x   
    E_TRANSMUTE        // transmute(T) x  CastType=T Left=x   
};

struct Expression {
    enum ExprType Type;

    // значения листьев 
    long long     IntVal;      // E_INT, E_BOOL 
    double        FloatVal;    // E_FLOAT, E_IMAG 
    char          ImagUnit;    // 'i', 'j' или 'k' для E_IMAG 
    unsigned int  RuneVal;     // E_RUNE 
    char         *Str;         // E_ID, E_STRING, E_RAW_STRING, имя поля у E_SELECTOR 

    // операнды 
    struct Expression *Left;   // единственный операнд унарной операции, левый - бинарной 
    struct Expression *Right;
    struct Expression *Cond;   // условие тернарной формы 

    struct TypeExpr   *CastType;  // E_CAST, E_TRANSMUTE 
    struct ExprList   *Args;      // E_CALL; NULL, если аргументов нет 

    struct Expression *Next;   // следующий элемент, если выражение входит в список 

    int Line;                  // строка в исходнике (для сообщений об ошибках) 
};

// Список выражений: expr_list, arg_list.
// Храним First и Last, чтобы добавление в конец было за O(1). 
struct ExprList {
    struct Expression *First;
    struct Expression *Last;
};

struct Ident {
    char *Name;
    struct Ident *Next;
    int Line;
};

struct IdList {
    struct Ident *First;
    struct Ident *Last;
};

// --- Встроенные типы (правило base_type) --- 
enum BaseType {
    BT_BOOL, BT_B8, BT_B16, BT_B32, BT_B64,
    BT_INT, BT_I8, BT_I16, BT_I32, BT_I64, BT_I128,
    BT_UINT, BT_U8, BT_U16, BT_U32, BT_U64, BT_U128, BT_UINTPTR,
    BT_F16, BT_F32, BT_F64,
    BT_COMPLEX32, BT_COMPLEX64, BT_COMPLEX128,
    BT_QUATERNION64, BT_QUATERNION128, BT_QUATERNION256,
    BT_STRING, BT_CSTRING, BT_BYTE, BT_RUNE, BT_RAWPTR, BT_ANY
};

// --- Вид типа --- 
enum TypeKind {
    TY_NAME,        // MyType -> Name                       
    TY_BASE,        
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

struct TypeExpr {
    enum TypeKind Kind;
 
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
 
// Список типов: return_type_list -> (int, string) 
struct TypeList {
    struct TypeExpr *First;
    struct TypeExpr *Last;
};
 
// --- Объявление "имена : тип" ---
// Одна структура на три правила с одинаковой формой:
// param (параметр процедуры), field_decl (поле struct/union)
// и далее пригодится для объявлений переменных.
//     a, b: int     -> Names = [a, b], Type = int                         
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
 
// --- Элемент enum:  Red   или   Green = 5 --- 
struct EnumItem {
    char              *Name;
    struct Expression *Value;    // NULL, если значение не задано 
    struct EnumItem   *Next;
    int Line;
};
 
struct EnumItemList {
    struct EnumItem *First;
    struct EnumItem *Last;
};

#endif // TREE_NODES_H 