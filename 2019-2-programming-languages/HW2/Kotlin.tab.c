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
#line 1 "Kotlin.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODENAME 25
#define MAX_NODECONTENT 700

extern int yylex(void);
extern void yyterminate();
extern int yyerror(const char *s);

yydebug = 1;

typedef struct ast_node{
    char nodename[MAX_NODENAME];
    char nodecontent[MAX_NODECONTENT];

    struct ast_node* child;
    struct ast_node* parent;
    struct ast_node* next;
    struct ast_node* prev;
}ast_node;

ast_node* create_node(char* name);
ast_node* create_child_dummy_node();

ast_node* add_child(ast_node* parent, ast_node* child);
ast_node* add_child_as_name(ast_node* cur_node, char* name);
ast_node* add_child_as_name_cont(ast_node* cur_node, char* name, char* content);

void print_tree(ast_node* root, int depth);
char* preprocess_id(char* name);


#line 103 "Kotlin.tab.c" /* yacc.c:339  */

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
   by #include "Kotlin.tab.h".  */
#ifndef YY_YY_KOTLIN_TAB_H_INCLUDED
# define YY_YY_KOTLIN_TAB_H_INCLUDED
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
    IMPORT = 261,
    PACKAGE = 262,
    FUNCTION = 263,
    RETURN = 264,
    VALUE = 265,
    VARIABLE = 266,
    NUL = 267,
    TYPE_INT = 268,
    TYPE_STR = 269,
    TYPE_CHAR = 270,
    TYPE_FLOAT = 271,
    TYPE_DOUBLE = 272,
    TYPE_UNIT = 273,
    TYPE_ANY = 274,
    IF = 275,
    ELSE = 276,
    WHEN = 277,
    FOR = 278,
    WHILE = 279,
    STEP = 280,
    DOWNTO = 281,
    IS = 282,
    IN = 283,
    DOT = 284,
    RANGE = 285,
    COMMA = 286,
    COLON = 287,
    DOLLAR = 288,
    QMARK = 289,
    LPAREN = 290,
    RPAREN = 291,
    LBRACE = 292,
    RBRACE = 293,
    LBRACK = 294,
    RBRACK = 295,
    INCREM = 296,
    DECREM = 297,
    ASSN = 298,
    PLUS = 299,
    MINUS = 300,
    MUL = 301,
    DIV = 302,
    MOD = 303,
    ADDASSN = 304,
    SUBASSN = 305,
    MULASSN = 306,
    DIVASSN = 307,
    MODASSN = 308,
    LARGE = 309,
    LARGEQ = 310,
    LESS = 311,
    LESSQ = 312,
    EQ = 313,
    NEQ = 314,
    LOGOR = 315,
    LOGAND = 316,
    NOT = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "Kotlin.y" /* yacc.c:355  */

    struct ast_node* node;
    double d_val;
    int i_val;
    char* s_val;

#line 213 "Kotlin.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_KOTLIN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "Kotlin.tab.c" /* yacc.c:358  */

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
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   173,   173,   179,   188,   192,   199,   207,   211,   220,
     224,   232,   240,   248,   249,   256,   264,   268,   276,   288,
     298,   311,   319,   327,   336,   340,   348,   355,   359,   368,
     377,   386,   399,   404,   411,   422,   433,   440,   449,   460,
     471,   476,   487,   492,   497,   502,   507,   512,   517,   522,
     529,   535,   543,   552,   562,   571,   581,   587,   595,   600,
     607,   612,   617,   622,   627,   632,   639,   644,   651,   656,
     661,   668,   673,   680,   685,   690,   695,   700,   705,   710,
     715,   723,   728,   735,   740,   745,   750,   755,   760,   767,
     774,   781,   788,   798,   803,   808,   815,   829,   836,   843,
     850,   858,   864,   870,   876,   881,   888,   893,   898,   907,
     912,   917,   924
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "STRING", "IMPORT",
  "PACKAGE", "FUNCTION", "RETURN", "VALUE", "VARIABLE", "NUL", "TYPE_INT",
  "TYPE_STR", "TYPE_CHAR", "TYPE_FLOAT", "TYPE_DOUBLE", "TYPE_UNIT",
  "TYPE_ANY", "IF", "ELSE", "WHEN", "FOR", "WHILE", "STEP", "DOWNTO", "IS",
  "IN", "DOT", "RANGE", "COMMA", "COLON", "DOLLAR", "QMARK", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "INCREM", "DECREM",
  "ASSN", "PLUS", "MINUS", "MUL", "DIV", "MOD", "ADDASSN", "SUBASSN",
  "MULASSN", "DIVASSN", "MODASSN", "LARGE", "LARGEQ", "LESS", "LESSQ",
  "EQ", "NEQ", "LOGOR", "LOGAND", "NOT", "$accept", "Program", "Code",
  "PackageDeclaration", "PackageName", "PackageSubName", "ImportList",
  "ImportItem", "ImportName", "ImportSubName", "Statements",
  "FunctionDeclaration", "FunctionCall", "Block", "Tuples",
  "FunctionParameters", "IfStatement", "Block_Or_Statement",
  "WhileStatement", "ForStatement", "ForCondition", "MemberId",
  "Statement", "ReturnStatement", "AssnStatement", "AssnDeclaration",
  "TypeVariable", "Sign", "Operator_Assn", "Operator_Low", "Operator_Mid",
  "Operator_High", "Type", "LogicalOp", "ConditionOp", "Condition",
  "Expression", "IfExpression", "ExpressionTerm", "ExpressionFactor",
  "ExpressionElem", "Literal", "StringLiteral", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

#define YYPACT_NINF -143

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-143)))

#define YYTABLE_NINF -37

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,    41,    64,  -143,    62,    42,  -143,  -143,    69,   149,
      62,    73,  -143,    53,  -143,  -143,   204,  -143,    83,   162,
    -143,  -143,  -143,    60,    65,    76,    84,   162,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,    68,   149,
    -143,  -143,  -143,    95,    85,    85,  -143,  -143,   -29,   103,
     -13,  -143,  -143,  -143,    42,     9,  -143,   119,   162,  -143,
    -143,  -143,  -143,  -143,  -143,   162,    89,    -5,    93,  -143,
      96,   196,   127,   196,   100,     3,  -143,   -18,  -143,   -13,
     -13,  -143,  -143,    85,  -143,  -143,  -143,    85,  -143,  -143,
      53,  -143,   105,  -143,   101,   110,  -143,   142,   196,  -143,
      63,    25,   121,   136,   111,    33,  -143,   120,  -143,   245,
     162,   103,   -13,  -143,  -143,   162,   138,    34,   102,   245,
     144,    39,  -143,  -143,   196,  -143,  -143,  -143,  -143,  -143,
    -143,   162,   162,    98,    98,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,   -16,  -143,  -143,   245,   179,   -20,   181,   152,
     245,   193,   149,  -143,   166,  -143,    55,  -143,   -10,    11,
    -143,  -143,  -143,   162,   152,   156,   245,   162,  -143,   168,
     152,   188,   157,    98,   195,   162,  -143,   245,    38,  -143,
    -143,  -143,  -143,  -143,   171,   152,  -143,   199,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     9,     7,     5,     1,     0,    16,
       9,     0,     6,    13,    11,   104,    40,   112,     0,    51,
      57,    56,   111,     0,     0,     0,     0,     0,    71,    72,
      58,    59,     3,    49,   107,    42,    44,    43,   106,    16,
      45,    46,    47,     0,     0,     0,    48,    95,    93,    98,
     100,    94,   109,    10,     7,     0,    12,     0,    24,    60,
      61,    62,    63,    64,    65,     0,     0,    40,     0,    50,
       0,     0,     0,     0,     0,     0,    17,     0,   104,   101,
     103,    66,    67,     0,    68,    69,    70,     0,   102,     8,
      13,    15,    40,    41,     0,    26,    52,    27,     0,    22,
      40,     0,     0,     0,     0,     0,   105,     0,   108,     0,
       0,    97,    99,    14,    21,    24,     0,     0,     0,     0,
       0,     0,    81,    82,     0,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,    79,    55,    54,    25,     0,     0,     0,     0,    91,
       0,    40,    16,    32,    30,    33,    90,    89,   106,     0,
      35,    34,    80,     0,    29,     0,     0,     0,    19,     0,
      92,     0,     0,     0,     0,     0,    53,     0,     0,    20,
      96,    23,    31,    39,    37,    28,    18,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,  -143,  -143,   151,   200,  -143,  -143,   122,
     -38,  -143,   134,  -142,   104,  -143,  -143,  -113,  -143,  -143,
    -143,   -54,    -7,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,   -46,  -110,  -143,  -143,   -67,   -19,  -143,  -143,   128,
     -34,  -143,  -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     6,    12,     9,    10,    14,    56,
      32,    33,    34,   153,    94,   117,    35,   154,    36,    37,
     104,    38,   155,    40,    41,    42,    43,    44,    65,    83,
      87,    45,   142,   124,   131,   101,    46,    47,    48,    49,
      50,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    76,    39,    93,    88,   168,   105,   107,    74,   149,
      79,    80,   166,    90,   109,    81,    82,   152,   162,    75,
     160,   161,    23,   167,    57,   110,   -36,   163,    28,    29,
      58,   118,    39,    88,    88,   164,   186,   174,     1,    95,
     170,   175,    15,   151,    17,     5,    96,    18,    19,    20,
      21,    22,   102,   112,   102,    91,   178,   156,    23,    24,
     182,   121,    25,    26,     7,   146,    88,   185,     8,   134,
     147,    11,   162,    13,    27,   152,   152,    54,   158,   102,
      28,    29,    55,    30,    31,   122,   123,    66,    78,    67,
     119,   143,    57,   122,   123,    70,    95,    75,    58,    77,
      71,    15,    16,    17,    23,   102,    18,    19,    20,    21,
      22,    72,   157,   159,   172,   122,   123,    23,    24,    73,
      27,    25,    26,    92,    97,   120,    28,    29,    98,    30,
      31,   103,    99,    27,    57,   152,   106,   114,   148,    28,
      29,   115,    30,    31,   176,    39,   116,   133,   179,    84,
      85,    86,    15,    16,    17,    58,   184,    18,    19,    20,
      21,    22,   122,   123,   132,    15,    67,    17,    23,    24,
     145,   150,    25,    26,    22,   125,   126,   127,   128,   129,
     130,    23,    68,   165,    27,   169,   162,   173,   177,   171,
      28,    29,   180,    30,    31,   181,   187,    27,   183,    15,
     100,    17,   188,    28,    29,    89,    30,    31,    22,   108,
      53,   111,   113,     0,   171,    23,    68,     0,     0,   144,
       0,     0,    57,     0,     0,     0,     0,     0,    58,     0,
       0,    27,     0,    57,     0,     0,    59,    28,    29,    58,
      30,    31,    60,    61,    62,    63,    64,    59,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,   135,   136,
     137,   138,   139,   140,   141
};

static const yytype_int16 yycheck[] =
{
      19,    39,     9,    57,    50,   147,    73,     4,    27,   119,
      44,    45,    32,     4,    32,    44,    45,    37,    34,    29,
     133,   134,    19,    43,    29,    43,    36,    43,    41,    42,
      35,    98,    39,    79,    80,   145,   178,    26,     7,    58,
     150,    30,     3,     4,     5,     4,    65,     8,     9,    10,
      11,    12,    71,    87,    73,    46,   166,   124,    19,    20,
     173,    36,    23,    24,     0,    31,   112,   177,     6,    36,
      36,    29,    34,     4,    35,    37,    37,     4,   132,    98,
      41,    42,    29,    44,    45,    60,    61,     4,     3,     4,
      27,   110,    29,    60,    61,    35,   115,    29,    35,     4,
      35,     3,     4,     5,    19,   124,     8,     9,    10,    11,
      12,    35,   131,   132,   152,    60,    61,    19,    20,    35,
      35,    23,    24,     4,    35,    62,    41,    42,    35,    44,
      45,     4,    36,    35,    29,    37,    36,    36,    36,    41,
      42,    31,    44,    45,   163,   152,     4,    36,   167,    46,
      47,    48,     3,     4,     5,    35,   175,     8,     9,    10,
      11,    12,    60,    61,    28,     3,     4,     5,    19,    20,
      32,    27,    23,    24,    12,    54,    55,    56,    57,    58,
      59,    19,    20,     4,    35,     4,    34,    21,    32,    21,
      41,    42,     4,    44,    45,    38,    25,    35,     3,     3,
       4,     5,     3,    41,    42,    54,    44,    45,    12,    75,
      10,    83,    90,    -1,    21,    19,    20,    -1,    -1,   115,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    35,    -1,    29,    -1,    -1,    43,    41,    42,    35,
      44,    45,    49,    50,    51,    52,    53,    43,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    13,    14,
      15,    16,    17,    18,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    64,    65,    66,     4,    67,     0,     6,    69,
      70,    29,    68,     4,    71,     3,     4,     5,     8,     9,
      10,    11,    12,    19,    20,    23,    24,    35,    41,    42,
      44,    45,    73,    74,    75,    79,    81,    82,    84,    85,
      86,    87,    88,    89,    90,    94,    99,   100,   101,   102,
     103,   104,   105,    69,     4,    29,    72,    29,    35,    43,
      49,    50,    51,    52,    53,    91,     4,     4,    20,    99,
      35,    35,    35,    35,    99,    29,    73,     4,     3,   103,
     103,    44,    45,    92,    46,    47,    48,    93,    94,    68,
       4,    46,     4,    84,    77,    99,    99,    35,    35,    36,
       4,    98,    99,     4,    83,    98,    36,     4,    75,    32,
      43,   102,   103,    72,    36,    31,     4,    78,    98,    27,
      62,    36,    60,    61,    96,    54,    55,    56,    57,    58,
      59,    97,    28,    36,    36,    13,    14,    15,    16,    17,
      18,    19,    95,    99,    77,    32,    31,    36,    36,    95,
      27,     4,    37,    76,    80,    85,    98,    99,    84,    99,
      80,    80,    34,    43,    95,     4,    32,    43,    76,     4,
      95,    21,    73,    21,    26,    30,    99,    32,    95,    99,
       4,    38,    80,     3,    99,    95,    76,    25,     3
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    66,    66,    67,    68,    68,    69,
      69,    70,    71,    72,    72,    72,    73,    73,    74,    74,
      74,    75,    75,    76,    77,    77,    77,    78,    78,    78,
      79,    79,    80,    80,    81,    82,    83,    83,    83,    83,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    88,    88,    88,    89,    89,    90,    90,
      91,    91,    91,    91,    91,    91,    92,    92,    93,    93,
      93,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    96,    96,    97,    97,    97,    97,    97,    97,    98,
      98,    98,    98,    99,    99,    99,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     2,     2,     0,     3,     0,
       2,     2,     2,     0,     3,     2,     0,     2,     8,     6,
       7,     4,     3,     3,     0,     3,     1,     0,     5,     3,
       5,     7,     1,     1,     5,     5,     3,     5,     7,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     6,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
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
#line 173 "Kotlin.y" /* yacc.c:1646  */
    {
    print_tree((yyvsp[0].node), 0);
    (yyval.i_val) = 0;
    }
#line 1474 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 179 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Code");
    add_child(root_here, (yyvsp[-2].node));
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1486 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 188 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("PackageDeclaration");
    (yyval.node) = root_here;
    }
#line 1495 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 192 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("PackageDeclaration");
    add_child_as_name(root_here, "PACKAGE");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1506 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 199 "Kotlin.y" /* yacc.c:1646  */
    { /* Revision */
    ast_node* root_here = create_node("PackageName");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-1].s_val));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1517 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 207 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("PackageSubName");
    (yyval.node) = root_here;
    }
#line 1526 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 211 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("PackageSubName");
    add_child_as_name(root_here, "DOT");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-1].s_val));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1538 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 220 "Kotlin.y" /* yacc.c:1646  */
    { /* Revision */
    ast_node* root_here = create_node("ImportList");
    (yyval.node) = root_here;
    }
#line 1547 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 224 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ImportList");
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1558 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 232 "Kotlin.y" /* yacc.c:1646  */
    { /* Revision */
    ast_node* root_here = create_node("ImportItem");
    add_child_as_name(root_here, "IMPORT");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1569 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 240 "Kotlin.y" /* yacc.c:1646  */
    { /* Revision */
    ast_node* root_here = create_node("ImportName");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-1].s_val));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1580 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 249 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ImportSubName");
    add_child_as_name(root_here, "DOT");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-1].s_val));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1592 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 256 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ImportSubName");
    add_child_as_name(root_here, "DOT");
    add_child_as_name(root_here, "MUL");
    (yyval.node) = root_here;
    }
#line 1603 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 264 "Kotlin.y" /* yacc.c:1646  */
    { /* Revision */
    ast_node* root_here = create_node("Statements");
    (yyval.node) = root_here;
    }
#line 1612 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 268 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Statements");
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1623 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 276 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("FunctionDeclaration");
    add_child_as_name(root_here, "FUNCTION");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-6].s_val));
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, (yyvsp[-4].node));
    add_child_as_name(root_here, "RPAREN");
    add_child_as_name(root_here, "COLON");
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1640 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 288 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("FunctionDeclaration");
    add_child_as_name(root_here, "FUNCTION");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-4].s_val));
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "RPAREN");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1655 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 298 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("FunctionDeclaration");
    add_child_as_name(root_here, "FUNCTION");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-5].s_val));
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, (yyvsp[-3].node));
    add_child_as_name(root_here, "RPAREN");
    add_child_as_name(root_here, "ASSN");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1671 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 311 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("FunctionCall");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-3].s_val));
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, (yyvsp[-1].node));
    add_child_as_name(root_here, "RPAREN");
    (yyval.node) = root_here;
    }
#line 1684 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 319 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("FunctionCall");
    add_child_as_name(root_here, "TYPE_ANY");
    add_child_as_name(root_here, "LPAREN");
    add_child_as_name(root_here, "RPAREN");
    }
#line 1695 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 327 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Block");
    add_child_as_name(root_here, "LBRACE");
    add_child(root_here, (yyvsp[-1].node));
    add_child_as_name(root_here, "RBRACE");
    (yyval.node) = root_here;
    }
#line 1707 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 336 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Tuples");
    (yyval.node) = root_here;
    }
#line 1716 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 340 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Tuples");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "COMMA");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1728 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 348 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Tuples");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1738 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 355 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("FunctionParameters");
    (yyval.node) = root_here;
    }
#line 1747 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 359 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("FunctionParameters");
    add_child(root_here, (yyvsp[-4].node));
    add_child_as_name(root_here, "COMMA");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-2].s_val));
    add_child_as_name(root_here, "COLON");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1761 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 368 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("FunctionParameters");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-2].s_val));
    add_child_as_name(root_here, "COLON");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1773 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 377 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("IfStatement");
    add_child_as_name(root_here, "IF");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "RPAREN");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1787 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 386 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("IfStatement");
    add_child_as_name(root_here, "IF");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, (yyvsp[-4].node));
    add_child_as_name(root_here, "RPAREN");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "ELSE");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1803 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 399 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Block_Or_Statement");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1813 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 404 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Block_Or_Statement");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1823 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 411 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("WhileStatement");
    add_child_as_name(root_here, "While");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "RPAREN");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1837 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 422 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ForStatement");
    add_child_as_name(root_here, "FOR");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "RPAREN");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1851 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 433 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ForCondition");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-2].s_val));
    add_child_as_name(root_here, "IN");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1863 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 440 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ForCondition");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-4].s_val));
    add_child_as_name(root_here, "IN");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "RANGE");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1877 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 449 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ForCondition");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-6].s_val));
    add_child_as_name(root_here, "IN");
    add_child(root_here, (yyvsp[-4].node));
    add_child_as_name(root_here, "RANGE");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "STEP");
    add_child_as_name(root_here, "NUMBER");
    (yyval.node) = root_here;
    }
#line 1893 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 460 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ForCondition");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-4].s_val));
    add_child_as_name(root_here, "IN");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "DOWNTO");
    add_child_as_name(root_here, "NUMBER");
    (yyval.node) = root_here;
    }
#line 1907 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 471 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("MemberId");
    add_child_as_name_cont(root_here, "ID", (yyvsp[0].s_val));
    (yyval.node) = root_here;
    }
#line 1917 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 476 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("MemberId");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-2].s_val));
    add_child_as_name(root_here, "DOT");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1929 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 487 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1939 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 492 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1949 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 497 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1959 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 502 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1969 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 507 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1979 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 512 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1989 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 517 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 1999 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 522 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2009 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 529 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ReturnStatement");
    add_child_as_name(root_here, "RETURN");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2020 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 535 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ReturnStatement");
    add_child_as_name(root_here, "RETURN");
    (yyval.node) = root_here;
    }
#line 2030 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 543 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("AssnStatement");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-2].s_val));
    add_child_as_name(root_here, "ASSN");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2042 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 552 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("AssnDeclaration");
    add_child(root_here, (yyvsp[-5].node));
    add_child_as_name_cont(root_here, "ID", (yyvsp[-4].s_val));
    add_child_as_name(root_here, "COLON");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "ASSN");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2057 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 562 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("AssnDeclaration");
    add_child(root_here, (yyvsp[-3].node));
    add_child_as_name_cont(root_here, "ID", (yyvsp[-2].s_val));
    add_child_as_name(root_here, "ASSN");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2070 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 571 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("AssnDeclaration");
    add_child(root_here, (yyvsp[-3].node));
    add_child_as_name_cont(root_here, "ID", (yyvsp[-2].s_val));
    add_child_as_name(root_here, "COLON");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2083 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 581 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("TypeVariable");
    add_child_as_name(root_here, "VARIABLE");
    (yyval.node) = root_here;

    }
#line 2094 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 587 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("TypeVariable");
    add_child_as_name(root_here, "VALUE");
    (yyval.node) = root_here;

    }
#line 2105 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 595 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Sign");
    add_child_as_name(root_here, "PLUS");
    (yyval.node) = root_here;
    }
#line 2115 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 600 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Sign");
    add_child_as_name(root_here, "MINUS");
    (yyval.node) = root_here;
    }
#line 2125 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 607 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "ASSN");
    (yyval.node) = root_here;
    }
#line 2135 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 612 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "ADDASSN");
    (yyval.node) = root_here;
    }
#line 2145 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 617 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "SUBASSN");
    (yyval.node) = root_here;
    }
#line 2155 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 622 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "MULASSN");
    (yyval.node) = root_here;
    }
#line 2165 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 627 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "DIVASSN");
    (yyval.node) = root_here;
    }
#line 2175 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 632 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "MODASSN");
    (yyval.node) = root_here;
    }
#line 2185 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 639 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Low");
    add_child_as_name(root_here, "PLUS");
    (yyval.node) = root_here;
    }
#line 2195 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 644 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Low");
    add_child_as_name(root_here, "MINUS");
    (yyval.node) = root_here;
    }
#line 2205 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 651 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Mid");
    add_child_as_name(root_here, "MUL");
    (yyval.node) = root_here;
    }
#line 2215 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 656 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Mid");
    add_child_as_name(root_here, "DIV");
    (yyval.node) = root_here;
    }
#line 2225 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 661 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_Mid");
    add_child_as_name(root_here, "MOD");
    (yyval.node) = root_here;
    }
#line 2235 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 668 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_High");
    add_child_as_name(root_here, "INCREM");
    (yyval.node) = root_here;
    }
#line 2245 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 673 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Operator_High");
    add_child_as_name(root_here, "DECREM");
    (yyval.node) = root_here;
    }
#line 2255 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 680 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_INT");
    (yyval.node) = root_here;
    }
#line 2265 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 685 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_STR");
    (yyval.node) = root_here;
    }
#line 2275 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 690 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_CHAR");
    (yyval.node) = root_here;
    }
#line 2285 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 695 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_FLOAT");
    (yyval.node) = root_here;
    }
#line 2295 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 700 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_DOUBLE");
    (yyval.node) = root_here;
    }
#line 2305 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 705 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_UNIT");
    (yyval.node) = root_here;
    }
#line 2315 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 710 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_ANY");
    (yyval.node) = root_here;
    }
#line 2325 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 715 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Type");
    add_child(root_here, (yyvsp[-1].node));
    add_child_as_name(root_here, "QMARK");
    (yyval.node) = root_here;
    }
#line 2336 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 723 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("LogicalOp");
    add_child_as_name(root_here, "LOGOR");
    (yyval.node) = root_here;
    }
#line 2346 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 728 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("LogicalOp");
    add_child_as_name(root_here, "LOGAND");
    (yyval.node) = root_here;
    }
#line 2356 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 735 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "LARGE");
    (yyval.node) = root_here;
    }
#line 2366 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 740 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "LARGEQ");
    (yyval.node) = root_here;
    }
#line 2376 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 745 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "LESS");
    (yyval.node) = root_here;
    }
#line 2386 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 750 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "LESSQ");
    (yyval.node) = root_here;
    }
#line 2396 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 755 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "EQ");
    (yyval.node) = root_here;
    }
#line 2406 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 760 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "NEQ");
    (yyval.node) = root_here;
    }
#line 2416 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 767 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Condition");
    add_child(root_here, (yyvsp[-2].node));
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2428 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 774 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Condition");
    add_child(root_here, (yyvsp[-2].node));
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2440 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 781 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Condition");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-2].s_val));
    add_child_as_name(root_here, "IS");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2452 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 788 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Condition");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-3].s_val));
    add_child_as_name(root_here, "NOT");
    add_child_as_name(root_here, "IS");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2465 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 798 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Expression");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2475 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 803 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Expression");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2485 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 808 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Expression");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2495 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 815 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("IfExpression");
    add_child_as_name(root_here, "ID");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, (yyvsp[-4].node));
    add_child_as_name(root_here, "RPAREN");
    add_child_as_name_cont(root_here, "ID", (yyvsp[-2].s_val));
    add_child_as_name(root_here, "ELSE");
    add_child_as_name_cont(root_here, "ID", (yyvsp[0].s_val));
    (yyval.node) = root_here;
    }
#line 2511 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 829 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionTerm");
    add_child(root_here, (yyvsp[-2].node));
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2523 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 836 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionTerm");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2533 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 843 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionFactor");
    add_child(root_here, (yyvsp[-2].node));
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2545 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 850 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionFactor");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2555 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 858 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2566 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 864 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2577 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 870 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, (yyvsp[-1].node));
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2588 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 876 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionElem");
    add_child_as_name(root_here, "NUMBER");
    (yyval.node) = root_here;
    }
#line 2598 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 881 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionElem");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, (yyvsp[-1].node));
    add_child_as_name(root_here, "RPAREN");
    (yyval.node) = root_here;
    }
#line 2610 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 888 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2620 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 893 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2630 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 898 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, (yyvsp[-2].node));
    add_child_as_name(root_here, "DOT");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
    }
#line 2642 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 907 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("Literal");
    add_child(root_here, (yyvsp[0].node));
    (yyval.node) = root_here;
   }
#line 2652 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 912 "Kotlin.y" /* yacc.c:1646  */
    {
   ast_node* root_here = create_node("Literal");
   add_child_as_name(root_here, "NUMBER");
   (yyval.node) = root_here;
   }
#line 2662 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 917 "Kotlin.y" /* yacc.c:1646  */
    {
   ast_node* root_here = create_node("Literal");
   add_child_as_name(root_here, "NUL");
   (yyval.node) = root_here;
   }
#line 2672 "Kotlin.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 924 "Kotlin.y" /* yacc.c:1646  */
    {
    ast_node* root_here = create_node("StringLiteral");
    add_child_as_name_cont(root_here, "STRING", (yyvsp[0].s_val));
    (yyval.node) = root_here;
    }
#line 2682 "Kotlin.tab.c" /* yacc.c:1646  */
    break;


#line 2686 "Kotlin.tab.c" /* yacc.c:1646  */
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
#line 931 "Kotlin.y" /* yacc.c:1906  */

/* User code */
int yyerror(const char *s)
{
    return printf("%s\n", s);
}

ast_node* create_node(char* name){
  ast_node* node = (ast_node*)malloc(sizeof(ast_node));
  node -> parent = NULL;
  node -> next = NULL;
  node -> prev = NULL;
  node -> child = create_child_dummy_node();

  strcpy(node -> nodename, name);
  (node -> nodecontent)[0] = '\0';
  return node;
}

ast_node* add_child_as_name(ast_node* cur_node, char* name){
  ast_node* new_node = create_node(name);
  return add_child(cur_node, new_node);
}

ast_node* add_child(ast_node* parent, ast_node* child){
  ast_node* cur_node = parent -> child;

  while(cur_node -> next != NULL)
    cur_node = cur_node -> next;

  cur_node -> next = child;
  child -> prev = cur_node;

  child -> parent = parent;
  return parent;

}

ast_node* add_child_as_name_cont(ast_node* cur_node, char* name, char* content){
    ast_node* new_node = create_node(name);
    strcpy(new_node -> nodecontent, content);
    if(strcmp(name, "ID") == 0)
        preprocess_id(new_node -> nodecontent);
    return add_child(cur_node, new_node);
}

ast_node* create_child_dummy_node(){
  ast_node* node = (ast_node*)malloc(sizeof(ast_node));
  node -> parent = NULL;
  node -> next = NULL;
  node -> prev = NULL;
  node -> child = NULL;

  strcpy(node -> nodename, "DUMMY");
  (node -> nodecontent)[0] = '\0';
  return node;

}

void print_tree(ast_node* root, int depth){
  for (int i = 0; i < depth; i++)
    printf("  ");

  printf("%s", root -> nodename);
  if ((root -> nodecontent)[0] != '\0')
      printf(" : %s", root -> nodecontent);
  printf("\n");

  ast_node* cur_node = root->child->next;

  while(cur_node != NULL) {
    print_tree(cur_node, depth + 1);
    cur_node = cur_node -> next;
  }
}

char* preprocess_id(char* name){
    int i = 0;
    while( ('a' <= name[i] && name[i] <= 'z') ||
           ('A' <= name[i] && name[i] <= 'Z') ||
           ('0' <= name[i] && name[i] <= '9') ||
           name[i] == '_')
           i++;
    name[i] = '\0';
    return name;
}
