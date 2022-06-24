%{
#include <stdlib.h>
#include <string.h>

#include "expr.tab.h"

extern int yyerror(const char*);
%}

NUMBER [0-9]+[.]?[0-9]*
ID [a-zA-Z][a-zA-Z0-9]*
SPACE [ \t\r\n]+

%%

{NUMBER} { yylval.real_val = atof(yytext);
//printf("Number : %lf\n", atof(yytext));
    return NUMBER;
}

{ID} { yylval.str_addr = yytext;
	//printf("ID : %s\n", yytext);
    return ID;
}

"+" { return PLUS; 
}

"-" { return MINUS;
}

"*" { return MULT; 
}

"/" { return DIV;
}

"=" { return ASSN;
}

"(" { return LPR;
}

")" { return RPR;
}

";" { return EOL;
}

{SPACE} { /* ignore */ 
}

.    {  printf("%lf\n", (double)yytext[0]);
           yyerror("unexpected input"); 
}


%%
/* User code */




