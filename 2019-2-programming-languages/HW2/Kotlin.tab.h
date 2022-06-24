/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 38 "Kotlin.y" /* yacc.c:1909  */

    struct ast_node* node;
    double d_val;
    int i_val;
    char* s_val;

#line 124 "Kotlin.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_KOTLIN_TAB_H_INCLUDED  */
