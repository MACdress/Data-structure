#include<stdio.h>
#include<stdlib.h>
#include"D:\\cx\\lb1.h"
ElemSN *  nizhi(ElemSN *h,ElemSN *hn)//hnΪ�µ�ͷָ�룬��ֵΪNULL�� 
{
	ElemSN *p;
	p=h;
	if(p)
	{
		p=h->next;
		h->next=hn;
		hn=h;
		hn=nizhi(p,hn); 
	}
	return hn;
	
}
int main(void)
{
	ElemSN *head,*hn;
	int *a;
	int n,i;
	hn=NULL;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",a+i);
	head=CreatLink(a,n);
	hn=nizhi(head,hn);
	PrintLink(hn);
	return 0;
}
