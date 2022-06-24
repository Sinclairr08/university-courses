%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODENAME 25
#define MAX_NODECONTENT 700

extern int yylex(void);
extern void yyterminate();
extern int yyerror(const char *s);

/* yydebug = 1;*/

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

%}

%union{
    struct ast_node* node;
    double d_val;
    int i_val;
    char* s_val;
}

%token <d_val> NUMBER
%token <s_val> ID
%token <s_val> STRING

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
%token <i_val> TYPE_UNIT
%token <i_val> TYPE_ANY

%token <i_val> IF
%token <i_val> ELSE
%token <i_val> WHEN

%token <i_val> FOR
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
%token <i_val> QMARK

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
%type <node> ForStatement
%type <node> WhileStatement
%type <node> ForCondition
%type <node> Statement
%type <node> ReturnStatement
%type <node> AssnStatement
%type <node> AssnDeclaration
%type <node> TypeVariable
%type <node> Sign
%type <node> Type
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

// https://github.com/yuneg11/SKKU-PL-PA2/blob/master/Kotlin.g4
// https://kotlinlang.org/docs/reference/basic-syntax.html
// https://github.com/Kotlin/kotlin-spec/blob/master/grammar/src/main/antlr/KotlinLexer.g4
// https://github.com/Kotlin/kotlin-spec/blob/master/grammar/src/main/antlr/KotlinParser.g4


%%
/* Rules */

Program : Code {
    print_tree($1, 0);
    $$ = 0;
    }
    ;

Code : PackageDeclaration ImportList Statements {
    ast_node* root_here = create_node("Code");
    add_child(root_here, $1);
    add_child(root_here, $2);
    add_child(root_here, $3);
    $$ = root_here;
    }
    ;

PackageDeclaration: /* empty */{
    ast_node* root_here = create_node("PackageDeclaration");
    $$ = root_here;
    }
    | PACKAGE PackageName {
    ast_node* root_here = create_node("PackageDeclaration");
    add_child_as_name(root_here, "PACKAGE");
    add_child(root_here, $2);
    $$ = root_here;
    }
    ;
PackageName: ID PackageSubName { /* Revision */
    ast_node* root_here = create_node("PackageName");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child(root_here, $2);
    $$ = root_here;
    }
    ;

PackageSubName: /* empty */{
    ast_node* root_here = create_node("PackageSubName");
    $$ = root_here;
    }
    | DOT ID PackageSubName {
    ast_node* root_here = create_node("PackageSubName");
    add_child_as_name(root_here, "DOT");
    add_child_as_name_cont(root_here, "ID", $2);
    add_child(root_here, $3);
    $$ = root_here;
    }
    ;

ImportList: /* empty */{ /* Revision */
    ast_node* root_here = create_node("ImportList");
    $$ = root_here;
    }
    | ImportItem ImportList  {
    ast_node* root_here = create_node("ImportList");
    add_child(root_here, $1);
    add_child(root_here, $2);
    $$ = root_here;
    }
    ;

ImportItem: IMPORT ImportName { /* Revision */
    ast_node* root_here = create_node("ImportItem");
    add_child_as_name(root_here, "IMPORT");
    add_child(root_here, $2);
    $$ = root_here;
    }
    ;

ImportName: ID ImportSubName { /* Revision */
    ast_node* root_here = create_node("ImportName");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child(root_here, $2);
    $$ = root_here;
    }
    ;

ImportSubName: /* empty */
    | DOT ID ImportSubName {
    ast_node* root_here = create_node("ImportSubName");
    add_child_as_name(root_here, "DOT");
    add_child_as_name_cont(root_here, "ID", $2);
    add_child(root_here, $3);
    $$ = root_here;
    }
    | DOT MUL {
    ast_node* root_here = create_node("ImportSubName");
    add_child_as_name(root_here, "DOT");
    add_child_as_name(root_here, "MUL");
    $$ = root_here;
    }
    ;

Statements: /* empty */{ /* Revision */
    ast_node* root_here = create_node("Statements");
    $$ = root_here;
    }
    | Statement Statements {
    ast_node* root_here = create_node("Statements");
    add_child(root_here, $1);
    add_child(root_here, $2);
    $$ = root_here;
    }
    ;

FunctionDeclaration: FUNCTION ID LPAREN FunctionParameters RPAREN COLON Type Block {
    ast_node* root_here = create_node("FunctionDeclaration");
    add_child_as_name(root_here, "FUNCTION");
    add_child_as_name_cont(root_here, "ID", $2);
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, $4);
    add_child_as_name(root_here, "RPAREN");
    add_child_as_name(root_here, "COLON");
    add_child(root_here, $7);
    add_child(root_here, $8);
    $$ = root_here;
    }
    | FUNCTION ID LPAREN FunctionParameters RPAREN Block {
    ast_node* root_here = create_node("FunctionDeclaration");
    add_child_as_name(root_here, "FUNCTION");
    add_child_as_name_cont(root_here, "ID", $2);
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, $4);
    add_child_as_name(root_here, "RPAREN");
    add_child(root_here, $6);
    $$ = root_here;
    }
    | FUNCTION ID LPAREN FunctionParameters RPAREN ASSN Expression {
    ast_node* root_here = create_node("FunctionDeclaration");
    add_child_as_name(root_here, "FUNCTION");
    add_child_as_name_cont(root_here, "ID", $2);
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, $4);
    add_child_as_name(root_here, "RPAREN");
    add_child_as_name(root_here, "ASSN");
    add_child(root_here, $7);
    $$ = root_here;
    }
    ;

FunctionCall: ID LPAREN Tuples RPAREN {
    ast_node* root_here = create_node("FunctionCall");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, $3);
    add_child_as_name(root_here, "RPAREN");
    $$ = root_here;
    }
    | TYPE_ANY LPAREN RPAREN {
    ast_node* root_here = create_node("FunctionCall");
    add_child_as_name(root_here, "TYPE_ANY");
    add_child_as_name(root_here, "LPAREN");
    add_child_as_name(root_here, "RPAREN");
    }
    ;

Block: LBRACE Statements RBRACE {
    ast_node* root_here = create_node("Block");
    add_child_as_name(root_here, "LBRACE");
    add_child(root_here, $2);
    add_child_as_name(root_here, "RBRACE");
    $$ = root_here;
    }
    ;

Tuples: /* empty */{
    ast_node* root_here = create_node("Tuples");
    $$ = root_here;
    }
    | Expression COMMA Tuples {
    ast_node* root_here = create_node("Tuples");
    add_child(root_here, $1);
    add_child_as_name(root_here, "COMMA");
    add_child(root_here, $3);
    $$ = root_here;
    }

    | Expression {
    ast_node* root_here = create_node("Tuples");
    add_child(root_here, $1);
    $$ = root_here;
    }
    ;

FunctionParameters: /* empty */ {
    ast_node* root_here = create_node("FunctionParameters");
    $$ = root_here;
    }
    | FunctionParameters COMMA ID COLON Type {
    ast_node* root_here = create_node("FunctionParameters");
    add_child(root_here, $1);
    add_child_as_name(root_here, "COMMA");
    add_child_as_name_cont(root_here, "ID", $3);
    add_child_as_name(root_here, "COLON");
    add_child(root_here, $5);
    $$ = root_here;
    }
    | ID COLON Type {
    ast_node* root_here = create_node("FunctionParameters");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child_as_name(root_here, "COLON");
    add_child(root_here, $3);
    $$ = root_here;
    }
    ;

IfStatement: IF LPAREN Condition RPAREN Block_Or_Statement {
    ast_node* root_here = create_node("IfStatement");
    add_child_as_name(root_here, "IF");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, $3);
    add_child_as_name(root_here, "RPAREN");
    add_child(root_here, $5);
    $$ = root_here;
    }
    | IF LPAREN Condition RPAREN Block_Or_Statement ELSE Block_Or_Statement {
    ast_node* root_here = create_node("IfStatement");
    add_child_as_name(root_here, "IF");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, $3);
    add_child_as_name(root_here, "RPAREN");
    add_child(root_here, $5);
    add_child_as_name(root_here, "ELSE");
    add_child(root_here, $7);
    $$ = root_here;
    }
    ;

Block_Or_Statement: Block {
    ast_node* root_here = create_node("Block_Or_Statement");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | Statement {
    ast_node* root_here = create_node("Block_Or_Statement");
    add_child(root_here, $1);
    $$ = root_here;
    }
    ;

WhileStatement: WHILE LPAREN Condition RPAREN Block_Or_Statement {
    ast_node* root_here = create_node("WhileStatement");
    add_child_as_name(root_here, "While");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, $3);
    add_child_as_name(root_here, "RPAREN");
    add_child(root_here, $5);
    $$ = root_here;
    }
    ;

ForStatement: FOR LPAREN ForCondition RPAREN Block_Or_Statement {
    ast_node* root_here = create_node("ForStatement");
    add_child_as_name(root_here, "FOR");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, $3);
    add_child_as_name(root_here, "RPAREN");
    add_child(root_here, $5);
    $$ = root_here;
    }
    ;

ForCondition: ID IN MemberId {
    ast_node* root_here = create_node("ForCondition");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child_as_name(root_here, "IN");
    add_child(root_here, $3);
    $$ = root_here;
    }
    | ID IN Expression RANGE Expression {
    ast_node* root_here = create_node("ForCondition");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child_as_name(root_here, "IN");
    add_child(root_here, $3);
    add_child_as_name(root_here, "RANGE");
    add_child(root_here, $5);
    $$ = root_here;
    }
    | ID IN Expression RANGE Expression STEP NUMBER {
    ast_node* root_here = create_node("ForCondition");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child_as_name(root_here, "IN");
    add_child(root_here, $3);
    add_child_as_name(root_here, "RANGE");
    add_child(root_here, $5);
    add_child_as_name(root_here, "STEP");
    add_child_as_name(root_here, "NUMBER");
    $$ = root_here;
    }
    | ID IN Expression DOWNTO NUMBER {
    ast_node* root_here = create_node("ForCondition");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child_as_name(root_here, "IN");
    add_child(root_here, $3);
    add_child_as_name(root_here, "DOWNTO");
    add_child_as_name(root_here, "NUMBER");
    $$ = root_here;
    }
    ;

MemberId: ID {
    ast_node* root_here = create_node("MemberId");
    add_child_as_name_cont(root_here, "ID", $1);
    $$ = root_here;
    }
    | ID DOT MemberId {
    ast_node* root_here = create_node("MemberId");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child_as_name(root_here, "DOT");
    add_child(root_here, $3);
    $$ = root_here;
    }
    ;

/* Statements */

Statement: IfStatement {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | ForStatement {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | WhileStatement{
    ast_node* root_here = create_node("Statement");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | ReturnStatement {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | AssnStatement{
    ast_node* root_here = create_node("Statement");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | AssnDeclaration {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | Expression {
    ast_node* root_here = create_node("Statement");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | FunctionDeclaration{
    ast_node* root_here = create_node("Statement");
    add_child(root_here, $1);
    $$ = root_here;
    }
    ;

ReturnStatement: RETURN Expression {
    ast_node* root_here = create_node("ReturnStatement");
    add_child_as_name(root_here, "RETURN");
    add_child(root_here, $2);
    $$ = root_here;
    }
    | RETURN {
    ast_node* root_here = create_node("ReturnStatement");
    add_child_as_name(root_here, "RETURN");
    $$ = root_here;
    }
    ;


AssnStatement: ID Operator_Assn Expression {
    ast_node* root_here = create_node("AssnStatement");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child_as_name(root_here, "ASSN");
    add_child(root_here, $3);
    $$ = root_here;
    }
    ;

AssnDeclaration: TypeVariable ID COLON Type ASSN Expression {
    ast_node* root_here = create_node("AssnDeclaration");
    add_child(root_here, $1);
    add_child_as_name_cont(root_here, "ID", $2);
    add_child_as_name(root_here, "COLON");
    add_child(root_here, $4);
    add_child_as_name(root_here, "ASSN");
    add_child(root_here, $6);
    $$ = root_here;
    }
    | TypeVariable ID ASSN Expression {
    ast_node* root_here = create_node("AssnDeclaration");
    add_child(root_here, $1);
    add_child_as_name_cont(root_here, "ID", $2);
    add_child_as_name(root_here, "ASSN");
    add_child(root_here, $4);
    $$ = root_here;
    }
    |
    TypeVariable ID COLON Type {
    ast_node* root_here = create_node("AssnDeclaration");
    add_child(root_here, $1);
    add_child_as_name_cont(root_here, "ID", $2);
    add_child_as_name(root_here, "COLON");
    add_child(root_here, $4);
    $$ = root_here;
    }
    ;

TypeVariable:   VARIABLE {
    ast_node* root_here = create_node("TypeVariable");
    add_child_as_name(root_here, "VARIABLE");
    $$ = root_here;

    }
    |   VALUE {
    ast_node* root_here = create_node("TypeVariable");
    add_child_as_name(root_here, "VALUE");
    $$ = root_here;

    }
    ;

Sign : PLUS {
    ast_node* root_here = create_node("Sign");
    add_child_as_name(root_here, "PLUS");
    $$ = root_here;
    }
    | MINUS {
    ast_node* root_here = create_node("Sign");
    add_child_as_name(root_here, "MINUS");
    $$ = root_here;
    }
    ;

Operator_Assn : ASSN {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "ASSN");
    $$ = root_here;
    }
    | ADDASSN {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "ADDASSN");
    $$ = root_here;
    }
    | SUBASSN {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "SUBASSN");
    $$ = root_here;
    }
    | MULASSN {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "MULASSN");
    $$ = root_here;
    }
    | DIVASSN {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "DIVASSN");
    $$ = root_here;
    }
    | MODASSN {
    ast_node* root_here = create_node("Operator_Assn");
    add_child_as_name(root_here, "MODASSN");
    $$ = root_here;
    }
    ;

Operator_Low : PLUS {
    ast_node* root_here = create_node("Operator_Low");
    add_child_as_name(root_here, "PLUS");
    $$ = root_here;
    }
    | MINUS {
    ast_node* root_here = create_node("Operator_Low");
    add_child_as_name(root_here, "MINUS");
    $$ = root_here;
    }
    ;

Operator_Mid : MUL {
    ast_node* root_here = create_node("Operator_Mid");
    add_child_as_name(root_here, "MUL");
    $$ = root_here;
    }
    | DIV {
    ast_node* root_here = create_node("Operator_Mid");
    add_child_as_name(root_here, "DIV");
    $$ = root_here;
    }
    | MOD {
    ast_node* root_here = create_node("Operator_Mid");
    add_child_as_name(root_here, "MOD");
    $$ = root_here;
    }
    ;

Operator_High : INCREM {
    ast_node* root_here = create_node("Operator_High");
    add_child_as_name(root_here, "INCREM");
    $$ = root_here;
    }
    | DECREM {
    ast_node* root_here = create_node("Operator_High");
    add_child_as_name(root_here, "DECREM");
    $$ = root_here;
    }
    ;

Type: TYPE_INT {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_INT");
    $$ = root_here;
    }
    | TYPE_STR {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_STR");
    $$ = root_here;
    }
    | TYPE_CHAR {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_CHAR");
    $$ = root_here;
    }
    | TYPE_FLOAT {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_FLOAT");
    $$ = root_here;
    }
    | TYPE_DOUBLE {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_DOUBLE");
    $$ = root_here;
    }
    | TYPE_UNIT {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_UNIT");
    $$ = root_here;
    }
    | TYPE_ANY {
    ast_node* root_here = create_node("Type");
    add_child_as_name(root_here, "TYPE_ANY");
    $$ = root_here;
    }
    | Type QMARK {
    ast_node* root_here = create_node("Type");
    add_child(root_here, $1);
    add_child_as_name(root_here, "QMARK");
    $$ = root_here;
    }
    ;

LogicalOp: LOGOR {
    ast_node* root_here = create_node("LogicalOp");
    add_child_as_name(root_here, "LOGOR");
    $$ = root_here;
    }
    | LOGAND {
    ast_node* root_here = create_node("LogicalOp");
    add_child_as_name(root_here, "LOGAND");
    $$ = root_here;
    }
    ;

ConditionOp: LARGE {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "LARGE");
    $$ = root_here;
    }
    | LARGEQ {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "LARGEQ");
    $$ = root_here;
    }
    | LESS {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "LESS");
    $$ = root_here;
    }
    | LESSQ {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "LESSQ");
    $$ = root_here;
    }
    | EQ {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "EQ");
    $$ = root_here;
    }
    | NEQ {
    ast_node* root_here = create_node("ConditionOp");
    add_child_as_name(root_here, "NEQ");
    $$ = root_here;
    }
    ;

Condition: Expression ConditionOp Expression {
    ast_node* root_here = create_node("Condition");
    add_child(root_here, $1);
    add_child(root_here, $2);
    add_child(root_here, $3);
    $$ = root_here;
    }
    | Condition LogicalOp Condition {
    ast_node* root_here = create_node("Condition");
    add_child(root_here, $1);
    add_child(root_here, $2);
    add_child(root_here, $3);
    $$ = root_here;
    }
    | ID IS Type {
    ast_node* root_here = create_node("Condition");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child_as_name(root_here, "IS");
    add_child(root_here, $3);
    $$ = root_here;
    }
    | ID NOT IS Type {
    ast_node* root_here = create_node("Condition");
    add_child_as_name_cont(root_here, "ID", $1);
    add_child_as_name(root_here, "NOT");
    add_child_as_name(root_here, "IS");
    add_child(root_here, $4);
    $$ = root_here;
    }
    ;

Expression : ExpressionTerm {
    ast_node* root_here = create_node("Expression");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | Literal{
    ast_node* root_here = create_node("Expression");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | IfExpression {
    ast_node* root_here = create_node("Expression");
    add_child(root_here, $1);
    $$ = root_here;
    }
    ;

IfExpression : IF LPAREN Condition RPAREN ID ELSE ID {
    ast_node* root_here = create_node("IfExpression");
    add_child_as_name(root_here, "ID");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, $3);
    add_child_as_name(root_here, "RPAREN");
    add_child_as_name_cont(root_here, "ID", $5);
    add_child_as_name(root_here, "ELSE");
    add_child_as_name_cont(root_here, "ID", $7);
    $$ = root_here;
    }
    ;


ExpressionTerm : ExpressionTerm Operator_Low ExpressionFactor {
    ast_node* root_here = create_node("ExpressionTerm");
    add_child(root_here, $1);
    add_child(root_here, $2);
    add_child(root_here, $3);
    $$ = root_here;
    }
    | ExpressionFactor{
    ast_node* root_here = create_node("ExpressionTerm");
    add_child(root_here, $1);
    $$ = root_here;
    }
    ;

ExpressionFactor : ExpressionFactor Operator_Mid ExpressionElem {
    ast_node* root_here = create_node("ExpressionFactor");
    add_child(root_here, $1);
    add_child(root_here, $2);
    add_child(root_here, $3);
    $$ = root_here;
    }
    | ExpressionElem {
    ast_node* root_here = create_node("ExpressionFactor");
    add_child(root_here, $1);
    $$ = root_here;
    }
    ;


ExpressionElem: Sign ExpressionElem {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, $1);
    add_child(root_here, $2);
    $$ = root_here;
    }
    | ExpressionElem Operator_High{
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, $1);
    add_child(root_here, $2);
    $$ = root_here;
    }
    | Operator_High ExpressionElem {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, $1);
    add_child(root_here, $2);
    $$ = root_here;
    }
    | NUMBER {
    ast_node* root_here = create_node("ExpressionElem");
    add_child_as_name(root_here, "NUMBER");
    $$ = root_here;
    }
    | LPAREN Expression RPAREN {
    ast_node* root_here = create_node("ExpressionElem");
    add_child_as_name(root_here, "LPAREN");
    add_child(root_here, $2);
    add_child_as_name(root_here, "RPAREN");
    $$ = root_here;
    }
    | MemberId {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | FunctionCall {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, $1);
    $$ = root_here;
    }
    | MemberId DOT FunctionCall {
    ast_node* root_here = create_node("ExpressionElem");
    add_child(root_here, $1);
    add_child_as_name(root_here, "DOT");
    add_child(root_here, $3);
    $$ = root_here;
    }
    ;

Literal: StringLiteral{
    ast_node* root_here = create_node("Literal");
    add_child(root_here, $1);
    $$ = root_here;
   }
   | NUMBER {
   ast_node* root_here = create_node("Literal");
   add_child_as_name(root_here, "NUMBER");
   $$ = root_here;
   }
   | NUL {
   ast_node* root_here = create_node("Literal");
   add_child_as_name(root_here, "NUL");
   $$ = root_here;
   }
   ;

StringLiteral: STRING {
    ast_node* root_here = create_node("StringLiteral");
    add_child_as_name_cont(root_here, "STRING", $1);
    $$ = root_here;
    }
    ;

%%
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
