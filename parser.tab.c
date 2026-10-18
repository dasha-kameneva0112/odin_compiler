/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);

#line 79 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASM = 3,                        /* ASM  */
  YYSYMBOL_AUTO_CAST = 4,                  /* AUTO_CAST  */
  YYSYMBOL_BIT_FIELD = 5,                  /* BIT_FIELD  */
  YYSYMBOL_BIT_SET = 6,                    /* BIT_SET  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_CASE = 8,                       /* CASE  */
  YYSYMBOL_CAST = 9,                       /* CAST  */
  YYSYMBOL_CONTEXT = 10,                   /* CONTEXT  */
  YYSYMBOL_CONTINUE = 11,                  /* CONTINUE  */
  YYSYMBOL_DEFER = 12,                     /* DEFER  */
  YYSYMBOL_DISTINCT = 13,                  /* DISTINCT  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_DYNAMIC = 15,                   /* DYNAMIC  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_ENUM = 17,                      /* ENUM  */
  YYSYMBOL_FALLTHROUGH = 18,               /* FALLTHROUGH  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_FOREIGN = 20,                   /* FOREIGN  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_IMPORT = 22,                    /* IMPORT  */
  YYSYMBOL_IN = 23,                        /* IN  */
  YYSYMBOL_MAP = 24,                       /* MAP  */
  YYSYMBOL_MATRIX = 25,                    /* MATRIX  */
  YYSYMBOL_NOT_IN = 26,                    /* NOT_IN  */
  YYSYMBOL_OR_BREAK = 27,                  /* OR_BREAK  */
  YYSYMBOL_OR_CONTINUE = 28,               /* OR_CONTINUE  */
  YYSYMBOL_OR_ELSE = 29,                   /* OR_ELSE  */
  YYSYMBOL_OR_RETURN = 30,                 /* OR_RETURN  */
  YYSYMBOL_PACKAGE = 31,                   /* PACKAGE  */
  YYSYMBOL_PROC = 32,                      /* PROC  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_STRUCT = 34,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 35,                    /* SWITCH  */
  YYSYMBOL_TRANSMUTE = 36,                 /* TRANSMUTE  */
  YYSYMBOL_TYPEID = 37,                    /* TYPEID  */
  YYSYMBOL_UNION = 38,                     /* UNION  */
  YYSYMBOL_USING = 39,                     /* USING  */
  YYSYMBOL_WHEN = 40,                      /* WHEN  */
  YYSYMBOL_WHERE = 41,                     /* WHERE  */
  YYSYMBOL_BOOL = 42,                      /* BOOL  */
  YYSYMBOL_B8 = 43,                        /* B8  */
  YYSYMBOL_B16 = 44,                       /* B16  */
  YYSYMBOL_B32 = 45,                       /* B32  */
  YYSYMBOL_B64 = 46,                       /* B64  */
  YYSYMBOL_INT = 47,                       /* INT  */
  YYSYMBOL_I8 = 48,                        /* I8  */
  YYSYMBOL_I16 = 49,                       /* I16  */
  YYSYMBOL_I32 = 50,                       /* I32  */
  YYSYMBOL_I64 = 51,                       /* I64  */
  YYSYMBOL_I128 = 52,                      /* I128  */
  YYSYMBOL_UINT = 53,                      /* UINT  */
  YYSYMBOL_U8 = 54,                        /* U8  */
  YYSYMBOL_U16 = 55,                       /* U16  */
  YYSYMBOL_U32 = 56,                       /* U32  */
  YYSYMBOL_U64 = 57,                       /* U64  */
  YYSYMBOL_U128 = 58,                      /* U128  */
  YYSYMBOL_UINTPTR = 59,                   /* UINTPTR  */
  YYSYMBOL_F16 = 60,                       /* F16  */
  YYSYMBOL_F32 = 61,                       /* F32  */
  YYSYMBOL_F64 = 62,                       /* F64  */
  YYSYMBOL_COMPLEX32 = 63,                 /* COMPLEX32  */
  YYSYMBOL_COMPLEX64 = 64,                 /* COMPLEX64  */
  YYSYMBOL_COMPLEX128 = 65,                /* COMPLEX128  */
  YYSYMBOL_QUATERNION64 = 66,              /* QUATERNION64  */
  YYSYMBOL_QUATERNION128 = 67,             /* QUATERNION128  */
  YYSYMBOL_QUATERNION256 = 68,             /* QUATERNION256  */
  YYSYMBOL_STRING = 69,                    /* STRING  */
  YYSYMBOL_CSTRING = 70,                   /* CSTRING  */
  YYSYMBOL_BYTE = 71,                      /* BYTE  */
  YYSYMBOL_RUNE = 72,                      /* RUNE  */
  YYSYMBOL_RAWPTR = 73,                    /* RAWPTR  */
  YYSYMBOL_ANY = 74,                       /* ANY  */
  YYSYMBOL_INT_LIT = 75,                   /* INT_LIT  */
  YYSYMBOL_BOOL_LIT = 76,                  /* BOOL_LIT  */
  YYSYMBOL_FLOAT_LIT = 77,                 /* FLOAT_LIT  */
  YYSYMBOL_ID = 78,                        /* ID  */
  YYSYMBOL_STRING_LIT = 79,                /* STRING_LIT  */
  YYSYMBOL_RAW_STRING_LIT = 80,            /* RAW_STRING_LIT  */
  YYSYMBOL_IMAGINARY_LIT = 81,             /* IMAGINARY_LIT  */
  YYSYMBOL_RUNE_LIT = 82,                  /* RUNE_LIT  */
  YYSYMBOL_NIL = 83,                       /* NIL  */
  YYSYMBOL_UNDEFINED = 84,                 /* UNDEFINED  */
  YYSYMBOL_ATTRIBUTE = 85,                 /* ATTRIBUTE  */
  YYSYMBOL_BUILD_DIRECTIVE = 86,           /* BUILD_DIRECTIVE  */
  YYSYMBOL_DIRECTIVE = 87,                 /* DIRECTIVE  */
  YYSYMBOL_AT = 88,                        /* AT  */
  YYSYMBOL_OP_ADD_ASSIGN = 89,             /* OP_ADD_ASSIGN  */
  YYSYMBOL_OP_SUB_ASSIGN = 90,             /* OP_SUB_ASSIGN  */
  YYSYMBOL_OP_MUL_ASSIGN = 91,             /* OP_MUL_ASSIGN  */
  YYSYMBOL_OP_DIV_ASSIGN = 92,             /* OP_DIV_ASSIGN  */
  YYSYMBOL_OP_MOD_ASSIGN = 93,             /* OP_MOD_ASSIGN  */
  YYSYMBOL_OP_MOD2_ASSIGN = 94,            /* OP_MOD2_ASSIGN  */
  YYSYMBOL_OP_OR_ASSIGN = 95,              /* OP_OR_ASSIGN  */
  YYSYMBOL_OP_NOT_ASSIGN = 96,             /* OP_NOT_ASSIGN  */
  YYSYMBOL_OP_AND_ASSIGN = 97,             /* OP_AND_ASSIGN  */
  YYSYMBOL_OP_AND_NOT_ASSIGN = 98,         /* OP_AND_NOT_ASSIGN  */
  YYSYMBOL_OP_SHL_ASSIGN = 99,             /* OP_SHL_ASSIGN  */
  YYSYMBOL_OP_SHR_ASSIGN = 100,            /* OP_SHR_ASSIGN  */
  YYSYMBOL_OP_LOG_AND_ASSIGN = 101,        /* OP_LOG_AND_ASSIGN  */
  YYSYMBOL_OP_LOG_OR_ASSIGN = 102,         /* OP_LOG_OR_ASSIGN  */
  YYSYMBOL_OP_LOG_AND = 103,               /* OP_LOG_AND  */
  YYSYMBOL_OP_LOG_OR = 104,                /* OP_LOG_OR  */
  YYSYMBOL_OP_AND_NOT = 105,               /* OP_AND_NOT  */
  YYSYMBOL_OP_SHL = 106,                   /* OP_SHL  */
  YYSYMBOL_OP_SHR = 107,                   /* OP_SHR  */
  YYSYMBOL_OP_EQ = 108,                    /* OP_EQ  */
  YYSYMBOL_OP_NE = 109,                    /* OP_NE  */
  YYSYMBOL_OP_LE = 110,                    /* OP_LE  */
  YYSYMBOL_OP_GE = 111,                    /* OP_GE  */
  YYSYMBOL_OP_RANGE = 112,                 /* OP_RANGE  */
  YYSYMBOL_OP_RANGE_INCLUSIVE = 113,       /* OP_RANGE_INCLUSIVE  */
  YYSYMBOL_OP_RANGE_EXCLUSIVE = 114,       /* OP_RANGE_EXCLUSIVE  */
  YYSYMBOL_OP_ARROW = 115,                 /* OP_ARROW  */
  YYSYMBOL_OP_DECL_TYPED = 116,            /* OP_DECL_TYPED  */
  YYSYMBOL_OP_DECL_INFERRED = 117,         /* OP_DECL_INFERRED  */
  YYSYMBOL_OP_MOD2 = 118,                  /* OP_MOD2  */
  YYSYMBOL_OP_DOLLAR = 119,                /* OP_DOLLAR  */
  YYSYMBOL_LEX_ERROR = 120,                /* LEX_ERROR  */
  YYSYMBOL_121_ = 121,                     /* '?'  */
  YYSYMBOL_122_ = 122,                     /* '<'  */
  YYSYMBOL_123_ = 123,                     /* '>'  */
  YYSYMBOL_124_ = 124,                     /* '+'  */
  YYSYMBOL_125_ = 125,                     /* '-'  */
  YYSYMBOL_126_ = 126,                     /* '|'  */
  YYSYMBOL_127_ = 127,                     /* '~'  */
  YYSYMBOL_128_ = 128,                     /* '*'  */
  YYSYMBOL_129_ = 129,                     /* '/'  */
  YYSYMBOL_130_ = 130,                     /* '%'  */
  YYSYMBOL_131_ = 131,                     /* '&'  */
  YYSYMBOL_UNARY = 132,                    /* UNARY  */
  YYSYMBOL_133_ = 133,                     /* '('  */
  YYSYMBOL_134_ = 134,                     /* '['  */
  YYSYMBOL_135_ = 135,                     /* '.'  */
  YYSYMBOL_136_ = 136,                     /* '^'  */
  YYSYMBOL_137_ = 137,                     /* ';'  */
  YYSYMBOL_138_ = 138,                     /* ')'  */
  YYSYMBOL_139_ = 139,                     /* '{'  */
  YYSYMBOL_140_ = 140,                     /* '}'  */
  YYSYMBOL_141_ = 141,                     /* ','  */
  YYSYMBOL_142_ = 142,                     /* ':'  */
  YYSYMBOL_143_ = 143,                     /* '='  */
  YYSYMBOL_144_ = 144,                     /* ']'  */
  YYSYMBOL_145_ = 145,                     /* '!'  */
  YYSYMBOL_YYACCEPT = 146,                 /* $accept  */
  YYSYMBOL_program = 147,                  /* program  */
  YYSYMBOL_package_clause = 148,           /* package_clause  */
  YYSYMBOL_import_list = 149,              /* import_list  */
  YYSYMBOL_import_decl = 150,              /* import_decl  */
  YYSYMBOL_decl_list = 151,                /* decl_list  */
  YYSYMBOL_decl = 152,                     /* decl  */
  YYSYMBOL_decl_core = 153,                /* decl_core  */
  YYSYMBOL_proc_decl = 154,                /* proc_decl  */
  YYSYMBOL_param_list_opt = 155,           /* param_list_opt  */
  YYSYMBOL_param_list = 156,               /* param_list  */
  YYSYMBOL_param = 157,                    /* param  */
  YYSYMBOL_id_list = 158,                  /* id_list  */
  YYSYMBOL_return_type = 159,              /* return_type  */
  YYSYMBOL_return_type_list = 160,         /* return_type_list  */
  YYSYMBOL_var_decl = 161,                 /* var_decl  */
  YYSYMBOL_const_decl = 162,               /* const_decl  */
  YYSYMBOL_type_expr = 163,                /* type_expr  */
  YYSYMBOL_type_core = 164,                /* type_core  */
  YYSYMBOL_field_list_opt = 165,           /* field_list_opt  */
  YYSYMBOL_field_list = 166,               /* field_list  */
  YYSYMBOL_field_decl = 167,               /* field_decl  */
  YYSYMBOL_foreign_decl = 168,             /* foreign_decl  */
  YYSYMBOL_base_type = 169,                /* base_type  */
  YYSYMBOL_enum_body_opt = 170,            /* enum_body_opt  */
  YYSYMBOL_enum_body = 171,                /* enum_body  */
  YYSYMBOL_enum_item = 172,                /* enum_item  */
  YYSYMBOL_block = 173,                    /* block  */
  YYSYMBOL_stmts = 174,                    /* stmts  */
  YYSYMBOL_stmt_list = 175,                /* stmt_list  */
  YYSYMBOL_stmt = 176,                     /* stmt  */
  YYSYMBOL_labelable = 177,                /* labelable  */
  YYSYMBOL_simple_stmt = 178,              /* simple_stmt  */
  YYSYMBOL_assign_op = 179,                /* assign_op  */
  YYSYMBOL_simple_stmt_opt = 180,          /* simple_stmt_opt  */
  YYSYMBOL_expr_opt = 181,                 /* expr_opt  */
  YYSYMBOL_if_stmt = 182,                  /* if_stmt  */
  YYSYMBOL_for_stmt = 183,                 /* for_stmt  */
  YYSYMBOL_switch_stmt = 184,              /* switch_stmt  */
  YYSYMBOL_switch_body = 185,              /* switch_body  */
  YYSYMBOL_case_list = 186,                /* case_list  */
  YYSYMBOL_case_clause = 187,              /* case_clause  */
  YYSYMBOL_expr_list = 188,                /* expr_list  */
  YYSYMBOL_when_stmt = 189,                /* when_stmt  */
  YYSYMBOL_attribute = 190,                /* attribute  */
  YYSYMBOL_attr_list = 191,                /* attr_list  */
  YYSYMBOL_attr = 192,                     /* attr  */
  YYSYMBOL_expr = 193,                     /* expr  */
  YYSYMBOL_arg_list_op = 194,              /* arg_list_op  */
  YYSYMBOL_arg_list = 195                  /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  146
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  238
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  410

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   376


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   145,     2,     2,     2,   130,   131,     2,
     133,   138,   128,   124,   141,   125,   135,   129,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   142,   137,
     122,   143,   123,   121,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   134,     2,   144,   136,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   139,   126,   140,   127,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   132
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    78,    82,    83,    86,    90,    91,    94,
      97,    98,    99,   100,   101,   108,   109,   113,   114,   117,
     118,   121,   125,   126,   130,   131,   132,   135,   136,   142,
     143,   144,   153,   154,   155,   159,   160,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     180,   181,   184,   185,   188,   192,   193,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     233,   234,   237,   238,   242,   243,   247,   251,   252,   255,
     256,   257,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   285,
     286,   287,   288,   294,   295,   296,   297,   298,   299,   300,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   321,   322,   326,   327,   333,   334,
     335,   336,   337,   338,   343,   344,   345,   346,   347,   348,
     349,   353,   354,   355,   356,   360,   364,   365,   369,   370,
     374,   375,   380,   381,   382,   387,   388,   389,   392,   393,
     396,   397,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   414,   415,   416,   417,   418,   419,   422,
     423,   425,   426,   427,   428,   429,   430,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   446,
     447,   448,   449,   452,   453,   454,   457,   458,   459,   460,
     461,   462,   463,   466,   467,   471,   472,   475,   476
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASM", "AUTO_CAST",
  "BIT_FIELD", "BIT_SET", "BREAK", "CASE", "CAST", "CONTEXT", "CONTINUE",
  "DEFER", "DISTINCT", "DO", "DYNAMIC", "ELSE", "ENUM", "FALLTHROUGH",
  "FOR", "FOREIGN", "IF", "IMPORT", "IN", "MAP", "MATRIX", "NOT_IN",
  "OR_BREAK", "OR_CONTINUE", "OR_ELSE", "OR_RETURN", "PACKAGE", "PROC",
  "RETURN", "STRUCT", "SWITCH", "TRANSMUTE", "TYPEID", "UNION", "USING",
  "WHEN", "WHERE", "BOOL", "B8", "B16", "B32", "B64", "INT", "I8", "I16",
  "I32", "I64", "I128", "UINT", "U8", "U16", "U32", "U64", "U128",
  "UINTPTR", "F16", "F32", "F64", "COMPLEX32", "COMPLEX64", "COMPLEX128",
  "QUATERNION64", "QUATERNION128", "QUATERNION256", "STRING", "CSTRING",
  "BYTE", "RUNE", "RAWPTR", "ANY", "INT_LIT", "BOOL_LIT", "FLOAT_LIT",
  "ID", "STRING_LIT", "RAW_STRING_LIT", "IMAGINARY_LIT", "RUNE_LIT", "NIL",
  "UNDEFINED", "ATTRIBUTE", "BUILD_DIRECTIVE", "DIRECTIVE", "AT",
  "OP_ADD_ASSIGN", "OP_SUB_ASSIGN", "OP_MUL_ASSIGN", "OP_DIV_ASSIGN",
  "OP_MOD_ASSIGN", "OP_MOD2_ASSIGN", "OP_OR_ASSIGN", "OP_NOT_ASSIGN",
  "OP_AND_ASSIGN", "OP_AND_NOT_ASSIGN", "OP_SHL_ASSIGN", "OP_SHR_ASSIGN",
  "OP_LOG_AND_ASSIGN", "OP_LOG_OR_ASSIGN", "OP_LOG_AND", "OP_LOG_OR",
  "OP_AND_NOT", "OP_SHL", "OP_SHR", "OP_EQ", "OP_NE", "OP_LE", "OP_GE",
  "OP_RANGE", "OP_RANGE_INCLUSIVE", "OP_RANGE_EXCLUSIVE", "OP_ARROW",
  "OP_DECL_TYPED", "OP_DECL_INFERRED", "OP_MOD2", "OP_DOLLAR", "LEX_ERROR",
  "'?'", "'<'", "'>'", "'+'", "'-'", "'|'", "'~'", "'*'", "'/'", "'%'",
  "'&'", "UNARY", "'('", "'['", "'.'", "'^'", "';'", "')'", "'{'", "'}'",
  "','", "':'", "'='", "']'", "'!'", "$accept", "program",
  "package_clause", "import_list", "import_decl", "decl_list", "decl",
  "decl_core", "proc_decl", "param_list_opt", "param_list", "param",
  "id_list", "return_type", "return_type_list", "var_decl", "const_decl",
  "type_expr", "type_core", "field_list_opt", "field_list", "field_decl",
  "foreign_decl", "base_type", "enum_body_opt", "enum_body", "enum_item",
  "block", "stmts", "stmt_list", "stmt", "labelable", "simple_stmt",
  "assign_op", "simple_stmt_opt", "expr_opt", "if_stmt", "for_stmt",
  "switch_stmt", "switch_body", "case_list", "case_clause", "expr_list",
  "when_stmt", "attribute", "attr_list", "attr", "expr", "arg_list_op",
  "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-362)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-171)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,   -41,    43,  -362,   -87,  -362,    36,  -362,   -20,  -362,
      -1,   -77,   -11,   -55,  -362,   -16,  -362,   -74,  -362,   -89,
    -362,  -362,  -362,    -1,  -362,   -14,  -362,  -362,   360,   -68,
    -362,   721,   -10,  1034,  -362,     0,   -73,   441,   721,   -65,
     -63,  1034,   -59,   -53,   -52,  -109,   -56,   -48,   -51,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,   721,   721,   721,   721,   721,   535,  1034,   721,
    -362,  -362,  2230,     8,   -46,  2230,  -362,   -40,  -362,  -110,
    -362,  -362,  -362,    20,    31,   522,  -362,   545,   721,   721,
     627,   721,   721,   522,  -362,  -362,   -31,  -362,  -362,  -362,
    -362,   -97,  -362,  1452,    83,  1034,  1034,  -362,    37,  1034,
     721,    38,    38,    38,  1034,    38,    83,    83,    83,    83,
    2114,   -30,  1034,  1188,  -362,    83,   721,  -362,  -362,   721,
    -362,   721,   721,   721,   721,   721,   721,   721,   721,   721,
     721,   721,   721,   721,   721,   721,   721,   721,   721,   721,
     721,   721,   721,   721,   721,   721,   721,   721,    40,  -362,
     -19,  -116,  -362,   721,    38,   721,   721,  -362,  -362,  -362,
    -362,  -362,   -15,    -9,  1025,    -7,   -94,  1807,   -46,  -362,
       2,  -362,  1924,  2230,  1961,  -362,  -362,   721,   838,   721,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,   721,   -23,    39,    26,   -17,    34,
    -362,    32,  1604,  -362,    41,    42,  -362,  -107,  -101,  -100,
      44,    45,  -362,    47,    50,  -362,  1034,  -362,  1034,  1643,
    2264,  1759,  1114,  2353,    83,    83,    83,   688,   688,   688,
     688,  2298,  2298,  2298,    83,  1493,   688,   688,  1562,  1562,
    1562,  1562,    83,    83,    83,    83,  2230,    49,    52,  1299,
    -362,   721,  -362,     8,  2230,    56,   -46,   -46,   721,   721,
    1034,   522,  -362,   721,   111,    -3,   627,  -362,   113,   -46,
     -88,  -362,  -362,  -362,  -362,  -362,   -46,  2230,  -362,   721,
     721,  -362,    37,  1034,   721,    63,    38,  1034,  -362,  1034,
    -362,    38,   721,  -362,  -362,  -362,   721,   721,   721,  -362,
     721,  -362,  2230,  -362,    63,    59,  2230,  1151,  -362,  1961,
     -13,   708,  -362,  -362,  -362,  2077,   -22,   721,   721,    83,
    2230,  -362,  -362,  1341,   937,    58,  -362,  -362,  -362,  -362,
      83,  2230,  2230,  2230,  2230,  -362,   721,   522,  -362,   164,
    -362,  -362,  -362,   -85,  -362,  -362,  -362,   -46,   -46,  1034,
    1034,  -362,  -362,    -8,  -362,   -13,  -362,  -362,  -362,  -112,
    -362,   522,  -362,  -362,  -362,  -362,  -362,  1034,  -362,  -362
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     7,     3,     0,     5,
       2,     0,     0,    22,   175,     0,     8,     0,    10,     0,
      11,    12,    13,     0,     6,     0,    99,    56,     0,   176,
       9,     0,     0,     0,    14,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   183,   191,   184,   182,   185,   186,   187,   188,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    37,    32,     0,    31,   170,    23,     0,    35,    30,
      36,    55,    96,   114,   116,     0,   118,   144,     0,   109,
       0,     0,     0,     0,   101,   103,    98,   102,   104,   105,
     106,     0,   107,   129,   198,     0,     0,    48,    90,     0,
       0,    17,     0,    50,     0,    50,   193,   194,   196,   197,
       0,     0,     0,     0,    38,   195,     0,   228,   229,     0,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,     0,     0,   226,
     180,     0,   178,     0,    17,     0,     0,   115,   117,   111,
     154,   145,     0,     0,   170,     0,     0,   170,   110,   166,
       0,   161,   170,   113,     0,   112,   100,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,     0,    94,     0,    91,
      92,     0,     0,    22,     0,    18,    19,     0,     0,     0,
       0,    51,    52,     0,     0,   192,     0,    39,     0,     0,
     219,     0,   200,   199,   216,   217,   218,   201,   202,   205,
     206,   220,   221,   222,   214,     0,   203,   204,   207,   208,
     209,   210,   211,   212,   213,   215,   237,     0,   236,     0,
     232,     0,   177,     0,   171,     0,    34,    29,   146,     0,
       0,     0,   155,     0,   148,     0,     0,   162,   172,   124,
     125,   119,   108,   120,   121,   122,   123,   128,    47,     0,
       0,    45,     0,     0,     0,    24,     0,     0,    16,     0,
      44,     0,     0,    46,    41,    40,     0,     0,     0,   230,
       0,   231,   181,   179,    24,     0,   147,     0,   158,     0,
       0,     0,   165,   167,   164,     0,     0,     0,     0,   233,
      95,    93,    42,     0,     0,    43,    20,    21,    54,    53,
     234,   225,   224,   223,   238,    43,   144,     0,   156,   151,
     149,   150,    99,     0,   163,   174,   173,   127,   126,     0,
       0,    25,    15,     0,   159,     0,   169,    99,    49,     0,
      27,     0,   157,   152,   153,   168,    26,     0,   160,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -362,  -362,  -362,  -362,  -362,  -362,  -362,   159,  -362,     4,
    -362,  -127,    28,  -144,  -362,  -362,  -362,   -32,   173,    60,
    -362,  -128,  -362,  -362,  -362,  -362,  -118,   -12,  -361,  -362,
    -113,  -362,  -105,  -362,  -169,  -362,  -214,    -6,     3,  -181,
    -362,  -362,   -28,  -148,  -362,  -362,   -84,   -21,  -362,  -362
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     6,     9,    10,    16,    17,    18,   244,
     245,   246,   247,   365,   399,    20,    21,   310,   110,   250,
     251,   252,    22,   101,   238,   239,   240,   125,    36,    37,
     126,   312,   127,   234,   202,   345,   128,   129,   130,   211,
     305,   353,   131,   132,    23,   191,   192,   105,   287,   288
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,   109,   199,   104,   313,   351,   401,   102,   118,   137,
     215,    25,   201,   205,   299,   210,   133,   134,   122,    12,
     217,   396,   292,   217,   141,   293,   406,     1,    31,   407,
     142,   307,   195,   196,    32,   327,   405,     4,    19,   328,
      32,    32,   329,     5,   193,   218,   219,   193,   300,   219,
       7,    19,    32,    33,   357,   358,   193,   397,     8,    11,
      24,    28,    29,    30,    35,   103,   154,   112,   106,   135,
     136,   146,   147,   148,   149,   150,   153,    13,   155,   111,
     138,   139,   140,   143,    14,   144,   190,    15,   145,   203,
     206,   208,   206,   194,   133,   193,   204,   207,   197,   212,
     213,   214,   133,   235,   236,   200,   216,   241,   217,   198,
     157,   158,   253,   160,   256,   237,   243,    26,   290,   242,
     257,   318,   298,   321,   291,   354,    26,   350,    26,   356,
     303,    26,   193,   300,   219,   259,   381,   352,   260,   306,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   289,   296,   297,   320,
     248,   249,   294,   249,   384,   322,   323,   319,   364,   325,
     395,   404,    34,   326,   330,   332,   331,   339,   348,   309,
     333,   316,   302,   340,   344,   304,   376,    26,   295,   366,
     375,   100,   308,   369,   361,   254,   311,   393,   386,   343,
       0,     0,   314,   317,     0,     0,   186,   187,   188,   189,
       0,   315,     0,     0,   334,     0,   335,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   394,     0,     0,     0,     0,     0,
     342,   201,     0,     0,     0,     0,     0,   346,   347,     0,
     133,     0,   349,     0,     0,   355,     0,     0,   408,     0,
       0,   362,     0,     0,     0,   367,     0,   368,   359,   360,
       0,     0,     0,   363,     0,     0,     0,     0,     0,     0,
       0,   370,     0,     0,     0,   371,   372,   373,     0,   374,
       0,     0,     0,   383,     0,     0,     0,     0,     0,   387,
     388,     0,   391,     0,     0,   378,     0,   379,   380,     0,
       0,     0,     0,     0,   385,     0,     0,     0,   206,     0,
       0,     0,     0,   392,     0,   133,   133,   398,   400,   249,
       0,     0,     0,     0,    38,     0,    39,     0,     0,    40,
       0,     0,     0,    41,     0,   409,     0,    42,     0,     0,
     133,   402,     0,   403,    43,    44,     0,     0,     0,     0,
       0,     0,    45,     0,    46,     0,    47,     0,    48,     0,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    38,     0,     0,   113,     0,
      40,     0,   114,   115,     0,     0,     0,     0,     0,   116,
     117,     0,   118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,     0,   120,    47,     0,     0,
     121,   122,     0,     0,    92,    93,     0,    94,     0,     0,
       0,    95,     0,    96,    97,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    38,     0,   123,   113,
       0,    40,     0,   114,   115,     0,     0,     0,     0,    38,
     116,   117,     0,   118,    40,     0,     0,     0,     0,    38,
     151,     0,     0,     0,    40,   119,     0,   120,    47,     0,
       0,   121,   122,     0,     0,    92,    93,     0,    94,     0,
       0,    47,    95,     0,    96,     0,     0,     0,   124,     0,
      26,    47,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,   123,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    38,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,     0,    94,
       0,     0,     0,    95,     0,    96,     0,     0,     0,    92,
      93,    26,    94,    47,     0,     0,    95,    99,    96,    92,
      93,     0,    94,     0,     0,     0,    95,     0,    96,   152,
      99,     0,     0,     0,    26,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    38,     0,     0,   157,   158,    40,   160,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,    92,    93,     0,    94,     0,     0,    47,    95,     0,
      96,     0,     0,     0,     0,     0,   209,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   164,   165,   166,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   174,     0,     0,     0,
       0,     0,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   189,     0,     0,     0,     0,     0,
       0,     0,    92,    93,     0,    94,     0,     0,     0,    95,
       0,    96,     0,     0,    39,    92,    93,     0,    94,     0,
     382,    41,    95,    99,    96,    42,     0,   117,     0,   118,
       0,     0,    43,    44,     0,     0,    99,     0,     0,     0,
     107,     0,    46,   120,     0,     0,    48,     0,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,    43,    44,     0,     0,     0,     0,     0,     0,   107,
       0,    46,    97,     0,    98,    48,     0,    26,     0,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   301,
      39,     0,     0,     0,     0,     0,   156,    41,     0,     0,
       0,    42,   157,   158,   159,   160,     0,     0,    43,    44,
       0,     0,     0,     0,     0,   161,   107,     0,    46,     0,
     390,    97,    48,    98,     0,     0,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,   108,     0,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,   157,   158,   174,   160,     0,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   189,  -129,     0,    26,   377,     0,     0,    97,     0,
      98,     0,   156,     0,     0,     0,     0,     0,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   156,
       0,     0,     0,     0,     0,   157,   158,   159,   160,   164,
     165,   166,   167,   168,   169,   170,     0,     0,   161,     0,
       0,     0,   174,     0,     0,     0,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     189,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,     0,   174,
       0,     0,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   189,     0,     0,
      26,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,   174,     0,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     156,   186,   187,   188,   189,     0,   157,   158,   159,   160,
       0,     0,   258,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,     0,     0,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,     0,   174,     0,     0,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,   189,     0,     0,     0,     0,
       0,     0,     0,   341,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,     0,   174,
       0,     0,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   156,   186,   187,   188,   189,     0,   157,
     158,   159,   160,     0,     0,   389,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,     0,     0,     0,     0,     0,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,  -170,
     174,     0,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,   189,   157,
     158,     0,   160,  -170,  -170,  -170,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
       0,   174,     0,     0,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   156,   186,   187,   188,   189,
       0,   157,   158,   159,   160,   338,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,     0,     0,     0,   156,     0,     0,   164,   165,   166,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
     174,     0,     0,   161,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   185,     0,   186,   187,   188,   189,     0,
       0,     0,     0,     0,     0,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,   174,     0,     0,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     189,     0,     0,     0,     0,   324,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
       0,   174,     0,     0,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   337,   186,   187,   188,   189,
     156,     0,     0,     0,     0,     0,   157,   158,   159,   160,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
       0,     0,     0,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,     0,   174,     0,     0,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,   189,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,   174,     0,     0,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,   189,  -129,   156,    26,     0,     0,     0,
       0,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,     0,     0,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,   174,     0,     0,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     189,  -129,     0,   209,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,     0,   174,
       0,     0,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   189,   156,     0,
      26,     0,     0,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,     0,     0,     0,     0,
       0,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,   174,     0,     0,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,   189,     0,     0,   209,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,   174,     0,     0,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     189,   156,   255,     0,     0,     0,     0,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,     0,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   158,     0,   160,     0,
       0,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,     0,   174,     0,
       0,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,   189,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
     157,   158,   174,   160,     0,     0,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     189,   162,   163,   164,   165,   166,   167,   168,   169,   170,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   189,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,     0,   164,   165,
     166,   167,   168,   169,   170,     0,     0,     0,     0,     0,
       0,   174,     0,     0,     0,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   189
};

static const yytype_int16 yycheck[] =
{
      12,    33,   115,    31,   218,     8,    14,    28,    21,    41,
     123,    22,   117,   118,    23,   120,    37,    38,    40,    20,
     117,   382,   138,   117,   133,   141,   138,    31,   117,   141,
     139,   212,   142,   143,   141,   142,   397,    78,    10,   140,
     141,   141,   142,     0,   141,   142,   143,   141,   142,   143,
     137,    23,   141,   142,   142,   143,   141,   142,    22,    79,
     137,   116,    78,   137,    78,   133,    98,   140,    78,   134,
     133,    92,    93,    94,    95,    96,    97,    78,    99,    79,
     139,   134,   134,   139,    85,   133,    78,    88,   139,   117,
     118,   119,   120,   133,   115,   141,   117,   118,    78,   120,
     121,   122,   123,   135,   136,   117,   137,   139,   117,    78,
      27,    28,   144,    30,   144,    78,    78,   139,    78,   140,
     152,   144,   137,   140,   143,   306,   139,    16,   139,    16,
     137,   139,   141,   142,   143,   156,   350,   140,   159,   137,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   195,   196,   143,
     142,   143,   193,   145,   355,   141,   144,   138,   115,   138,
      16,   395,    23,   141,   140,   138,   141,   138,   301,   217,
     140,   219,   204,   141,   138,   207,   137,   139,   194,   326,
     344,    28,   214,   331,   322,   145,   218,   376,   356,   293,
      -1,    -1,   218,   234,    -1,    -1,   133,   134,   135,   136,
      -1,   218,    -1,    -1,   256,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,
     291,   376,    -1,    -1,    -1,    -1,    -1,   298,   299,    -1,
     301,    -1,   303,    -1,    -1,   306,    -1,    -1,   401,    -1,
      -1,   323,    -1,    -1,    -1,   327,    -1,   329,   319,   320,
      -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   332,    -1,    -1,    -1,   336,   337,   338,    -1,   340,
      -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,   357,
     358,    -1,   364,    -1,    -1,   347,    -1,   349,   350,    -1,
      -1,    -1,    -1,    -1,   356,    -1,    -1,    -1,   376,    -1,
      -1,    -1,    -1,   365,    -1,   376,   377,   389,   390,   331,
      -1,    -1,    -1,    -1,     4,    -1,     6,    -1,    -1,     9,
      -1,    -1,    -1,    13,    -1,   407,    -1,    17,    -1,    -1,
     401,   393,    -1,   395,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    36,    -1,    38,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     4,    -1,    -1,     7,    -1,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,
      39,    40,    -1,    -1,   124,   125,    -1,   127,    -1,    -1,
      -1,   131,    -1,   133,   134,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     4,    -1,    87,     7,
      -1,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,     4,
      18,    19,    -1,    21,     9,    -1,    -1,    -1,    -1,     4,
      15,    -1,    -1,    -1,     9,    33,    -1,    35,    36,    -1,
      -1,    39,    40,    -1,    -1,   124,   125,    -1,   127,    -1,
      -1,    36,   131,    -1,   133,    -1,    -1,    -1,   137,    -1,
     139,    36,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    87,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,     4,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,    -1,   133,    -1,    -1,    -1,   124,
     125,   139,   127,    36,    -1,    -1,   131,   145,   133,   124,
     125,    -1,   127,    -1,    -1,    -1,   131,    -1,   133,   144,
     145,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     4,    -1,    -1,    27,    28,     9,    30,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,    -1,   127,    -1,    -1,    36,   131,    -1,
     133,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,   105,   106,   107,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,   118,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,    -1,   127,    -1,    -1,    -1,   131,
      -1,   133,    -1,    -1,     6,   124,   125,    -1,   127,    -1,
     142,    13,   131,   145,   133,    17,    -1,    19,    -1,    21,
      -1,    -1,    24,    25,    -1,    -1,   145,    -1,    -1,    -1,
      32,    -1,    34,    35,    -1,    -1,    38,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,   134,    -1,   136,    38,    -1,   139,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
       6,    -1,    -1,    -1,    -1,    -1,    21,    13,    -1,    -1,
      -1,    17,    27,    28,    29,    30,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    40,    32,    -1,    34,    -1,
     133,   134,    38,   136,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    27,    28,   118,    30,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,   133,   134,
     135,   136,   137,    -1,   139,    14,    -1,    -1,   134,    -1,
     136,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    40,    -1,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,   134,   135,
     136,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,   118,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   133,   134,   135,   136,    -1,    -1,
     139,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,   118,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      21,   133,   134,   135,   136,    -1,    27,    28,    29,    30,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,    -1,   118,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,   118,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    21,   133,   134,   135,   136,    -1,    27,
      28,    29,    30,    -1,    -1,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,   117,
     118,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,   133,   134,   135,   136,    27,
      28,    -1,    30,   141,   142,   143,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,   118,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    21,   133,   134,   135,   136,
      -1,    27,    28,    29,    30,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    21,    -1,    -1,   105,   106,   107,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,   118,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,   141,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,   118,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    16,   133,   134,   135,   136,
      21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,    -1,   118,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    -1,   133,   134,   135,   136,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,   118,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,   134,   135,   136,   137,    21,   139,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,   118,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,   134,   135,
     136,   137,    -1,   139,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,   118,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    -1,   133,   134,   135,   136,    21,    -1,
     139,    -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,   118,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    -1,
     133,   134,   135,   136,    -1,    -1,   139,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,   118,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,   134,   135,
     136,    21,   138,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,   118,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,   134,   135,   136,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      27,    28,   118,    30,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,   134,   135,
     136,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,   105,   106,
     107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    -1,   133,   134,   135,   136
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,   147,   148,    78,     0,   149,   137,    22,   150,
     151,    79,    20,    78,    85,    88,   152,   153,   154,   158,
     161,   162,   168,   190,   137,    22,   139,   173,   116,    78,
     137,   117,   141,   142,   153,    78,   174,   175,     4,     6,
       9,    13,    17,    24,    25,    32,    34,    36,    38,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   124,   125,   127,   131,   133,   134,   136,   145,
     164,   169,   193,   133,   188,   193,    78,    32,    78,   163,
     164,    79,   140,     7,    11,    12,    18,    19,    21,    33,
      35,    39,    40,    87,   137,   173,   176,   178,   182,   183,
     184,   188,   189,   193,   193,   134,   133,   163,   139,   134,
     134,   133,   139,   139,   133,   139,   193,   193,   193,   193,
     193,    15,   144,   193,   163,   193,    21,    27,    28,    29,
      30,    40,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   118,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   133,   134,   135,   136,
      78,   191,   192,   141,   133,   142,   143,    78,    78,   176,
     173,   178,   180,   188,   193,   178,   188,   193,   188,   139,
     178,   185,   193,   193,   193,   176,   137,   117,   142,   143,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   179,   163,   163,    78,   170,   171,
     172,   163,   193,    78,   155,   156,   157,   158,   158,   158,
     165,   166,   167,   163,   165,   138,   144,   163,   144,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   194,   195,   193,
      78,   143,   138,   141,   193,   155,   188,   188,   137,    23,
     142,    14,   173,   137,   173,   186,   137,   185,   173,   188,
     163,   173,   177,   182,   183,   184,   188,   193,   144,   138,
     143,   140,   141,   144,   141,   138,   141,   142,   140,   142,
     140,   141,   138,   140,   163,   163,    16,    16,   142,   138,
     141,   144,   193,   192,   138,   181,   193,   193,   176,   193,
      16,     8,   140,   187,   185,   193,    16,   142,   143,   193,
     193,   172,   163,   193,   115,   159,   157,   163,   163,   167,
     193,   193,   193,   193,   193,   159,   137,    14,   173,   173,
     173,   182,   142,   188,   185,   173,   189,   188,   188,   144,
     133,   163,   173,   180,   176,    16,   174,   142,   163,   160,
     163,    14,   173,   173,   182,   174,   138,   141,   176,   163
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   146,   147,   148,   149,   149,   150,   151,   151,   152,
     153,   153,   153,   153,   153,   154,   154,   155,   155,   156,
     156,   157,   158,   158,   159,   159,   159,   160,   160,   161,
     161,   161,   162,   162,   162,   163,   163,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     165,   165,   166,   166,   167,   168,   168,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   174,   174,   175,
     175,   175,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   177,
     177,   177,   177,   178,   178,   178,   178,   178,   178,   178,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   180,   180,   181,   181,   182,   182,
     182,   182,   182,   182,   183,   183,   183,   183,   183,   183,
     183,   184,   184,   184,   184,   185,   186,   186,   187,   187,
     188,   188,   189,   189,   189,   190,   190,   190,   191,   191,
     192,   192,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   194,   194,   195,   195
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     0,     2,     3,     0,     2,     2,
       1,     1,     1,     1,     2,     8,     6,     0,     1,     1,
       3,     3,     1,     3,     0,     2,     4,     1,     3,     5,
       3,     3,     3,     3,     5,     1,     1,     1,     2,     3,
       4,     4,     5,     5,     4,     4,     4,     4,     2,     7,
       0,     1,     1,     3,     3,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     3,     1,     3,     3,     1,     2,     0,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     2,     2,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     3,     3,     3,     5,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     1,     3,     5,
       5,     5,     7,     7,     2,     3,     5,     7,     4,     6,
       8,     2,     3,     5,     4,     3,     0,     2,     4,     3,
       1,     3,     3,     5,     5,     1,     2,     5,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     5,     5,     2,     2,     2,     2,
       4,     4,     3,     5,     5,     0,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {

#line 2368 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 479 "parser.y"


extern FILE *yyin;

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylloc.first_line, s);
}

int main(int argc, char **argv) {
    if (argc < 2) { fprintf(stderr, "Usage: %s <file>\n", argv[0]); return 1; }
    yyin = fopen(argv[1], "r");
    if (!yyin) { perror(argv[1]); return 1; }
    int r = yyparse();
    fclose(yyin);
    if (r == 0) printf("Good\n");
    return r;
}
