/* Header files*/

#include<stdio.h> //standard input output
#include<string.h> //string manipulation
#include<ctype.h> //character manupulation
#include<stdlib.h>// to use atoi() function which is used to convert character to integer


/*function initialisation */
void constant();
void change(int p,char *result);
void display();

/* end of function initialisation */


int n;

/*structure initialisation */
struct expr{
char op[2],op1[5],op2[5],res[5];
int flag;
}arr[10];


void main(){

int i;
/* Reading Input intermediate code */
printf("\n Enter the maximum number of expression \n");
scanf("%d",&n);
printf("\n Enter the Input \n");
for(i=0;i<n;i++){
scanf("%s",&arr[i].op);
scanf("%s",&arr[i].op1);
scanf("%s",&arr[i].op2);
scanf("%s",&arr[i].res);
arr[i].flag=0;
}

    
constant();    
display();
  
}
/* Change function changes all instance of a to 3 and replaces it with 3 its also known as folding */
void change(int p,char *result){
	int i;
	for(i=p;i<n;i++){
		if(strcmp(arr[p].res,arr[i].op1)==0){
		strcpy(arr[i].op1,result);
		
		
		}else if(strcmp(arr[p].res,arr[i].op2)==0){
			strcpy(arr[i].op2,result);
		
		}
	
	
	}



}



void display(){

int i=0;
printf("\n Optimized code is ....\n");
for(i=0;i<n;i++){

	if(!arr[i].flag){
	
		printf("\n %s%s%s%s",arr[i].op,arr[i].op1,arr[i].op2,arr[i].res);
	
	
	}

}
printf("\n");

}

/* Propogation block ,In which we finds a value to be equated in the occurence of its here if wen consider example
a=3
t1=a+b
t2=a+c
t3=t1+t2
here a=3 so this function return 3 and the index value 0 which is the paramater of change function.
*/
void constant(){

int i;
int opr1,opr2,result;
char op,res1[10];
for(i=0;i<n;i++){
	if((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) ||(strcmp(arr[i].op,"=")==0)){
		
		opr1=atoi(arr[i].op1);
		opr2=atoi(arr[i].op2);
		op=arr[i].op[0];
		switch(op){
			case '=':
			result=opr1;
			break;
			case '+': result=opr1+opr2;
			break;
			case '-': result=opr1-opr2;
			break;
			case '*': result =opr1*opr2;
			break;
			case '/':result=opr1/opr2;
			break;
		
		}
		sprintf(res1,"%d",result);
		arr[i].flag=1;
		
		change(i,res1);
	}

}}
