#include<stdio.h>
#include<stdlib.h>
#include"D:\\cx\\lb.h"

 int main(void)
 {
 	ElemSN *head;
 	int a[10]={1,3,6,8,9,6,4,6,8,8};
 	//�������� 
 	head=PreCreatLink(a,10);
 	//������� 
 	PrintLink(head);
 	//�������� 
 	head=PrePrintLink(head);
 	//������� 
	PrintLink(head);
	return 0; 
 }
