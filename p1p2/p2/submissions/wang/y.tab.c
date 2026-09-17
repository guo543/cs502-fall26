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
#include <string.h>
#include <iostream>
#include "typecheck.h"
#include <vector>
#include "ast.h"
#include "stt.h"
void yyerror( const char *);

extern int yylex();

// Global variables defined by lex.yy.c.
extern int yylineno;
extern char* yytext;
extern FILE *yyin;

struct ASTNode* root;

#line 91 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    KW_BOOLEAN = 258,              /* KW_BOOLEAN  */
    KW_CLASS = 259,                /* KW_CLASS  */
    KW_PUBLIC = 260,               /* KW_PUBLIC  */
    KW_PRIVATE = 261,              /* KW_PRIVATE  */
    KW_STATIC = 262,               /* KW_STATIC  */
    KW_VOID = 263,                 /* KW_VOID  */
    KW_STRING = 264,               /* KW_STRING  */
    KW_INT = 265,                  /* KW_INT  */
    KW_IF = 266,                   /* KW_IF  */
    KW_ELSE = 267,                 /* KW_ELSE  */
    KW_WHILE = 268,                /* KW_WHILE  */
    KW_RETURN = 269,               /* KW_RETURN  */
    KW_NEW = 270,                  /* KW_NEW  */
    PRINTLN = 271,                 /* PRINTLN  */
    PRINT = 272,                   /* PRINT  */
    PARSEINT = 273,                /* PARSEINT  */
    LENGTH = 274,                  /* LENGTH  */
    KW_TRUE = 275,                 /* KW_TRUE  */
    KW_FALSE = 276,                /* KW_FALSE  */
    TOK_ID = 277,                  /* TOK_ID  */
    TOK_STRLITERAL = 278,          /* TOK_STRLITERAL  */
    TOK_INTLITERAL = 279,          /* TOK_INTLITERAL  */
    TOK_PLUSPLUS = 280,            /* TOK_PLUSPLUS  */
    TOK_MINUSMINUS = 281,          /* TOK_MINUSMINUS  */
    TOK_ANDAND = 282,              /* TOK_ANDAND  */
    TOK_OROR = 283,                /* TOK_OROR  */
    TOK_GREQ = 284,                /* TOK_GREQ  */
    TOK_LEQ = 285,                 /* TOK_LEQ  */
    TOK_EQEQ = 286,                /* TOK_EQEQ  */
    TOK_NEQ = 287,                 /* TOK_NEQ  */
    INT_LITERAL = 288,             /* INT_LITERAL  */
    STR_LITERAL = 289,             /* STR_LITERAL  */
    ID = 290,                      /* ID  */
    KW_MAIN = 291                  /* KW_MAIN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_BOOLEAN 258
#define KW_CLASS 259
#define KW_PUBLIC 260
#define KW_PRIVATE 261
#define KW_STATIC 262
#define KW_VOID 263
#define KW_STRING 264
#define KW_INT 265
#define KW_IF 266
#define KW_ELSE 267
#define KW_WHILE 268
#define KW_RETURN 269
#define KW_NEW 270
#define PRINTLN 271
#define PRINT 272
#define PARSEINT 273
#define LENGTH 274
#define KW_TRUE 275
#define KW_FALSE 276
#define TOK_ID 277
#define TOK_STRLITERAL 278
#define TOK_INTLITERAL 279
#define TOK_PLUSPLUS 280
#define TOK_MINUSMINUS 281
#define TOK_ANDAND 282
#define TOK_OROR 283
#define TOK_GREQ 284
#define TOK_LEQ 285
#define TOK_EQEQ 286
#define TOK_NEQ 287
#define INT_LITERAL 288
#define STR_LITERAL 289
#define ID 290
#define KW_MAIN 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

    struct ASTNode* node;
    int integer;
    char* string;

#line 222 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_BOOLEAN = 3,                 /* KW_BOOLEAN  */
  YYSYMBOL_KW_CLASS = 4,                   /* KW_CLASS  */
  YYSYMBOL_KW_PUBLIC = 5,                  /* KW_PUBLIC  */
  YYSYMBOL_KW_PRIVATE = 6,                 /* KW_PRIVATE  */
  YYSYMBOL_KW_STATIC = 7,                  /* KW_STATIC  */
  YYSYMBOL_KW_VOID = 8,                    /* KW_VOID  */
  YYSYMBOL_KW_STRING = 9,                  /* KW_STRING  */
  YYSYMBOL_KW_INT = 10,                    /* KW_INT  */
  YYSYMBOL_KW_IF = 11,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 12,                   /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 13,                  /* KW_WHILE  */
  YYSYMBOL_KW_RETURN = 14,                 /* KW_RETURN  */
  YYSYMBOL_KW_NEW = 15,                    /* KW_NEW  */
  YYSYMBOL_PRINTLN = 16,                   /* PRINTLN  */
  YYSYMBOL_PRINT = 17,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 18,                  /* PARSEINT  */
  YYSYMBOL_LENGTH = 19,                    /* LENGTH  */
  YYSYMBOL_KW_TRUE = 20,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 21,                  /* KW_FALSE  */
  YYSYMBOL_TOK_ID = 22,                    /* TOK_ID  */
  YYSYMBOL_TOK_STRLITERAL = 23,            /* TOK_STRLITERAL  */
  YYSYMBOL_TOK_INTLITERAL = 24,            /* TOK_INTLITERAL  */
  YYSYMBOL_TOK_PLUSPLUS = 25,              /* TOK_PLUSPLUS  */
  YYSYMBOL_TOK_MINUSMINUS = 26,            /* TOK_MINUSMINUS  */
  YYSYMBOL_TOK_ANDAND = 27,                /* TOK_ANDAND  */
  YYSYMBOL_TOK_OROR = 28,                  /* TOK_OROR  */
  YYSYMBOL_TOK_GREQ = 29,                  /* TOK_GREQ  */
  YYSYMBOL_TOK_LEQ = 30,                   /* TOK_LEQ  */
  YYSYMBOL_TOK_EQEQ = 31,                  /* TOK_EQEQ  */
  YYSYMBOL_TOK_NEQ = 32,                   /* TOK_NEQ  */
  YYSYMBOL_INT_LITERAL = 33,               /* INT_LITERAL  */
  YYSYMBOL_STR_LITERAL = 34,               /* STR_LITERAL  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_KW_MAIN = 36,                   /* KW_MAIN  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '['  */
  YYSYMBOL_42_ = 42,                       /* ']'  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_46_ = 46,                       /* '+'  */
  YYSYMBOL_47_ = 47,                       /* '-'  */
  YYSYMBOL_48_ = 48,                       /* '!'  */
  YYSYMBOL_49_ = 49,                       /* '*'  */
  YYSYMBOL_50_ = 50,                       /* '/'  */
  YYSYMBOL_51_ = 51,                       /* '<'  */
  YYSYMBOL_52_ = 52,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_Program = 54,                   /* Program  */
  YYSYMBOL_MainClass = 55,                 /* MainClass  */
  YYSYMBOL_MainMethod = 56,                /* MainMethod  */
  YYSYMBOL_MainMethodArgs = 57,            /* MainMethodArgs  */
  YYSYMBOL_PrimeType = 58,                 /* PrimeType  */
  YYSYMBOL_Type = 59,                      /* Type  */
  YYSYMBOL_StaticVarDeclList = 60,         /* StaticVarDeclList  */
  YYSYMBOL_StaticVarDecl = 61,             /* StaticVarDecl  */
  YYSYMBOL_VarDeclLine = 62,               /* VarDeclLine  */
  YYSYMBOL_ExtraVarDecl = 63,              /* ExtraVarDecl  */
  YYSYMBOL_VarInit = 64,                   /* VarInit  */
  YYSYMBOL_StaticMethodDeclList = 65,      /* StaticMethodDeclList  */
  YYSYMBOL_StaticMethodDecl = 66,          /* StaticMethodDecl  */
  YYSYMBOL_MethodCall = 67,                /* MethodCall  */
  YYSYMBOL_FormalList = 68,                /* FormalList  */
  YYSYMBOL_FormalVar = 69,                 /* FormalVar  */
  YYSYMBOL_LeftValue = 70,                 /* LeftValue  */
  YYSYMBOL_StatementList = 71,             /* StatementList  */
  YYSYMBOL_Statement = 72,                 /* Statement  */
  YYSYMBOL_ExpList = 73,                   /* ExpList  */
  YYSYMBOL_ExpL16 = 74,                    /* ExpL16  */
  YYSYMBOL_ExpL14 = 75,                    /* ExpL14  */
  YYSYMBOL_ExpL12 = 76,                    /* ExpL12  */
  YYSYMBOL_ExpL11 = 77,                    /* ExpL11  */
  YYSYMBOL_ExpL9 = 78,                     /* ExpL9  */
  YYSYMBOL_ExpL8 = 79,                     /* ExpL8  */
  YYSYMBOL_ExpL4 = 80,                     /* ExpL4  */
  YYSYMBOL_ExpL3 = 81,                     /* ExpL3  */
  YYSYMBOL_Exp = 82,                       /* Exp  */
  YYSYMBOL_Index = 83                      /* Index  */
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
#define YYLAST   187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,     2,     2,     2,     2,
      39,    40,    49,    46,    44,    47,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      51,    45,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    67,    80,    91,   100,   104,   108,   115,
     118,   124,   128,   134,   141,   152,   159,   165,   169,   175,
     179,   185,   196,   201,   208,   212,   216,   222,   230,   238,
     242,   248,   251,   255,   261,   266,   270,   274,   279,   283,
     289,   293,   297,   303,   306,   311,   316,   321,   326,   330,
     333,   336,   346,   350,   354,   358,   364,   369,   374,   380,
     385,   390,   396,   401,   406,   411,   416,   422,   427,   432,
     438,   443,   449,   454,   460,   466,   471
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
  "\"end of file\"", "error", "\"invalid token\"", "KW_BOOLEAN",
  "KW_CLASS", "KW_PUBLIC", "KW_PRIVATE", "KW_STATIC", "KW_VOID",
  "KW_STRING", "KW_INT", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_RETURN",
  "KW_NEW", "PRINTLN", "PRINT", "PARSEINT", "LENGTH", "KW_TRUE",
  "KW_FALSE", "TOK_ID", "TOK_STRLITERAL", "TOK_INTLITERAL", "TOK_PLUSPLUS",
  "TOK_MINUSMINUS", "TOK_ANDAND", "TOK_OROR", "TOK_GREQ", "TOK_LEQ",
  "TOK_EQEQ", "TOK_NEQ", "INT_LITERAL", "STR_LITERAL", "ID", "KW_MAIN",
  "'{'", "'}'", "'('", "')'", "'['", "']'", "';'", "','", "'='", "'+'",
  "'-'", "'!'", "'*'", "'/'", "'<'", "'>'", "$accept", "Program",
  "MainClass", "MainMethod", "MainMethodArgs", "PrimeType", "Type",
  "StaticVarDeclList", "StaticVarDecl", "VarDeclLine", "ExtraVarDecl",
  "VarInit", "StaticMethodDeclList", "StaticMethodDecl", "MethodCall",
  "FormalList", "FormalVar", "LeftValue", "StatementList", "Statement",
  "ExpList", "ExpL16", "ExpL14", "ExpL12", "ExpL11", "ExpL9", "ExpL8",
  "ExpL4", "ExpL3", "Exp", "Index", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -14,    30,  -126,    10,  -126,  -126,    43,    37,  -126,
      49,     5,    50,    32,  -126,  -126,  -126,  -126,  -126,     7,
    -126,     8,  -126,    52,    41,    74,    46,    -8,  -126,  -126,
      83,    86,     5,    95,  -126,  -126,  -126,  -126,   107,    -8,
      -8,    -8,    -8,  -126,   129,  -126,  -126,    55,    71,    33,
     106,   122,   123,  -126,    96,   141,     5,   111,    -8,    -8,
     112,   114,  -126,  -126,  -126,  -126,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,  -126,   120,
     115,   117,    51,    38,  -126,    -8,   118,    54,  -126,    -8,
    -126,  -126,  -126,    55,    55,    71,    71,    71,    71,    33,
      33,   106,   122,    52,   119,   125,  -126,   126,     5,   124,
    -126,  -126,    -8,   127,  -126,   130,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,    42,    58,   112,   121,   128,    -8,   131,
     132,  -126,  -126,  -126,   116,   133,  -126,  -126,    -8,    -8,
     134,    -8,    -8,    98,  -126,    -8,   135,   136,  -126,   139,
     140,  -126,   138,   110,   110,   142,   143,  -126,   152,  -126,
    -126,  -126,   110,  -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,    12,    20,     0,    11,
       0,     0,     0,     0,    19,     7,     8,     6,     9,     0,
      13,     0,     3,    18,     0,     0,     0,     0,    16,    10,
       0,     0,     0,     0,    46,    47,    44,    45,    76,     0,
       0,     0,     0,    50,    49,    55,    58,    61,    66,    69,
      71,    73,    74,    17,     0,     0,    26,     0,     0,    42,
      28,     0,    52,    53,    54,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,    25,     0,     0,     0,    41,     0,
      43,    56,    57,    60,    59,    65,    64,    62,    63,    68,
      67,    70,    72,    18,     0,     0,    27,     0,     0,     0,
      23,    22,     0,     0,    15,     0,    30,    30,    24,    76,
      40,    75,     5,     0,     0,    51,     0,     0,     0,     0,
       0,    30,     4,    31,     0,     0,    29,    21,     0,     0,
       0,     0,     0,     0,    39,     0,     0,     0,    38,     0,
       0,    32,     0,     0,     0,     0,     0,    37,     0,    34,
      35,    36,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,  -126,  -126,   150,   -20,  -126,  -126,   157,
    -126,    70,  -126,  -126,  -121,  -126,    64,  -119,  -108,  -125,
    -126,  -126,    24,    73,    59,    69,   108,    97,  -126,   -39,
      68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    13,    81,    18,    19,     7,     9,   133,
      54,    28,    10,    14,    43,    83,    84,    44,   123,   136,
      87,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    26,   134,   134,   135,   135,     1,    32,    15,   124,
      33,    15,    34,    35,    16,    17,    25,    16,    17,    86,
      88,     4,   134,   143,   135,    36,    37,    38,   158,   159,
       5,    39,   134,   134,   135,   135,    82,   163,    40,    41,
      42,   134,    23,   135,    11,    15,   109,     6,    24,     8,
     113,    16,    17,   126,    12,   127,   128,    21,   129,   130,
      33,    15,    70,    71,    62,    63,    64,    16,    17,   126,
      22,   127,   128,   120,   129,   130,    33,    38,   107,   131,
     132,    31,   108,    29,    72,    73,   106,    24,    82,   140,
      91,    92,    24,    38,   111,   131,   137,    27,   112,   146,
     147,    15,   149,   150,    66,    67,   152,    16,    17,   126,
      30,   127,   128,    15,   129,   130,    33,    68,    69,    16,
      17,   126,    55,   127,   128,    56,   129,   130,    33,    95,
      96,    97,    98,    38,    58,   131,   151,    74,    75,    78,
      79,    93,    94,    99,   100,    38,    59,   131,    65,    76,
      80,    77,    85,    89,    90,   103,   104,   105,   110,   144,
     138,   115,   116,   117,   162,   122,   119,   139,    20,   121,
     141,   142,   118,   114,   102,   153,   154,   148,   145,   155,
     156,   157,    57,     0,   101,   160,   161,   125
};

static const yytype_int16 yycheck[] =
{
      39,    21,   123,   124,   123,   124,     4,    15,     3,   117,
      18,     3,    20,    21,     9,    10,     8,     9,    10,    58,
      59,    35,   143,   131,   143,    33,    34,    35,   153,   154,
       0,    39,   153,   154,   153,   154,    56,   162,    46,    47,
      48,   162,    35,   162,     7,     3,    85,    37,    41,     6,
      89,     9,    10,    11,     5,    13,    14,     7,    16,    17,
      18,     3,    29,    30,    40,    41,    42,     9,    10,    11,
      38,    13,    14,   112,    16,    17,    18,    35,    40,    37,
      38,    35,    44,    42,    51,    52,    35,    41,   108,   128,
      66,    67,    41,    35,    40,    37,    38,    45,    44,   138,
     139,     3,   141,   142,    49,    50,   145,     9,    10,    11,
      36,    13,    14,     3,    16,    17,    18,    46,    47,     9,
      10,    11,    39,    13,    14,    39,    16,    17,    18,    70,
      71,    72,    73,    35,    39,    37,    38,    31,    32,    43,
      44,    68,    69,    74,    75,    35,    39,    37,    19,    27,
       9,    28,    41,    41,    40,    35,    41,    40,    40,    43,
      39,    42,    37,    37,    12,    35,    42,    39,    11,    42,
      39,    39,   108,   103,    77,    40,    40,    43,    45,    40,
      40,    43,    32,    -1,    76,    43,    43,   119
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    54,    55,    35,     0,    37,    60,     6,    61,
      65,     7,     5,    56,    66,     3,     9,    10,    58,    59,
      62,     7,    38,    35,    41,     8,    59,    45,    64,    42,
      36,    35,    15,    18,    20,    21,    33,    34,    35,    39,
      46,    47,    48,    67,    70,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    63,    39,    39,    58,    39,    39,
      83,    82,    75,    75,    75,    19,    49,    50,    46,    47,
      29,    30,    51,    52,    31,    32,    27,    28,    43,    44,
       9,    57,    59,    68,    69,    41,    82,    73,    82,    41,
      40,    75,    75,    76,    76,    77,    77,    77,    77,    78,
      78,    79,    80,    35,    41,    40,    35,    40,    44,    82,
      40,    40,    44,    82,    64,    42,    37,    37,    69,    42,
      82,    42,    35,    71,    71,    83,    11,    13,    14,    16,
      17,    37,    38,    62,    67,    70,    72,    38,    39,    39,
      82,    39,    39,    71,    43,    45,    82,    82,    43,    82,
      82,    38,    82,    40,    40,    40,    40,    43,    72,    72,
      43,    43,    12,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    56,    57,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    63,    63,    64,    64,    65,
      65,    66,    67,    67,    68,    68,    68,    69,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    75,    75,    75,    75,    76,    76,    76,    77,
      77,    77,    78,    78,    78,    78,    78,    79,    79,    79,
      80,    80,    81,    81,    82,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     7,    10,     4,     1,     1,     1,     1,
       3,     2,     0,     3,     5,     4,     0,     2,     0,     2,
       0,    10,     4,     4,     3,     1,     0,     2,     2,     2,
       0,     1,     3,     7,     5,     5,     5,     4,     3,     2,
       3,     1,     0,     3,     1,     1,     1,     1,     2,     1,
       1,     6,     2,     2,     2,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     1,     4,     0
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
  case 2: /* Program: MainClass  */
#line 59 "parser.y"
              {
        (yyval.node) = new_node(NODETYPE_PROGRAM);
        root = (yyval.node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1402 "y.tab.c"
    break;

  case 3: /* MainClass: KW_CLASS ID '{' StaticVarDeclList StaticMethodDeclList MainMethod '}'  */
#line 70 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_MAINCLASS);
        set_string_value((yyval.node), (yyvsp[-5].string));
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1414 "y.tab.c"
    break;

  case 4: /* MainMethod: KW_PUBLIC KW_STATIC KW_VOID KW_MAIN '(' MainMethodArgs ')' '{' StatementList '}'  */
#line 81 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_MAINMETHOD);
        (yyval.node)->lineno = (yyvsp[-4].node)->lineno;
        set_string_value((yyval.node), (yyvsp[-6].string));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1426 "y.tab.c"
    break;

  case 5: /* MainMethodArgs: KW_STRING '[' ']' ID  */
#line 91 "parser.y"
                         {
        (yyval.node) = new_node(NODETYPE_MAINMETHODARGS);
        set_string_value((yyval.node), (yyvsp[0].string));
        set_data_type((yyval.node), DATATYPE_STR);
        (yyval.node)->data.dimensions = 1;
    }
#line 1437 "y.tab.c"
    break;

  case 6: /* PrimeType: KW_INT  */
#line 100 "parser.y"
           {
        (yyval.node) = new_node(NODETYPE_PRIMETYPE);
        set_data_type((yyval.node), DATATYPE_INT);
    }
#line 1446 "y.tab.c"
    break;

  case 7: /* PrimeType: KW_BOOLEAN  */
#line 104 "parser.y"
                 {
        (yyval.node) = new_node(NODETYPE_PRIMETYPE);
        set_data_type((yyval.node), DATATYPE_BOOL);
    }
#line 1455 "y.tab.c"
    break;

  case 8: /* PrimeType: KW_STRING  */
#line 108 "parser.y"
                {
        (yyval.node) = new_node(NODETYPE_PRIMETYPE);
        set_data_type((yyval.node), DATATYPE_STR);
    }
#line 1464 "y.tab.c"
    break;

  case 9: /* Type: PrimeType  */
#line 115 "parser.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1472 "y.tab.c"
    break;

  case 10: /* Type: Type '[' ']'  */
#line 118 "parser.y"
                   {
        (yyval.node)->data.dimensions++;
    }
#line 1480 "y.tab.c"
    break;

  case 11: /* StaticVarDeclList: StaticVarDeclList StaticVarDecl  */
#line 124 "parser.y"
                                    {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1489 "y.tab.c"
    break;

  case 12: /* StaticVarDeclList: %empty  */
#line 128 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_STATICVARDECLLIST);
    }
#line 1497 "y.tab.c"
    break;

  case 13: /* StaticVarDecl: KW_PRIVATE KW_STATIC VarDeclLine  */
#line 134 "parser.y"
                                     {
        (yyval.node) = (yyvsp[0].node);
        (yyval.node)->node_type = NODETYPE_STATICVARDECLLINE;
    }
#line 1506 "y.tab.c"
    break;

  case 14: /* VarDeclLine: Type ID VarInit ExtraVarDecl ';'  */
#line 141 "parser.y"
                                     {
        (yyval.node) = (yyvsp[-1].node);
        struct ASTNode* vardecl = new_node(NODETYPE_VARDECL);
        set_string_value(vardecl, (yyvsp[-3].string));
        add_child(vardecl, (yyvsp[-2].node));
        prepend_child((yyval.node), vardecl);
        prepend_child((yyval.node), (yyvsp[-4].node));
    }
#line 1519 "y.tab.c"
    break;

  case 15: /* ExtraVarDecl: ExtraVarDecl ',' ID VarInit  */
#line 152 "parser.y"
                                {
        (yyval.node) = (yyvsp[-3].node);
        struct ASTNode* vardecl = new_node(NODETYPE_VARDECL);
        set_string_value(vardecl, (yyvsp[-1].string));
        add_child(vardecl, (yyvsp[0].node));
        add_child((yyval.node), vardecl);
    }
#line 1531 "y.tab.c"
    break;

  case 16: /* ExtraVarDecl: %empty  */
#line 159 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_VARDECLLINE);
    }
#line 1539 "y.tab.c"
    break;

  case 17: /* VarInit: '=' Exp  */
#line 165 "parser.y"
            {
        (yyval.node) = new_node(NODETYPE_VARINIT);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1548 "y.tab.c"
    break;

  case 18: /* VarInit: %empty  */
#line 169 "parser.y"
      {
        (yyval.node) = NULL;
    }
#line 1556 "y.tab.c"
    break;

  case 19: /* StaticMethodDeclList: StaticMethodDeclList StaticMethodDecl  */
#line 175 "parser.y"
                                          {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1565 "y.tab.c"
    break;

  case 20: /* StaticMethodDeclList: %empty  */
#line 179 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_STATICMETHODLIST);
    }
#line 1573 "y.tab.c"
    break;

  case 21: /* StaticMethodDecl: KW_PUBLIC KW_STATIC Type ID '(' FormalList ')' '{' StatementList '}'  */
#line 185 "parser.y"
                                                                         {
        (yyval.node) = new_node(NODETYPE_STATICMETHODDECL);
        (yyval.node)->lineno = (yyvsp[-4].node)->lineno;
        set_string_value((yyval.node), (yyvsp[-6].string));
        add_child((yyval.node), (yyvsp[-7].node));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1586 "y.tab.c"
    break;

  case 22: /* MethodCall: ID '(' ExpList ')'  */
#line 196 "parser.y"
                       {
        (yyval.node) = new_node(NODETYPE_METHODCALL);
        set_string_value((yyval.node), (yyvsp[-3].string));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1596 "y.tab.c"
    break;

  case 23: /* MethodCall: PARSEINT '(' Exp ')'  */
#line 201 "parser.y"
                           {
        (yyval.node) = new_node(NODETYPE_STATEMENT_PARSEINT);
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1605 "y.tab.c"
    break;

  case 24: /* FormalList: FormalList ',' FormalVar  */
#line 208 "parser.y"
                             {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1614 "y.tab.c"
    break;

  case 25: /* FormalList: FormalVar  */
#line 212 "parser.y"
                {
        (yyval.node) = new_node(NODETYPE_FORMALLIST);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1623 "y.tab.c"
    break;

  case 26: /* FormalList: %empty  */
#line 216 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_FORMALLIST);
    }
#line 1631 "y.tab.c"
    break;

  case 27: /* FormalVar: Type ID  */
#line 222 "parser.y"
            {
        (yyval.node) = new_node(NODETYPE_FORMALVAR);
        add_child((yyval.node), (yyvsp[-1].node));
        set_string_value((yyval.node), (yyvsp[0].string));
    }
#line 1641 "y.tab.c"
    break;

  case 28: /* LeftValue: ID Index  */
#line 230 "parser.y"
             {
        (yyval.node) = new_node(NODETYPE_LEFTVALUE);
        set_string_value((yyval.node), (yyvsp[-1].string));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1651 "y.tab.c"
    break;

  case 29: /* StatementList: StatementList Statement  */
#line 238 "parser.y"
                            {
        (yyval.node) = (yyvsp[-1].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1660 "y.tab.c"
    break;

  case 30: /* StatementList: %empty  */
#line 242 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_STATEMENTLIST);
    }
#line 1668 "y.tab.c"
    break;

  case 31: /* Statement: VarDeclLine  */
#line 248 "parser.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1676 "y.tab.c"
    break;

  case 32: /* Statement: '{' StatementList '}'  */
#line 251 "parser.y"
                            {
        (yyval.node) = new_node(NODETYPE_STATEMENT_COMPOUND);
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1685 "y.tab.c"
    break;

  case 33: /* Statement: KW_IF '(' Exp ')' Statement KW_ELSE Statement  */
#line 255 "parser.y"
                                                    {
        (yyval.node) = new_node(NODETYPE_STATEMENT_IFELSE);
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1696 "y.tab.c"
    break;

  case 34: /* Statement: KW_WHILE '(' Exp ')' Statement  */
#line 261 "parser.y"
                                     {
        (yyval.node) = new_node(NODETYPE_STATEMENT_WHILE);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1706 "y.tab.c"
    break;

  case 35: /* Statement: PRINTLN '(' Exp ')' ';'  */
#line 266 "parser.y"
                              {
        (yyval.node) = new_node(NODETYPE_STATEMENT_PRINTLN);
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1715 "y.tab.c"
    break;

  case 36: /* Statement: PRINT '(' Exp ')' ';'  */
#line 270 "parser.y"
                            {
        (yyval.node) = new_node(NODETYPE_STATEMENT_PRINT);
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1724 "y.tab.c"
    break;

  case 37: /* Statement: LeftValue '=' Exp ';'  */
#line 274 "parser.y"
                            {
        (yyval.node) = new_node(NODETYPE_STATEMENT_ASSIGNMENT);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1734 "y.tab.c"
    break;

  case 38: /* Statement: KW_RETURN Exp ';'  */
#line 279 "parser.y"
                        {
        (yyval.node) = new_node(NODETYPE_STATEMENT_RETURN);
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1743 "y.tab.c"
    break;

  case 39: /* Statement: MethodCall ';'  */
#line 283 "parser.y"
                     {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1751 "y.tab.c"
    break;

  case 40: /* ExpList: ExpList ',' Exp  */
#line 289 "parser.y"
                    {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1760 "y.tab.c"
    break;

  case 41: /* ExpList: Exp  */
#line 293 "parser.y"
          {
        (yyval.node) = new_node(NODETYPE_EXPLIST);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1769 "y.tab.c"
    break;

  case 42: /* ExpList: %empty  */
#line 297 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_EXPLIST);
    }
#line 1777 "y.tab.c"
    break;

  case 43: /* ExpL16: '(' Exp ')'  */
#line 303 "parser.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1785 "y.tab.c"
    break;

  case 44: /* ExpL16: INT_LITERAL  */
#line 306 "parser.y"
                  {
        (yyval.node) = new_node(NODETYPE_EXP_INTLITERAL);
        set_data_type((yyval.node), DATATYPE_INT);
        set_int_value((yyval.node), (yyvsp[0].integer));
    }
#line 1795 "y.tab.c"
    break;

  case 45: /* ExpL16: STR_LITERAL  */
#line 311 "parser.y"
                  {
        (yyval.node) = new_node(NODETYPE_EXP_STRLITERAL);
        set_data_type((yyval.node), DATATYPE_STR);
        set_string_value((yyval.node), (yyvsp[0].string));
    }
#line 1805 "y.tab.c"
    break;

  case 46: /* ExpL16: KW_TRUE  */
#line 316 "parser.y"
              {
        (yyval.node) = new_node(NODETYPE_EXP_BOOLLITERAL);
        set_data_type((yyval.node), DATATYPE_BOOL);
        set_boolean_value((yyval.node), true);
    }
#line 1815 "y.tab.c"
    break;

  case 47: /* ExpL16: KW_FALSE  */
#line 321 "parser.y"
               {
        (yyval.node) = new_node(NODETYPE_EXP_BOOLLITERAL);
        set_data_type((yyval.node), DATATYPE_BOOL);
        set_boolean_value((yyval.node), false);
    }
#line 1825 "y.tab.c"
    break;

  case 48: /* ExpL16: LeftValue LENGTH  */
#line 326 "parser.y"
                       {
        (yyval.node) = (yyvsp[-1].node);
        (yyval.node)->node_type = NODETYPE_EXP_LEFTVALLENGTH;
    }
#line 1834 "y.tab.c"
    break;

  case 49: /* ExpL16: LeftValue  */
#line 330 "parser.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1842 "y.tab.c"
    break;

  case 50: /* ExpL16: MethodCall  */
#line 333 "parser.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1850 "y.tab.c"
    break;

  case 51: /* ExpL16: KW_NEW PrimeType '[' Exp ']' Index  */
#line 336 "parser.y"
                                         {
        (yyval.node) = new_node(NODETYPE_EXP_NEWOBJ);
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[0].node));
        prepend_child((yyvsp[0].node), (yyvsp[-2].node));
        (yyvsp[0].node)->data.dimensions++;
    }
#line 1862 "y.tab.c"
    break;

  case 52: /* ExpL14: '+' ExpL14  */
#line 346 "parser.y"
               {
        (yyval.node) = new_node(NODETYPE_EXP_POSITIVE);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1871 "y.tab.c"
    break;

  case 53: /* ExpL14: '-' ExpL14  */
#line 350 "parser.y"
                 {
        (yyval.node) = new_node(NODETYPE_EXP_NEGATIVE);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1880 "y.tab.c"
    break;

  case 54: /* ExpL14: '!' ExpL14  */
#line 354 "parser.y"
                 {
        (yyval.node) = new_node(NODETYPE_EXP_NEGATE);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1889 "y.tab.c"
    break;

  case 55: /* ExpL14: ExpL16  */
#line 358 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1897 "y.tab.c"
    break;

  case 56: /* ExpL12: ExpL12 '*' ExpL14  */
#line 364 "parser.y"
                      {
        (yyval.node) = new_node(NODETYPE_EXP_MULTIPLY);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1907 "y.tab.c"
    break;

  case 57: /* ExpL12: ExpL12 '/' ExpL14  */
#line 369 "parser.y"
                        {
        (yyval.node) = new_node(NODETYPE_EXP_DIVIDE);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1917 "y.tab.c"
    break;

  case 58: /* ExpL12: ExpL14  */
#line 374 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1925 "y.tab.c"
    break;

  case 59: /* ExpL11: ExpL11 '-' ExpL12  */
#line 380 "parser.y"
                      {
        (yyval.node) = new_node(NODETYPE_EXP_SUBTRACT);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1935 "y.tab.c"
    break;

  case 60: /* ExpL11: ExpL11 '+' ExpL12  */
#line 385 "parser.y"
                        {
        (yyval.node) = new_node(NODETYPE_EXP_ADD);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1945 "y.tab.c"
    break;

  case 61: /* ExpL11: ExpL12  */
#line 390 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1953 "y.tab.c"
    break;

  case 62: /* ExpL9: ExpL9 '<' ExpL11  */
#line 396 "parser.y"
                     {
        (yyval.node) = new_node(NODETYPE_EXP_LESSER);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1963 "y.tab.c"
    break;

  case 63: /* ExpL9: ExpL9 '>' ExpL11  */
#line 401 "parser.y"
                       {
        (yyval.node) = new_node(NODETYPE_EXP_GREATER);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1973 "y.tab.c"
    break;

  case 64: /* ExpL9: ExpL9 TOK_LEQ ExpL11  */
#line 406 "parser.y"
                           {
        (yyval.node) = new_node(NODETYPE_EXP_LEQ);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1983 "y.tab.c"
    break;

  case 65: /* ExpL9: ExpL9 TOK_GREQ ExpL11  */
#line 411 "parser.y"
                            {
        (yyval.node) = new_node(NODETYPE_EXP_GREQ);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1993 "y.tab.c"
    break;

  case 66: /* ExpL9: ExpL11  */
#line 416 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2001 "y.tab.c"
    break;

  case 67: /* ExpL8: ExpL8 TOK_NEQ ExpL9  */
#line 422 "parser.y"
                        {
        (yyval.node) = new_node(NODETYPE_EXP_NEQ);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2011 "y.tab.c"
    break;

  case 68: /* ExpL8: ExpL8 TOK_EQEQ ExpL9  */
#line 427 "parser.y"
                           {
        (yyval.node) = new_node(NODETYPE_EXP_EQEQ);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2021 "y.tab.c"
    break;

  case 69: /* ExpL8: ExpL9  */
#line 432 "parser.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2029 "y.tab.c"
    break;

  case 70: /* ExpL4: ExpL4 TOK_ANDAND ExpL8  */
#line 438 "parser.y"
                           {
        (yyval.node) = new_node(NODETYPE_EXP_LOGAND);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2039 "y.tab.c"
    break;

  case 71: /* ExpL4: ExpL8  */
#line 443 "parser.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2047 "y.tab.c"
    break;

  case 72: /* ExpL3: ExpL3 TOK_OROR ExpL4  */
#line 449 "parser.y"
                         {
        (yyval.node) = new_node(NODETYPE_EXP_LOGOR);
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2057 "y.tab.c"
    break;

  case 73: /* ExpL3: ExpL4  */
#line 454 "parser.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2065 "y.tab.c"
    break;

  case 74: /* Exp: ExpL3  */
#line 460 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2073 "y.tab.c"
    break;

  case 75: /* Index: Index '[' Exp ']'  */
#line 466 "parser.y"
                      {
        (yyval.node) = (yyvsp[-3].node);
        add_child((yyval.node), (yyvsp[-1].node));
        (yyval.node)->data.dimensions++;
    }
#line 2083 "y.tab.c"
    break;

  case 76: /* Index: %empty  */
#line 471 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_INDEX);
    }
#line 2091 "y.tab.c"
    break;


#line 2095 "y.tab.c"

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

#line 475 "parser.y"


void yyerror( const char* s) {
    fprintf(stderr, "Syntax errors in line %d\n", yylineno);
}

int main(int argc, char* argv[] )
{
    yyin = fopen( argv[1], "r" );

    // Checks for syntax errors and constructs AST
    if (yyparse() != 0)
        return 1;

    // Traverse the AST to check for semantic errors if no syntac errors
    constructSTT(root);
    //printSTT(root->scope);
    typeCheck(root);
    //print_AST(root, 0);
    dump_reports();
    
    return 0;
}
