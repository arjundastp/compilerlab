%{
#include<stdio.h>
valid=1;
%}

%token id num op

%%

start : s '='s ';'
s:id x
 |num x
 |'-' num x
 |'('s')' x
 |;
x :op s
  |'-'s
  |;
  
%%
int yyerror(){

valid=0;
printf("\n Invalid Expression \n");
return 0;}


int main(){
printf("\n Enter Input\n");
yyparse();
if(valid){
printf("\n Valid expressiom \n");

}


}
