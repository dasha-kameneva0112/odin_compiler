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
  YYSYMBOL_138_ = 138,                     /* ';'  */
  YYSYMBOL_139_ = 139,                     /* ')'  */
  YYSYMBOL_140_ = 140,                     /* '{'  */
  YYSYMBOL_141_ = 141,                     /* '}'  */
  YYSYMBOL_142_ = 142,                     /* ','  */
  YYSYMBOL_143_ = 143,                     /* ':'  */
  YYSYMBOL_144_ = 144,                     /* '='  */
  YYSYMBOL_145_ = 145,                     /* ']'  */
  YYSYMBOL_146_ = 146,                     /* '!'  */
  YYSYMBOL_YYACCEPT = 147,                 /* $accept  */
  YYSYMBOL_program = 148,                  /* program  */
  YYSYMBOL_package_clause = 149,           /* package_clause  */
  YYSYMBOL_import_list = 150,              /* import_list  */
  YYSYMBOL_import_decl = 151,              /* import_decl  */
  YYSYMBOL_decl_list = 152,                /* decl_list  */
  YYSYMBOL_decl = 153,                     /* decl  */
  YYSYMBOL_decl_core = 154,                /* decl_core  */
  YYSYMBOL_proc_decl = 155,                /* proc_decl  */
  YYSYMBOL_param_list_opt = 156,           /* param_list_opt  */
  YYSYMBOL_param_list = 157,               /* param_list  */
  YYSYMBOL_param = 158,                    /* param  */
  YYSYMBOL_id_list = 159,                  /* id_list  */
  YYSYMBOL_return_type = 160,              /* return_type  */
  YYSYMBOL_return_type_list = 161,         /* return_type_list  */
  YYSYMBOL_var_decl = 162,                 /* var_decl  */
  YYSYMBOL_const_decl = 163,               /* const_decl  */
  YYSYMBOL_type_decl = 164,                /* type_decl  */
  YYSYMBOL_type_expr = 165,                /* type_expr  */
  YYSYMBOL_type_core = 166,                /* type_core  */
  YYSYMBOL_field_list_opt = 167,           /* field_list_opt  */
  YYSYMBOL_field_list = 168,               /* field_list  */
  YYSYMBOL_field_decl = 169,               /* field_decl  */
  YYSYMBOL_foreign_decl = 170,             /* foreign_decl  */
  YYSYMBOL_base_type = 171,                /* base_type  */
  YYSYMBOL_enum_body_opt = 172,            /* enum_body_opt  */
  YYSYMBOL_enum_body = 173,                /* enum_body  */
  YYSYMBOL_enum_item = 174,                /* enum_item  */
  YYSYMBOL_block = 175,                    /* block  */
  YYSYMBOL_stmts = 176,                    /* stmts  */
  YYSYMBOL_stmt_list = 177,                /* stmt_list  */
  YYSYMBOL_stmt = 178,                     /* stmt  */
  YYSYMBOL_compound_stmt = 179,            /* compound_stmt  */
  YYSYMBOL_label_stmt = 180,               /* label_stmt  */
  YYSYMBOL_labelable_stmt = 181,           /* labelable_stmt  */
  YYSYMBOL_term_stmt = 182,                /* term_stmt  */
  YYSYMBOL_simple_stmt = 183,              /* simple_stmt  */
  YYSYMBOL_assign_op = 184,                /* assign_op  */
  YYSYMBOL_simple_stmt_opt = 185,          /* simple_stmt_opt  */
  YYSYMBOL_expr_opt = 186,                 /* expr_opt  */
  YYSYMBOL_if_stmt = 187,                  /* if_stmt  */
  YYSYMBOL_for_stmt = 188,                 /* for_stmt  */
  YYSYMBOL_for_do_stmt = 189,              /* for_do_stmt  */
  YYSYMBOL_switch_stmt = 190,              /* switch_stmt  */
  YYSYMBOL_switch_body = 191,              /* switch_body  */
  YYSYMBOL_case_list = 192,                /* case_list  */
  YYSYMBOL_case_clause = 193,              /* case_clause  */
  YYSYMBOL_expr_list = 194,                /* expr_list  */
  YYSYMBOL_when_stmt = 195,                /* when_stmt  */
  YYSYMBOL_return_stmt = 196,              /* return_stmt  */
  YYSYMBOL_expr = 197,                     /* expr  */
  YYSYMBOL_arg_list_op = 198,              /* arg_list_op  */
  YYSYMBOL_arg_list = 199                  /* arg_list  */
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
#define YYLAST   2735

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  240
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  423

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
     134,   139,   129,   125,   142,   126,   136,   130,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   143,   138,
     123,   144,   124,   122,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   135,     2,   145,   137,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   140,   127,   141,   128,     2,     2,     2,
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
       0,    65,    65,    69,    70,    73,    75,    79,    80,    83,
      85,    90,    91,    95,    96,    97,    98,    99,   106,   107,
     110,   112,   116,   117,   121,   125,   126,   129,   131,   132,
     136,   137,   143,   144,   145,   154,   155,   162,   166,   167,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   186,   188,   192,   193,   197,   201,   202,
     206,   206,   206,   206,   206,   207,   207,   207,   207,   207,
     207,   208,   208,   208,   208,   208,   208,   208,   209,   209,
     209,   210,   210,   210,   211,   211,   211,   212,   212,   212,
     212,   212,   212,   215,   217,   221,   222,   226,   227,   235,
     239,   240,   243,   245,   249,   250,   251,   255,   256,   257,
     258,   259,   260,   266,   270,   271,   272,   273,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   291,
     292,   293,   294,   295,   296,   297,   301,   301,   301,   301,
     302,   302,   302,   302,   303,   303,   303,   303,   304,   304,
     307,   309,   312,   314,   318,   319,   320,   321,   322,   323,
     327,   328,   329,   330,   335,   336,   337,   341,   342,   343,
     344,   348,   351,   353,   357,   358,   362,   363,   367,   368,
     369,   373,   374,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   392,   393,   394,   395,   396,
     397,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   420,   421,   422,   423,   425,   426,   427,   429,   430,
     431,   432,   433,   434,   435,   437,   438,   441,   443,   447,
     448
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
  "'&'", "UNARY", "'('", "'['", "'.'", "'^'", "';'", "')'", "'{'", "'}'",
  "','", "':'", "'='", "']'", "'!'", "$accept", "program",
  "package_clause", "import_list", "import_decl", "decl_list", "decl",
  "decl_core", "proc_decl", "param_list_opt", "param_list", "param",
  "id_list", "return_type", "return_type_list", "var_decl", "const_decl",
  "type_decl", "type_expr", "type_core", "field_list_opt", "field_list",
  "field_decl", "foreign_decl", "base_type", "enum_body_opt", "enum_body",
  "enum_item", "block", "stmts", "stmt_list", "stmt", "compound_stmt",
  "label_stmt", "labelable_stmt", "term_stmt", "simple_stmt", "assign_op",
  "simple_stmt_opt", "expr_opt", "if_stmt", "for_stmt", "for_do_stmt",
  "switch_stmt", "switch_body", "case_list", "case_clause", "expr_list",
  "when_stmt", "return_stmt", "expr", "arg_list_op", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-375)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-177)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,   -54,    35,  -375,   -82,  -375,    33,  -375,   -22,  -375,
      -3,   -78,    -8,   -56,  -375,   -76,  -375,  -111,  -375,  -375,
    -375,  -375,  -375,   -16,  -375,  -375,   399,  -375,   768,    -9,
    1076,    -7,   -69,   500,  -375,  -375,   768,   -61,   -57,  1076,
     -60,   -52,   -51,   -95,   -59,   -55,   -53,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,   768,
     768,   768,   768,   768,   605,  1076,   768,  -375,  -375,  2444,
     -45,  2444,  -375,   -49,  -375,  -103,  -375,  -375,  -375,  -375,
    -375,   500,  -375,   641,   768,   768,   732,   768,   768,   500,
    -375,  -375,   -48,  -375,   -40,  -375,  -375,  -375,  -375,  -375,
    -106,  -375,  -375,  1561,    79,  1076,  1076,  -375,    24,  1076,
     768,   768,    25,   768,  1076,   768,    79,    79,    79,    79,
    2329,   -39,  1076,  1353,  -375,    79,   768,  -375,  -375,   768,
    -375,   768,   768,   768,   768,   768,   768,   768,   768,   768,
     768,   768,   768,   768,   768,   768,   768,   768,   768,   768,
     768,   768,   768,   768,   768,   768,   768,   768,    26,  -375,
     768,   768,   768,   768,  -375,  -375,  -375,  -375,   -31,   -19,
    1067,   -28,  -100,  2024,   -45,  -375,   -26,  -375,  2140,  2444,
    2177,  -375,  -375,  -375,  -375,   768,   882,   768,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,   768,   -32,   -23,   -30,   -15,   -21,  -375,    22,
    1822,    31,    29,  -375,   -96,  -375,   -93,    36,    30,  -375,
     -92,    37,    38,  -375,  1076,  -375,  1076,  1861,  2478,  1976,
    1280,  2566,    79,    79,    79,  2363,  2363,  2363,  2363,  2512,
    2512,  2512,    79,  1712,  2363,  2363,  2598,  2598,  2598,  2598,
      79,    79,    79,    79,  2444,    42,    32,  1395,  -375,  2444,
      44,   -45,   -45,   768,   768,  1076,   583,  -375,   768,   112,
      23,   732,  -375,   115,   -45,   641,   -91,  -375,  -375,  -375,
    -375,  -375,   -45,  2444,  -375,   768,   768,  -375,    24,  1076,
     768,    68,   768,  1076,  -375,  -375,   768,  1076,   768,  -375,
    -375,  -375,   768,   768,   768,  -375,   768,  -375,    68,    47,
    2444,  1192,   768,  -375,  2177,   -20,   742,  -375,  -375,  -375,
    2292,   -38,    51,    50,  2024,   768,   768,    79,  2444,  -375,
    -375,  1505,   980,    55,  -375,  -375,  -375,  -375,    79,  2444,
    2444,  2444,  2444,  -375,   768,   583,  -375,    52,    57,  1243,
     178,  -375,  -375,  -375,   -88,  -375,  -375,  -375,   768,   768,
     -45,   -45,  1076,  1076,  -375,  -375,   -11,  -375,   768,   768,
     -20,  -375,  -375,    59,  2177,  -375,  -116,  -375,   583,  -375,
      64,  1678,  -375,  -375,  -375,   768,  -375,  1076,  -375,   768,
      55,  -375,   187
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     3,     1,     9,     4,     0,     6,
       2,     7,     0,    25,    10,    11,    13,     0,    14,    15,
      16,    17,     8,     0,   102,    59,     0,    12,     0,     0,
       0,     0,     0,   100,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
     184,   185,   183,   186,   187,   188,   189,   190,   191,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    40,    35,
      34,   176,    26,     0,    38,    33,    39,    58,    99,   121,
     122,     0,   123,   150,     0,   181,     0,     0,     0,     0,
     107,   103,   104,   112,   101,   118,   108,   109,   119,   110,
       0,   111,   120,   135,   200,     0,     0,    51,    93,     0,
       0,    20,     0,    53,     0,    53,   195,   196,   198,   199,
       0,     0,     0,     0,    41,   197,     0,   230,   231,     0,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,     0,     0,   228,
       0,    20,     0,     0,   126,   125,   160,   151,     0,     0,
     176,     0,     0,   176,   182,   172,     0,   167,   176,   124,
       0,   128,   127,   105,   106,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,     0,    97,     0,    94,    95,     0,
       0,     0,    21,    22,     0,    25,     0,     0,    54,    55,
       0,     0,     0,   194,     0,    42,     0,     0,   221,     0,
     202,   201,   218,   219,   220,   203,   204,   207,   208,   222,
     223,   224,   216,     0,   205,   206,   209,   210,   211,   212,
     213,   214,   215,   217,   239,     0,   238,     0,   234,   177,
       0,    36,    32,   152,     0,     0,     0,   161,     0,   154,
       0,     0,   168,   178,   130,   150,   131,   114,   113,   115,
     116,   117,   129,   134,    50,     0,     0,    48,     0,     0,
       0,    27,     0,     0,    19,    47,     0,     0,     0,    49,
      44,    43,     0,     0,     0,   232,     0,   233,    27,     0,
     153,     0,   150,   164,     0,     0,     0,   171,   173,   170,
       0,     0,     0,     0,   176,     0,     0,   235,    98,    96,
      45,     0,     0,    46,    23,    24,    56,    57,   236,   227,
     226,   225,   240,    46,   150,     0,   162,     0,     0,   176,
     157,   155,   156,   102,     0,   169,   180,   179,   152,     0,
     133,   132,     0,     0,    28,    18,     0,   165,   152,     0,
       0,   175,   102,     0,     0,    52,     0,    30,     0,   163,
       0,     0,   158,   159,   174,   150,    29,     0,   166,   150,
       0,    31,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,    14,
    -375,  -113,    69,  -121,  -375,  -375,  -375,  -375,   -17,   193,
      75,  -375,  -105,  -375,  -375,  -375,  -375,   -94,   -12,  -374,
    -375,  -375,   -90,  -375,  -375,  -109,   -99,  -375,  -246,  -368,
    -182,     6,  -375,     7,  -184,  -375,  -375,    67,  -126,  -375,
     -25,  -375,  -375
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     6,     9,    10,    14,    15,    16,   241,
     242,   243,    17,   363,   406,    18,    19,    20,   306,   106,
     247,   248,   249,    21,    98,   236,   237,   238,   120,    32,
      33,   121,   122,   123,   308,   124,   125,   232,   198,   339,
     126,   127,   128,   129,   207,   300,   348,   202,   131,   132,
     101,   285,   286
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    99,   195,   114,   118,   408,   294,    28,   133,   401,
     212,   134,   215,   105,   197,   201,    23,   206,   215,    12,
     403,   194,   137,   416,   302,     4,   417,     1,   414,   211,
     410,    29,    30,   346,   309,     5,   190,   216,   217,   141,
     192,   193,   190,   295,   217,   142,   190,   323,   324,    29,
     190,   327,   355,   356,   190,   402,     7,     8,    11,   352,
      22,    26,    27,    31,   146,   147,   148,   149,   150,   153,
     102,   155,   108,   107,   135,   389,    13,   136,   154,   144,
     138,   143,   399,   139,   140,   191,   133,   145,   200,   203,
     213,   208,   209,   210,   133,   100,   377,   190,   214,   215,
     130,   196,    24,   235,   245,   288,   254,   293,   157,   158,
     298,   160,   301,   314,   316,   240,   315,   349,   233,   234,
      24,   318,   239,   190,   295,   217,   317,   251,   396,    24,
     345,   257,    24,   351,   258,   255,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   287,   382,   347,   289,   385,   319,   215,   420,
     321,   322,   326,   422,   336,   215,   328,   325,   130,   329,
     199,   335,   204,   338,   362,   374,   130,   343,   297,   388,
     398,   299,   190,   295,   217,    24,   400,   415,   303,   190,
     295,   217,   419,   408,   307,   290,   197,   313,   244,   364,
     250,   246,   250,   186,   187,   188,   189,   373,   413,    97,
     252,   366,   310,   311,   359,   387,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   330,     0,   331,
       0,     0,     0,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   291,
     292,     0,     0,     0,     0,     0,   397,     0,   340,   341,
       0,   133,     0,   344,     0,   197,   350,     0,     0,     0,
     354,     0,   304,     0,   312,     0,     0,     0,     0,     0,
     357,   358,     0,   196,     0,   361,     0,     0,     0,   418,
       0,     0,   360,   368,     0,     0,   365,   369,   370,   371,
     367,   372,     0,     0,     0,     0,   197,   379,     0,     0,
     197,     0,     0,     0,     0,     0,     0,     0,     0,   376,
       0,     0,   380,   381,     0,     0,     0,     0,     0,   386,
       0,     0,   297,     0,     0,   394,     0,     0,     0,   133,
     133,   395,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   340,   404,     0,     0,     0,     0,     0,
       0,     0,   353,   340,   411,   405,   407,     0,     0,     0,
       0,     0,     0,   133,   409,     0,     0,     0,   412,   244,
     133,     0,   376,   250,   133,     0,     0,     0,     0,     0,
     421,     0,    34,    35,     0,    36,     0,    37,   409,   378,
      38,     0,     0,   384,    39,     0,     0,     0,    40,     0,
       0,     0,   390,   391,     0,    41,    42,     0,     0,     0,
       0,     0,     0,    43,     0,    44,     0,    45,     0,    46,
       0,     0,     0,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,    36,     0,     0,   109,
       0,    38,     0,   110,   111,     0,     0,     0,     0,     0,
     112,   113,     0,   114,    89,    90,     0,    91,     0,     0,
       0,    92,     0,    93,    94,   115,    95,   116,    45,     0,
       0,   117,   118,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    34,    35,   119,    36,
       0,     0,   109,     0,    38,     0,   110,   111,     0,     0,
       0,     0,     0,   112,   342,     0,     0,     0,    34,    35,
       0,    36,     0,     0,     0,     0,    38,     0,   115,     0,
       0,    45,   151,     0,   117,    89,    90,     0,    91,     0,
       0,     0,    92,     0,    93,     0,     0,     0,     0,     0,
      24,     0,     0,    45,    34,    35,    96,    36,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
       0,    91,     0,     0,     0,    92,     0,    93,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,    96,
      89,    90,     0,    91,     0,    34,    35,    92,    36,    93,
       0,     0,     0,    38,     0,    34,    35,     0,    36,     0,
     152,    96,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,     0,    91,
      45,    34,    35,    92,    36,    93,     0,     0,     0,    38,
      45,    24,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,    90,     0,
      91,     0,     0,     0,    92,     0,    93,    89,    90,     0,
      91,     0,   205,     0,    92,     0,    93,     0,    96,     0,
       0,     0,     0,     0,     0,   383,     0,     0,    96,     0,
      37,     0,     0,    89,    90,     0,    91,    39,     0,     0,
      92,    40,    93,   305,     0,   114,     0,     0,    41,    42,
       0,     0,     0,     0,    96,     0,   103,     0,    44,   116,
       0,     0,    46,     0,     0,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,    41,    42,     0,     0,
       0,     0,     0,     0,   103,     0,    44,    94,     0,    95,
      46,     0,    24,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   296,    37,     0,     0,     0,     0,     0,
     156,    39,     0,     0,     0,    40,   157,   158,   159,   160,
       0,     0,    41,    42,     0,     0,     0,     0,     0,   161,
     103,     0,    44,     0,   393,    94,    46,    95,     0,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,   104,     0,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,   174,     0,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   189,  -135,     0,    24,   375,     0,
       0,    94,     0,    95,     0,   156,     0,     0,     0,     0,
       0,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,   156,     0,     0,     0,
       0,     0,   157,   158,   159,   160,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,   157,
     158,   174,   160,     0,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   189,
       0,     0,    24,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,   174,     0,     0,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   156,   186,   187,   188,
     189,  -135,   157,   158,   159,   160,   164,   165,   166,   167,
     168,   169,   170,     0,     0,   161,     0,     0,     0,   174,
       0,     0,     0,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   189,   156,     0,
       0,     0,     0,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,   174,     0,     0,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     189,     0,     0,     0,     0,     0,     0,     0,   256,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,   174,     0,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   156,   186,
     187,   188,   189,     0,   157,   158,   159,   160,     0,     0,
     337,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,     0,     0,     0,     0,     0,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,   174,     0,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,   189,     0,     0,     0,     0,     0,     0,     0,
     392,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,  -176,
     174,     0,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   375,   186,   187,   188,   189,     0,
       0,   156,     0,  -176,  -176,  -176,     0,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,     0,     0,     0,     0,
       0,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,     0,   174,     0,     0,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,   189,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
       0,   174,     0,     0,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   156,   186,   187,   188,   189,
       0,   157,   158,   159,   160,   334,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
       0,     0,     0,     0,   156,     0,     0,     0,     0,     0,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
       0,   174,     0,     0,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   189,
       0,     0,     0,     0,   320,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,     0,
     174,     0,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   333,   186,   187,   188,   189,   156,
       0,     0,     0,     0,     0,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,     0,
       0,     0,     0,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,   174,     0,     0,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,   189,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,     0,   174,     0,     0,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   189,  -135,   156,    24,     0,     0,     0,     0,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,   157,   158,   159,   160,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,     0,   174,
       0,     0,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   189,  -135,     0,
     205,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,   174,     0,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   189,   156,     0,    24,     0,     0,
       0,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,     0,     0,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,     0,   160,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,     0,
       0,   174,     0,     0,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   189,
       0,     0,   205,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,     0,   174,     0,
       0,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,   189,   156,   253,   164,
     165,   166,     0,   157,   158,   159,   160,     0,     0,     0,
       0,     0,   174,     0,     0,     0,   161,     0,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     189,     0,     0,     0,     0,     0,     0,   157,   158,     0,
     160,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,     0,   160,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,     0,     0,   174,     0,     0,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   189,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,   157,   158,   174,   160,     0,
       0,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,   189,   162,   163,   164,   165,
     166,   167,   168,   169,   170,     0,     0,   157,   158,     0,
     160,   174,     0,     0,     0,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,   164,   165,   166,   167,   168,   169,   170,     0,
       0,     0,     0,     0,     0,   174,     0,     0,     0,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,   189,   164,   165,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   183,   184,
     185,     0,   186,   187,   188,   189
};

static const yytype_int16 yycheck[] =
{
      12,    26,   111,    23,    42,    16,    25,   118,    33,   383,
     119,    36,   118,    30,   113,   114,    24,   116,   118,    22,
     388,   111,    39,   139,   208,    79,   142,    33,   402,   119,
     398,   142,   143,    10,   216,     0,   142,   143,   144,   134,
     143,   144,   142,   143,   144,   140,   142,   143,   141,   142,
     142,   143,   143,   144,   142,   143,   138,    24,    80,   305,
     138,   117,   138,    79,    89,    90,    91,    92,    93,    94,
      79,    96,   141,    80,   135,    25,    79,   134,    95,   134,
     140,   140,    25,   135,   135,   134,   111,   140,   113,   114,
     138,   116,   117,   118,   119,    28,   342,   142,   138,   118,
      33,   113,   140,    79,    79,    79,   145,   138,    29,    30,
     138,    32,   138,   145,   144,   140,   139,   301,   135,   136,
     140,   142,   139,   142,   143,   144,   141,   144,   374,   140,
      18,   156,   140,    18,   159,   152,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   345,   141,   190,   350,   145,   118,   415,
     139,   142,   142,   419,   142,   118,   139,   141,   111,   141,
     113,   139,   115,   139,   116,   138,   119,   296,   200,   138,
     138,   203,   142,   143,   144,   140,    18,   138,   210,   142,
     143,   144,   138,    16,   216,   191,   305,   232,   141,   322,
     143,   142,   145,   134,   135,   136,   137,   338,   400,    26,
     145,   326,   216,   216,   318,   351,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,   256,
      -1,    -1,    -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,   192,
     193,    -1,    -1,    -1,    -1,    -1,   375,    -1,   293,   294,
      -1,   296,    -1,   298,    -1,   374,   301,    -1,    -1,    -1,
     305,    -1,   215,    -1,   217,    -1,    -1,    -1,    -1,    -1,
     315,   316,    -1,   305,    -1,   320,    -1,    -1,    -1,   408,
      -1,    -1,   319,   328,    -1,    -1,   323,   332,   333,   334,
     327,   336,    -1,    -1,    -1,    -1,   415,   342,    -1,    -1,
     419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,
      -1,    -1,   344,   345,    -1,    -1,    -1,    -1,    -1,   351,
      -1,    -1,   354,    -1,    -1,   362,    -1,    -1,    -1,   374,
     375,   363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   388,   389,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   305,   398,   399,   392,   393,    -1,    -1,    -1,
      -1,    -1,    -1,   408,   396,    -1,    -1,    -1,   400,   322,
     415,    -1,   404,   326,   419,    -1,    -1,    -1,    -1,    -1,
     417,    -1,     3,     4,    -1,     6,    -1,     8,   420,   342,
      11,    -1,    -1,   346,    15,    -1,    -1,    -1,    19,    -1,
      -1,    -1,   355,   356,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    36,    -1,    38,    -1,    40,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,     6,    -1,    -1,     9,
      -1,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      20,    21,    -1,    23,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,    -1,   134,   135,    35,   137,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     3,     4,    88,     6,
      -1,    -1,     9,    -1,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    20,    21,    -1,    -1,    -1,     3,     4,
      -1,     6,    -1,    -1,    -1,    -1,    11,    -1,    35,    -1,
      -1,    38,    17,    -1,    41,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,    -1,   134,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    38,     3,     4,   146,     6,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,    -1,   134,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    -1,   146,
     125,   126,    -1,   128,    -1,     3,     4,   132,     6,   134,
      -1,    -1,    -1,    11,    -1,     3,     4,    -1,     6,    -1,
     145,   146,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,    -1,   128,
      38,     3,     4,   132,     6,   134,    -1,    -1,    -1,    11,
      38,   140,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    -1,    -1,   125,   126,    -1,
     128,    -1,    -1,    -1,   132,    -1,   134,   125,   126,    -1,
     128,    -1,   140,    -1,   132,    -1,   134,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,   146,    -1,
       8,    -1,    -1,   125,   126,    -1,   128,    15,    -1,    -1,
     132,    19,   134,    21,    -1,    23,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,   146,    -1,    34,    -1,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    36,   135,    -1,   137,
      40,    -1,   140,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,     8,    -1,    -1,    -1,    -1,    -1,
      23,    15,    -1,    -1,    -1,    19,    29,    30,    31,    32,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    42,
      34,    -1,    36,    -1,   134,   135,    40,   137,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,   137,   138,    -1,   140,    16,    -1,
      -1,   135,    -1,   137,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    29,
      30,   119,    32,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,   137,
      -1,    -1,   140,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,   119,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    23,   134,   135,   136,
     137,   138,    29,    30,    31,    32,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    42,    -1,    -1,    -1,   119,
      -1,    -1,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,   134,   135,   136,   137,    23,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,   119,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    23,   134,
     135,   136,   137,    -1,    29,    30,    31,    32,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,   118,
     119,    -1,    -1,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    16,   134,   135,   136,   137,    -1,
      -1,    23,    -1,   142,   143,   144,    -1,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,   134,   135,   136,   137,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    23,   134,   135,   136,   137,
      -1,    29,    30,    31,    32,   143,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,   142,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
     119,    -1,    -1,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    18,   134,   135,   136,   137,    23,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
     134,   135,   136,   137,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,   119,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,   137,   138,    23,   140,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,   134,   135,   136,   137,   138,    -1,
     140,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,   137,    23,    -1,   140,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    32,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,   137,
      -1,    -1,   140,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,   119,    -1,
      -1,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,   136,   137,    23,   139,   106,
     107,   108,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    42,    -1,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    32,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,   119,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,   137,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    29,    30,   119,    32,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,   134,   135,   136,   137,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,    -1,    29,    30,    -1,
      32,   119,    -1,    -1,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
     134,   135,   136,   137,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,    -1,   134,   135,   136,   137
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,   148,   149,    79,     0,   150,   138,    24,   151,
     152,    80,    22,    79,   153,   154,   155,   159,   162,   163,
     164,   170,   138,    24,   140,   175,   117,   138,   118,   142,
     143,    79,   176,   177,     3,     4,     6,     8,    11,    15,
      19,    26,    27,    34,    36,    38,    40,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   125,
     126,   128,   132,   134,   135,   137,   146,   166,   171,   197,
     194,   197,    79,    34,    79,   165,   166,    80,   141,     9,
      13,    14,    20,    21,    23,    35,    37,    41,    42,    88,
     175,   178,   179,   180,   182,   183,   187,   188,   189,   190,
     194,   195,   196,   197,   197,   135,   134,   165,   140,   135,
     135,   134,   140,   140,   134,   140,   197,   197,   197,   197,
     197,    17,   145,   197,   165,   197,    23,    29,    30,    31,
      32,    42,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   119,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   134,   135,   136,   137,
     142,   134,   143,   144,   179,   182,   175,   183,   185,   194,
     197,   183,   194,   197,   194,   140,   183,   191,   197,   197,
     197,   179,   182,   138,   138,   118,   143,   144,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   184,   165,   165,    79,   172,   173,   174,   165,
     197,   156,   157,   158,   194,    79,   159,   167,   168,   169,
     194,   165,   167,   139,   145,   165,   145,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   198,   199,   197,    79,   197,
     156,   194,   194,   138,    25,   143,    16,   175,   138,   175,
     192,   138,   191,   175,   194,    21,   165,   175,   181,   187,
     188,   190,   194,   197,   145,   139,   144,   141,   142,   145,
     142,   139,   142,   143,   141,   141,   142,   143,   139,   141,
     165,   165,    18,    18,   143,   139,   142,   145,   139,   186,
     197,   197,    21,   182,   197,    18,    10,   141,   193,   191,
     197,    18,   185,   194,   197,   143,   144,   197,   197,   174,
     165,   197,   116,   160,   158,   165,   169,   165,   197,   197,
     197,   197,   197,   160,   138,    16,   175,   185,   194,   197,
     175,   175,   187,   143,   194,   191,   175,   195,   138,    25,
     194,   194,   145,   134,   165,   175,   185,   182,   138,    25,
      18,   176,   143,   186,   197,   165,   161,   165,    16,   175,
     186,   197,   175,   187,   176,   138,   139,   142,   182,   138,
     185,   165,   185
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   147,   148,   149,   149,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   154,   154,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   159,   159,   160,   160,   160,
     161,   161,   162,   162,   162,   163,   163,   164,   165,   165,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   167,   167,   168,   168,   169,   170,   170,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   172,   172,   173,   173,   174,   174,   175,
     176,   176,   177,   177,   178,   178,   178,   179,   179,   179,
     179,   179,   179,   180,   181,   181,   181,   181,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   183,
     183,   183,   183,   183,   183,   183,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     185,   185,   186,   186,   187,   187,   187,   187,   187,   187,
     188,   188,   188,   188,   189,   189,   189,   190,   190,   190,
     190,   191,   192,   192,   193,   193,   194,   194,   195,   195,
     195,   196,   196,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   198,   198,   199,
     199
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     3,     0,     2,     2,     3,     0,
       2,     1,     2,     1,     1,     1,     1,     1,     8,     6,
       0,     1,     1,     3,     3,     1,     3,     0,     2,     4,
       1,     3,     5,     3,     3,     3,     5,     3,     1,     1,
       1,     2,     3,     4,     4,     5,     5,     4,     4,     4,
       4,     2,     7,     0,     1,     1,     3,     3,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     3,     1,     3,     3,
       1,     2,     0,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     3,
       3,     3,     5,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     0,     1,     3,     5,     5,     5,     7,     7,
       2,     3,     5,     7,     4,     6,     8,     2,     3,     5,
       4,     3,     0,     2,     4,     3,     1,     3,     3,     5,
       5,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     5,     5,     2,     2,
       2,     2,     4,     4,     3,     5,     5,     0,     1,     1,
       3
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

#line 2433 "parser.tab.c"

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

#line 451 "parser.y"


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
