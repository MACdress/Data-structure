#include<stdio.h>
int main(void)
{
	int i,j,n,k=1;
	int a[100][100];
	scanf("%d",&n);
	if(n>0){
    for(j=n-1;j>=n/2;--j){
    	for(i=n-j-1;i<j;++i)
    		a[i][j]=k++;
    	for(i=j;i>n-j-1;--i)
    	    a[j][i]=k++;
    	for(i=j;i>n-j-1;--i)
    	    a[i][n-j-1]=k++;
    	for(i=n-j-1;i<j;++i)
    	    a[n-j-1][i]=k++;
    	    if(2*j+1==n) a[j][j]=k++;
	}
	if(n!=1){
			for(i=0;i<n;i++){
			for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
			printf("\n");
		}
	}
		else{
			printf("%d ",n);
			printf("\n");
		}
	}
		return 0;
}
