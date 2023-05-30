%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror (char *str);
int yylex();


%}

%token UPDATE IDENTIFIER SET ASSIGN WHERE ANDOR CONDITION SEMICOLON TEXT NUMBER COMMA NEWLINE;
%%

line: update { printf("Syntax Correct\n");return 0;} ;

update: UPDATE table set| 
		error{yyerror(" : MISSING KEYWORD \"UPDATE\".\n");return 1;}
		; 
table: IDENTIFIER | 
		error{yyerror(" : Table name is missing\n");return 1;}
		; 
set: SET column where | 
		SET column semicolon NEWLINE |
		error{yyerror(" : MISSING KEYWORD \"SET\".\n");return 1;}
		;
column: IDENTIFIER ASSIGN TEXT | 
		IDENTIFIER ASSIGN NUMBER | 
		IDENTIFIER ASSIGN TEXT COMMA column | 
		IDENTIFIER ASSIGN NUMBER COMMA column |
		error{yyerror(" : Incorrect statement for SET clause\n");return 1;}
		;
where: WHERE condition semicolon NEWLINE|
		error{yyerror(" : MISSING CLAUSE \"WHERE\".\n");return 1;}
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
				yyerror(" : Incorrect statement for WHERE clause\n");			
				return 1;
			}
			;
semicolon: SEMICOLON | error {yyerror(" : Missing Semicolon \";\"\n"); return 1;};
%%

int yywrap() {
	return 1;
}

int main() {
	printf("\nSQL >> ");
	yyparse();              
	return 0;    
}


void yyerror (char *s) {       
  printf("%s",s);
  return;
}