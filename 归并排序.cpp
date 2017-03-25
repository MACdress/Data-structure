#include<stdio.h>
#include<stdlib.h>
void Sort(int a[],int low,int mid,int high)
{
	int k,i,j;
	int *b;
	b=(int *)malloc(high*sizeof(int));//中间数组 
	k=low;
	for(i=low,j=mid;i<mid||j<high;){ 
		if(i>=mid||j<high&&a[i]>a[j]){//重要代码 
			b[k++]=a[j++];
		}
		else{
			b[k++]=a[i++];
		}
	}
	for(i=low;i<high;i++){
		a[i]=b[i];
	}
	free(b);
}
void MergeSort(int a[],int low,int high){
	if(high-low>1){
		int mid=(low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid,high);
		Sort(a,low,mid,high);
	}
}
void Print(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%3d",a[i]);
	}
	printf("\n");
}
	int main(void){
	int n;
	int *a;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int)); 
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	MergeSort(a,0,n);
	Print(a,n);
	free(a);
	return 0;
}				
