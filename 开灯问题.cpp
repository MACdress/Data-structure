#include<stdio.h>
int main()
{  
	int n,k,t,i,j;
	scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
    	t=0;
    	for(j=1;j<=k;j++){
    		if(!(i%j)){
    			if(t==1){
    				t=0;
				}
				else{
					t=1;
				}
			}
		}
		if(t==1){
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}
 
