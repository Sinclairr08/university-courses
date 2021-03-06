/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Kotlin2Java.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ast_tree.h"
#include "data_utils.h"

extern int yylex(void);
extern void yyterminate();
extern int yyerror(const char *s);

extern FILE * yyout;

/*yydebug = 1;*/


#line 85 "Kotlin2Java.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Kotlin2Java.tab.h".  */
#ifndef YY_YY_KOTLIN2JAVA_TAB_H_INCLUDED
# define YY_YY_KOTLIN2JAVA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    ID = 259,
    STRING = 260,
    MAIN = 261,
    IMPORT = 262,
    PACKAGE = 263,
    FUNCTION = 264,
    RETURN = 265,
    VALUE = 266,
    VARIABLE = 267,
    NUL = 268,
    TYPE_INT = 269,
    TYPE_STR = 270,
    TYPE_CHAR = 271,
    TYPE_FLOAT = 272,
    TYPE_DOUBLE = 273,
    IF = 274,
    ELSE = 275,
    WHEN = 276,
    WHILE = 277,
    STEP = 278,
    DOWNTO = 279,
    IS = 280,
    IN = 281,
    DOT = 282,
    RANGE = 283,
    COMMA = 284,
    COLON = 285,
    DOLLAR = 286,
    LPAREN = 287,
    RPAREN = 288,
    LBRACE = 289,
    RBRACE = 290,
    LBRACK = 291,
    RBRACK = 292,
    INCREM = 293,
    DECREM = 294,
    ASSN = 295,
    PLUS = 296,
    MINUS = 297,
    MUL = 298,
    DIV = 299,
    MOD = 300,
    ADDASSN = 301,
    SUBASSN = 302,
    MULASSN = 303,
    DIVASSN = 304,
    MODASSN = 305,
    LARGE = 306,
    LARGEQ = 307,
    LESS = 308,
    LESSQ = 309,
    EQ = 310,
    NEQ = 311,
    LOGOR = 312,
    LOGAND = 313,
    NOT = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "Kotlin2Java.y" /* yacc.c:355  */

    struct ast_node* node;
    double d_val;
    int i_val;
    char* s_val;

#line 192 "Kotlin2Java.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_KOTLIN2JAVA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 209 "Kotlin2Java.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   156,   165,   169,   177,   185,   189,   198,
     202,   210,   219,   227,   228,   235,   243,   247,   255,   264,
     273,   284,   295,   304,   308,   316,   323,   327,   334,   341,
     350,   362,   367,   374,   385,   390,   401,   406,   411,   416,
     421,   426,   431,   438,   444,   452,   461,   469,   478,   486,
     491,   498,   503,   510,   515,   520,   525,   530,   535,   542,
     547,   554,   559,   564,   571,   576,   583,   586,   589,   592,
     595,   599,   604,   611,   616,   621,   626,   631,   636,   643,
     650,   657,   663,   672,   677,   682,   689,   703,   710,   717,
     724,   732,   738,   744,   750,   755,   762,   767,   772,   781,
     786,   791,   798
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "STRING", "MAIN",
  "IMPORT", "PACKAGE", "FUNCTION", "RETURN", "VALUE", "VARIABLE", "NUL",
  "TYPE_INT", "TYPE_STR", "TYPE_CHAR", "TYPE_FLOAT", "TYPE_DOUBLE", "IF",
  "ELSE", "WHEN", "WHILE", "STEP", "DOWNTO", "IS", "IN", "DOT", "RANGE",
  "COMMA", "COLON", "DOLLAR", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACK", "RBRACK", "INCREM", "DECREM", "ASSN", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "ADDASSN", "SUBASSN", "MULASSN", "DIVASSN", "MODASSN",
  "LARGE", "LARGEQ", "LESS", "LESSQ", "EQ", "NEQ", "LOGOR", "LOGAND",
  "NOT", "$accept", "Program", "Code", "PackageDeclaration", "PackageName",
  "PackageSubName", "ImportList", "ImportItem", "ImportName",
  "ImportSubName", "Statements", "FunctionDeclaration", "FunctionCall",
  "Block", "Tuples", "FunctionParameters", "IfStatement",
  "Block_Or_Statement", "WhileStatement", "MemberId", "Statement",
  "ReturnStatement", "AssnStatement", "AssnDeclaration", "TypeVariable",
  "Sign", "Operator_Assn", "Operator_Low", "Operator_Mid", "Operator_High",
  "Type", "LogicalOp", "ConditionOp", "Condition", "Expression",
  "IfExpression", "ExpressionTerm", "ExpressionFactor", "ExpressionElem",
  "Literal", "StringLiteral", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -128

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-128)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    22,    39,  -128,    45,    59,  -128,  -128,    58,   141,
      45,    84,  -128,    68,  -128,  -128,   200,  -128,    38,   152,
    -128,  -128,  -128,    66,    67,   152,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,    76,   141,  -128,  -128,  -128,
     104,    31,    31,  -128,  -128,    42,    35,    53,  -128,  -128,
    -128,    59,     3,  -128,   111,   152,  -128,  -128,  -128,  -128,
    -128,  -128,   152,    85,    86,    -7,    87,  -128,   173,   173,
      83,   117,  -128,   -22,  -128,    53,    53,  -128,  -128,    31,
    -128,  -128,  -128,    31,  -128,  -128,    68,  -128,    95,  -128,
      97,   102,  -128,   130,   130,   173,    -8,   -17,    73,   -10,
    -128,   105,  -128,   183,   152,    35,    53,  -128,  -128,   152,
     106,   -20,    -1,    24,   183,   113,    55,  -128,  -128,   173,
    -128,  -128,  -128,  -128,  -128,  -128,   152,   101,  -128,  -128,
    -128,  -128,  -128,   107,  -128,  -128,   183,   137,    41,   114,
     145,  -128,   183,   176,   141,  -128,   138,  -128,    44,  -128,
    -128,   152,  -128,   129,   183,  -128,  -128,   142,  -128,   157,
     131,   101,  -128,   183,   114,  -128,  -128,  -128,  -128,  -128
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     9,     7,     5,     1,     0,    16,
       9,     0,     6,    13,    11,    94,    34,   102,     0,    44,
      50,    49,   101,     0,     0,     0,    64,    65,    51,    52,
       3,    42,    96,    36,    37,    97,    16,    38,    39,    40,
       0,     0,     0,    41,    85,    83,    88,    90,    84,    99,
      10,     7,     0,    12,     0,    23,    53,    54,    55,    56,
      57,    58,     0,     0,     0,    34,     0,    43,     0,     0,
       0,     0,    17,     0,    94,    91,    93,    59,    60,     0,
      61,    62,    63,     0,    92,     8,    13,    15,    34,    35,
       0,    25,    45,    26,    26,     0,    34,     0,     0,     0,
      95,     0,    98,     0,     0,    87,    89,    14,    21,    23,
       0,     0,     0,     0,     0,     0,     0,    71,    72,     0,
      73,    74,    75,    76,    77,    78,     0,     0,    66,    67,
      68,    69,    70,    48,    47,    24,     0,     0,     0,     0,
       0,    81,     0,    34,    16,    31,    29,    32,    80,    79,
      33,     0,    28,     0,     0,    19,    20,     0,    82,     0,
       0,     0,    46,     0,     0,    86,    22,    30,    27,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,  -128,   116,   154,  -128,  -128,    82,
     -35,  -128,    98,  -127,    61,    78,  -128,  -123,  -128,   120,
    -106,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,   -45,
    -109,  -128,  -128,   -66,   -19,  -128,  -128,    96,   -27,  -128,
    -128
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     6,    12,     9,    10,    14,    53,
      30,    31,    32,   145,    90,   111,    33,   146,    34,    35,
      36,    37,    38,    39,    40,    41,    62,    79,    83,    42,
     133,   119,   126,    97,    43,    44,    45,    46,    47,    48,
      49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      67,    72,    84,    99,   150,   141,    70,    86,   103,   137,
     147,   155,   156,   138,    75,    76,   116,   114,   104,    54,
      54,   147,     1,   127,    55,    55,     5,   152,   137,   113,
      84,    84,   139,   158,    74,    65,    91,   169,   167,     7,
     117,   118,    63,    92,    64,   164,    87,   117,   118,    98,
      98,   115,     8,   148,   168,   147,   106,   140,    15,   143,
      17,    84,    13,    25,    18,    19,    20,    21,    22,    26,
      27,   154,    28,    29,    23,   144,    98,    24,    80,    81,
      82,   117,   118,    77,    78,   134,    11,    25,    51,   144,
      91,    26,    27,    26,    27,    52,    28,    29,    68,    69,
      98,   117,   118,    71,    15,    16,    17,   149,    73,   160,
      18,    19,    20,    21,    22,    88,   100,    93,    94,    95,
      23,   101,    54,    24,   120,   121,   122,   123,   124,   125,
     108,   109,   162,    25,   110,   144,   136,    55,   142,    26,
      27,   153,    28,    29,    15,    16,    17,   151,   144,   157,
      18,    19,    20,    21,    22,    15,    65,    17,   161,   163,
      23,   165,   159,    24,    50,    22,   166,    85,   107,   102,
     135,    66,   112,    25,    89,   105,    15,    96,    17,    26,
      27,     0,    28,    29,    25,     0,    22,     0,     0,     0,
      26,    27,    66,    28,    29,     0,   159,   128,   129,   130,
     131,   132,     0,    54,     0,    25,     0,     0,    55,     0,
       0,    26,    27,     0,    28,    29,    56,     0,     0,     0,
       0,     0,    57,    58,    59,    60,    61,    54,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61
};

static const yytype_int16 yycheck[] =
{
      19,    36,    47,    69,   127,   114,    25,     4,    30,    29,
     116,   138,   139,    33,    41,    42,    33,    25,    40,    27,
      27,   127,     8,    33,    32,    32,     4,   136,    29,    95,
      75,    76,    33,   142,     3,     4,    55,   164,   161,     0,
      57,    58,     4,    62,     6,   154,    43,    57,    58,    68,
      69,    59,     7,   119,   163,   161,    83,    33,     3,     4,
       5,   106,     4,    32,     9,    10,    11,    12,    13,    38,
      39,    30,    41,    42,    19,    34,    95,    22,    43,    44,
      45,    57,    58,    41,    42,   104,    27,    32,     4,    34,
     109,    38,    39,    38,    39,    27,    41,    42,    32,    32,
     119,    57,    58,    27,     3,     4,     5,   126,     4,   144,
       9,    10,    11,    12,    13,     4,    33,    32,    32,    32,
      19,     4,    27,    22,    51,    52,    53,    54,    55,    56,
      33,    29,   151,    32,     4,    34,    30,    32,    25,    38,
      39,     4,    41,    42,     3,     4,     5,    40,    34,     4,
       9,    10,    11,    12,    13,     3,     4,     5,    20,    30,
      19,     4,    20,    22,    10,    13,    35,    51,    86,    71,
     109,    19,    94,    32,    54,    79,     3,     4,     5,    38,
      39,    -1,    41,    42,    32,    -1,    13,    -1,    -1,    -1,
      38,    39,    19,    41,    42,    -1,    20,    14,    15,    16,
      17,    18,    -1,    27,    -1,    32,    -1,    -1,    32,    -1,
      -1,    38,    39,    -1,    41,    42,    40,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    27,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    61,    62,    63,     4,    64,     0,     7,    66,
      67,    27,    65,     4,    68,     3,     4,     5,     9,    10,
      11,    12,    13,    19,    22,    32,    38,    39,    41,    42,
      70,    71,    72,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    89,    94,    95,    96,    97,    98,    99,   100,
      66,     4,    27,    69,    27,    32,    40,    46,    47,    48,
      49,    50,    86,     4,     6,     4,    19,    94,    32,    32,
      94,    27,    70,     4,     3,    98,    98,    41,    42,    87,
      43,    44,    45,    88,    89,    65,     4,    43,     4,    79,
      74,    94,    94,    32,    32,    32,     4,    93,    94,    93,
      33,     4,    72,    30,    40,    97,    98,    69,    33,    29,
       4,    75,    75,    93,    25,    59,    33,    57,    58,    91,
      51,    52,    53,    54,    55,    56,    92,    33,    14,    15,
      16,    17,    18,    90,    94,    74,    30,    29,    33,    33,
      33,    90,    25,     4,    34,    73,    77,    80,    93,    94,
      77,    40,    90,     4,    30,    73,    73,     4,    90,    20,
      70,    20,    94,    30,    90,     4,    35,    77,    90,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    63,    63,    64,    65,    65,    66,
      66,    67,    68,    69,    69,    69,    70,    70,    71,    71,
      71,    72,    73,    74,    74,    74,    75,    75,    75,    76,
      76,    77,    77,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    82,    83,    83,    83,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    87,
      87,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    91,    91,    92,    92,    92,    92,    92,    92,    93,
      93,    93,    93,    94,    94,    94,    95,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,    99,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     2,     2,     0,     3,     0,
       2,     2,     2,     0,     3,     2,     0,     2,     8,     6,
       6,     4,     3,     0,     3,     1,     0,     5,     3,     5,
       7,     1,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     6,     4,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     4,     1,     1,     1,     7,     3,     1,     3,
       1,     2,     2,     2,     1,     3,     1,     1,     3,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 145 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    printf("import java.util.* \n\n");
    printf("class Main \{\n");
    fprintf(yyout, "class Main \{\n");
    traverse_tree((yyvsp[0].node));
    printf("}\n");
    fprintf(yyout, "}\n");
    (yyval.i_val) = 0;
    }
#line 1445 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 156 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1457 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 165 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    (yyval.node) = root_here;
    }
#line 1466 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 169 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("package", TRUE));
    add_child_last(root_here, (yyvsp[0].node));
    add_child_last(root_here, create_node_enter());
    (yyval.node) = root_here;
    }
#line 1478 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 177 "Kotlin2Java.y" /* yacc.c:1646  */
    { /* Revision */
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id((yyvsp[-1].s_val), -1));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1489 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 185 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    (yyval.node) = root_here;
    }
#line 1498 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 189 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token(".", FALSE));
    add_child_last(root_here, create_node_id((yyvsp[-1].s_val), -1));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1510 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 198 "Kotlin2Java.y" /* yacc.c:1646  */
    { /* Revision */
    ast_node* root_here = create_node();
    (yyval.node) = root_here;
    }
#line 1519 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 202 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1530 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 210 "Kotlin2Java.y" /* yacc.c:1646  */
    { /* Revision */
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("import", TRUE));
    add_child_last(root_here, (yyvsp[0].node));
    add_child_last(root_here, create_node_enter());
    (yyval.node) = root_here;
    }
#line 1542 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 219 "Kotlin2Java.y" /* yacc.c:1646  */
    { /* Revision */
    ast_node* root_here = create_node("ImportName");
    add_child_last(root_here, create_node_id((yyvsp[-1].s_val), -1));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1553 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 228 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node(".", FALSE));
    add_child_last(root_here, create_node_id((yyvsp[-1].s_val), -1));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1565 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 235 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node(".", FALSE));
    add_child_last(root_here, create_node("*", FALSE));
    (yyval.node) = root_here;
    }
#line 1576 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 243 "Kotlin2Java.y" /* yacc.c:1646  */
    { /* Revision */
    ast_node* root_here = create_node();
    (yyval.node) = root_here;
    }
#line 1585 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 247 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1596 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 255 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id((yyvsp[-6].s_val), (yyvsp[-1].i_val)));
    add_child_last(root_here, create_node_token("(", FALSE));
    add_child_last(root_here, (yyvsp[-4].node));
    add_child_last(root_here, create_node_token(")", FALSE));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1610 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 264 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id((yyvsp[-4].s_val), -1));
    add_child_last(root_here, create_node_token("(", FALSE));
    add_child_last(root_here, create_node_token(")", FALSE));
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1624 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 273 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("public static void", TRUE));
    add_child_last(root_here, create_node_token("main", TRUE));
    add_child_last(root_here, create_node_token("(String[] args)", FALSE));
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1638 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 284 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id((yyvsp[-3].s_val), -1));
    add_child_last(root_here, create_node_token("(", FALSE));
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, create_node_token(")", FALSE));
    add_child_last(root_here, create_node_enter());
    (yyval.node) = root_here;
    }
#line 1652 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 295 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("\{\n", FALSE));
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, create_node_token("\}\n", FALSE));
    (yyval.node) = root_here;
    }
#line 1664 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 304 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    (yyval.node) = root_here;
    }
#line 1673 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 308 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, create_node_token(",", TRUE));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1685 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 316 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1695 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 323 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    (yyval.node) = root_here;
    }
#line 1704 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 327 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-4].node));
    add_child_last(root_here, create_node_token(",", TRUE));
    add_child_last(root_here, create_node_id((yyvsp[-2].s_val), (yyvsp[0].i_val)));
    (yyval.node) = root_here;
    }
#line 1716 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 334 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id((yyvsp[-2].s_val), (yyvsp[0].i_val)));
    (yyval.node) = root_here;
    }
#line 1726 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 341 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("if", TRUE));
    add_child_last(root_here, create_node_token("(", TRUE));
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, create_node_token(")", TRUE));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1740 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 350 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("if", TRUE));
    add_child_last(root_here, create_node_token("(", TRUE));
    add_child_last(root_here, (yyvsp[-4].node));
    add_child_last(root_here, create_node_token(")", TRUE));
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, create_node_token("else", TRUE));
    (yyval.node) = root_here;
    }
#line 1755 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 362 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1765 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 367 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Block_Or_Statement");
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1775 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 374 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("while", TRUE));
    add_child_last(root_here, create_node_token("(", TRUE));
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, create_node_token(")", TRUE));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1789 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 385 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id((yyvsp[0].s_val), -1));
    (yyval.node) = root_here;
    }
#line 1799 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 390 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token(".", FALSE));
    add_child_last(root_here, create_node_id((yyvsp[-2].s_val), -1));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1811 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 401 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1821 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 406 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1831 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 411 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1841 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 416 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1851 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 421 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1861 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 426 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1871 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 431 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1881 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 438 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("return", TRUE));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1892 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 444 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("return", TRUE));
    (yyval.node) = root_here;
    }
#line 1902 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 452 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id((yyvsp[-2].s_val), -1));
    add_child_last(root_here, create_node_token("=", TRUE));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1914 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 461 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-5].node));
    add_child_last(root_here, create_node_id((yyvsp[-4].s_val), (yyvsp[-2].i_val)));
    add_child_last(root_here, create_node_token("=", TRUE));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1927 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 469 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-3].node));
    add_child_last(root_here, create_node_id((yyvsp[-2].s_val), -1));
    add_child_last(root_here, create_node_token("=", TRUE));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1940 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 478 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-3].node));
    add_child_last(root_here, create_node_id((yyvsp[-2].s_val), (yyvsp[0].i_val)));
    (yyval.node) = root_here;
    }
#line 1951 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 486 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    (yyval.node) = root_here;

    }
#line 1961 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 491 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("final", TRUE));
    (yyval.node) = root_here;
    }
#line 1971 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 498 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("+", TRUE));
    (yyval.node) = root_here;
    }
#line 1981 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 503 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("-", TRUE));
    (yyval.node) = root_here;
    }
#line 1991 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 510 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("=", TRUE));
    (yyval.node) = root_here;
    }
#line 2001 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 515 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("+=", TRUE));
    (yyval.node) = root_here;
    }
#line 2011 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 520 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("-=", TRUE));
    (yyval.node) = root_here;
    }
#line 2021 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 525 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("*=", TRUE));
    (yyval.node) = root_here;
    }
#line 2031 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 530 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("/=", TRUE));
    (yyval.node) = root_here;
    }
#line 2041 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 535 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("%=", TRUE));
    (yyval.node) = root_here;
    }
#line 2051 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 542 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("+", TRUE));
    (yyval.node) = root_here;
    }
#line 2061 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 547 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("-", TRUE));
    (yyval.node) = root_here;
    }
#line 2071 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 554 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("*", TRUE));
    (yyval.node) = root_here;
    }
#line 2081 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 559 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("/", TRUE));
    (yyval.node) = root_here;
    }
#line 2091 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 564 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("%", TRUE));
    (yyval.node) = root_here;
    }
#line 2101 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 571 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("++", TRUE));
    (yyval.node) = root_here;
    }
#line 2111 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 576 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("--", TRUE));
    (yyval.node) = root_here;
    }
#line 2121 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 583 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    (yyval.i_val) = T_INT;
    }
#line 2129 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 586 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    (yyval.i_val) = T_STR;
    }
#line 2137 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 589 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    (yyval.i_val) = T_CHAR;
    }
#line 2145 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 592 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    (yyval.i_val) = T_FLOAT;
    }
#line 2153 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 595 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    (yyval.i_val) = T_DOUBLE;
    }
#line 2161 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 599 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("||", TRUE));
    (yyval.node) = root_here;
    }
#line 2171 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 604 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("&&", TRUE));
    (yyval.node) = root_here;
    }
#line 2181 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 611 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token(">", TRUE));
    (yyval.node) = root_here;
    }
#line 2191 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 616 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token(">=", TRUE));
    (yyval.node) = root_here;
    }
#line 2201 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 621 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("<", TRUE));
    (yyval.node) = root_here;
    }
#line 2211 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 626 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("<=", TRUE));
    (yyval.node) = root_here;
    }
#line 2221 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 631 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("==", TRUE));
    (yyval.node) = root_here;
    }
#line 2231 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 636 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("!=", TRUE));
    (yyval.node) = root_here;
    }
#line 2241 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 643 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2253 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 650 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2265 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 657 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id((yyvsp[-2].s_val), (yyvsp[0].i_val)));
    add_child_last(root_here, create_node_token("is", TRUE));
    (yyval.node) = root_here;
    }
#line 2276 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 663 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id((yyvsp[-3].s_val), (yyvsp[0].i_val)));
    add_child_last(root_here, create_node_token("!", FALSE));
    add_child_last(root_here, create_node_token("is", TRUE));
    (yyval.node) = root_here;
    }
#line 2288 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 672 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2298 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 677 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2308 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 682 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2318 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 689 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("if", TRUE));
    add_child_last(root_here, create_node_token("(", TRUE));
    add_child_last(root_here, (yyvsp[-4].node));
    add_child_last(root_here, create_node_token(")", TRUE));
    add_child_last(root_here, create_node_id((yyvsp[-2].s_val), -1));
    add_child_last(root_here, create_node_token("else", TRUE));
    add_child_last(root_here, create_node_id((yyvsp[0].s_val), -1));
    (yyval.node) = root_here;
    }
#line 2334 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 703 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2346 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 710 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2356 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 717 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2368 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 724 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2378 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 732 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2389 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 738 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2400 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 744 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2411 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 750 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token(copy_name((yyvsp[0].s_val)), TRUE));
    (yyval.node) = root_here;
    }
#line 2421 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 755 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("(", TRUE));
    add_child_last(root_here, (yyvsp[-1].node));
    add_child_last(root_here, create_node_token(")", TRUE));
    (yyval.node) = root_here;
    }
#line 2433 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 762 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2443 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 767 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2453 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 772 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[-2].node));
    add_child_last(root_here, create_node_token(".", FALSE));
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2465 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 781 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
   }
#line 2475 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 786 "Kotlin2Java.y" /* yacc.c:1646  */
    {
   ast_node* root_here = create_node();
   add_child_last(root_here, create_node_token(copy_name((yyvsp[0].s_val)), TRUE));
   (yyval.node) = root_here;
   }
#line 2485 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 791 "Kotlin2Java.y" /* yacc.c:1646  */
    {
   ast_node* root_here = create_node();
   add_child_last(root_here, create_node_token("null", TRUE));
   (yyval.node) = root_here;
   }
#line 2495 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 798 "Kotlin2Java.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_string((yyvsp[0].s_val), TYPE_STR));
    (yyval.node) = root_here;
    }
#line 2505 "Kotlin2Java.tab.c" /* yacc.c:1646  */
    break;


#line 2509 "Kotlin2Java.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 805 "Kotlin2Java.y" /* yacc.c:1906  */

/* User code */
int yyerror(const char *s)
{
    return printf("%s\n", s);
}
