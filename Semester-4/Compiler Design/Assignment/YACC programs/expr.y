%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int yylex();
void yyerror(char *);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%left '^'
%left UMINUS

%%

expression: NUMBER
          | '-' expression %prec UMINUS
          | expression '+' expression
          | expression '-' expression
          | expression '*' expression
          | expression '/' expression
          | expression '^' expression
          | '(' expression ')'
          ;

%%

int main() {
  yyparse();
  return 0;
}

void yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
}

