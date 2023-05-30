%{
#include <stdio.h>
#include "y.tab.h"

%}

%%
(u|U)(p|P)(d|D)(a|A)(t|T)(e|E)          return UPDATE;    // update case insensitive
(s|S)(e|E)(t|T)                         return SET;      // set case insensitive
(w|W)(H|h)(e|E)(r|R)(e|E)               return WHERE;     // where case insensitive  
(A|a)(n|N)(d|D)                         return ANDOR;     // and case insensitive  
(o|O)(r|R)                              return ANDOR;     // or case insensitive  
[\"](.)+[\"]                            return TEXT;
['](.)+[']                              return TEXT;
[0-9]+                                  return NUMBER;
"="                                     return ASSIGN;
"<"                                     return CONDITION;
">"                                     return CONDITION;
"<="                                    return CONDITION;
">="                                    return CONDITION;
"=="                                    return CONDITION;
"!="                                    return CONDITION;
[a-zA-Z][a-zA-Z0-9_]*                   return IDENTIFIER;
\n                                      return NEWLINE;
";"                                     return SEMICOLON;
","                                     return COMMA;
[ \t]|" "                               ;	
.                                       return *yytext;
%%