%{
#include "y.tab.h"
%}

%%

[0-9]+(\.[0-9]+)? { yylval = atof(yytext); return NUMBER; }
[ \t\n]           { /* ignore whitespace */ }
.                 { return yytext[0]; }

%%

int yywrap() {
  return 1;
}
