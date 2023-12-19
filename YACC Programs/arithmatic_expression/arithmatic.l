%{
#include<stdio.h>
#include "y.tab.h"
%}
%%
[a-zA-Z_][a-zA-Z_0-9]* return id;
[0-9]+(\.[0-9]*)?  return num;
[+/*] return op;
\n return 0;
. return yytext[0];
%%

yywrap(){

return 1;
}
