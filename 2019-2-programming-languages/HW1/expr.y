%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int yylex(void);
extern void yyterminate();
extern int yyerror(const char *s);

//extern int yydebug = 1;


char* preprocess(char* str);
char* name_arr[100]= { 0 };    // Array of names
double value_arr[100] = { 0. };    // Array of values

int last_idx = 0;

void Id_assign(char* ID,  double value);
int Index_of_Id(char* ID);
double Value_of_Id(char* ID);

%}

%union{
    double real_val;
    char* str_addr;
    int int_val;
}

%type <real_val> eval 
%type <real_val> expr 
%type <real_val> term 
%type <real_val> factor 

%token <real_val> NUMBER
%token <int_val> EOL
%token <str_addr> ID

%right ASSN
%left  PLUS MINUS
%left  MULT DIV

%nonassoc UMINUS UPLUS
%nonassoc LPR RPR

%%
/* Rules */
goal:    eval goal    {}
    |    eval        {}
    ;
eval:    expr EOL    { printf("%lf\n", $1);
    }
    |   ID ASSN eval {Id_assign($1, $3);
    }
    ;

expr:    expr PLUS term    { $$ = $1 + $3;
    }
    |    expr MINUS term    { $$ = $1 - $3;
    }
    |    term        { $$ = $1;
    } 
    ;
term:    term MULT factor { $$ = $1 * $3;
    } 
    |    term DIV factor    { $$ = $1 / $3;
    } 
    |    factor        { $$ = $1;
    }
    ;
factor:  NUMBER    { $$ = $1;
    }
    |    PLUS factor { $$ = $2;
    }
    |    MINUS factor { $$ = -$2;
    }
    |    ID { $$ = Value_of_Id($1);
    }
    |    LPR expr RPR { $$ = $2;
    }
    ;

%%
/* User code */
int yyerror(const char *s)
{
    return printf("%s\n", s);
}

void Id_assign(char* ID,  double value){
    int idx = Index_of_Id(ID);

    if(idx == -1)
        idx = last_idx++;

    char* pre_ID = preprocess(ID);

    name_arr[idx] = (char*)malloc(sizeof(char) * 100);
    strcpy(name_arr[idx], pre_ID);
    value_arr[idx] = value;

    free(pre_ID);
    return;    
}

double Value_of_Id(char * ID){
    int idx = Index_of_Id(ID);
    return value_arr[idx];
}

int Index_of_Id(char* ID){
    char* check = (char*)malloc(sizeof(char) * 100);
    char* pre_ID = preprocess(ID);
    
    int idx = 0;   
    
    while(name_arr[idx] != (char*)0){
        strcpy(check,name_arr[idx]);
        if(strcmp(check, pre_ID) == 0)
            break;

        idx += 1;
    }

    free(check);
    free(pre_ID);

    return idx == 100 ? -1 : idx;
}

char* preprocess(char* str){
    char* dst = (char*)malloc(sizeof(char) * 100);

    int i = 0;
    while(str[i] != '\0' && !isblank(str[i]) &&  str[i] != '='){
        dst[i] = str[i];
        i++;
    }
    dst[i] = '\0';
    
    return dst;
}






