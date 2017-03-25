#include<stdio.h>
#include<stdlib.h>
void Swap(int *a,int j,int i){
	int temp;
	temp=a[j];
	a[j]=a[i];
	a[i]=temp;
}
void Print (int *a,int n,int j){
	int i;
	if(j<n){
		for(i=j;i<n;i++){
			Swap(a,j,i);
			Print(a,n,j+1);
			Swap(a,j,i);	
		}
	}
	else{
		for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
	}
}
int main(void)
{
	int n;
	int *a,*b;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",a+i); 
	}
	Print(a,n,0);
	free(a);
	free(b);
	return 0;
}