#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	char a[10000];
}Ch;
void  CreateChar(Ch *s,int n) {
	int i,end;
	end = n;
	for(i=0;i<end;i++) {
		scanf("%s",s[i].a);
	}
}
int Judge(char s[]) {
	int i, n, top,tag=0;
	char b[strlen(s)];
	i=0;
	top= -1;
	n = strlen(s);
do{
		if(s[i]=='('||s[i]=='[') {
		 b[++top]=s[i];
	}
		else
			if(top>=-1){
				if(top>-1&&(b[top]=='['&&s[i]==']')||(b[top]=='('&&s[i]==')'))
			    top--;
			    else   break;
		}
		i++;
	}while(i<n&&top>=-1);
		if((i==n)&&(top==-1)) tag=1;
		return tag;
}
int main(void)
{
	Ch * s;
	int i,t,n;
	scanf("%d", &n);
	s = (Ch*)malloc(n * sizeof(Ch));
	CreatChar(s, n);
	for (i = 0; i < n;i++) {
		t = Judge(s[i].a);
		if (t)
			printf("Yes\n");
		else
			printf("No\n");
	}
	free(s);
	return 0;
}
