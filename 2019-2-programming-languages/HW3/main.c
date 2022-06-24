#include <stdio.h>
#include <stdlib.h>

extern int yyparse(void);
FILE * yyin;
FILE * yyout;

void main(int argc, char** argv)
{
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	yyparse();
	fclose(yyin);
	fclose(yyout);
}
