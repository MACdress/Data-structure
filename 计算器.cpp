#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int leveal(char q)
{
	switch(q){
		case '@':  return -1;
		case'(':  return 0;
		case'+':
		case'-':   return 1;
		case'*':
		case'/':   return 2;
	}
}
   double cal(double x,double y,char q)
	{
		switch(q){
			case '+':  return x+y;
			case'-':   return x-y;
			case'*':   return x*y;
		    case'/':   return x/y;
		}
	}
   double  compate(char s[]){
   	double vas[100],v1,v2,y;
   	int vtop,otop,i;
   	char ops[100],op;
   	i=0;
   	vtop=otop=-1;
   	ops[++otop]='@';
   while(s[i]){
   	if(s[i]>='0'&&s[i]<='9'){
   		y=0;
   		while(s[i]>='0'&&s[i]<='9'){
   			y=(double)(10*y+s[i]-48);
   			i++;
   		}
   			vas[++vtop]=y;
   			i--;
	   }
	   else {
	   if(s[i]=='(')
	   ops[++otop]='(';
	   else{ 
	   if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
	   	while(leveal(ops[otop])>=leveal(s[i])){
	       op=ops[otop--];
	       v1=vas[vtop--];
	       v2=vas[vtop--];
	    vas[++vtop]=cal(v2,v1,op);
	   }
	   ops[++otop]=s[i];
	   }
	   else{ 
	   if(s[i]==')'){
	   	while(ops[otop]-'('){
	   	   op=ops[otop--];
	       v1=vas[vtop--];
	       v2=vas[vtop--];
	       vas[++vtop]=cal(v2,v1,op);
		   }
		   otop--;
	   }
	  } 
	  }
	  } 
	  i++;
	  } 
   while(otop!=0){
   	       op=ops[otop--];
	       v1=vas[vtop--];
	       v2=vas[vtop--];
	       vas[++vtop]=cal(v2,v1,op);
   }
   return vas[otop];
}
int main(void){
	double real;
	char s[100];
	printf("请输入表达式：\n"); 
	gets(s);
	real=compate(s);
	printf("%s=%.3lf",s,real);
	return 0;
}
