#include<stdio.h>
int Ni(int x,int sum)
{
	if(x/10)  return x%10;
	else{
		sum=sum*10+x%10;
		sum=Ni(x/10,sum);
	}
	return sum;
}
int mian(void){
	int x,sum=0;
	scanf("%d",&x);
	sum=Ni(x,sum);
	printf("%d\n",sum);
	return 0;
}
