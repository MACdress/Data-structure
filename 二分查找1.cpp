#include<stdio.h>
#include<stdlib.h>
int halfsearch(int a[],int low,int high,int key)
{
	int b,mid;
	if(low<=high){
		mid=(low+high)/2;
		if(a[mid]==key)  b=mid;
		else{
			if(a[mid]<key)    b=halfsearch(a,mid+1,high,key);
			else              b=halfsearch(a,low,mid-1,key);
		}
	}
	else b=-1;
	return b;
}
int main(void){
	int Data[]={1,3,5,7,9,11,13,15,17,19};
	int key,n,low,high;
	low=0;
	high=9;
	scanf("%d",&key);
	n=halfsearch(Data,low,high,key);
	printf("%d",n);
	return 0;
}
