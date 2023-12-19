%{
#include<stdio.h>
int chars=0;
int words=0;
int lines=0;
int space=0;
%}


%%

[^ \n\t]+ {words++,chars+=yyleng;}
\n   {lines++;}
\t   {space++;}
" "  {space++;}


%%

int yywrap(){

return 1;}

void main(){
yyin=fopen("data.txt","r");
yylex();
printf("char : %d \n words :%d \n lines:%d \n space:%d \n ",chars,words,lines,space);
}
