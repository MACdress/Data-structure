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
 //�ڵ���� 
 int JieDian(ElemsN *h)
 {
 	int i=0;
 	ElemsN *p;
 	for(p=h;p;p=p->next)
 	i++;
 	return i;
 }
 //�������� 
 int JiShu(ElemsN *h)
 {
 	int i=0;
 	ElemsN *p;
 	for(p=h;p&&(i+=(p->data%2));p=p->next);
 	return i;
 }
 //���ֵ 
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
 //�������
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
 //�ڵ����
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
 	printf("������ڵ������");
 	i=JieDian(head);
	printf("%d\n",i);
	printf("����������ڵ������");
	j=JiShu(head);
	printf("%d\n",j);
	printf("��������ֵ��");
	max=MaxLink(head);
	printf("%d",max);
	printf("���������������");
	PrePrintLink(head);
	printf("������һ������");
	scanf("%d",&key);
	printf("���ĵ�ַΪ��");
	if(FindKey(head,key))
	printf("%x",FindKey(head,key));
	else
	printf("�Ҳ�����"); 
 	return 0;
 }
