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
		printf("û��ֵ!");
		return;
	}
	for (i = 0; i < n; i++) {
		if (h[i].tag)  printf("%d��ɢ��λ�ã�%3d\n",i, h[i].data);
		else    printf("%d��ɢ��λ�ã�  \n",i);
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
	printf("������Ҫ��������ĸ�����\n");
	scanf_s("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	printf("������Ҫ���������\n");
	for (i = 0; i < n; i++)
		scanf_s("%d", a + i);
	head = CreatHaXi(a, n);
	printf("������Ҫ���ҵ�����\n");
	scanf_s("%d", &key);
	hk = FindHaXi(head, key, n);
	if (hk>=0)   printf("�ҵ�����%d\n", head[hk].data);
	else      printf("û���ҵ�����\n");
	PrintHaXi(head, n);
	system("pause");
	return 0;
}