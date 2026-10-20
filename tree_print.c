#include <stdio.h>
#include "tree_print.h"

static void print_rec(const struct ExprNode* e, int depth, const char* role);
static void print_type_rec(const struct TypeNode* t, int depth, const char* role);

static const char* type_kind_name[] = {
    "TY_NAME", "TY_BASE", "TY_POINTER", "TY_SLICE", "TY_ARRAY", "TY_DYN_ARRAY",
    "TY_MAP", "TY_PROC", "TY_STRUCT", "TY_ENUM", "TY_UNION", "TY_BIT_SET",
    "TY_DISTINCT", "TY_MATRIX"
};

/* порядок такой же, как в enum BaseType */
static const char* base_type_name[] = {
    "bool", "b8", "b16", "b32", "b64",
    "int", "i8", "i16", "i32", "i64", "i128",
    "uint", "u8", "u16", "u32", "u64", "u128", "uintptr",
    "f16", "f32", "f64",
    "complex32", "complex64", "complex128",
    "quaternion64", "quaternion128", "quaternion256",
    "string", "cstring", "byte", "rune", "rawptr", "any"
};

static void print_type_rec(const struct TypeNode* t, int depth, const char* role)
{
    int i;

    for (i = 0; i < depth; i++)
        printf("    ");
    if (role)
        printf("%s: ", role);

    printf("%s", type_kind_name[t->Kind]);
    if (t->Kind == TY_NAME)
        printf(" %s", t->Name ? t->Name : "(null)");
    if (t->Kind == TY_BASE)
        printf(" %s", base_type_name[t->Base]);
    printf("  (line %d)\n", t->Line);

    if (t->Key)  print_type_rec(t->Key, depth + 1, "Key");
    if (t->Len)  print_rec(t->Len, depth + 1, "Len");
    if (t->Cols) print_rec(t->Cols, depth + 1, "Cols");
    if (t->Elem) print_type_rec(t->Elem, depth + 1, "Elem");
}

/* Название вида узла: по нему видно, какое правило сработало */
static const char *expr_name(enum ExprType t)
{
    switch (t)
    {
        case E_ID:          return "E_ID";
        case E_INT:         return "E_INT";
        case E_FLOAT:       return "E_FLOAT";
        case E_STRING:      return "E_STRING";
        case E_RAW_STRING:  return "E_RAW_STRING";
        case E_IMAG:        return "E_IMAG";
        case E_RUNE:        return "E_RUNE";
        case E_BOOL:        return "E_BOOL";
        case E_NIL:         return "E_NIL";
        case E_UNDEF:       return "E_UNDEF";
        case E_UPLUS:       return "E_UPLUS";
        case E_UMINUS:      return "E_UMINUS";
        case E_NOT:         return "E_NOT";
        case E_BIT_NOT:     return "E_BIT_NOT";
        case E_ADDR:        return "E_ADDR";
        case E_AUTO_CAST:   return "E_AUTO_CAST";
        case E_LOG_OR:      return "E_LOG_OR";
        case E_LOG_AND:     return "E_LOG_AND";
        case E_EQ:          return "E_EQ";
        case E_NE:          return "E_NE";
        case E_LT:          return "E_LT";
        case E_GT:          return "E_GT";
        case E_LE:          return "E_LE";
        case E_GE:          return "E_GE";
        case E_ADD:         return "E_ADD";
        case E_SUB:         return "E_SUB";
        case E_BIT_OR:      return "E_BIT_OR";
        case E_BIT_XOR:     return "E_BIT_XOR";
        case E_MUL:         return "E_MUL";
        case E_DIV:         return "E_DIV";
        case E_MOD:         return "E_MOD";
        case E_MOD2:        return "E_MOD2";
        case E_BIT_AND:     return "E_BIT_AND";
        case E_AND_NOT:     return "E_AND_NOT";
        case E_SHL:         return "E_SHL";
        case E_SHR:         return "E_SHR";
        case E_OR_ELSE:     return "E_OR_ELSE";
        case E_RANGE:       return "E_RANGE";
        case E_RANGE_INCL:  return "E_RANGE_INCL";
        case E_RANGE_EXCL:  return "E_RANGE_EXCL";
        case E_TERNARY_Q:   return "E_TERNARY_Q";
        case E_TERNARY_IF:  return "E_TERNARY_IF";
        case E_TERNARY_WHEN:return "E_TERNARY_WHEN";
        case E_DEREF:       return "E_DEREF";
        case E_OR_RETURN:   return "E_OR_RETURN";
        case E_OR_BREAK:    return "E_OR_BREAK";
        case E_OR_CONTINUE: return "E_OR_CONTINUE";
        case E_CALL:        return "E_CALL";
        case E_INDEX:       return "E_INDEX";
        case E_SELECTOR:    return "E_SELECTOR";
        case E_CAST:        return "E_CAST";
    }
    return "???";
}

/* role - подпись: кем узел приходится родителю (Cond / Left / Right / Arg) */
static void print_rec(const struct ExprNode *e, int depth, const char *role)
{
    int i;
    const struct ExprNode *arg;

    for (i = 0; i < depth; i++)
        printf("    ");
    if (role)
        printf("%s: ", role);

    printf("%s", expr_name(e->Type));

    /* значение, если оно есть у этого вида узла */
    switch (e->Type)
    {
        case E_ID: case E_STRING: case E_RAW_STRING: case E_SELECTOR:
            printf(" %s", e->Str ? e->Str : "(null)");
            break;
        case E_INT:
            printf(" %lld", e->IntVal);
            break;
        case E_FLOAT:
            printf(" %g", e->FloatVal);
            break;
        case E_IMAG:
            printf(" %g%c", e->FloatVal, e->ImagUnit);
            break;
        case E_RUNE:
            printf(" %u", e->RuneVal);
            break;
        case E_BOOL:
            printf(e->IntVal ? " true" : " false");
            break;
        default:
            break;
    }
    printf("  (line %d)\n", e->Line);

    /* потомки: в том порядке, в каком читается выражение */
    if (e->Cond)  print_rec(e->Cond,  depth + 1, "Cond");
    if (e->Left)  print_rec(e->Left,  depth + 1, "Left");
    if (e->Right) print_rec(e->Right, depth + 1, "Right");
    if (e->CastType) print_type_rec(e->CastType, depth + 1, "Type");

    if (e->Type == E_CALL)
    {
        if (!e->Args)
            printf("%*sArgs: (none)\n", (depth + 1) * 4, "");
        else
            for (arg = e->Args->First; arg; arg = arg->Next)
                print_rec(arg, depth + 1, "Arg");
    }
}

void print_expr(const struct ExprNode *expr)
{
    print_rec(expr, 0, NULL);
    printf("\n");
}
