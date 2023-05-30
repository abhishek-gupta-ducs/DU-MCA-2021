%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int yylex();
void yyerror(char *);
%}

%token ID
%left '+' '-'
%left '*' '/'

%%
E: E '+' T | T {printf("Valid Statement \n"); return 0;};
T: T '*' F | F ;
F: '(' E ')' | ID;

%%

int main(){
  yyparse();
  return 0;
}

void yyerror(char *s) {
  printf("Syntax Error\n");
}
