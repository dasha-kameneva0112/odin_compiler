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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TRUE = 258,                    /* TRUE  */
    FALSE = 259,                   /* FALSE  */
    ASM = 260,                     /* ASM  */
    AUTO_CAST = 261,               /* AUTO_CAST  */
    BIT_FIELD = 262,               /* BIT_FIELD  */
    BIT_SET = 263,                 /* BIT_SET  */
    BREAK = 264,                   /* BREAK  */
    CASE = 265,                    /* CASE  */
    CAST = 266,                    /* CAST  */
    CONTEXT = 267,                 /* CONTEXT  */
    CONTINUE = 268,                /* CONTINUE  */
    DEFER = 269,                   /* DEFER  */
    DISTINCT = 270,                /* DISTINCT  */
    DO = 271,                      /* DO  */
    DYNAMIC = 272,                 /* DYNAMIC  */
    ELSE = 273,                    /* ELSE  */
    ENUM = 274,                    /* ENUM  */
    FALLTHROUGH = 275,             /* FALLTHROUGH  */
    FOR = 276,                     /* FOR  */
    FOREIGN = 277,                 /* FOREIGN  */
    IF = 278,                      /* IF  */
    IMPORT = 279,                  /* IMPORT  */
    IN = 280,                      /* IN  */
    MAP = 281,                     /* MAP  */
    MATRIX = 282,                  /* MATRIX  */
    NOT_IN = 283,                  /* NOT_IN  */
    OR_BREAK = 284,                /* OR_BREAK  */
    OR_CONTINUE = 285,             /* OR_CONTINUE  */
    OR_ELSE = 286,                 /* OR_ELSE  */
    OR_RETURN = 287,               /* OR_RETURN  */
    PACKAGE = 288,                 /* PACKAGE  */
    PROC = 289,                    /* PROC  */
    RETURN = 290,                  /* RETURN  */
    STRUCT = 291,                  /* STRUCT  */
    SWITCH = 292,                  /* SWITCH  */
    TRANSMUTE = 293,               /* TRANSMUTE  */
    TYPEID = 294,                  /* TYPEID  */
    UNION = 295,                   /* UNION  */
    USING = 296,                   /* USING  */
    WHEN = 297,                    /* WHEN  */
    WHERE = 298,                   /* WHERE  */
    BOOL = 299,                    /* BOOL  */
    B8 = 300,                      /* B8  */
    B16 = 301,                     /* B16  */
    B32 = 302,                     /* B32  */
    B64 = 303,                     /* B64  */
    INT = 304,                     /* INT  */
    I8 = 305,                      /* I8  */
    I16 = 306,                     /* I16  */
    I32 = 307,                     /* I32  */
    I64 = 308,                     /* I64  */
    I128 = 309,                    /* I128  */
    UINT = 310,                    /* UINT  */
    U8 = 311,                      /* U8  */
    U16 = 312,                     /* U16  */
    U32 = 313,                     /* U32  */
    U64 = 314,                     /* U64  */
    U128 = 315,                    /* U128  */
    UINTPTR = 316,                 /* UINTPTR  */
    F16 = 317,                     /* F16  */
    F32 = 318,                     /* F32  */
    F64 = 319,                     /* F64  */
    COMPLEX32 = 320,               /* COMPLEX32  */
    COMPLEX64 = 321,               /* COMPLEX64  */
    COMPLEX128 = 322,              /* COMPLEX128  */
    QUATERNION64 = 323,            /* QUATERNION64  */
    QUATERNION128 = 324,           /* QUATERNION128  */
    QUATERNION256 = 325,           /* QUATERNION256  */
    STRING = 326,                  /* STRING  */
    CSTRING = 327,                 /* CSTRING  */
    BYTE = 328,                    /* BYTE  */
    RUNE = 329,                    /* RUNE  */
    RAWPTR = 330,                  /* RAWPTR  */
    ANY = 331,                     /* ANY  */
    INT_LIT = 332,                 /* INT_LIT  */
    FLOAT_LIT = 333,               /* FLOAT_LIT  */
    ID = 334,                      /* ID  */
    STRING_LIT = 335,              /* STRING_LIT  */
    RAW_STRING_LIT = 336,          /* RAW_STRING_LIT  */
    IMAGINARY_LIT = 337,           /* IMAGINARY_LIT  */
    RUNE_LIT = 338,                /* RUNE_LIT  */
    NIL = 339,                     /* NIL  */
    UNDEFINED = 340,               /* UNDEFINED  */
    ATTRIBUTE = 341,               /* ATTRIBUTE  */
    BUILD_DIRECTIVE = 342,         /* BUILD_DIRECTIVE  */
    DIRECTIVE = 343,               /* DIRECTIVE  */
    AT = 344,                      /* AT  */
    OP_ADD_ASSIGN = 345,           /* OP_ADD_ASSIGN  */
    OP_SUB_ASSIGN = 346,           /* OP_SUB_ASSIGN  */
    OP_MUL_ASSIGN = 347,           /* OP_MUL_ASSIGN  */
    OP_DIV_ASSIGN = 348,           /* OP_DIV_ASSIGN  */
    OP_MOD_ASSIGN = 349,           /* OP_MOD_ASSIGN  */
    OP_MOD2_ASSIGN = 350,          /* OP_MOD2_ASSIGN  */
    OP_OR_ASSIGN = 351,            /* OP_OR_ASSIGN  */
    OP_NOT_ASSIGN = 352,           /* OP_NOT_ASSIGN  */
    OP_AND_ASSIGN = 353,           /* OP_AND_ASSIGN  */
    OP_AND_NOT_ASSIGN = 354,       /* OP_AND_NOT_ASSIGN  */
    OP_SHL_ASSIGN = 355,           /* OP_SHL_ASSIGN  */
    OP_SHR_ASSIGN = 356,           /* OP_SHR_ASSIGN  */
    OP_LOG_AND_ASSIGN = 357,       /* OP_LOG_AND_ASSIGN  */
    OP_LOG_OR_ASSIGN = 358,        /* OP_LOG_OR_ASSIGN  */
    OP_LOG_AND = 359,              /* OP_LOG_AND  */
    OP_LOG_OR = 360,               /* OP_LOG_OR  */
    OP_AND_NOT = 361,              /* OP_AND_NOT  */
    OP_SHL = 362,                  /* OP_SHL  */
    OP_SHR = 363,                  /* OP_SHR  */
    OP_EQ = 364,                   /* OP_EQ  */
    OP_NE = 365,                   /* OP_NE  */
    OP_LE = 366,                   /* OP_LE  */
    OP_GE = 367,                   /* OP_GE  */
    OP_RANGE = 368,                /* OP_RANGE  */
    OP_RANGE_INCLUSIVE = 369,      /* OP_RANGE_INCLUSIVE  */
    OP_RANGE_EXCLUSIVE = 370,      /* OP_RANGE_EXCLUSIVE  */
    OP_ARROW = 371,                /* OP_ARROW  */
    OP_DECL_TYPED = 372,           /* OP_DECL_TYPED  */
    OP_DECL_INFERRED = 373,        /* OP_DECL_INFERRED  */
    OP_MOD2 = 374,                 /* OP_MOD2  */
    OP_DOLLAR = 375,               /* OP_DOLLAR  */
    LEX_ERROR = 376,               /* LEX_ERROR  */
    UNARY = 377                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "parser.y"

    long long    int_val;  /* целочисленный литерал   */
    double       float_val;  /* вещественный литерал    */
    char        *str_val;   /* ID, строки, директивы   */
    unsigned int rune_val;   /* символьный (rune) литерал */

#line 193 "parser.tab.h"

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
