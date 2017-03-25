#include<iostream>
#include<stdlib.h>
using namespace std;
namespace CompA
{
int getMaxor(int arr[],int count, bool isMax)
{
	int temp=arr[0];
	for(int i=1;i<count;i++){
		if(isMax){
			if(temp<arr[i])
			temp=arr[i];
		}
		else{
			if(temp>arr[i])
			temp=arr[i];
		}
	}
	return temp;
}
}
int main(void){
	int a=3;
	int &b=a;
	b=10;
	cout<<a<<endl;
	system("pause");
	return 0;
}
