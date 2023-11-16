%{
	#include<stdio.h>
	#include<y.tab.h>
	extern int yy1val;
	%}

%%
[0-9]+ {
	yyval=atoi(yytext);
	return NUMBER;
	}
[\t] ;
[\n] return 0;
. return yytext[0];
%%

int yywrap(){
return 1;
}



