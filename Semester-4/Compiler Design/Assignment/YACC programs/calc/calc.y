%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%token NUMBER EOL
%left '+' '-'
%left '*' '/'
%left UMINUS

%%

statement: expr EOL            { printf("= %d\n", $1); }
         |                  /* empty */
         ;

expr:    expr '+' expr        { $$ = $1 + $3; }
        | expr '-' expr      { $$ = $1 - $3; }
        | expr '*' expr      { $$ = $1 * $3; }
        | expr '/' expr      { $$ = $1 / $3; }
        | '(' expr ')'       { $$ = $2; }
        | '-' expr %prec UMINUS { $$ = -$2; }
        | NUMBER             { $$ = $1; }
        ;

%%

int main(void) {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "error: %s\n", s);
}

