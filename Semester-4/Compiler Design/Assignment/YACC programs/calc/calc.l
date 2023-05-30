%{
#include "y.tab.h"
%}

%%

[0-9]+                  { yylval = atoi(yytext); return NUMBER; }
[ \t]                   ; // ignore whitespace
\n                      return EOL;

[-+*/()=]               { return yytext[0]; }

.                       { printf("Invalid character: %c\n", yytext[0]); }

%%

int yywrap(void) {
    return 1;
}

