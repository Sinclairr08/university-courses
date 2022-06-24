%{
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

%}

%union{
    struct ast_node* node;
    double d_val;
    int i_val;
    char* s_val;
}

%token <s_val> NUMBER
%token <s_val> ID
%token <s_val> STRING

%token <i_val> MAIN
%token <i_val> IMPORT
%token <i_val> PACKAGE
%token <i_val> FUNCTION
%token <i_val> RETURN

%token <i_val> VALUE
%token <i_val> VARIABLE
%token <i_val> NUL

%token <i_val> TYPE_INT
%token <i_val> TYPE_STR
%token <i_val> TYPE_CHAR
%token <i_val> TYPE_FLOAT
%token <i_val> TYPE_DOUBLE

%token <i_val> IF
%token <i_val> ELSE
%token <i_val> WHEN

%token <i_val> WHILE
%token <i_val> STEP
%token <i_val> DOWNTO

%token <i_val> IS
%token <i_val> IN

%token <i_val> DOT
%token <i_val> RANGE
%token <i_val> COMMA
%token <i_val> COLON
%token <i_val> DOLLAR

%token <i_val> LPAREN
%token <i_val> RPAREN
%token <i_val> LBRACE
%token <i_val> RBRACE
%token <i_val> LBRACK
%token <i_val> RBRACK

%token <i_val> INCREM
%token <i_val> DECREM
%token <i_val> ASSN
%token <i_val> PLUS
%token <i_val> MINUS
%token <i_val> MUL
%token <i_val> DIV
%token <i_val> MOD
%token <i_val> ADDASSN
%token <i_val> SUBASSN
%token <i_val> MULASSN
%token <i_val> DIVASSN
%token <i_val> MODASSN

%token <i_val> LARGE
%token <i_val> LARGEQ
%token <i_val> LESS
%token <i_val> LESSQ
%token <i_val> EQ
%token <i_val> NEQ

%token <i_val> LOGOR
%token <i_val> LOGAND

%token <i_val> NOT

%type <i_val> Program

%type <node> Code
%type <node> PackageDeclaration
%type <node> PackageName
%type <node> PackageSubName
%type <node> ImportList
%type <node> ImportItem
%type <node> ImportName
%type <node> ImportSubName
%type <node> Statements
%type <node> FunctionDeclaration
%type <node> FunctionParameters
%type <node> FunctionCall
%type <node> IfStatement
%type <node> IfExpression
%type <node> WhileStatement
%type <node> Statement
%type <node> ReturnStatement
%type <node> AssnStatement
%type <node> AssnDeclaration
%type <node> TypeVariable
%type <node> Sign
%type <i_val> Type
%type <node> LogicalOp
%type <node> ConditionOp
%type <node> Condition
%type <node> Expression
%type <node> ExpressionTerm
%type <node> ExpressionFactor
%type <node> ExpressionElem

%type <node> Block
%type <node> Block_Or_Statement
%type <node> Tuples
%type <node> StringLiteral
%type <node> Literal
%type <node> Operator_Low
%type <node> Operator_Mid
%type <node> Operator_High
%type <node> Operator_Assn

%type <node> MemberId


%%
/* Rules */

Program : Code {
    printf("import java.util.* \n\n");
    printf("class Main \{\n");
    fprintf(yyout, "class Main \{\n");
    traverse_tree($1);
    printf("}\n");
    fprintf(yyout, "}\n");
    $$ = 0;
    }
    ;

Code : PackageDeclaration ImportList Statements {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, $2);
    add_child_last(root_here, $3);
    $$ = root_here;
    }
    ;

PackageDeclaration: /* empty */{
    ast_node* root_here = create_node();
    $$ = root_here;
    }
    | PACKAGE PackageName {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("package", TRUE));
    add_child_last(root_here, $2);
    add_child_last(root_here, create_node_enter());
    $$ = root_here;
    }
    ;
PackageName: ID PackageSubName { /* Revision */
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id($1, -1));
    add_child_last(root_here, $2);
    $$ = root_here;
    }
    ;

PackageSubName: /* empty */{
    ast_node* root_here = create_node();
    $$ = root_here;
    }
    | DOT ID PackageSubName {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token(".", FALSE));
    add_child_last(root_here, create_node_id($2, -1));
    add_child_last(root_here, $3);
    $$ = root_here;
    }
    ;

ImportList: /* empty */{ /* Revision */
    ast_node* root_here = create_node();
    $$ = root_here;
    }
    | ImportItem ImportList  {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, $2);
    $$ = root_here;
    }
    ;

ImportItem: IMPORT ImportName { /* Revision */
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("import", TRUE));
    add_child_last(root_here, $2);
    add_child_last(root_here, create_node_enter());
    $$ = root_here;
    }
    ;

ImportName: ID ImportSubName { /* Revision */
    ast_node* root_here = create_node("ImportName");
    add_child_last(root_here, create_node_id($1, -1));
    add_child_last(root_here, $2);
    $$ = root_here;
    }
    ;

ImportSubName: /* empty */
    | DOT ID ImportSubName {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node(".", FALSE));
    add_child_last(root_here, create_node_id($2, -1));
    add_child_last(root_here, $3);
    $$ = root_here;
    }
    | DOT MUL {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node(".", FALSE));
    add_child_last(root_here, create_node("*", FALSE));
    $$ = root_here;
    }
    ;

Statements: /* empty */{ /* Revision */
    ast_node* root_here = create_node();
    $$ = root_here;
    }
    | Statement Statements {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, $2);
    $$ = root_here;
    }
    ;

FunctionDeclaration: FUNCTION ID LPAREN FunctionParameters RPAREN COLON Type Block {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id($2, $7));
    add_child_last(root_here, create_node_token("(", FALSE));
    add_child_last(root_here, $4);
    add_child_last(root_here, create_node_token(")", FALSE));
    add_child_last(root_here, $8);
    $$ = root_here;
    }
    | FUNCTION ID LPAREN FunctionParameters RPAREN Block {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id($2, -1));
    add_child_last(root_here, create_node_token("(", FALSE));
    add_child_last(root_here, create_node_token(")", FALSE));
    add_child_last(root_here, $4);
    add_child_last(root_here, $6);
    $$ = root_here;
    }
    | FUNCTION MAIN LPAREN FunctionParameters RPAREN Block {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("public static void", TRUE));
    add_child_last(root_here, create_node_token("main", TRUE));
    add_child_last(root_here, create_node_token("(String[] args)", FALSE));
    add_child_last(root_here, $4);
    add_child_last(root_here, $6);
    $$ = root_here;
    }
    ;

FunctionCall: ID LPAREN Tuples RPAREN {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id($1, -1));
    add_child_last(root_here, create_node_token("(", FALSE));
    add_child_last(root_here, $3);
    add_child_last(root_here, create_node_token(")", FALSE));
    add_child_last(root_here, create_node_enter());
    $$ = root_here;
    }
    ;

Block: LBRACE Statements RBRACE {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("\{\n", FALSE));
    add_child_last(root_here, $2);
    add_child_last(root_here, create_node_token("\}\n", FALSE));
    $$ = root_here;
    }
    ;

Tuples: /* empty */{
    ast_node* root_here = create_node();
    $$ = root_here;
    }
    | Expression COMMA Tuples {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, create_node_token(",", TRUE));
    add_child_last(root_here, $3);
    $$ = root_here;
    }

    | Expression {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    ;

FunctionParameters: /* empty */ {
    ast_node* root_here = create_node();
    $$ = root_here;
    }
    | FunctionParameters COMMA ID COLON Type {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, create_node_token(",", TRUE));
    add_child_last(root_here, create_node_id($3, $5));
    $$ = root_here;
    }
    | ID COLON Type {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id($1, $3));
    $$ = root_here;
    }
    ;

IfStatement: IF LPAREN Condition RPAREN Block_Or_Statement {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("if", TRUE));
    add_child_last(root_here, create_node_token("(", TRUE));
    add_child_last(root_here, $3);
    add_child_last(root_here, create_node_token(")", TRUE));
    add_child_last(root_here, $5);
    $$ = root_here;
    }
    | IF LPAREN Condition RPAREN Block_Or_Statement ELSE Block_Or_Statement {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("if", TRUE));
    add_child_last(root_here, create_node_token("(", TRUE));
    add_child_last(root_here, $3);
    add_child_last(root_here, create_node_token(")", TRUE));
    add_child_last(root_here, $5);
    add_child_last(root_here, create_node_token("else", TRUE));
    $$ = root_here;
    }
    ;

Block_Or_Statement: Block {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | Statement {
    ast_node* root_here = create_node("Block_Or_Statement");
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    ;

WhileStatement: WHILE LPAREN Condition RPAREN Block_Or_Statement {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("while", TRUE));
    add_child_last(root_here, create_node_token("(", TRUE));
    add_child_last(root_here, $3);
    add_child_last(root_here, create_node_token(")", TRUE));
    add_child_last(root_here, $5);
    $$ = root_here;
    }
    ;

MemberId: ID {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id($1, -1));
    $$ = root_here;
    }
    | ID DOT MemberId {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token(".", FALSE));
    add_child_last(root_here, create_node_id($1, -1));
    add_child_last(root_here, $3);
    $$ = root_here;
    }
    ;

/* Statements */

Statement: IfStatement {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | WhileStatement{
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | ReturnStatement {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | AssnStatement{
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | AssnDeclaration {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | Expression {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | FunctionDeclaration{
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    ;

ReturnStatement: RETURN Expression {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("return", TRUE));
    add_child_last(root_here, $2);
    $$ = root_here;
    }
    | RETURN {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("return", TRUE));
    $$ = root_here;
    }
    ;


AssnStatement: ID Operator_Assn Expression {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id($1, -1));
    add_child_last(root_here, create_node_token("=", TRUE));
    add_child_last(root_here, $3);
    $$ = root_here;
    }
    ;

AssnDeclaration: TypeVariable ID COLON Type ASSN Expression {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, create_node_id($2, $4));
    add_child_last(root_here, create_node_token("=", TRUE));
    add_child_last(root_here, $6);
    $$ = root_here;
    }
    | TypeVariable ID ASSN Expression {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, create_node_id($2, -1));
    add_child_last(root_here, create_node_token("=", TRUE));
    add_child_last(root_here, $4);
    $$ = root_here;
    }
    |
    TypeVariable ID COLON Type {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, create_node_id($2, $4));
    $$ = root_here;
    }
    ;

TypeVariable:   VARIABLE {
    ast_node* root_here = create_node();
    $$ = root_here;

    }
    |   VALUE {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("final", TRUE));
    $$ = root_here;
    }
    ;

Sign : PLUS {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("+", TRUE));
    $$ = root_here;
    }
    | MINUS {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("-", TRUE));
    $$ = root_here;
    }
    ;

Operator_Assn : ASSN {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("=", TRUE));
    $$ = root_here;
    }
    | ADDASSN {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("+=", TRUE));
    $$ = root_here;
    }
    | SUBASSN {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("-=", TRUE));
    $$ = root_here;
    }
    | MULASSN {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("*=", TRUE));
    $$ = root_here;
    }
    | DIVASSN {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("/=", TRUE));
    $$ = root_here;
    }
    | MODASSN {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("%=", TRUE));
    $$ = root_here;
    }
    ;

Operator_Low : PLUS {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("+", TRUE));
    $$ = root_here;
    }
    | MINUS {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("-", TRUE));
    $$ = root_here;
    }
    ;

Operator_Mid : MUL {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("*", TRUE));
    $$ = root_here;
    }
    | DIV {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("/", TRUE));
    $$ = root_here;
    }
    | MOD {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("%", TRUE));
    $$ = root_here;
    }
    ;

Operator_High : INCREM {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("++", TRUE));
    $$ = root_here;
    }
    | DECREM {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("--", TRUE));
    $$ = root_here;
    }
    ;

Type: TYPE_INT {
    $$ = T_INT;
    }
    | TYPE_STR {
    $$ = T_STR;
    }
    | TYPE_CHAR {
    $$ = T_CHAR;
    }
    | TYPE_FLOAT {
    $$ = T_FLOAT;
    }
    | TYPE_DOUBLE {
    $$ = T_DOUBLE;
    }

LogicalOp: LOGOR {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("||", TRUE));
    $$ = root_here;
    }
    | LOGAND {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("&&", TRUE));
    $$ = root_here;
    }
    ;

ConditionOp: LARGE {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token(">", TRUE));
    $$ = root_here;
    }
    | LARGEQ {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token(">=", TRUE));
    $$ = root_here;
    }
    | LESS {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("<", TRUE));
    $$ = root_here;
    }
    | LESSQ {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("<=", TRUE));
    $$ = root_here;
    }
    | EQ {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("==", TRUE));
    $$ = root_here;
    }
    | NEQ {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("!=", TRUE));
    $$ = root_here;
    }
    ;

Condition: Expression ConditionOp Expression {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, $2);
    add_child_last(root_here, $3);
    $$ = root_here;
    }
    | Condition LogicalOp Condition {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, $2);
    add_child_last(root_here, $3);
    $$ = root_here;
    }
    | ID IS Type {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id($1, $3));
    add_child_last(root_here, create_node_token("is", TRUE));
    $$ = root_here;
    }
    | ID NOT IS Type {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_id($1, $4));
    add_child_last(root_here, create_node_token("!", FALSE));
    add_child_last(root_here, create_node_token("is", TRUE));
    $$ = root_here;
    }
    ;

Expression : ExpressionTerm {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | Literal{
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | IfExpression {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    ;

IfExpression : IF LPAREN Condition RPAREN ID ELSE ID {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("if", TRUE));
    add_child_last(root_here, create_node_token("(", TRUE));
    add_child_last(root_here, $3);
    add_child_last(root_here, create_node_token(")", TRUE));
    add_child_last(root_here, create_node_id($5, -1));
    add_child_last(root_here, create_node_token("else", TRUE));
    add_child_last(root_here, create_node_id($7, -1));
    $$ = root_here;
    }
    ;


ExpressionTerm : ExpressionTerm Operator_Low ExpressionFactor {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, $2);
    add_child_last(root_here, $3);
    $$ = root_here;
    }
    | ExpressionFactor{
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    ;

ExpressionFactor : ExpressionFactor Operator_Mid ExpressionElem {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, $2);
    add_child_last(root_here, $3);
    $$ = root_here;
    }
    | ExpressionElem {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    ;


ExpressionElem: Sign ExpressionElem {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, $2);
    $$ = root_here;
    }
    | ExpressionElem Operator_High{
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, $2);
    $$ = root_here;
    }
    | Operator_High ExpressionElem {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, $2);
    $$ = root_here;
    }
    | NUMBER {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token(copy_name($1), TRUE));
    $$ = root_here;
    }
    | LPAREN Expression RPAREN {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_token("(", TRUE));
    add_child_last(root_here, $2);
    add_child_last(root_here, create_node_token(")", TRUE));
    $$ = root_here;
    }
    | FunctionCall {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | MemberId {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
    }
    | MemberId DOT FunctionCall {
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    add_child_last(root_here, create_node_token(".", FALSE));
    add_child_last(root_here, $3);
    $$ = root_here;
    }
    ;

Literal: StringLiteral{
    ast_node* root_here = create_node();
    add_child_last(root_here, $1);
    $$ = root_here;
   }
   | NUMBER {
   ast_node* root_here = create_node();
   add_child_last(root_here, create_node_token(copy_name($1), TRUE));
   $$ = root_here;
   }
   | NUL {
   ast_node* root_here = create_node();
   add_child_last(root_here, create_node_token("null", TRUE));
   $$ = root_here;
   }
   ;

StringLiteral: STRING {
    ast_node* root_here = create_node();
    add_child_last(root_here, create_node_string($1, TYPE_STR));
    $$ = root_here;
    }
    ;

%%
/* User code */
int yyerror(const char *s)
{
    return printf("%s\n", s);
}
