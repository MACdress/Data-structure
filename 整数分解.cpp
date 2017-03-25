#include<stdio.h>
#include<stdlib.h>
void Print (int *a,int n,int j){
	int k; 
	if(n>0){
		k=n;
		if(k>1){	
			while(k){
				a[j]=k;
				Print(a,n-k,j+1);
				k--;
			}
		}
		else{
			a[j]=k;
			Print(a,n-k,j+1);
		}
	}
	else{
		for(int i=0;i<j;i++){
			printf("%d",a[i]);
		}
		printf("\n");
	}
}
int main(void)
{
	int n;
	int *a;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	Print(a,n,0);
	free(a);
	return 0;
}