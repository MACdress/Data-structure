#include<stdio.h>
#include<stdlib.h>
#include"D:\\cx\\lb.h"
//删除奇数 
ElemSN * DeleJiNode(ElemSN *h)
{
	ElemSN *p,*q;
	p=h;\
	while(p)
	{
		if(!(p->data%2)){
			q=p;
			p=p->next;
		}
		else{
			if(p==h){
				h=h->next;
				free(p);
				p=h;
			}
			else{
				q->next=p->next;
				free(p);
				p=q->next;
			}
		}
	}
	return h;
 } 
 //删除kty 
 ElemSN * PreDeleKty(ElemSN *h,int kty)
 {
 	ElemSN *p,*q;
 	p=h;
 	while(p){
 		if(p->data-kty){
 			q=p;
 			p=p->next;
		 }
		 else{
		 	if(p==h){
			   h=h->next;
			   free(p);
			   p=h;
		}
		 	else{
			  q->next=p->next;
			  free(p);
			  p=q->next;
		 }
		 }
	 }
	 return h;
 }
 int main(void)
 {
 	int kty;
 	ElemSN *head;
 	int a[9]={1,3,5,8,9,6,8,6,7},b[13]={1,1,2,3,3,4,5,6,6,7,8,9,9};
    head=CreatLink(a,9);
    PrintLink(head);
    head=DeleJiNode(head);
    PrintLink(head);
    head=CreatLink(b,13);
    PrintLink(head);
	printf("请输入要删除的值：");
	printf("\n"); 
   scanf("%d",&kty);
    head=PreDeleKty(head,kty);
    PrintLink(head);
    return 0;
 }
