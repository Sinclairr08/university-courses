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
#line 20 "Kotlin2Java.y" /* yacc.c:1909  */

    struct ast_node* node;
    double d_val;
    int i_val;
    char* s_val;

#line 121 "Kotlin2Java.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_KOTLIN2JAVA_TAB_H_INCLUDED  */
