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
#line 1 "gpp_interpreter.y"

/*definitions*/
#include <stdio.h> 
#include <stdlib.h> //for exit function and malloc
#include <string.h> //for string operations

#include "helpers.h" // for all the structs (valuef_t, variable_t, function_t)
#include "helperMethods.h" // for all the helper methods 

FILE *inputFile,*outputFile, *strFile; //input and output files for reading and writing

extern FILE *yyin;
void writeList(int *list);

#include "valueF.h" //functions for fractional numbers
#include "variables.h" //functions for variables (set, get)
#include "functionsDef.h" //functions for functions definitions (set, get)


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
    OP_PLUS = 258,                 /* OP_PLUS  */
    OP_MINUS = 259,                /* OP_MINUS  */
    OP_DIV = 260,                  /* OP_DIV  */
    OP_MULT = 261,                 /* OP_MULT  */
    OP_OP = 262,                   /* OP_OP  */
    OP_CP = 263,                   /* OP_CP  */
    OP_COMMA = 264,                /* OP_COMMA  */
    KW_AND = 265,                  /* KW_AND  */
    KW_OR = 266,                   /* KW_OR  */
    KW_NOT = 267,                  /* KW_NOT  */
    KW_EQUAL = 268,                /* KW_EQUAL  */
    KW_LESS = 269,                 /* KW_LESS  */
    KW_NIL = 270,                  /* KW_NIL  */
    KW_LIST = 271,                 /* KW_LIST  */
    KW_APPEND = 272,               /* KW_APPEND  */
    KW_CONCAT = 273,               /* KW_CONCAT  */
    KW_SET = 274,                  /* KW_SET  */
    KW_DEF = 275,                  /* KW_DEF  */
    KW_FOR = 276,                  /* KW_FOR  */
    KW_IF = 277,                   /* KW_IF  */
    KW_EXIT = 278,                 /* KW_EXIT  */
    KW_LOAD = 279,                 /* KW_LOAD  */
    KW_DISP = 280,                 /* KW_DISP  */
    KW_TRUE = 281,                 /* KW_TRUE  */
    KW_FALSE = 282,                /* KW_FALSE  */
    COMMENT = 283,                 /* COMMENT  */
    VALUEF = 284,                  /* VALUEF  */
    IDENTIFIER = 285               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define OP_PLUS 258
#define OP_MINUS 259
#define OP_DIV 260
#define OP_MULT 261
#define OP_OP 262
#define OP_CP 263
#define OP_COMMA 264
#define KW_AND 265
#define KW_OR 266
#define KW_NOT 267
#define KW_EQUAL 268
#define KW_LESS 269
#define KW_NIL 270
#define KW_LIST 271
#define KW_APPEND 272
#define KW_CONCAT 273
#define KW_SET 274
#define KW_DEF 275
#define KW_FOR 276
#define KW_IF 277
#define KW_EXIT 278
#define KW_LOAD 279
#define KW_DISP 280
#define KW_TRUE 281
#define KW_FALSE 282
#define COMMENT 283
#define VALUEF 284
#define IDENTIFIER 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "gpp_interpreter.y"

    int num;
    int *nums;
    char *str;
    valuef_t fractionalNum;

#line 211 "y.tab.c"

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
  YYSYMBOL_OP_PLUS = 3,                    /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 4,                   /* OP_MINUS  */
  YYSYMBOL_OP_DIV = 5,                     /* OP_DIV  */
  YYSYMBOL_OP_MULT = 6,                    /* OP_MULT  */
  YYSYMBOL_OP_OP = 7,                      /* OP_OP  */
  YYSYMBOL_OP_CP = 8,                      /* OP_CP  */
  YYSYMBOL_OP_COMMA = 9,                   /* OP_COMMA  */
  YYSYMBOL_KW_AND = 10,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 11,                     /* KW_OR  */
  YYSYMBOL_KW_NOT = 12,                    /* KW_NOT  */
  YYSYMBOL_KW_EQUAL = 13,                  /* KW_EQUAL  */
  YYSYMBOL_KW_LESS = 14,                   /* KW_LESS  */
  YYSYMBOL_KW_NIL = 15,                    /* KW_NIL  */
  YYSYMBOL_KW_LIST = 16,                   /* KW_LIST  */
  YYSYMBOL_KW_APPEND = 17,                 /* KW_APPEND  */
  YYSYMBOL_KW_CONCAT = 18,                 /* KW_CONCAT  */
  YYSYMBOL_KW_SET = 19,                    /* KW_SET  */
  YYSYMBOL_KW_DEF = 20,                    /* KW_DEF  */
  YYSYMBOL_KW_FOR = 21,                    /* KW_FOR  */
  YYSYMBOL_KW_IF = 22,                     /* KW_IF  */
  YYSYMBOL_KW_EXIT = 23,                   /* KW_EXIT  */
  YYSYMBOL_KW_LOAD = 24,                   /* KW_LOAD  */
  YYSYMBOL_KW_DISP = 25,                   /* KW_DISP  */
  YYSYMBOL_KW_TRUE = 26,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 27,                  /* KW_FALSE  */
  YYSYMBOL_COMMENT = 28,                   /* COMMENT  */
  YYSYMBOL_VALUEF = 29,                    /* VALUEF  */
  YYSYMBOL_IDENTIFIER = 30,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_START = 32,                     /* START  */
  YYSYMBOL_EXPI = 33,                      /* EXPI  */
  YYSYMBOL_EXPB = 34,                      /* EXPB  */
  YYSYMBOL_FUNCTION = 35                   /* FUNCTION  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  5
/* YYNRULES -- Number of rules.  */
#define YYNRULES  34
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  93

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    71,    73,    75,    77,    79,    81,    83,
      86,    98,   100,   102,   104,   106,   108,   110,   112,   114,
     116,   118,   120,   124,   126,   128,   130,   132,   134,   136,
     138,   140,   145,   151,   157
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
  "\"end of file\"", "error", "\"invalid token\"", "OP_PLUS", "OP_MINUS",
  "OP_DIV", "OP_MULT", "OP_OP", "OP_CP", "OP_COMMA", "KW_AND", "KW_OR",
  "KW_NOT", "KW_EQUAL", "KW_LESS", "KW_NIL", "KW_LIST", "KW_APPEND",
  "KW_CONCAT", "KW_SET", "KW_DEF", "KW_FOR", "KW_IF", "KW_EXIT", "KW_LOAD",
  "KW_DISP", "KW_TRUE", "KW_FALSE", "COMMENT", "VALUEF", "IDENTIFIER",
  "$accept", "START", "EXPI", "EXPB", "FUNCTION", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-28)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,    82,   -28,   -28,   -28,   -28,   -28,     1,   -28,   -28,
     -28,    34,    34,    34,    34,    72,    72,    72,    44,    34,
     -27,   -26,    72,    72,    -3,    44,    -2,   -28,   105,   -28,
     -28,   -28,   140,    34,    34,    34,    34,   161,    72,    72,
       2,   128,    34,    72,    34,    34,   -21,    34,    34,   -28,
       9,    12,   -28,    18,    34,    24,    32,    35,    41,    72,
      42,    45,   -28,    52,    57,    58,    60,     8,    64,    51,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,    34,    67,   -28,   -28,    68,    75,
     -28,   -28,   -28
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    29,    30,     6,    17,    16,     0,     2,     3,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     7,
       4,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
      22,    31,     9,    10,    11,    13,    12,    23,    24,    27,
      26,    28,    18,    34,    16,     0,    20,    19,     0,     0,
      33,    21,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,     0,    39,   -28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,    50,    51,    10
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       8,    27,     1,    45,    46,    49,    52,    30,    28,    67,
      62,    33,    34,    35,    36,    32,    83,    70,    42,    44,
      71,     2,     3,     4,     5,     6,    72,     2,     3,    29,
       5,     6,    73,    55,    56,    57,    58,     5,    84,     9,
      74,    32,    63,    75,    65,    66,    31,    68,    69,    76,
      77,    41,     0,    78,    38,    39,    40,    43,    32,    87,
      79,    47,    48,     5,     6,    80,    81,    85,    82,    88,
       2,     3,    86,     5,     6,    90,    91,    60,    61,    37,
       5,     6,    64,    92,    89,    11,    12,    13,    14,     0,
       0,     0,    15,    16,    17,    18,    19,     0,     2,     3,
       0,    20,    21,    22,    23,    24,     0,    25,    11,    12,
      13,    14,    26,     0,     0,    15,    16,    17,    18,    19,
       0,     0,     0,     0,    20,    21,    22,    23,    53,     0,
      25,    11,    12,    13,    14,    26,     0,     0,    15,    16,
      17,    18,    19,    11,    12,    13,    14,    20,    21,    22,
      23,     0,     0,    25,     0,     0,     0,     0,    26,    20,
      21,    22,    23,     0,     0,    54,     0,     0,     0,     0,
      26,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59
};

static const yytype_int8 yycheck[] =
{
       0,     0,     7,    30,    30,     8,     8,     7,     7,    30,
       8,    11,    12,    13,    14,     7,     8,     8,    18,    19,
       8,    26,    27,    28,    29,    30,     8,    26,    27,    28,
      29,    30,     8,    33,    34,    35,    36,    29,    30,     0,
       8,     7,    42,     8,    44,    45,     7,    47,    48,     8,
       8,     7,    -1,     8,    15,    16,    17,    18,     7,     8,
       8,    22,    23,    29,    30,     8,     8,    67,     8,    69,
      26,    27,     8,    29,    30,     8,     8,    38,    39,     7,
      29,    30,    43,     8,    84,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    -1,    26,    27,
      -1,    19,    20,    21,    22,    23,    -1,    25,     3,     4,
       5,     6,    30,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,
      25,     3,     4,     5,     6,    30,    -1,    -1,    10,    11,
      12,    13,    14,     3,     4,     5,     6,    19,    20,    21,
      22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    19,
      20,    21,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      30,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    26,    27,    28,    29,    30,    32,    33,    34,
      35,     3,     4,     5,     6,    10,    11,    12,    13,    14,
      19,    20,    21,    22,    23,    25,    30,     0,     7,    28,
      33,    34,     7,    33,    33,    33,    33,     7,    34,    34,
      34,     7,    33,    34,    33,    30,    30,    34,    34,     8,
      33,    34,     8,    23,    25,    33,    33,    33,    33,    25,
      34,    34,     8,    33,    34,    33,    33,    30,    33,    33,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,    30,    33,     8,     8,    33,    33,
       8,     8,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    32,    32,    32,    32,    32,    32,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    35,    35,    35
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     2,     3,     4,
       5,     5,     5,     5,     1,     3,     1,     1,     5,     5,
       5,     6,     4,     5,     5,     4,     5,     5,     5,     1,
       1,     4,     7,     6,     5
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
  case 2: /* START: EXPI  */
#line 69 "gpp_interpreter.y"
         {printf("expi"); fprintf(outputFile,"CORRECT SYNTAX. \nResult: %s\n", (yyvsp[0].str) );}
#line 1290 "y.tab.c"
    break;

  case 3: /* START: EXPB  */
#line 71 "gpp_interpreter.y"
         {printf("expb"); fprintf(outputFile,"CORRECT SYNTAX. \nResult: %s\n", (yyvsp[0].num) == 1 ? "TRUE" : "FALSE");}
#line 1296 "y.tab.c"
    break;

  case 4: /* START: START EXPI  */
#line 73 "gpp_interpreter.y"
               {fprintf(outputFile,"CORRECT SYNTAX. \nResult: %s\n", (yyvsp[0].str)); printf("expression is : %s\n", (yyvsp[0].str));}
#line 1302 "y.tab.c"
    break;

  case 5: /* START: START EXPB  */
#line 75 "gpp_interpreter.y"
               {printf("start expb"); fprintf(outputFile,"CORRECT SYNTAX. \nResult: %s\n", (yyvsp[0].num) == 1 ? "TRUE" : "FALSE");}
#line 1308 "y.tab.c"
    break;

  case 6: /* START: COMMENT  */
#line 77 "gpp_interpreter.y"
            {}
#line 1314 "y.tab.c"
    break;

  case 7: /* START: START COMMENT  */
#line 79 "gpp_interpreter.y"
                  {}
#line 1320 "y.tab.c"
    break;

  case 8: /* START: OP_OP KW_EXIT OP_CP  */
#line 81 "gpp_interpreter.y"
                        { printf("File has created!\n"); exit(-1);}
#line 1326 "y.tab.c"
    break;

  case 9: /* START: START OP_OP KW_EXIT OP_CP  */
#line 83 "gpp_interpreter.y"
                              { printf("File has created!\n"); exit(-1); }
#line 1332 "y.tab.c"
    break;

  case 10: /* EXPI: OP_OP OP_PLUS EXPI EXPI OP_CP  */
#line 86 "gpp_interpreter.y"
                                   { 
                                        if(isDigit((yyvsp[-2].str)[0]) && isDigit((yyvsp[-1].str)[0])){
                                            (yyval.str) = sumF((yyvsp[-2].str), (yyvsp[-1].str)); 
                                        } 
                                        else{
                                            //string concat ( new string: (+ $3 $4) )
                                            char * result = createExpString((yyvsp[-2].str), (yyvsp[-1].str), "+");
                                            (yyval.str) = result;
                                        }
                                    }
#line 1347 "y.tab.c"
    break;

  case 11: /* EXPI: OP_OP OP_MINUS EXPI EXPI OP_CP  */
#line 98 "gpp_interpreter.y"
                                   { (yyval.str) = subF((yyvsp[-2].str), (yyvsp[-1].str)); }
#line 1353 "y.tab.c"
    break;

  case 12: /* EXPI: OP_OP OP_MULT EXPI EXPI OP_CP  */
#line 100 "gpp_interpreter.y"
                                   { (yyval.str) = multF((yyvsp[-2].str), (yyvsp[-1].str)); }
#line 1359 "y.tab.c"
    break;

  case 13: /* EXPI: OP_OP OP_DIV EXPI EXPI OP_CP  */
#line 102 "gpp_interpreter.y"
                                   {  (yyval.str) = divF((yyvsp[-2].str), (yyvsp[-1].str)); }
#line 1365 "y.tab.c"
    break;

  case 14: /* EXPI: FUNCTION  */
#line 104 "gpp_interpreter.y"
             { printf("a function named %s is created\n", (yyvsp[0].str)); (yyval.str) = (yyvsp[0].str); }
#line 1371 "y.tab.c"
    break;

  case 15: /* EXPI: OP_OP IDENTIFIER OP_CP  */
#line 106 "gpp_interpreter.y"
                           {(yyval.str) = getVariableValue((yyvsp[-1].str)); }
#line 1377 "y.tab.c"
    break;

  case 16: /* EXPI: IDENTIFIER  */
#line 108 "gpp_interpreter.y"
               {(yyval.str) = (yyvsp[0].str);}
#line 1383 "y.tab.c"
    break;

  case 17: /* EXPI: VALUEF  */
#line 110 "gpp_interpreter.y"
           {(yyval.str) = valuefToString((yyvsp[0].fractionalNum)) ;}
#line 1389 "y.tab.c"
    break;

  case 18: /* EXPI: OP_OP KW_SET IDENTIFIER EXPI OP_CP  */
#line 112 "gpp_interpreter.y"
                                       {printf("burdayim sette\n"); (yyval.str) = (yyvsp[-1].str); setVariable((yyvsp[-2].str), (yyvsp[-1].str));}
#line 1395 "y.tab.c"
    break;

  case 19: /* EXPI: OP_OP KW_IF EXPB EXPI OP_CP  */
#line 114 "gpp_interpreter.y"
                                { (yyval.str) = (yyvsp[-2].num) ? (yyvsp[-1].str) : "FALSE"; }
#line 1401 "y.tab.c"
    break;

  case 20: /* EXPI: OP_OP KW_FOR EXPB EXPI OP_CP  */
#line 116 "gpp_interpreter.y"
                                 { /* $$ = $4; for(int i=0; isTrue($3); ++i){$4 = $4;}*/ }
#line 1407 "y.tab.c"
    break;

  case 21: /* EXPI: OP_OP KW_IF EXPB EXPI EXPI OP_CP  */
#line 118 "gpp_interpreter.y"
                                     { /* $$ = isTrue($3) ? $4 : $5; */ }
#line 1413 "y.tab.c"
    break;

  case 22: /* EXPI: OP_OP KW_DISP EXPI OP_CP  */
#line 120 "gpp_interpreter.y"
                             { /*$$ = $3; fprintf(outputFile,"Display : %d\n", $3);*/}
#line 1419 "y.tab.c"
    break;

  case 23: /* EXPB: OP_OP KW_AND EXPB EXPB OP_CP  */
#line 124 "gpp_interpreter.y"
                                 { (yyval.num) = (yyvsp[-2].num) && (yyvsp[-1].num);}
#line 1425 "y.tab.c"
    break;

  case 24: /* EXPB: OP_OP KW_OR EXPB EXPB OP_CP  */
#line 126 "gpp_interpreter.y"
                                 { (yyval.num) = (yyvsp[-2].num) || (yyvsp[-1].num); }
#line 1431 "y.tab.c"
    break;

  case 25: /* EXPB: OP_OP KW_NOT EXPB OP_CP  */
#line 128 "gpp_interpreter.y"
                             { (yyval.num) = ! ((yyvsp[-1].num)); }
#line 1437 "y.tab.c"
    break;

  case 26: /* EXPB: OP_OP KW_EQUAL EXPB EXPB OP_CP  */
#line 130 "gpp_interpreter.y"
                                   { (yyval.num) = ((yyvsp[-2].num) == (yyvsp[-1].num)); }
#line 1443 "y.tab.c"
    break;

  case 27: /* EXPB: OP_OP KW_EQUAL EXPI EXPI OP_CP  */
#line 132 "gpp_interpreter.y"
                                   { (yyval.num) = equalF((yyvsp[-2].str), (yyvsp[-1].str)); }
#line 1449 "y.tab.c"
    break;

  case 28: /* EXPB: OP_OP KW_LESS EXPI EXPI OP_CP  */
#line 134 "gpp_interpreter.y"
                                  { (yyval.num) = lessThanF((yyvsp[-2].str), (yyvsp[-1].str)); }
#line 1455 "y.tab.c"
    break;

  case 29: /* EXPB: KW_TRUE  */
#line 136 "gpp_interpreter.y"
             { (yyval.num) = 1; }
#line 1461 "y.tab.c"
    break;

  case 30: /* EXPB: KW_FALSE  */
#line 138 "gpp_interpreter.y"
               { (yyval.num) = 0; }
#line 1467 "y.tab.c"
    break;

  case 31: /* EXPB: OP_OP KW_DISP EXPB OP_CP  */
#line 140 "gpp_interpreter.y"
                             { /* $$ = $3; fprintf(outputFile,"Display : %s\n", ($3 ? "T":"NIL")); */}
#line 1473 "y.tab.c"
    break;

  case 32: /* FUNCTION: OP_OP KW_DEF IDENTIFIER IDENTIFIER IDENTIFIER EXPI OP_CP  */
#line 145 "gpp_interpreter.y"
                                                             { 
                                                                (yyval.str) = (yyvsp[-4].str); 
                                                                createFunction2((yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str)); 
                                                            }
#line 1482 "y.tab.c"
    break;

  case 33: /* FUNCTION: OP_OP KW_DEF IDENTIFIER IDENTIFIER EXPI OP_CP  */
#line 151 "gpp_interpreter.y"
                                                  { 
                                                    (yyval.str) = (yyvsp[-3].str); 
                                                    createFunction1((yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str)); 
                                                }
#line 1491 "y.tab.c"
    break;

  case 34: /* FUNCTION: OP_OP KW_DEF IDENTIFIER IDENTIFIER OP_CP  */
#line 157 "gpp_interpreter.y"
                                             { 
                                                (yyval.str) = (yyvsp[-2].str); 
                                                createFunction0((yyvsp[-2].str), (yyvsp[-1].str)); 
                                            }
#line 1500 "y.tab.c"
    break;


#line 1504 "y.tab.c"

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

#line 162 "gpp_interpreter.y"


int yyerror(char *error) {
    // this function is called when an error occurs. for example, when the input is not in the language. (syntax error)
    fprintf(outputFile, "SYNTAX ERROR \n");
}

void writeList(int *list){
    fprintf(outputFile, "(");
    for(int i=0;list[i]!=-999; ++i){
      if(list[i+1]!=-999){
        fprintf(outputFile,"%d ", list[i]);
      }
      else{
        fprintf(outputFile,"%d", list[i]);
      }
    }
    fprintf(outputFile, ")\n");
}


int main(int argc, char **argv){
  outputFile = fopen("output.txt","w");
  if(outputFile == NULL)
  {
    printf("Error output.txt doesn't exist!\n");
    exit(1);
  }
  if(argc > 1){
    //read input from file
    inputFile = fopen(argv[1],"r");
    if(inputFile == NULL)
    {
      printf("Error File doesn't exist!\n");
      exit(1);
    }
    yyin = inputFile;
    yyparse();
    printf("File has created!\n");
  }
  else{
    //read input from terminal in repl mode
    printf("Welcome to G++ shell \n> ");
    char* newLine = NULL;
    char* line = (char*)malloc(20*sizeof(char));;
    int is_empty_string;
    size_t size = 0;
    //read until empty string and store them
    do{
      is_empty_string = getline(&newLine, &size, stdin);
      if(is_empty_string != 1){
        line = (char *) realloc(line, (strlen(line)+size+2)*sizeof(char));
        strcat(line,newLine);
      }
    }while(is_empty_string != 1);
    //after reading, tokenize by using string stream fuction fmemopen
    strFile = fmemopen (line, strlen (line) - 1, "r");
    yyin = strFile;
    yyparse();
    printf("The output.txt file is created!\n");
  }
  exit(-1);
}
