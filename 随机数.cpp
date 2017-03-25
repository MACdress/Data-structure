#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(0));
    for(int i=0;i<10;i++)
        printf("%3d",rand()%30);
    printf("\n");
    return 0;
}
