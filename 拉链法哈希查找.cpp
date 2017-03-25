#include<stdio.h>
#include<stdlib.h>
#define  SIZE  7
typedef struct node {
	int data;
	struct node *next;
}ElemSN;
ElemSN ** CreatHuXi(int a[], int n)
{
	ElemSN ** h;
	ElemSN *p, *t;
	int i,r;
	h = (ElemSN**)malloc(SIZE * sizeof(ElemSN*));
	for (i = 0; i < SIZE; i++)
		h[i] = NULL;
	for (i = 0; i < n; i++) {
		p = (ElemSN*)malloc(sizeof(ElemSN));
		p->data = a[i];
		p->next = NULL;
		r = a[i] % SIZE;
		t = h[r];
		while (t&&(t->next))   t = t->next;
		if (t)   t->next = p;
		else   h[r] = p;
	}
	return h;
}
ElemSN * FindHuXi(ElemSN ** h, int key)
{
	ElemSN *p;
	int i,r;
	r = key%SIZE;
	p = h[r];
	while (p && (p->data - key))  p = p->next;
	return p;
}
void  PrintHuXi(ElemSN** h)
{
	ElemSN *p;
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("散列位置为%d:", i);
		for (p = h[i]; p; p = p->next)
			printf("%6d", p->data);
		printf("\n");
	}
}
int main(void) {
	ElemSN **head;
	ElemSN * hk;
	int * a;
	int i,key, n;
	printf("请输入要输入的数的个数：");
	scanf_s("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	printf("请输入要输入的数：");
	for (i = 0; i < n; i++)
		scanf_s("%d", a + i);
	head = CreatHuXi(a, n);
	printf("请输入要查找的数：");
	scanf_s("%d", &key);
	hk = FindHuXi(head, key);
	if (hk)   printf("找到了值：%d\n", hk->data);
	else     printf("没有找到值!\n");
	printf("哈希表的输出为：\n");
	PrintHuXi(head);
        free(a);
        free(head);
	system("pause");
	return 0;
}