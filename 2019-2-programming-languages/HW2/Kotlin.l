%{
#include <stdlib.h>
#include <string.h>

#include "Kotlin.tab.h"
extern int yyerror(const char*);
%}

NUMBER [0-9]+[.]?[0-9]*
STRING ["].*["]

LINECOMMENT [/][/][^\n]*

SPACE [ \t\r\n]+

IMPORT  import
PACKAGE package
FUNCTION  fun
RETURN  return

VALUE val
VARIABLE  var
NUL null

TYPE_INT  Int
TYPE_STR  String
TYPE_CHAR Char
TYPE_FLOAT  Float
TYPE_DOUBLE Double
TYPE_UNIT Unit
TYPE_ANY Any

IF  if
ELSE  else
WHEN  when

FOR for
WHILE while
STEP  step
DOWNTO  downTo

IS  is
IN  in

ID [_a-zA-Z][a-zA-Z0-9]*

%%

{NUMBER} { yylval.d_val = atof(yytext);
    return NUMBER;
}


{LINECOMMENT} {/* IGNORE */}

{SPACE} {/* IGNORE */}

{STRING} { yylval.s_val = yytext;
    return STRING;
}

{IMPORT} {return IMPORT; }
{PACKAGE} {return PACKAGE; }
{FUNCTION} {return FUNCTION; }
{RETURN} {return RETURN; }

{VALUE} {return VALUE; }
{VARIABLE} {return VARIABLE; }
{NUL} {return NUL; }

{TYPE_INT} {return TYPE_INT; }
{TYPE_STR} {return TYPE_STR; }
{TYPE_CHAR} {return TYPE_CHAR; }
{TYPE_FLOAT} {return TYPE_FLOAT; }
{TYPE_DOUBLE} {return TYPE_DOUBLE; }
{TYPE_UNIT} {return TYPE_UNIT; }
{TYPE_ANY} {return TYPE_ANY; }

{IF} {return IF; }
{ELSE} {return ELSE; }
{WHEN} {return WHEN; }

{FOR} {return FOR; }
{WHILE} {return WHILE; }
{STEP} {return STEP; }
{DOWNTO} {return DOWNTO; }

{IS} {return IS; }
{IN} {return IN; }


"." {return DOT;}
".." {return RANGE;}
"," {return COMMA;}
":" {return COLON;}
"$" {return DOLLAR;}
"?" {return QMARK;}

"(" {return LPAREN;}
")" {return RPAREN;}
"{" {return LBRACE;}
"}" {return RBRACE;}
"[" {return LBRACK;}
"]" {return RBRACK;}

"++" {return INCREM;}
"--" {return DECREM;}
"=" {return ASSN;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}
"+=" {return ADDASSN;}
"-=" {return SUBASSN;}
"*=" {return MULASSN;}
"/=" {return DIVASSN;}
"%=" {return MODASSN;}

">" {return LARGE;}
">=" {return LARGEQ;}
"<" {return LESS;}
"<=" {return LESSQ;}
"==" {return EQ;}
"!=" {return NEQ;}

"||" {return LOGOR;}
"&&" {return LOGAND;}

"!" {return NOT;}

{ID} { yylval.s_val = yytext;
    return ID;
}

.    {  printf("%lf\n", (double)yytext[0]);
           yyerror("unexpected input");
}


%%
/* User code */