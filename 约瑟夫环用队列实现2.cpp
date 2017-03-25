#include<stdio.h>
#include<stdlib.h>
void  Josphus(int *q,int n,int m)
{
	int front,rear,i,cnt=0;
	front=0;
	rear=n;
	while(front-rear){
		for(i=0;i<m-1;i++)
		{
		front=(front+1)%(n+1);
		rear=(rear+1)%(n+1);
		q[rear]=q[front];
	}
	         front=(front+1)%(n+1);
		  printf("%3d",q[front]);
	}
 } 
 int main(void){
 	int n,m,i;
 	int*q;
 	printf("请依次输入小孩子的个数和要出列孩子所报的数："); 
 	scanf("%d%d",&n,&m);
 	q=(int*)malloc((n+1)*sizeof(int));
 	for(i=1;i<n+1;i++)
 	q[i]=i;
 	Josphus(q,n,m);
 	free(q);
 	return 0;
 	} 
 
