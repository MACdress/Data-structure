#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data, tag;
}ElemSN;
typedef struct {
	ElemSN *head;
	int  len,t;
}HaXi;
int GetP(int x)
{
	int max, i,j;
	max = 1;
	for (i = 1; i <= x; i++) {
		for (j = 1; j <= i&&i%j; j++);
		if (i - j) {
			if (max < i) max = i;
		}
	}
	return max;
}
HaXi   CreatHaXi( int a[], int n) {
	HaXi s;
	int i, j, r, k;

	if (n == 0)
		s.head = NULL; 
	else
	{
		s.head = (ElemSN *)malloc((n + 2) * sizeof(ElemSN));
		s.len = (n + 2);
		s.t = GetP(s.len);
		for (i = 0; i < s.len; i++)
			s.head[i].tag = 0;
		for (i = 0; i < n; i++) {
			r = a[i] %s.t;
			for (k = 0; k <=( s.len / 2); k = ++k, k = k*k) {
				j = (r + k)%s.len;
				if (!s.head[j].tag)
					break;
				else {
					j = r - k;
					if (j < 0)  j = s.len + j;
					if (!s.head[j].tag)
						break;
				}
			}
			s.head[j].data = a[i];
			s.head[j].tag = 1;
		}
	}
	return s;
}
				void PrintHaXi(HaXi s)
			{
				int i;
				if (s.head == NULL)   return;
				for (i = 0; i < s.len; i++) {
					if (s.head[i].tag)  printf("%d的散列位置：%3d\n", i,s.head[i].data);
					else    printf("%d的散列位置：  \n", i);
				}
			}
			int  FindHaXi(HaXi h, int key, int n) {
	 			int k, i,j,b, r,temp;
				temp = -1;
				r = key%n;
				if (h.head != NULL) {
					for (i = r, k = 0; k < (h.len / 2); k = ++k, k = k*k) {
						j = (r + k) % h.len;
						b = r - k;
						if (b < 0)  b = b + h.len;
						if (!(h.head[j].data - key))
						{
							temp = j;
							break;
						}
						else
							if (!(h.head[b].data - key)) {
								temp = b;
								break;
							}
					}
				}
				return temp;
			}
				int main(void) {
					HaXi s;
					int *a;
					int hk, n, i, key;
					printf("请输入要输入的数的个数：\n");
					scanf_s("%d", &n);
					a = (int *)malloc(n * sizeof(int));
					printf("请输入要输入的数：\n");
					for (i = 0; i < n; i++)
						scanf_s("%d", a + i);
					s=CreatHaXi( a, n);
					printf("请输入要查找的数：\n");
					scanf_s("%d", &key);
					hk = FindHaXi(s, key, n);
					if (hk >= 0)   printf("找到数：%d\n", s.head[hk].data);
					else      printf("没有找到数！\n");
					PrintHaXi(s);
					system("pause");
					return 0;
				}