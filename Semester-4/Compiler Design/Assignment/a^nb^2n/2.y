%{
    #include<stdio.h>
    #include<stdlib.h>   
    int yylex();
    void yyerror(char *); 
%}
%token A B;
%%
S : A S B B |
    A B B | 
    error { 
        yyerror(" : Incorrect pattern\n"); 
        exit(1);
    };  
%%
int main(){
    printf("Enter a string containing a and b only : ");
    yyparse();
    printf("String is in the form a^n b^2n .\n");
    return 0;
}

void yyerror(char* s){
    printf("%s",s);
}