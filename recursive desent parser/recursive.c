#include<stdio.h>
#include<string.h>
#include<ctype.h>

// E T E Eprime Tprime are production  non terminals
/*if right hand side have non terminal call function of that else if terminal check presence of that in our expression if increment i
else presence of closing and open brackets add i++ finaly check wheather parsed fully throufh expresiion and error flag==0 if true accept */



void E();
void T();
void Tprime();
void Eprime();
void F();
char input[10];
int i=0,error=0;

void main(){
printf("\n enter arithmetic expression \n");

fgets(input, sizeof(input),stdin);


E();

if(strlen(input)-1==i && error==0){

printf("\n Accepted \n");
}
else{


printf("\n Rejected \n");}
}

void E(){

T();
Eprime();

}

void Eprime(){
if(input[i]=='+'){
i++;
T(); Eprime();}

}

void T(){

F();
Tprime();
}

void Tprime(){

if(input[i]=='*'){
i++;
F(); 
Tprime();
}}


void F(){
if(isalnum(input[i])){
i++;}
else if(input[i]=='('){
i++;
E();
if(input[i]==')'){
i++;}
else{
error=1;}}
else{
error=1;
}}


