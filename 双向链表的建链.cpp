#include<stdio.h>
#include<stdlib.h>
typedef  struct node{
	int data;
	struct node *prior,*next;
}DLNode,*DLinkList;
DLinkList CreatLink(int a[],int n){
	DLinkList rear,t,h;
	int i;
	h=t=(DLinkList)malloc(sizeof(DLinkList*));
	t->next=NULL;
	for(i=0;i<n;i++){
		t->next=(DLinkList)malloc(sizeof(DLinkList*));
	    t->next->prior=t;
	    t=t->next;
		t->next=NULL
	}
	rear=t;
	rear->next=h
} 
