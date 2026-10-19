/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 9 "parser.y"

    #include "tree_nodes.h"

#line 53 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ASM = 258,                     /* ASM  */
    AUTO_CAST = 259,               /* AUTO_CAST  */
    BIT_FIELD = 260,               /* BIT_FIELD  */
    BIT_SET = 261,                 /* BIT_SET  */
    BREAK = 262,                   /* BREAK  */
    CASE = 263,                    /* CASE  */
    CAST = 264,                    /* CAST  */
    CONTEXT = 265,                 /* CONTEXT  */
    CONTINUE = 266,                /* CONTINUE  */
    DEFER = 267,                   /* DEFER  */
    DISTINCT = 268,                /* DISTINCT  */
    DO = 269,                      /* DO  */
    DYNAMIC = 270,                 /* DYNAMIC  */
    ELSE = 271,                    /* ELSE  */
    ENUM = 272,                    /* ENUM  */
    FALLTHROUGH = 273,             /* FALLTHROUGH  */
    FOR = 274,                     /* FOR  */
    FOREIGN = 275,                 /* FOREIGN  */
    IF = 276,                      /* IF  */
    IMPORT = 277,                  /* IMPORT  */
    IN = 278,                      /* IN  */
    MAP = 279,                     /* MAP  */
    MATRIX = 280,                  /* MATRIX  */
    NOT_IN = 281,                  /* NOT_IN  */
    OR_BREAK = 282,                /* OR_BREAK  */
    OR_CONTINUE = 283,             /* OR_CONTINUE  */
    OR_ELSE = 284,                 /* OR_ELSE  */
    OR_RETURN = 285,               /* OR_RETURN  */
    PACKAGE = 286,                 /* PACKAGE  */
    PROC = 287,                    /* PROC  */
    RETURN = 288,                  /* RETURN  */
    STRUCT = 289,                  /* STRUCT  */
    SWITCH = 290,                  /* SWITCH  */
    TYPEID = 291,                  /* TYPEID  */
    UNION = 292,                   /* UNION  */
    USING = 293,                   /* USING  */
    WHEN = 294,                    /* WHEN  */
    WHERE = 295,                   /* WHERE  */
    BOOL = 296,                    /* BOOL  */
    B8 = 297,                      /* B8  */
    B16 = 298,                     /* B16  */
    B32 = 299,                     /* B32  */
    B64 = 300,                     /* B64  */
    INT = 301,                     /* INT  */
    I8 = 302,                      /* I8  */
    I16 = 303,                     /* I16  */
    I32 = 304,                     /* I32  */
    I64 = 305,                     /* I64  */
    I128 = 306,                    /* I128  */
    UINT = 307,                    /* UINT  */
    U8 = 308,                      /* U8  */
    U16 = 309,                     /* U16  */
    U32 = 310,                     /* U32  */
    U64 = 311,                     /* U64  */
    U128 = 312,                    /* U128  */
    UINTPTR = 313,                 /* UINTPTR  */
    F16 = 314,                     /* F16  */
    F32 = 315,                     /* F32  */
    F64 = 316,                     /* F64  */
    COMPLEX32 = 317,               /* COMPLEX32  */
    COMPLEX64 = 318,               /* COMPLEX64  */
    COMPLEX128 = 319,              /* COMPLEX128  */
    QUATERNION64 = 320,            /* QUATERNION64  */
    QUATERNION128 = 321,           /* QUATERNION128  */
    QUATERNION256 = 322,           /* QUATERNION256  */
    STRING = 323,                  /* STRING  */
    CSTRING = 324,                 /* CSTRING  */
    BYTE = 325,                    /* BYTE  */
    RUNE = 326,                    /* RUNE  */
    RAWPTR = 327,                  /* RAWPTR  */
    ANY = 328,                     /* ANY  */
    INT_LIT = 329,                 /* INT_LIT  */
    BOOL_LIT = 330,                /* BOOL_LIT  */
    FLOAT_LIT = 331,               /* FLOAT_LIT  */
    ID = 332,                      /* ID  */
    STRING_LIT = 333,              /* STRING_LIT  */
    RAW_STRING_LIT = 334,          /* RAW_STRING_LIT  */
    IMAGINARY_LIT = 335,           /* IMAGINARY_LIT  */
    RUNE_LIT = 336,                /* RUNE_LIT  */
    NIL = 337,                     /* NIL  */
    UNDEFINED = 338,               /* UNDEFINED  */
    ATTRIBUTE = 339,               /* ATTRIBUTE  */
    BUILD_DIRECTIVE = 340,         /* BUILD_DIRECTIVE  */
    DIRECTIVE = 341,               /* DIRECTIVE  */
    AT = 342,                      /* AT  */
    OP_ADD_ASSIGN = 343,           /* OP_ADD_ASSIGN  */
    OP_SUB_ASSIGN = 344,           /* OP_SUB_ASSIGN  */
    OP_MUL_ASSIGN = 345,           /* OP_MUL_ASSIGN  */
    OP_DIV_ASSIGN = 346,           /* OP_DIV_ASSIGN  */
    OP_MOD_ASSIGN = 347,           /* OP_MOD_ASSIGN  */
    OP_MOD2_ASSIGN = 348,          /* OP_MOD2_ASSIGN  */
    OP_OR_ASSIGN = 349,            /* OP_OR_ASSIGN  */
    OP_NOT_ASSIGN = 350,           /* OP_NOT_ASSIGN  */
    OP_AND_ASSIGN = 351,           /* OP_AND_ASSIGN  */
    OP_AND_NOT_ASSIGN = 352,       /* OP_AND_NOT_ASSIGN  */
    OP_SHL_ASSIGN = 353,           /* OP_SHL_ASSIGN  */
    OP_SHR_ASSIGN = 354,           /* OP_SHR_ASSIGN  */
    OP_LOG_AND_ASSIGN = 355,       /* OP_LOG_AND_ASSIGN  */
    OP_LOG_OR_ASSIGN = 356,        /* OP_LOG_OR_ASSIGN  */
    OP_LOG_AND = 357,              /* OP_LOG_AND  */
    OP_LOG_OR = 358,               /* OP_LOG_OR  */
    OP_AND_NOT = 359,              /* OP_AND_NOT  */
    OP_SHL = 360,                  /* OP_SHL  */
    OP_SHR = 361,                  /* OP_SHR  */
    OP_EQ = 362,                   /* OP_EQ  */
    OP_NE = 363,                   /* OP_NE  */
    OP_LE = 364,                   /* OP_LE  */
    OP_GE = 365,                   /* OP_GE  */
    OP_RANGE = 366,                /* OP_RANGE  */
    OP_RANGE_INCLUSIVE = 367,      /* OP_RANGE_INCLUSIVE  */
    OP_RANGE_EXCLUSIVE = 368,      /* OP_RANGE_EXCLUSIVE  */
    OP_ARROW = 369,                /* OP_ARROW  */
    OP_DECL_TYPED = 370,           /* OP_DECL_TYPED  */
    OP_DECL_INFERRED = 371,        /* OP_DECL_INFERRED  */
    OP_MOD2 = 372,                 /* OP_MOD2  */
    OP_DOLLAR = 373,               /* OP_DOLLAR  */
    LEX_ERROR = 374,               /* LEX_ERROR  */
    UNARY = 375                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "parser.y"

    long long    int_val;  /* целочисленный литерал   */
    double       float_val;  /* вещественный литерал    */
    char        *str_val;   /* ID, строки, директивы   */
    unsigned int rune_val;   /* символьный (rune) литерал */
    struct {
            double value;
            char unit;
            } imag_val;   /* 3.5i -> {3.5, 'i'} */

 /* Узлы синтаксического дерева */
    struct Expression  *expr_node;                       /* Указатель на выражение */
    struct ExprList    *expr_list_node;                  /* Список выражений */
    struct TypeExpr    *type_expr_node;                  /* Указатель на описание типа */
    struct IdList      *id_list_node;                    /* Cписок имен */
    struct FieldDecl   *field_decl_node;                 /* Одно объявление полей или параметров */
    struct FieldList   *field_list_node;                 /* Список таких объявлений */
    struct TypeList    *type_list_node;                  /* Список типов */
    struct EnumItem    *enum_item_node;                  /* Один элемент enum */
    struct EnumItemList *enum_item_list_node;            /* Список элементов enum */

#line 212 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
