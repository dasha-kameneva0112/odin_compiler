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
  YYSYMBOL_QUESTION = 90,                  /* QUESTION  */
  YYSYMBOL_OP_ADD_ASSIGN = 91,             /* OP_ADD_ASSIGN  */
  YYSYMBOL_OP_SUB_ASSIGN = 92,             /* OP_SUB_ASSIGN  */
  YYSYMBOL_OP_MUL_ASSIGN = 93,             /* OP_MUL_ASSIGN  */
  YYSYMBOL_OP_DIV_ASSIGN = 94,             /* OP_DIV_ASSIGN  */
  YYSYMBOL_OP_MOD_ASSIGN = 95,             /* OP_MOD_ASSIGN  */
  YYSYMBOL_OP_MOD2_ASSIGN = 96,            /* OP_MOD2_ASSIGN  */
  YYSYMBOL_OP_OR_ASSIGN = 97,              /* OP_OR_ASSIGN  */
  YYSYMBOL_OP_NOT_ASSIGN = 98,             /* OP_NOT_ASSIGN  */
  YYSYMBOL_OP_AND_ASSIGN = 99,             /* OP_AND_ASSIGN  */
  YYSYMBOL_OP_AND_NOT_ASSIGN = 100,        /* OP_AND_NOT_ASSIGN  */
  YYSYMBOL_OP_SHL_ASSIGN = 101,            /* OP_SHL_ASSIGN  */
  YYSYMBOL_OP_SHR_ASSIGN = 102,            /* OP_SHR_ASSIGN  */
  YYSYMBOL_OP_LOG_AND_ASSIGN = 103,        /* OP_LOG_AND_ASSIGN  */
  YYSYMBOL_OP_LOG_OR_ASSIGN = 104,         /* OP_LOG_OR_ASSIGN  */
  YYSYMBOL_OP_LOG_AND = 105,               /* OP_LOG_AND  */
  YYSYMBOL_OP_LOG_OR = 106,                /* OP_LOG_OR  */
  YYSYMBOL_OP_AND_NOT = 107,               /* OP_AND_NOT  */
  YYSYMBOL_OP_SHL = 108,                   /* OP_SHL  */
  YYSYMBOL_OP_SHR = 109,                   /* OP_SHR  */
  YYSYMBOL_OP_EQ = 110,                    /* OP_EQ  */
  YYSYMBOL_OP_NE = 111,                    /* OP_NE  */
  YYSYMBOL_OP_LE = 112,                    /* OP_LE  */
  YYSYMBOL_OP_GE = 113,                    /* OP_GE  */
  YYSYMBOL_OP_RANGE = 114,                 /* OP_RANGE  */
  YYSYMBOL_OP_RANGE_INCLUSIVE = 115,       /* OP_RANGE_INCLUSIVE  */
  YYSYMBOL_OP_RANGE_EXCLUSIVE = 116,       /* OP_RANGE_EXCLUSIVE  */
  YYSYMBOL_OP_ARROW = 117,                 /* OP_ARROW  */
  YYSYMBOL_OP_DECL_TYPED = 118,            /* OP_DECL_TYPED  */
  YYSYMBOL_OP_DECL_INFERRED = 119,         /* OP_DECL_INFERRED  */
  YYSYMBOL_OP_MOD2 = 120,                  /* OP_MOD2  */
  YYSYMBOL_OP_DOLLAR = 121,                /* OP_DOLLAR  */
  YYSYMBOL_LEX_ERROR = 122,                /* LEX_ERROR  */
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
  YYSYMBOL_expr = 177,                     /* expr  */
  YYSYMBOL_arg_list_op = 178,              /* arg_list_op  */
  YYSYMBOL_arg_list = 179                  /* arg_list  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   845

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   378


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
     123,   143,   124,     2,     2,     2,     2,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   122,   133
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    62,    65,    67,    71,    74,    76,    80,
      81,    82,    83,    84,    92,    93,    96,    98,   102,   103,
     107,   111,   112,   115,   116,   117,   126,   127,   128,   136,
     137,   145,   149,   150,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   173,   175,   179,
     180,   184,   192,   193,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   233,   234,   237,
     239,   243,   244,   248,   249,   253,   256,   258,   263,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   280,   281,   282,   283,   284,   285,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   309,   310,   311,
     312,   316,   319,   323,   324,   327,   328
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
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
  "QUESTION", "OP_ADD_ASSIGN", "OP_SUB_ASSIGN", "OP_MUL_ASSIGN",
  "OP_DIV_ASSIGN", "OP_MOD_ASSIGN", "OP_MOD2_ASSIGN", "OP_OR_ASSIGN",
  "OP_NOT_ASSIGN", "OP_AND_ASSIGN", "OP_AND_NOT_ASSIGN", "OP_SHL_ASSIGN",
  "OP_SHR_ASSIGN", "OP_LOG_AND_ASSIGN", "OP_LOG_OR_ASSIGN", "OP_LOG_AND",
  "OP_LOG_OR", "OP_AND_NOT", "OP_SHL", "OP_SHR", "OP_EQ", "OP_NE", "OP_LE",
  "OP_GE", "OP_RANGE", "OP_RANGE_INCLUSIVE", "OP_RANGE_EXCLUSIVE",
  "OP_ARROW", "OP_DECL_TYPED", "OP_DECL_INFERRED", "OP_MOD2", "OP_DOLLAR",
  "LEX_ERROR", "'<'", "'>'", "'+'", "'-'", "'|'", "'~'", "'*'", "'/'",
  "'%'", "'&'", "UNARY", "'('", "'['", "'.'", "'^'", "')'", "'{'", "'}'",
  "','", "':'", "'='", "']'", "';'", "'!'", "$accept", "program",
  "package_clause", "import_list", "import_decl", "decl_list", "decl",
  "proc_decl", "param_list_opt", "param_list", "param", "id_list",
  "return_type", "var_decl", "const_decl", "type_decl", "type_expr",
  "type_core", "field_list_opt", "field_list", "field_decl",
  "foreign_decl", "base_type", "type_list", "enum_body_opt", "enum_body",
  "enum_item", "block", "stmt_list", "stmt", "expr", "arg_list_op",
  "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-139)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-33)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,   -45,    38,  -139,  -139,  -139,    24,   -23,  -139,   -21,
    -139,    -9,  -115,  -139,  -139,  -139,  -139,  -139,  -139,   -18,
    -139,  -139,   195,   278,   477,    -7,  -138,  -139,  -139,   278,
     -76,   -72,   477,   -68,   -61,   -60,  -129,   -63,   -71,   -62,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,     9,  -139,  -139,  -139,  -139,
    -139,  -139,   278,   278,   278,   278,   278,    22,   477,   278,
    -139,  -139,  -139,   644,  -139,   644,   -56,  -139,  -122,  -139,
    -139,  -139,  -139,  -118,   477,   477,  -139,     0,   477,   278,
       3,     3,     3,   477,     3,  -118,  -118,  -118,  -118,   610,
     -59,   477,   452,  -139,  -118,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,     4,  -139,     3,
     278,   278,   -58,   -51,   -53,   -49,   -48,  -139,   -50,   573,
    -139,   -43,   -10,  -139,  -105,   -87,   -86,   -44,    -6,  -139,
     -40,    -8,  -139,   477,  -139,   477,   708,   677,  -118,  -118,
    -118,   -85,   -85,   -85,   -85,  -118,   -85,   -85,   178,   178,
     178,   178,  -118,  -118,  -118,  -118,   644,    -1,    -3,   493,
    -139,     1,   644,   644,  -139,   278,   278,  -139,     0,   477,
     278,    23,     3,    62,   477,  -139,   477,  -139,     3,   278,
    -139,  -139,  -139,  -139,   278,  -139,    23,  -118,   644,  -139,
    -139,   533,   381,     5,  -139,  -139,  -139,  -139,  -139,  -118,
     644,  -139,   477,   477,  -139,  -139,  -139,  -139,  -127,  -139,
     477,  -139
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     3,     1,     7,     0,     5,     2,
       6,     0,     0,     8,     9,    10,    11,    12,    13,     0,
      96,    53,     0,     0,     0,     0,     0,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,   100,   101,    99,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    33,    34,    29,    99,    28,     0,    32,    27,    52,
      95,    98,    97,   116,     0,     0,    45,    89,     0,     0,
      16,     0,    47,     0,    47,   111,   112,   114,   115,     0,
       0,     0,     0,    35,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,     0,     0,   140,    16,
       0,     0,     0,     0,    93,     0,    90,    91,     0,     0,
      21,     0,    17,    18,     0,     0,     0,     0,    48,    49,
       0,     0,   110,     0,    36,     0,   118,   117,   134,   135,
     136,   119,   120,   123,   124,   132,   121,   122,   125,   126,
     127,   128,   129,   130,   131,   133,   145,     0,   144,     0,
     139,     0,    30,    26,    44,     0,     0,    42,     0,     0,
       0,    23,     0,     0,     0,    15,     0,    41,     0,     0,
      43,    38,    37,   137,     0,   138,    23,   141,    94,    92,
      39,     0,     0,    40,    19,    22,    20,    51,    50,   142,
     146,    40,     0,     0,    24,    14,    46,    87,     0,    25,
       0,    88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,    -4,  -139,
     -70,   -82,   -83,  -139,  -139,  -139,   -24,  -139,    32,  -139,
     -66,  -139,  -139,  -139,  -139,  -139,   -55,   -78,  -139,  -139,
     -17,  -139,  -139
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     6,     8,     9,    13,    14,   161,   162,
     163,   164,   233,    15,    16,    17,    90,    91,   167,   168,
     169,    18,    92,   248,   155,   156,   157,    21,    26,   102,
      93,   197,   198
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,    11,   100,    22,    23,   110,    95,   101,   106,   -32,
     111,   249,   103,     1,   250,    19,   145,   146,   147,   148,
     150,   151,   127,   128,   129,    27,    28,    24,    29,   165,
     166,   -32,   166,    31,     4,   134,   213,   214,     5,   120,
     137,   138,   139,   140,   141,   142,   143,   144,     7,   145,
     146,   147,   148,   215,   213,   213,   216,    10,    12,   104,
      38,    25,   105,   113,   123,   115,   116,   117,   118,   119,
     122,   107,   124,    99,   108,   109,   112,   114,   149,   154,
     152,   153,   160,   200,   158,   173,   204,   205,   -32,   170,
     206,   207,   159,   208,   209,   211,   217,   174,   219,    73,
      74,    94,    76,    77,    78,    79,    80,    81,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   199,
      20,   212,   220,   202,   203,   218,   166,   223,   224,   226,
     232,   235,   234,   241,    20,   201,   171,    82,    83,   221,
      84,   222,   238,   229,    85,   245,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   230,     0,     0,   227,   228,
     236,     0,   237,   231,     0,     0,     0,     0,    27,    28,
       0,    29,   239,    30,     0,     0,    31,   240,   244,     0,
      32,     0,     0,     0,    33,     0,     0,     0,   246,   247,
       0,    34,    35,     0,     0,     0,   251,     0,     0,    36,
       0,    37,     0,    38,     0,    39,     0,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    27,    28,     0,    29,   127,   128,   129,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,   134,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   142,   143,
     144,     0,   145,   146,   147,   148,    38,     0,     0,     0,
      82,    83,     0,    84,     0,     0,     0,    85,     0,    86,
      87,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    94,    76,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
      33,     0,     0,    82,    83,     0,    84,    34,    35,     0,
      85,     0,    86,     0,     0,    96,     0,    37,     0,     0,
       0,    39,     0,     0,    89,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,     0,     0,
       0,    96,     0,    37,     0,   243,    87,    39,    88,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    97,   125,   126,   127,
     128,   129,   130,   131,   132,   133,     0,     0,     0,     0,
       0,     0,   134,     0,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,   145,   146,   147,   148,
       0,     0,     0,     0,     0,     0,   175,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,    87,   134,    88,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,   145,   146,   147,
     148,     0,     0,     0,     0,     0,     0,   225,   125,   126,
     127,   128,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,     0,   134,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,   145,   146,   147,
     148,     0,     0,     0,     0,     0,     0,   242,   125,   126,
     127,   128,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,     0,   134,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,   145,   146,   147,
     148,     0,     0,     0,   210,   125,   126,   127,   128,   129,
     130,   131,   132,   133,     0,     0,     0,     0,     0,     0,
     134,     0,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,   145,   146,   147,   148,   172,   125,
     126,   127,   128,   129,   130,   131,   132,   133,     0,     0,
       0,     0,     0,     0,   134,     0,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,   145,   146,
     147,   148,   125,     0,   127,   128,   129,   130,   131,   132,
     133,     0,     0,     0,     0,     0,     0,   134,     0,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,   145,   146,   147,   148,   127,   128,   129,   130,   131,
     132,   133,     0,     0,     0,     0,     0,     0,   134,     0,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,   145,   146,   147,   148
};

static const yytype_int16 yycheck[] =
{
      24,    22,   140,   118,   119,   134,    23,   145,    32,     0,
     139,   138,    29,    33,   141,    24,   134,   135,   136,   137,
     142,   143,   107,   108,   109,     3,     4,   142,     6,   111,
     112,    22,   114,    11,    79,   120,   141,   142,     0,    17,
     125,   126,   127,   128,   129,   130,   131,   132,    24,   134,
     135,   136,   137,   140,   141,   141,   142,    80,    79,   135,
      38,    79,   134,   134,    88,    82,    83,    84,    85,    86,
      87,   139,    89,    80,   135,   135,   139,   139,   134,    79,
     104,   105,    79,    79,   108,   144,   144,   138,    79,   113,
     143,   140,   109,   141,   144,   138,   140,   121,   138,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     139,   141,   140,   150,   151,   141,   218,   138,   141,   138,
     117,    79,   212,   226,   139,   149,   114,   125,   126,   173,
     128,   175,   218,   208,   132,   233,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,    -1,    -1,   205,   206,
     214,    -1,   216,   210,    -1,    -1,    -1,    -1,     3,     4,
      -1,     6,   219,     8,    -1,    -1,    11,   224,   232,    -1,
      15,    -1,    -1,    -1,    19,    -1,    -1,    -1,   242,   243,
      -1,    26,    27,    -1,    -1,    -1,   250,    -1,    -1,    34,
      -1,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     3,     4,    -1,     6,   107,   108,   109,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,    -1,   134,   135,   136,   137,    38,    -1,    -1,    -1,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,    -1,   134,
     135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      19,    -1,    -1,   125,   126,    -1,   128,    26,    27,    -1,
     132,    -1,   134,    -1,    -1,    34,    -1,    36,    -1,    -1,
      -1,    40,    -1,    -1,   146,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    36,    -1,   134,   135,    40,   137,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    79,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,   135,   120,   137,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
     137,    -1,    -1,    -1,   141,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,   134,   135,   136,   137,   138,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,   137,   105,    -1,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,   137,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,   134,   135,   136,   137
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,   148,   149,    79,     0,   150,    24,   151,   152,
      80,    22,    79,   153,   154,   160,   161,   162,   168,    24,
     139,   174,   118,   119,   142,    79,   175,     3,     4,     6,
       8,    11,    15,    19,    26,    27,    34,    36,    38,    40,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   125,   126,   128,   132,   134,   135,   137,   146,
     163,   164,   169,   177,    79,   177,    34,    79,   163,    80,
     140,   145,   176,   177,   135,   134,   163,   139,   135,   135,
     134,   139,   139,   134,   139,   177,   177,   177,   177,   177,
      17,   144,   177,   163,   177,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   120,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   134,   135,   136,   137,   134,
     142,   143,   163,   163,    79,   171,   172,   173,   163,   177,
      79,   155,   156,   157,   158,   158,   158,   165,   166,   167,
     163,   165,   138,   144,   163,   144,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   178,   179,   177,
      79,   155,   177,   177,   144,   138,   143,   140,   141,   144,
     141,   138,   141,   141,   142,   140,   142,   140,   141,   138,
     140,   163,   163,   138,   141,   144,   138,   177,   177,   173,
     163,   177,   117,   159,   157,    79,   163,   163,   167,   177,
     177,   159,   144,   134,   163,   174,   163,   163,   170,   138,
     141,   163
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   147,   148,   149,   150,   150,   151,   152,   152,   153,
     153,   153,   153,   153,   154,   154,   155,   155,   156,   156,
     157,   158,   158,   159,   159,   159,   160,   160,   160,   161,
     161,   162,   163,   163,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   165,   165,   166,
     166,   167,   168,   168,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   170,   170,   171,
     171,   172,   172,   173,   173,   174,   175,   175,   176,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   178,   178,   179,   179
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     0,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     8,     6,     0,     1,     1,     3,
       3,     1,     3,     0,     2,     4,     5,     3,     3,     3,
       5,     3,     1,     1,     1,     2,     3,     4,     4,     5,
       5,     4,     4,     4,     4,     2,     7,     0,     1,     1,
       3,     3,     4,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     3,     1,     3,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     3,
       2,     5,     5,     0,     1,     1,     3
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {

#line 1560 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 330 "parser.y"


void yyerror(const char *s) {
	fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
	return yyparse();
}

