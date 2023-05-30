%{
#include <stdio.h>
#include <stdlib.h>

void yyerror (char *str);
int yylex();
%}

%token DELETE FROM IDENTIFIER WHERE ANDOR CONDITION SEMICOLON TEXT NUMBER NEWLINE;
%%
line: delete { printf("Syntax Correct\n");return 0;}
	;

delete: DELETE from| error {yyerror(" : Did you mean \"DELETE\" ??\n");return 1;}
	;

from: FROM table where| FROM table semicolon NEWLINE | error {yyerror(" : Did you mean \"FROM\" ??\n");return 1;}
	;

table: IDENTIFIER
			| error {yyerror(" : table name is missing.\n");return 1;}
	;

where: WHERE condition semicolon NEWLINE
 			| error {yyerror(" : Did you mean \"WHERE\" ??\n");return 1;}
	;
condition: IDENTIFIER CONDITION IDENTIFIER |
			IDENTIFIER CONDITION TEXT |
			IDENTIFIER CONDITION NUMBER |
			IDENTIFIER CONDITION IDENTIFIER ANDOR condition |
			IDENTIFIER CONDITION TEXT ANDOR condition |
			IDENTIFIER CONDITION NUMBER ANDOR condition |
			NUMBER CONDITION NUMBER |
			NUMBER CONDITION NUMBER ANDOR condition |
			error {
				yyerror(" : Incorrect Condition \n");			
				return 1;
			}
		;
semicolon: SEMICOLON | error {yyerror(" : Missing Semicolon \";\"\n"); return 1;};
%%


int main() {
	printf("\nSQL >> ");
	yyparse();              
	return 0;    
}

void yyerror (char *s) {       
  printf("%s",s);
  return;
}

int yywrap(){
	return 1;
}