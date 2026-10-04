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
  YYSYMBOL_TRUE = 3,                       /* TRUE  */
  YYSYMBOL_FALSE = 4,                      /* FALSE  */
  YYSYMBOL_ASM = 5,                        /* ASM  */
  YYSYMBOL_AUTO_CAST = 6,                  /* AUTO_CAST  */
  YYSYMBOL_BIT_FIELD = 7,                  /* BIT_FIELD  */
  YYSYMBOL_BIT_SET = 8,                    /* BIT_SET  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CASE = 10,                      /* CASE  */
  YYSYMBOL_CAST = 11,                      /* CAST  */
  YYSYMBOL_CONTEXT = 12,                   /* CONTEXT  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_DEFER = 14,                     /* DEFER  */
  YYSYMBOL_DISTINCT = 15,                  /* DISTINCT  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_DYNAMIC = 17,                   /* DYNAMIC  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_ENUM = 19,                      /* ENUM  */
  YYSYMBOL_FALLTHROUGH = 20,               /* FALLTHROUGH  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_FOREIGN = 22,                   /* FOREIGN  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_IMPORT = 24,                    /* IMPORT  */
  YYSYMBOL_IN = 25,                        /* IN  */
  YYSYMBOL_MAP = 26,                       /* MAP  */
  YYSYMBOL_MATRIX = 27,                    /* MATRIX  */
  YYSYMBOL_NOT_IN = 28,                    /* NOT_IN  */
  YYSYMBOL_OR_BREAK = 29,                  /* OR_BREAK  */
  YYSYMBOL_OR_CONTINUE = 30,               /* OR_CONTINUE  */
  YYSYMBOL_OR_ELSE = 31,                   /* OR_ELSE  */
  YYSYMBOL_OR_RETURN = 32,                 /* OR_RETURN  */
  YYSYMBOL_PACKAGE = 33,                   /* PACKAGE  */
  YYSYMBOL_PROC = 34,                      /* PROC  */
  YYSYMBOL_RETURN = 35,                    /* RETURN  */
  YYSYMBOL_STRUCT = 36,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 37,                    /* SWITCH  */
  YYSYMBOL_TRANSMUTE = 38,                 /* TRANSMUTE  */
  YYSYMBOL_TYPEID = 39,                    /* TYPEID  */
  YYSYMBOL_UNION = 40,                     /* UNION  */
  YYSYMBOL_USING = 41,                     /* USING  */
  YYSYMBOL_WHEN = 42,                      /* WHEN  */
  YYSYMBOL_WHERE = 43,                     /* WHERE  */
  YYSYMBOL_BOOL = 44,                      /* BOOL  */
  YYSYMBOL_B8 = 45,                        /* B8  */
  YYSYMBOL_B16 = 46,                       /* B16  */
  YYSYMBOL_B32 = 47,                       /* B32  */
  YYSYMBOL_B64 = 48,                       /* B64  */
  YYSYMBOL_INT = 49,                       /* INT  */
  YYSYMBOL_I8 = 50,                        /* I8  */
  YYSYMBOL_I16 = 51,                       /* I16  */
  YYSYMBOL_I32 = 52,                       /* I32  */
  YYSYMBOL_I64 = 53,                       /* I64  */
  YYSYMBOL_I128 = 54,                      /* I128  */
  YYSYMBOL_UINT = 55,                      /* UINT  */
  YYSYMBOL_U8 = 56,                        /* U8  */
  YYSYMBOL_U16 = 57,                       /* U16  */
  YYSYMBOL_U32 = 58,                       /* U32  */
  YYSYMBOL_U64 = 59,                       /* U64  */
  YYSYMBOL_U128 = 60,                      /* U128  */
  YYSYMBOL_UINTPTR = 61,                   /* UINTPTR  */
  YYSYMBOL_F16 = 62,                       /* F16  */
  YYSYMBOL_F32 = 63,                       /* F32  */
  YYSYMBOL_F64 = 64,                       /* F64  */
  YYSYMBOL_COMPLEX32 = 65,                 /* COMPLEX32  */
  YYSYMBOL_COMPLEX64 = 66,                 /* COMPLEX64  */
  YYSYMBOL_COMPLEX128 = 67,                /* COMPLEX128  */
  YYSYMBOL_QUATERNION64 = 68,              /* QUATERNION64  */
  YYSYMBOL_QUATERNION128 = 69,             /* QUATERNION128  */
  YYSYMBOL_QUATERNION256 = 70,             /* QUATERNION256  */
  YYSYMBOL_STRING = 71,                    /* STRING  */
  YYSYMBOL_CSTRING = 72,                   /* CSTRING  */
  YYSYMBOL_BYTE = 73,                      /* BYTE  */
  YYSYMBOL_RUNE = 74,                      /* RUNE  */
  YYSYMBOL_RAWPTR = 75,                    /* RAWPTR  */
  YYSYMBOL_ANY = 76,                       /* ANY  */
  YYSYMBOL_INT_LIT = 77,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 78,                 /* FLOAT_LIT  */
  YYSYMBOL_ID = 79,                        /* ID  */
  YYSYMBOL_STRING_LIT = 80,                /* STRING_LIT  */
  YYSYMBOL_RAW_STRING_LIT = 81,            /* RAW_STRING_LIT  */
  YYSYMBOL_IMAGINARY_LIT = 82,             /* IMAGINARY_LIT  */
  YYSYMBOL_RUNE_LIT = 83,                  /* RUNE_LIT  */
  YYSYMBOL_NIL = 84,                       /* NIL  */
  YYSYMBOL_UNDEFINED = 85,                 /* UNDEFINED  */
  YYSYMBOL_ATTRIBUTE = 86,                 /* ATTRIBUTE  */
  YYSYMBOL_BUILD_DIRECTIVE = 87,           /* BUILD_DIRECTIVE  */
  YYSYMBOL_DIRECTIVE = 88,                 /* DIRECTIVE  */
  YYSYMBOL_AT = 89,                        /* AT  */
  YYSYMBOL_OP_ADD_ASSIGN = 90,             /* OP_ADD_ASSIGN  */
  YYSYMBOL_OP_SUB_ASSIGN = 91,             /* OP_SUB_ASSIGN  */
  YYSYMBOL_OP_MUL_ASSIGN = 92,             /* OP_MUL_ASSIGN  */
  YYSYMBOL_OP_DIV_ASSIGN = 93,             /* OP_DIV_ASSIGN  */
  YYSYMBOL_OP_MOD_ASSIGN = 94,             /* OP_MOD_ASSIGN  */
  YYSYMBOL_OP_MOD2_ASSIGN = 95,            /* OP_MOD2_ASSIGN  */
  YYSYMBOL_OP_OR_ASSIGN = 96,              /* OP_OR_ASSIGN  */
  YYSYMBOL_OP_NOT_ASSIGN = 97,             /* OP_NOT_ASSIGN  */
  YYSYMBOL_OP_AND_ASSIGN = 98,             /* OP_AND_ASSIGN  */
  YYSYMBOL_OP_AND_NOT_ASSIGN = 99,         /* OP_AND_NOT_ASSIGN  */
  YYSYMBOL_OP_SHL_ASSIGN = 100,            /* OP_SHL_ASSIGN  */
  YYSYMBOL_OP_SHR_ASSIGN = 101,            /* OP_SHR_ASSIGN  */
  YYSYMBOL_OP_LOG_AND_ASSIGN = 102,        /* OP_LOG_AND_ASSIGN  */
  YYSYMBOL_OP_LOG_OR_ASSIGN = 103,         /* OP_LOG_OR_ASSIGN  */
  YYSYMBOL_OP_LOG_AND = 104,               /* OP_LOG_AND  */
  YYSYMBOL_OP_LOG_OR = 105,                /* OP_LOG_OR  */
  YYSYMBOL_OP_AND_NOT = 106,               /* OP_AND_NOT  */
  YYSYMBOL_OP_SHL = 107,                   /* OP_SHL  */
  YYSYMBOL_OP_SHR = 108,                   /* OP_SHR  */
  YYSYMBOL_OP_EQ = 109,                    /* OP_EQ  */
  YYSYMBOL_OP_NE = 110,                    /* OP_NE  */
  YYSYMBOL_OP_LE = 111,                    /* OP_LE  */
  YYSYMBOL_OP_GE = 112,                    /* OP_GE  */
  YYSYMBOL_OP_RANGE = 113,                 /* OP_RANGE  */
  YYSYMBOL_OP_RANGE_INCLUSIVE = 114,       /* OP_RANGE_INCLUSIVE  */
  YYSYMBOL_OP_RANGE_EXCLUSIVE = 115,       /* OP_RANGE_EXCLUSIVE  */
  YYSYMBOL_OP_ARROW = 116,                 /* OP_ARROW  */
  YYSYMBOL_OP_DECL_TYPED = 117,            /* OP_DECL_TYPED  */
  YYSYMBOL_OP_DECL_INFERRED = 118,         /* OP_DECL_INFERRED  */
  YYSYMBOL_OP_MOD2 = 119,                  /* OP_MOD2  */
  YYSYMBOL_OP_DOLLAR = 120,                /* OP_DOLLAR  */
  YYSYMBOL_LEX_ERROR = 121,                /* LEX_ERROR  */
  YYSYMBOL_122_ = 122,                     /* '?'  */
  YYSYMBOL_123_ = 123,                     /* '<'  */
  YYSYMBOL_124_ = 124,                     /* '>'  */
  YYSYMBOL_125_ = 125,                     /* '+'  */
  YYSYMBOL_126_ = 126,                     /* '-'  */
  YYSYMBOL_127_ = 127,                     /* '|'  */
  YYSYMBOL_128_ = 128,                     /* '~'  */
  YYSYMBOL_129_ = 129,                     /* '*'  */
  YYSYMBOL_130_ = 130,                     /* '/'  */
  YYSYMBOL_131_ = 131,                     /* '%'  */
  YYSYMBOL_132_ = 132,                     /* '&'  */
  YYSYMBOL_UNARY = 133,                    /* UNARY  */
  YYSYMBOL_134_ = 134,                     /* '('  */
  YYSYMBOL_135_ = 135,                     /* '['  */
  YYSYMBOL_136_ = 136,                     /* '.'  */
  YYSYMBOL_137_ = 137,                     /* '^'  */
  YYSYMBOL_138_ = 138,                     /* ')'  */
  YYSYMBOL_139_ = 139,                     /* '{'  */
  YYSYMBOL_140_ = 140,                     /* '}'  */
  YYSYMBOL_141_ = 141,                     /* ','  */
  YYSYMBOL_142_ = 142,                     /* ':'  */
  YYSYMBOL_143_ = 143,                     /* '='  */
  YYSYMBOL_144_ = 144,                     /* ']'  */
  YYSYMBOL_145_ = 145,                     /* ';'  */
  YYSYMBOL_146_ = 146,                     /* '!'  */
  YYSYMBOL_YYACCEPT = 147,                 /* $accept  */
  YYSYMBOL_program = 148,                  /* program  */
  YYSYMBOL_package_clause = 149,           /* package_clause  */
  YYSYMBOL_import_list = 150,              /* import_list  */
  YYSYMBOL_import_decl = 151,              /* import_decl  */
  YYSYMBOL_decl_list = 152,                /* decl_list  */
  YYSYMBOL_decl = 153,                     /* decl  */
  YYSYMBOL_proc_decl = 154,                /* proc_decl  */
  YYSYMBOL_param_list_opt = 155,           /* param_list_opt  */
  YYSYMBOL_param_list = 156,               /* param_list  */
  YYSYMBOL_param = 157,                    /* param  */
  YYSYMBOL_id_list = 158,                  /* id_list  */
  YYSYMBOL_return_type = 159,              /* return_type  */
  YYSYMBOL_var_decl = 160,                 /* var_decl  */
  YYSYMBOL_const_decl = 161,               /* const_decl  */
  YYSYMBOL_type_decl = 162,                /* type_decl  */
  YYSYMBOL_type_expr = 163,                /* type_expr  */
  YYSYMBOL_type_core = 164,                /* type_core  */
  YYSYMBOL_field_list_opt = 165,           /* field_list_opt  */
  YYSYMBOL_field_list = 166,               /* field_list  */
  YYSYMBOL_field_decl = 167,               /* field_decl  */
  YYSYMBOL_foreign_decl = 168,             /* foreign_decl  */
  YYSYMBOL_base_type = 169,                /* base_type  */
  YYSYMBOL_type_list = 170,                /* type_list  */
  YYSYMBOL_enum_body_opt = 171,            /* enum_body_opt  */
  YYSYMBOL_enum_body = 172,                /* enum_body  */
  YYSYMBOL_enum_item = 173,                /* enum_item  */
  YYSYMBOL_block = 174,                    /* block  */
  YYSYMBOL_stmt_list = 175,                /* stmt_list  */
  YYSYMBOL_stmt = 176,                     /* stmt  */
  YYSYMBOL_simple_stmt = 177,              /* simple_stmt  */
  YYSYMBOL_if_stmt = 178,                  /* if_stmt  */
  YYSYMBOL_for_stmt = 179,                 /* for_stmt  */
  YYSYMBOL_switch_stmt = 180,              /* switch_stmt  */
  YYSYMBOL_switch_body = 181,              /* switch_body  */
  YYSYMBOL_case_list = 182,                /* case_list  */
  YYSYMBOL_case_clause = 183,              /* case_clause  */
  YYSYMBOL_expr_list = 184,                /* expr_list  */
  YYSYMBOL_when_stmt = 185,                /* when_stmt  */
  YYSYMBOL_return_stmt = 186,              /* return_stmt  */
  YYSYMBOL_defer_stmt = 187,               /* defer_stmt  */
  YYSYMBOL_expr = 188,                     /* expr  */
  YYSYMBOL_arg_list_op = 189,              /* arg_list_op  */
  YYSYMBOL_arg_list = 190                  /* arg_list  */
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
#define YYLAST   2842

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  404

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   377


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
       2,     2,     2,   146,     2,     2,     2,   131,   132,     2,
     134,   138,   129,   125,   141,   126,   136,   130,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   142,   145,
     123,   143,   124,   122,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   135,     2,   144,   137,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   139,   127,   140,   128,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   133
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    68,    71,    73,    77,    80,    82,    86,
      87,    88,    89,    90,    98,    99,   102,   104,   108,   109,
     113,   117,   118,   121,   122,   123,   132,   133,   134,   142,
     143,   151,   155,   156,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   180,   182,
     186,   187,   191,   199,   200,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   240,   241,
     244,   246,   250,   251,   255,   256,   260,   263,   264,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   287,   288,   289,   290,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   310,
     311,   312,   313,   314,   315,   326,   327,   329,   330,   332,
     334,   335,   336,   337,   344,   345,   346,   347,   351,   354,
     356,   364,   365,   369,   370,   374,   375,   376,   383,   384,
     392,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   410,   411,   412,   413,   414,   415,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   440,
     441,   442,   443,   446,   447,   448,   451,   452,   453,   455,
     457,   458,   459,   463,   466,   470,   471,   474,   475
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
  "\"end of file\"", "error", "\"invalid token\"", "TRUE", "FALSE", "ASM",
  "AUTO_CAST", "BIT_FIELD", "BIT_SET", "BREAK", "CASE", "CAST", "CONTEXT",
  "CONTINUE", "DEFER", "DISTINCT", "DO", "DYNAMIC", "ELSE", "ENUM",
  "FALLTHROUGH", "FOR", "FOREIGN", "IF", "IMPORT", "IN", "MAP", "MATRIX",
  "NOT_IN", "OR_BREAK", "OR_CONTINUE", "OR_ELSE", "OR_RETURN", "PACKAGE",
  "PROC", "RETURN", "STRUCT", "SWITCH", "TRANSMUTE", "TYPEID", "UNION",
  "USING", "WHEN", "WHERE", "BOOL", "B8", "B16", "B32", "B64", "INT", "I8",
  "I16", "I32", "I64", "I128", "UINT", "U8", "U16", "U32", "U64", "U128",
  "UINTPTR", "F16", "F32", "F64", "COMPLEX32", "COMPLEX64", "COMPLEX128",
  "QUATERNION64", "QUATERNION128", "QUATERNION256", "STRING", "CSTRING",
  "BYTE", "RUNE", "RAWPTR", "ANY", "INT_LIT", "FLOAT_LIT", "ID",
  "STRING_LIT", "RAW_STRING_LIT", "IMAGINARY_LIT", "RUNE_LIT", "NIL",
  "UNDEFINED", "ATTRIBUTE", "BUILD_DIRECTIVE", "DIRECTIVE", "AT",
  "OP_ADD_ASSIGN", "OP_SUB_ASSIGN", "OP_MUL_ASSIGN", "OP_DIV_ASSIGN",
  "OP_MOD_ASSIGN", "OP_MOD2_ASSIGN", "OP_OR_ASSIGN", "OP_NOT_ASSIGN",
  "OP_AND_ASSIGN", "OP_AND_NOT_ASSIGN", "OP_SHL_ASSIGN", "OP_SHR_ASSIGN",
  "OP_LOG_AND_ASSIGN", "OP_LOG_OR_ASSIGN", "OP_LOG_AND", "OP_LOG_OR",
  "OP_AND_NOT", "OP_SHL", "OP_SHR", "OP_EQ", "OP_NE", "OP_LE", "OP_GE",
  "OP_RANGE", "OP_RANGE_INCLUSIVE", "OP_RANGE_EXCLUSIVE", "OP_ARROW",
  "OP_DECL_TYPED", "OP_DECL_INFERRED", "OP_MOD2", "OP_DOLLAR", "LEX_ERROR",
  "'?'", "'<'", "'>'", "'+'", "'-'", "'|'", "'~'", "'*'", "'/'", "'%'",
  "'&'", "UNARY", "'('", "'['", "'.'", "'^'", "')'", "'{'", "'}'", "','",
  "':'", "'='", "']'", "';'", "'!'", "$accept", "program",
  "package_clause", "import_list", "import_decl", "decl_list", "decl",
  "proc_decl", "param_list_opt", "param_list", "param", "id_list",
  "return_type", "var_decl", "const_decl", "type_decl", "type_expr",
  "type_core", "field_list_opt", "field_list", "field_decl",
  "foreign_decl", "base_type", "type_list", "enum_body_opt", "enum_body",
  "enum_item", "block", "stmt_list", "stmt", "simple_stmt", "if_stmt",
  "for_stmt", "switch_stmt", "switch_body", "case_list", "case_clause",
  "expr_list", "when_stmt", "return_stmt", "defer_stmt", "expr",
  "arg_list_op", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-354)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-154)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,   -20,    60,  -354,  -354,  -354,    37,   -18,  -354,    -3,
    -354,   -19,   -95,  -354,  -354,   -93,  -354,  -354,  -354,  -354,
     -16,  -354,  -354,   345,  1043,   929,   -15,  1043,   -13,   550,
    -354,  -354,   929,   -70,   -66,  1043,   -68,   -63,   -62,  -103,
     -65,   -59,   -61,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,     7,  -354,
    -354,  -354,  -354,  -354,  -354,   929,   929,   929,   929,   449,
     733,  1043,   929,  -354,  -354,  -354,  2585,   -57,  -354,  1043,
     -73,  -354,   929,  2585,  -354,   -64,  -354,     9,    11,   650,
    -354,   540,   939,   929,   748,   929,   929,   -90,   650,  -354,
     -88,  -354,  -354,  -354,  -354,  -354,  -354,  -108,  -354,  -354,
    -354,  1876,    64,  1043,  1043,  -354,    12,  1043,   929,    13,
      13,    13,  1043,    13,    64,    64,    64,    64,  -354,  -104,
    2440,   -49,  1043,  1676,  -354,    64,   929,  -354,  -354,   929,
    -354,   929,   929,   929,   929,   929,   929,   929,   929,   929,
     929,   929,   929,   929,   929,   929,   929,   929,   929,   929,
     929,   929,   929,   929,   929,   929,   929,   929,    19,  -354,
      13,   929,   929,  -354,  -354,  -354,   -86,  -354,   -46,  1200,
     -44,  1407,  2585,  -354,   -43,  -354,  1524,  2585,  2289,   650,
    -354,   929,  1043,   929,   929,   929,   929,   929,   929,   929,
     929,   929,   929,   929,  1043,   -41,   -34,   -38,   -23,   -22,
    -354,   -26,  2174,  -354,   -14,    -9,  -354,  -101,   -97,   -96,
     -17,    -4,  -354,   -10,     1,  -354,  1043,  -354,  1043,  -354,
    1043,  1991,  2528,  2025,  2705,  2673,    64,    64,    64,  1288,
    1288,  1288,  1288,  2637,  2637,  2637,    64,  2135,  1288,  1288,
    1114,  1114,  1114,  1114,    64,    64,    64,    64,  2585,    -8,
       2,  1717,  -354,    -2,  2585,  2585,   929,   939,   929,   929,
    -354,   929,   104,    -6,   763,  -354,   107,  -354,     5,  2585,
    -354,  2585,     5,  2585,  2585,  2585,  2585,  2585,  2585,  2585,
    2585,  2585,    40,  -354,   929,   929,  -354,    12,  1043,   929,
      34,    13,  1043,  -354,  1043,  -354,    13,   929,  -354,  -354,
    -354,  -354,   929,   929,   929,  -354,   929,  -354,    34,  1566,
    -354,  1240,  2475,  2289,   -12,   846,  -354,  -354,  -354,  2325,
     -25,   929,    64,  2585,  -354,  -354,  1827,  1139,    14,  -354,
    -354,  -354,  -354,    64,  2585,  2585,  2585,  2585,  -354,   939,
     939,  -354,   929,   108,  -354,  -354,  -354,   -84,  -354,  -354,
    -354,  2585,  1043,  1043,  -354,  -354,    10,  -354,  1357,   -12,
     650,  -354,  -354,   -99,   939,  -354,   939,  -354,  -354,  -354,
     650,  -354,  -354,  -354
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     3,     1,     7,     0,     5,     2,
       6,     0,    21,     8,     9,     0,    10,    11,    12,    13,
       0,    97,    54,     0,     0,     0,     0,     0,     0,     0,
     170,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,   162,   163,   161,   164,
     165,   166,   167,   168,   169,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    33,    34,    29,     0,    32,     0,
       0,   161,     0,    28,    22,    27,    53,   108,   110,     0,
     112,     0,     0,   158,     0,     0,     0,   161,     0,    96,
       0,   100,    98,    99,   101,   102,   103,     0,   104,   105,
     106,   128,   178,     0,     0,    46,    90,     0,     0,    16,
       0,    48,     0,    48,   173,   174,   176,   177,    88,     0,
       0,     0,     0,     0,    35,   175,     0,   208,   209,     0,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   215,     0,     0,   206,
      16,     0,     0,   109,   111,   160,   161,   135,     0,   128,
       0,   153,   159,   149,     0,   144,   153,   114,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,    91,
      92,     0,     0,    21,     0,    17,    18,     0,     0,     0,
       0,    49,    50,     0,     0,    41,     0,   172,     0,    36,
       0,     0,   199,     0,   180,   179,   196,   197,   198,   181,
     182,   185,   186,   200,   201,   202,   194,     0,   183,   184,
     187,   188,   189,   190,   191,   192,   193,   195,   217,     0,
     216,     0,   212,     0,    30,    26,     0,     0,     0,     0,
     136,     0,   129,     0,     0,   145,   155,   107,   116,   153,
     118,   154,   115,   119,   120,   121,   122,   123,   125,   124,
     126,   127,     0,    45,     0,     0,    43,     0,     0,     0,
      23,     0,     0,    15,     0,    42,     0,     0,    44,    89,
      38,    37,     0,     0,     0,   210,     0,   211,    23,     0,
     140,     0,     0,     0,     0,     0,   148,   150,   147,     0,
       0,     0,   213,    95,    93,    39,     0,     0,    40,    19,
      20,    52,    51,   214,   205,   204,   203,   218,    40,     0,
       0,   137,     0,   132,   130,   131,    97,     0,   146,   157,
     156,   117,     0,     0,    24,    14,     0,   141,     0,     0,
     152,    97,    47,     0,     0,   139,     0,   138,   133,   134,
     151,    25,   143,   142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,   -55,  -354,
    -192,    -1,  -186,  -354,  -354,  -354,   -21,  -354,    41,  -354,
    -171,  -354,  -354,  -191,  -354,  -354,  -124,   -11,  -353,   -94,
    -102,  -323,  -354,  -354,  -205,  -354,  -354,  -198,  -156,  -354,
    -354,    -5,  -354,  -354
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     6,     8,     9,    13,    14,   234,   235,
     236,   120,   358,    16,    17,    18,   148,    94,   240,   241,
     242,    19,    95,   149,   228,   229,   230,   121,    29,   122,
     123,   124,   125,   126,   205,   293,   347,   127,   128,   129,
     130,   131,   279,   280
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,   295,    93,   100,   345,    20,   105,   -32,    15,   198,
     200,   112,   204,   298,   135,   195,   302,   116,    96,    11,
     103,   375,    23,   390,   210,    25,   394,   132,   -21,   -32,
     211,   139,   -21,   213,   245,   214,   140,   246,   400,   401,
      26,   322,   246,   323,    26,    26,   324,    24,    26,    27,
       1,   -21,   209,    26,   212,   -21,   -21,   213,   391,     4,
       5,     7,    10,    28,   104,   133,   399,   106,   134,   191,
     154,   136,   137,   138,   141,   142,    12,   190,   143,   192,
     144,   145,   146,   147,   150,   153,   -32,   155,   193,   348,
     194,   227,   233,   157,   158,   248,   160,   150,   282,   286,
     197,   291,   294,   313,   314,   315,   199,   201,   202,   206,
     207,   208,   225,   226,    21,   297,   231,   316,   318,   317,
      21,   243,   344,   325,   320,   350,   389,    21,   327,   359,
     335,   249,   321,   232,   346,   283,   338,   326,   237,   238,
     239,   328,   239,   336,   378,   -32,   213,   377,   -32,    21,
     357,   251,   368,    21,   252,   362,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   281,   351,   244,   340,   284,   285,   290,   237,
     292,   300,   393,   354,   380,     0,     0,   296,   186,   187,
     188,   189,     0,   312,     0,     0,   299,     0,   301,   299,
     303,   304,   305,   306,   307,   308,   309,   310,   311,     0,
       0,     0,     0,     0,     0,   329,     0,   330,     0,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   386,   387,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   339,     0,   341,   342,     0,   343,     0,     0,   349,
       0,     0,   402,     0,   403,     0,     0,   355,     0,     0,
       0,   360,     0,   361,     0,     0,     0,     0,     0,   352,
     353,     0,     0,     0,   356,     0,     0,     0,     0,     0,
     237,     0,   363,     0,     0,   239,     0,   364,   365,   366,
     371,   367,   373,   374,     0,     0,   384,     0,     0,   379,
     299,     0,     0,     0,     0,     0,   381,   385,    30,    31,
       0,    32,     0,    33,     0,     0,    34,     0,     0,     0,
      35,   392,     0,     0,    36,     0,     0,   388,     0,     0,
       0,    37,    38,     0,     0,   395,     0,   397,   398,    39,
       0,    40,     0,    41,     0,    42,     0,     0,     0,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    31,     0,    32,     0,    33,     0,     0,
      34,     0,     0,     0,    35,     0,     0,     0,    36,     0,
      85,    86,     0,    87,     0,    37,    38,    88,     0,    89,
      90,     0,    91,    97,     0,    40,     0,    41,     0,    42,
       0,    92,     0,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    31,     0,    32,     0,     0,     0,
       0,    34,     0,    30,    31,     0,    32,     0,     0,   107,
       0,    34,     0,   108,   109,     0,     0,     0,     0,     0,
     110,   111,     0,   112,    85,    86,     0,    87,    41,     0,
       0,    88,     0,    89,    90,   113,    91,   114,    41,     0,
       0,   115,   116,     0,     0,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,   196,
      79,    80,    81,    82,    83,    84,     0,    76,    77,   117,
      79,    80,    81,    82,    83,    84,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    31,     0,    32,     0,     0,   107,
       0,    34,     0,   108,   109,    85,    86,     0,    87,     0,
     110,   111,    88,   112,   102,    85,    86,     0,    87,    21,
       0,     0,    88,     0,   102,   113,    92,   114,    41,    21,
     119,   115,   116,     0,     0,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,   117,
      79,    80,    81,    82,    83,    84,    30,    31,   118,    32,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
     151,    30,    31,     0,    32,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,    30,    31,     0,    32,
       0,    41,     0,     0,    34,    85,    86,     0,    87,     0,
       0,     0,    88,     0,   102,     0,    41,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    92,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,   101,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,    76,    77,   196,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
      76,    77,   101,    79,    80,    81,    82,    83,    84,    30,
      31,     0,    32,     0,     0,     0,     0,    34,    85,    86,
       0,    87,     0,     0,     0,    88,     0,   102,     0,     0,
       0,     0,     0,    85,    86,     0,    87,   152,     0,    92,
      88,     0,   102,     0,    41,     0,     0,   203,    85,    86,
       0,    87,     0,     0,    92,    88,     0,   102,     0,     0,
       0,     0,   203,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    77,   101,    79,    80,    81,    82,
      83,    84,    30,    31,     0,    32,     0,     0,     0,     0,
      34,     0,    30,    31,     0,    32,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    85,    86,     0,    87,     0,     0,    41,    88,     0,
     102,     0,     0,     0,     0,     0,     0,     0,   376,     0,
       0,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,    77,   101,    79,
      80,    81,    82,    83,    84,     0,    76,    77,   196,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,     0,     0,    85,    86,     0,    87,    35,     0,
       0,    88,    36,   102,    85,    86,     0,    87,     0,    37,
      38,    88,     0,   102,     0,    92,     0,    97,     0,    40,
       0,     0,     0,    42,     0,    92,     0,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,     0,   160,    33,     0,     0,
       0,     0,     0,     0,    35,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,     0,    97,     0,    40,     0,    99,    90,    42,
      91,     0,     0,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,   287,     0,    98,     0,
     164,   165,   166,   156,     0,   288,     0,     0,     0,   157,
     158,   159,   160,   174,     0,     0,     0,     0,     0,     0,
       0,     0,   161,   182,   183,   184,   185,     0,   186,   187,
     188,   189,     0,     0,     0,     0,   370,     0,     0,     0,
       0,     0,     0,   156,     0,     0,     0,     0,     0,   157,
     158,   159,   160,   383,    90,     0,    91,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
     215,   216,   217,   218,   219,     0,   220,     0,   221,     0,
     222,   223,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,   157,   158,   174,
     160,     0,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   189,     0,    21,
       0,   289,   224,  -153,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,     0,   174,
       0,     0,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   396,   186,   187,   188,   189,     0,    21,
     156,     0,     0,     0,     0,     0,   157,   158,   159,   160,
       0,     0,     0,     0,   164,   165,   166,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,   189,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,   157,   158,   159,   160,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,   174,     0,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   189,     0,    21,   215,   216,   217,
     218,   219,     0,   220,     0,   221,     0,   222,   223,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,   174,     0,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   189,     0,    21,   156,     0,   224,
       0,     0,  -128,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   156,
       0,     0,     0,     0,     0,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,   215,   216,   217,   218,   219,     0,
     220,     0,   221,     0,   222,   223,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,     0,   174,     0,     0,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   189,     0,   203,     0,     0,   224,     0,     0,  -128,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,   174,     0,     0,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   156,
     186,   187,   188,   189,     0,   157,   158,   159,   160,     0,
       0,   369,     0,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,   157,   158,   159,   160,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,   174,     0,     0,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,   189,     0,     0,     0,     0,     0,     0,
     250,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,   174,     0,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     156,   186,   187,   188,   189,     0,   157,   158,   159,   160,
       0,   337,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   156,
       0,     0,     0,     0,     0,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,   174,     0,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   189,     0,   215,   216,   217,   218,
     219,   382,   220,     0,   221,     0,   222,   223,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,   174,     0,     0,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   332,
     186,   187,   188,   189,   156,     0,     0,  -153,   224,  -153,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   333,     0,     0,     0,     0,   156,     0,
       0,     0,     0,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,     0,
     174,     0,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,   189,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,   174,     0,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   156,   186,
     187,   188,   189,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,   174,     0,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,   189,     0,     0,     0,     0,   334,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,     0,   174,     0,     0,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   189,   156,     0,     0,   319,     0,     0,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
       0,     0,     0,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,     0,   174,     0,
       0,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,   189,     0,    21,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,   174,     0,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,   189,   156,   203,     0,     0,     0,     0,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
     372,     0,     0,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,   157,   158,   174,
     160,     0,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   189,   247,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,   174,     0,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   156,   186,
     187,   188,   189,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,     0,   174,     0,     0,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,   189,   157,   158,     0,   160,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,   157,   158,   174,   160,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,   189,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,     0,   160,     0,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   189,     0,     0,   162,     0,   164,
     165,   166,   167,   168,   169,   170,     0,     0,     0,     0,
       0,     0,   174,     0,     0,     0,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     189,   164,   165,   166,   167,   168,   169,   170,     0,     0,
       0,     0,     0,     0,   174,     0,     0,     0,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,   189
};

static const yytype_int16 yycheck[] =
{
      11,   206,    23,    24,    10,    24,    27,     0,     9,   111,
     112,    23,   114,   211,    35,   109,   214,    42,    23,    22,
      25,   344,   117,   376,   118,   118,    16,    32,   118,    22,
     118,   134,   118,   141,   138,   143,   139,   141,   391,   138,
     141,   142,   141,   140,   141,   141,   142,   142,   141,   142,
      33,   141,   142,   141,   142,   141,   142,   141,   142,    79,
       0,    24,    80,    79,    79,   135,   389,    80,   134,   142,
      91,   139,   135,   135,   139,   134,    79,   134,   139,   143,
      85,    86,    87,    88,    89,    90,    79,    92,    79,   294,
      79,    79,    79,    29,    30,   144,    32,   102,    79,   145,
     111,   145,   145,   144,   138,   143,   111,   112,   113,   114,
     115,   116,   133,   134,   139,   209,   137,   140,   144,   141,
     139,   142,    18,   140,   138,    18,    18,   139,   138,   321,
     138,   152,   141,   138,   140,   190,   138,   141,   139,   140,
     141,   140,   143,   141,   349,   138,   141,   345,   141,   139,
     116,   156,   338,   139,   159,   326,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   143,   143,   287,   191,   192,   199,   190,
     201,   212,   383,   317,   350,    -1,    -1,   208,   134,   135,
     136,   137,    -1,   224,    -1,    -1,   211,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
      -1,    -1,    -1,    -1,    -1,   246,    -1,   248,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,   370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   286,    -1,   288,   289,    -1,   291,    -1,    -1,   294,
      -1,    -1,   394,    -1,   396,    -1,    -1,   318,    -1,    -1,
      -1,   322,    -1,   324,    -1,    -1,    -1,    -1,    -1,   314,
     315,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,
     321,    -1,   327,    -1,    -1,   326,    -1,   332,   333,   334,
     341,   336,   343,   344,    -1,    -1,   357,    -1,    -1,   350,
     345,    -1,    -1,    -1,    -1,    -1,   351,   358,     3,     4,
      -1,     6,    -1,     8,    -1,    -1,    11,    -1,    -1,    -1,
      15,   382,    -1,    -1,    19,    -1,    -1,   372,    -1,    -1,
      -1,    26,    27,    -1,    -1,   386,    -1,   388,   389,    34,
      -1,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,     6,    -1,     8,    -1,    -1,
      11,    -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    -1,
     125,   126,    -1,   128,    -1,    26,    27,   132,    -1,   134,
     135,    -1,   137,    34,    -1,    36,    -1,    38,    -1,    40,
      -1,   146,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,     6,    -1,    -1,    -1,
      -1,    11,    -1,     3,     4,    -1,     6,    -1,    -1,     9,
      -1,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      20,    21,    -1,    23,   125,   126,    -1,   128,    38,    -1,
      -1,   132,    -1,   134,   135,    35,   137,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,     6,    -1,    -1,     9,
      -1,    11,    -1,    13,    14,   125,   126,    -1,   128,    -1,
      20,    21,   132,    23,   134,   125,   126,    -1,   128,   139,
      -1,    -1,   132,    -1,   134,    35,   146,    37,    38,   139,
     140,    41,    42,    -1,    -1,    -1,   146,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     3,     4,    88,     6,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,     3,     4,    -1,     6,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,     6,
      -1,    38,    -1,    -1,    11,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,    -1,   134,    -1,    38,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     3,
       4,    -1,     6,    -1,    -1,    -1,    -1,    11,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,    -1,   134,    -1,    -1,
      -1,    -1,    -1,   125,   126,    -1,   128,   144,    -1,   146,
     132,    -1,   134,    -1,    38,    -1,    -1,   139,   125,   126,
      -1,   128,    -1,    -1,   146,   132,    -1,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     3,     4,    -1,     6,    -1,    -1,    -1,    -1,
      11,    -1,     3,     4,    -1,     6,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,   125,   126,    -1,   128,    -1,    -1,    38,   132,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,   125,   126,    -1,   128,    15,    -1,
      -1,   132,    19,   134,   125,   126,    -1,   128,    -1,    26,
      27,   132,    -1,   134,    -1,   146,    -1,    34,    -1,    36,
      -1,    -1,    -1,    40,    -1,   146,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    32,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    36,    -1,   134,   135,    40,
     137,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    16,    -1,    79,    -1,
     106,   107,   108,    23,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,    32,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,   129,   130,   131,   132,    -1,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,   134,   135,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    -1,    96,    -1,    98,    -1,
     100,   101,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    29,    30,   119,
      32,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,   134,   135,   136,   137,    -1,   139,
      -1,   141,   142,   143,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    16,   134,   135,   136,   137,    -1,   139,
      23,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,   137,    -1,   139,    90,    91,    92,
      93,    94,    -1,    96,    -1,    98,    -1,   100,   101,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,   137,    -1,   139,    23,    -1,   142,
      -1,    -1,   145,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    -1,
      96,    -1,    98,    -1,   100,   101,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,   119,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,   137,    -1,   139,    -1,    -1,   142,    -1,    -1,   145,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    23,
     134,   135,   136,   137,    -1,    29,    30,    31,    32,    -1,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      23,   134,   135,   136,   137,    -1,    29,    30,    31,    32,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,   137,    -1,    90,    91,    92,    93,
      94,   144,    96,    -1,    98,    -1,   100,   101,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    18,
     134,   135,   136,   137,    23,    -1,    -1,   141,   142,   143,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
     119,    -1,    -1,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,   134,   135,   136,   137,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    23,   134,
     135,   136,   137,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,   142,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,   119,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,   137,    23,    -1,    -1,   141,    -1,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,   119,    -1,
      -1,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,   136,   137,    -1,   139,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,   134,
     135,   136,   137,    23,   139,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    29,    30,   119,
      32,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,   134,   135,   136,   137,   138,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    23,   134,
     135,   136,   137,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,   134,   135,   136,   137,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    29,    30,   119,    32,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    32,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,   137,    -1,    -1,   104,    -1,   106,
     107,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
     137,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,   134,
     135,   136,   137
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,   148,   149,    79,     0,   150,    24,   151,   152,
      80,    22,    79,   153,   154,   158,   160,   161,   162,   168,
      24,   139,   174,   117,   142,   118,   141,   142,    79,   175,
       3,     4,     6,     8,    11,    15,    19,    26,    27,    34,
      36,    38,    40,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   125,   126,   128,   132,   134,
     135,   137,   146,   163,   164,   169,   188,    34,    79,   134,
     163,    79,   134,   188,    79,   163,    80,     9,    13,    14,
      20,    21,    23,    35,    37,    41,    42,    79,    88,   140,
     158,   174,   176,   177,   178,   179,   180,   184,   185,   186,
     187,   188,   188,   135,   134,   163,   139,   135,   135,   134,
     139,   139,   134,   139,   188,   188,   188,   188,   163,   170,
     188,    17,   144,   188,   163,   188,    23,    29,    30,    31,
      32,    42,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   119,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   134,   135,   136,   137,
     134,   142,   143,    79,    79,   176,    79,   174,   177,   188,
     177,   188,   188,   139,   177,   181,   188,   188,   188,   142,
     176,   118,   142,   141,   143,    90,    91,    92,    93,    94,
      96,    98,   100,   101,   142,   163,   163,    79,   171,   172,
     173,   163,   188,    79,   155,   156,   157,   158,   158,   158,
     165,   166,   167,   163,   165,   138,   141,   138,   144,   163,
     144,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   189,
     190,   188,    79,   155,   188,   188,   145,    16,    25,   141,
     174,   145,   174,   182,   145,   181,   174,   176,   184,   188,
     163,   188,   184,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   163,   144,   138,   143,   140,   141,   144,   141,
     138,   141,   142,   140,   142,   140,   141,   138,   140,   163,
     163,   163,    18,    18,   142,   138,   141,   144,   138,   188,
     177,   188,   188,   188,    18,    10,   140,   183,   181,   188,
      18,   143,   188,   188,   173,   163,   188,   116,   159,   157,
     163,   163,   167,   188,   188,   188,   188,   188,   159,   145,
      16,   174,    25,   174,   174,   178,   142,   184,   181,   174,
     185,   188,   144,   134,   163,   174,   177,   177,   188,    18,
     175,   142,   163,   170,    16,   174,    16,   174,   174,   178,
     175,   138,   177,   177
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   147,   148,   149,   150,   150,   151,   152,   152,   153,
     153,   153,   153,   153,   154,   154,   155,   155,   156,   156,
     157,   158,   158,   159,   159,   159,   160,   160,   160,   161,
     161,   162,   163,   163,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   165,   165,
     166,   166,   167,   168,   168,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   170,   170,
     171,   171,   172,   172,   173,   173,   174,   175,   175,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   178,
     178,   178,   178,   178,   178,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   180,   180,   180,   180,   181,   182,
     182,   183,   183,   184,   184,   185,   185,   185,   186,   186,
     187,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   189,   189,   190,   190
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     0,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     8,     6,     0,     1,     1,     3,
       3,     1,     3,     0,     2,     4,     5,     3,     3,     3,
       5,     3,     1,     1,     1,     2,     3,     4,     4,     5,
       5,     3,     4,     4,     4,     4,     2,     7,     0,     1,
       1,     3,     3,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     1,     1,     3,     1,     3,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       1,     2,     1,     2,     2,     3,     3,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       5,     5,     5,     7,     7,     2,     3,     5,     7,     7,
       4,     6,     8,     8,     2,     3,     5,     4,     3,     0,
       2,     4,     3,     1,     3,     3,     5,     5,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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

#line 2428 "parser.tab.c"

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
    if (r == 0) printf("OK\n");
    return r;
}
