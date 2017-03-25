#include<stdio.h>
#include<stdlib.h>
#include"D:\\cx\\lb1.h"
 typedef struct {
 	ElemSN  *head;
 }Vs;
 ElemSN * FZ(ElemSN *h,int n)
 {
 	Vs *a;
 	int i,j,k,num=0;
 	ElemSN *p;
 	p=h;
 	while(p){
 		num++;
 		p=p->next;
	 }
	 a=(Vs*)malloc(num*sizeof(Vs));
	 for(i=0;i<num;i++){
	 	a[i].head=h;
	 	h=h->next;
	 }
	 for(i=0;i<num;i=i+n){
	 	for(j=i,k=(i+n-1);j<k&&k<num;j++,k--)
	 	{
	 		p=a[j].head;
	 		a[j].head=a[k].head;
	 		a[k].head=p;
		 }
	 }
	 for(i=0;i<num;i++){
	 	if(!h){
	 		h=p=a[i].head;
		 }
		 else{
		 	p->next=a[i].head;
		 	p=p->next;
		 }
	 }
	 p->next=NULL;
	 free(a);
	 return h;
}
int main(void){
	ElemSN *h;
	int *a;
	int n,i,b;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	h=CreatLink(a,n);
	scanf("%d",&b);
	h=FZ(h,b);
	PrintLink(h);
	free(a);
	return 0;
}
