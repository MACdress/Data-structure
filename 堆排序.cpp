#include<stdio.h>
#include<stdlib.h>
void DUI(int a[], int n) {
	int end, tag=1, temp, p;
	end=n;
	while (end - 1) {
		p=end/2;
		while(tag){
			tag=0;
			while(p) {
				if (a[p] < a[2*p]) {
					temp = a[p];
					a[p] = a[2*p];
					a[2*p] = temp;
					tag = 1;
				}
				if ((2*p+1<=end)&&a[p] < a[2*p + 1]) {
					temp = a[p];
					a[p] = a[2*p+1];
					a[2*p+1] = temp;
					tag = 1;
				}
				p--;
			}
		}
		temp = a[1];
		a[1] = a[end];
		a[end] = temp;
		end--;
	}
}
int main (void){
	int n, i;
	int *a;
	scanf("%d",&n);
	a = (int *)malloc((n + 1) * sizeof(int));
	for (i = 1; i <= n; i++)
		scanf("%d", a + i);
	DUI(a, n);
	for (i = 1; i <= n; i++)
		printf(" %d", a[i]);
		printf("\n");  
return 0;
}
