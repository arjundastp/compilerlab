%{
#include<stdio.h>
int valid=1;

%}

%token digit letter

%%

start:letter s
s : letter s
  |digit s
  |
  ;
  
%%
int yyerror(){

valid=0;
printf("\n Invalid\n");
return 0;
}
int main(){
printf("\n Enter Input \n");
yyparse();
if(valid){

printf("\n Valid identifier");
}


}  

