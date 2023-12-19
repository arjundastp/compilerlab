%{
#include<stdio.h>
int valid=0;
%}

%token NUMBER
%left '+' '-'
%left '/' '*' '%'
%left '(' ')'


%%

ArithmeticExpression: E{
	printf("\n The result is = %d",$$);
	return 0;

};

E:E'+'E {$$=$1+$3;}
 | E'-'E {$$=$1-$3;}
 | '('E')' {$$=$2;}
 | E '*' E {$$=$1*$3;}
 | E '/' E {$$=$1/$3;}
 | E '%' E {$$=$1%$3;}
 | NUMBER {$$=$1;}
 |
 ;
 
 
%%
 int yyerror(){
 valid=1;
 printf("\n error");
 return 0;
 }
 void main(){
 printf("\n Enter ");
 yyparse();
 
 if(valid==0){
 printf("\nvalid");
 }}
