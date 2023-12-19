%{
#include<stdio.h>
int vow=0;
int conso=0;
%}

%%
[aeiouAEIOU] {vow++;}
[A-za-z]  {conso++;}

%%


int yywrap(){
return 1;
}

void main(){

printf("\n Enter the string ");
yylex();
printf("\n vowels : %d \n consonants :%d",vow,conso);
}
