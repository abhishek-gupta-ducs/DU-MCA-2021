%{
	#include<stdio.h>
%}
%%
\n ;
. ;
[a-zA-Z_]+ {fprintf(yyout,"%s",yytext);
		fprintf(yyout,"%c",'|');}
%%
int main(){
	yyin = fopen("keyword.txt","r");
	yyout = fopen("key.txt","w");
	yylex();
}
int yywrap(){
	return 1;
}
