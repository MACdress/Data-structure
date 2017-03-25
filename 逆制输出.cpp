#include<stdio.h>
#include<stdlib.h>
#include"D:\\cx\\lb.h"

 int main(void)
 {
 	ElemSN *head;
 	int a[10]={1,3,6,8,9,6,4,6,8,8};
 	//构建链表 
 	head=PreCreatLink(a,10);
 	//输出链表 
 	PrintLink(head);
 	//逆制链表 
 	head=PrePrintLink(head);
 	//输出链表 
	PrintLink(head);
	return 0; 
 }
