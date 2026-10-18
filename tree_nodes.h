#ifndef TREE_NODES_H
#define TREE_NODES_H

// Узлы синтаксического дерева языка Odin 

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

struct ExprList;

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

#endif // TREE_NODES_H 