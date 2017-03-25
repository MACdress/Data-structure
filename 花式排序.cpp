#include<stdio.h>
#include<stdlib.h>
void  Z(int a[],int n)
{//÷±Ω”—°‘Ò≈≈–Ú 
	int i,j,temp,kmin;
	for(i=0;i<n-1;i++){
		kmin=i;
		for(j=i;j<n;j++){
			if(a[kmin]>a[j])
			kmin=j;
			}
			if(kmin-j)
			{
				temp=a[i];
				a[i]=a[kmin];
				a[kmin]=temp;
			}
		}
}
void   Bubblesort(int a[],int n)
{//√∞≈›≈≈–Ú 
	int i,j,temp,tag=0;
	for(i=0;i<n;i++){
		tag=0;
		for(j=n-1;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
				tag=1;
			}
		}
		if(!tag)       break;
	}
}
void  H(int a[],int low,int high)
{// 
	int i,j,x,temp;
	if(low<high){
	j=high;
	i=low+1;
	x=a[low];
	while(i<j){
		while(i<high&&a[i]<x)   i++;
		while(low<j&&a[j]>x)   j--;
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	if(a[low]>a[j]){
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
}
	H(a,low,j-1);
	H(a,j+1,high);
}
}
int QKpass(int a[], int low, int high)
{
	a[0] = a[i];
	while (low < high) {
		while (low < high&&a[high] >= a[0])    --high;
		while (low < high&&a[low] < a[0])    ++low;
		a[high] = a[low];
	}
	a[low] = a[0];
	return low;
}
void  QKSort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = QKpass(a, low, high);
		QKSort(a, low, mid - 1);
		QKSort(a, mid + 1, high);
	}
}
int main(void)
{
	int data[10];
	int low,high,i;
	for (i = 1; i <= 9; i++)
		scanf("%d", data + i);
	low=1;high=9;
	QKSort(data,low,high);
	for(i=0;i<9;i++)
	printf("  %d",data[i]);
	printf("\n");
	return 0 ;
}