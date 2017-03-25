#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data, tag;
}ElemSN;
ElemSN * CreatHaXi(int  * a, int n) {
	ElemSN *ha;
	if (n == 0)  return NULL;
	int i, j, r;
	ha = (ElemSN *)malloc(n * sizeof(ElemSN));
	for (i = 0; i < n; i++)
	ha[i].tag = 0;
	for (i = 0; i < n; i++)
	{
		r = a[i] % n;
		if (!ha[r].tag) {
			ha[r].data = a[i];
			ha[r].tag = 1;
		}
		else {
			for (j = r+1; (j-r)&&ha[j].tag; j=(j+1)%n);
			ha[j].data = a[i];
			ha[j].tag = 1;
		}
	}
	return ha;
}
void PrintHaXi(ElemSN *h, int n)
{
	int i;
	if (!h) {
		printf("没有值!");
		return;
	}
	for (i = 0; i < n; i++) {
		if (h[i].tag)  printf("%d的散列位置：%3d\n",i, h[i].data);
		else    printf("%d的散列位置：  \n",i);
	}
}
int  FindHaXi(ElemSN *h, int key, int n) {
	int temp , i,r ;
	r = key%n;
	temp  = -1;
	i = r;
	do {
		if (h[i].tag && (h[i].data == key)) {
			temp = i;
			break;
		}
		i=(i+1)%n; 
	} while (i - r);
	return temp;
}
int main(void) {
	ElemSN *head;
	int *a;
	int hk, n, i, key;
	printf("请输入要输入的数的个数：\n");
	scanf_s("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	printf("请输入要输入的数：\n");
	for (i = 0; i < n; i++)
		scanf_s("%d", a + i);
	head = CreatHaXi(a, n);
	printf("请输入要查找的数：\n");
	scanf_s("%d", &key);
	hk = FindHaXi(head, key, n);
	if (hk>=0)   printf("找到数：%d\n", head[hk].data);
	else      printf("没有找到数！\n");
	PrintHaXi(head, n);
	system("pause");
	return 0;
}