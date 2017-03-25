#include<stdio.h>
#include<stdlib.h>
#include"D:\\cx\\lb1.h"
ElemSN * PreSortALink(ElemSN *h1,ElemSN *h2)
{
	ElemSN *h,*p;
	h=NULL;
	while(h1||h2){
		//判断尾插p2的条件
		if(h2&&(!h1||h1->data>h2->data)){
		//尾插p2的过程 
			if(!h)	p=h=h2;
			else	p=p->next=h2;
			h2=h2->next;
		} 
		//尾插p1的过程 
		else{
			if(h1->data-p->data){
			if(!h)	p=h=h1;
			else	p=p->next=h1;
		}
	        h1=h1->next;
		}
	}
	return h;
 } 
 int main(void)
 {
 	ElemSN  *h,*h1,*h2;
 	int a1[20]={2,5,6,8,9,11,13,15,17,19,21,22,23,24,25,26,27,28,29,30},a2[15]={1,6,8,9,11,12,13,15,16,17,18,19,20,21,25};
 	h1=CreatLink(a1,20);
 	h2=CreatLink(a2,15);
 	PrintLink(h1);
 	PrintLink(h2);
 	h=PreSortALink(h1,h2);
 	PrintLink(h);
 	return 0;
 }
