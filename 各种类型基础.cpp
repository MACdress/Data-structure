#include<stdio.h>
#include<stdlib.h>
#include"D:\\cx\\lb1.h" 
/*typedef struct node
{
	int data;
	struct node *next;
 } ElemsN;
 ElemsN * CreatLink(int a[],int n)
 {
 	ElemsN *h=NULL,*t,*p;
 	int i;
 	for(i=0;i<n;i++)
 	{
 		p=(ElemsN*)malloc(sizeof(ElemsN));
 		p->data=a[i];
 		p->next=NULL;
 		if(!h)
 		h=t=p;
 		else
 		t=t->next=p;
	 }
	 return h;
 }
 void PrintfLink(ElemsN *h)
 {
 	ElemsN *p;
 	for(p=h;p!=NULL;p=p->next)
 	printf("%5d",p->data);
 	printf("\n");
 }
 //节点个数 
 int JieDian(ElemsN *h)
 {
 	int i=0;
 	ElemsN *p;
 	for(p=h;p;p=p->next)
 	i++;
 	return i;
 }
 //奇数个数 
 int JiShu(ElemsN *h)
 {
 	int i=0;
 	ElemsN *p;
 	for(p=h;p&&(i+=(p->data%2));p=p->next);
 	return i;
 }
 //最大值 
 int MaxLink(ElemsN *h)
 {
 	ElemsN *p,*max;
 	max=h;
 	for(p=h->next;p;p=p->next){
	 if(max->data<p->data)
	 max=p;
}
     return max->data;
}
 //逆制输出
 void PrePrintLink(ElemsN *h)
 {
     ElemsN *p;
	 int cnt=0,a[100];
	 for(p=h;p;p=p->next)
	 a[cnt++]=p->data;
	 while(cnt>0)
     printf("%5d",a[--cnt]);
     printf("\n");
 }
 //节点查找
 ElemsN * FindKey(ElemsN *h,int key)
 {
 	ElemsN *p;
 	for(p=h;p&&(p->data)-key;p=p->next);
 	return p;
 }*/ 
 int main(void)
 {
 	int a[8]={3,2,5,8,4,7,6,9};
 	int max,key,i,j;
 	ElemSN *head;
 	head=CreatLink(a,8);
 	printf("请输出节点个数：");
 	i=JieDian(head);
	printf("%d\n",i);
	printf("请输出奇数节点个数：");
	j=JiShu(head);
	printf("%d\n",j);
	printf("请输出最大值：");
	max=MaxLink(head);
	printf("%d",max);
	printf("请逆制输出数据域：");
	PrePrintLink(head);
	printf("请输入一个数：");
	scanf("%d",&key);
	printf("他的地址为：");
	if(FindKey(head,key))
	printf("%x",FindKey(head,key));
	else
	printf("找不到！"); 
 	return 0;
 }
