#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define  M 256

int w[256]={0}; 

typedef struct {
	int weight;
	int parent, Lchild, Rchild;
}HTNode;

typedef struct{
	int weigh;
	char data;
	double bm;
	int num;
	int *z;
}ZF;

void select(HTNode *ht, int n, int * s1, int * s2) 
{
	int i,t,min,max;
    max=min=0;
    for(i=1;i<=n;i++)
	{
    	if(!ht[i].parent)
		{
    		if(max&&min)
			{
    			if(ht[max].weight>ht[i].weight)
				{
    				if(ht[min].weight>ht[i].weight)
					{
    					max=min;
    					min=i;
					}
					else{
						max=i;
					}
				}
			}
			else
			{
				if(!min)
				{
					min=i;
				}
				else
				{
					max=i;
				}
			}
		}
	}
	(*s1)=min;
	(*s2)=max;
}
ZF * CrtHuffmanTree(HTNode *ht,ZF *w,int n) 
{
	int i,s1,s2,m;
	m=2*n-1;
	for (i = 1; i <= n; i++)
	{
		ht[i].weight=w[i].weigh;
		ht[i].Lchild=0;
		ht[i].parent=0;
		ht[i].Rchild=0;
	}   
	for (i = n + 1; i <= m; i++){
		ht[i].weight=0;
		ht[i].Lchild=0;
		ht[i].parent=0;
		ht[i].Rchild=0;
	}
	for (i = n+1; i <= m; i++)
	{
		select(ht, i - 1, &s1, &s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[s1].parent = ht[s2].parent = i;
		ht[i].Lchild = s1; ht[i].Rchild = s2;
	}
	return w;
}

void CrtHuffmanCodel(HTNode *ht, int n,ZF *w)
{
	int *cd;
	int i,p,c,start,j,k;
	FILE *fp;
	cd = (int *)malloc(n * sizeof(int));
	for (i = 1; i <= n; i++)
	{
		start=0;
		c = i; 
		p = ht[i].parent;
		while (p) 
		{
			if (ht[p].Lchild == c) 
			{
				 cd[start] = 0;
			}
			else
			{
				cd[start] = 1;
			}	
			c = p;
			p = ht[c].parent;
			start++; 
		}
		k=start-1;
		w[i].bm=0;
		w[i].num=start;
		w[i].z=(int *)malloc(start*sizeof(int));
		for(j=0;j<start;j++)
	{
		w[i].z[j]=cd[k--];
	}
		for(j=0;j<start;j++)
		{
			w[i].bm=w[i].bm+cd[j]*pow(2,k);
			k-=1;
		}
	}
	fp=fopen("bianma.txt","wt");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%c %.0lf\n",w[i].data,w[i].bm);
	} 
	fclose(fp);
	free(cd);
}

/*int  JMHuffmanCode(HTNode *ht,ZF *s,int n){
	char d[100];
	int *a;
	int i,j,t,len,z;
	scanf("%s",d);
	getchar();
	len=strlen(d);
	a=(int *)malloc(sizeof(int));
	for(i=0;i<len;i++)
	{
		a[i]=d[i]-48;
	}
	for(i=0;i<n;i++)
	{
		z=len;
		t=s[i+1].num;
		if(t==z){ 
			for(j=0;j<t&&(a[j]==s[i+1].z[j]);j++);
		if(j== t){
		    return i;
	     }
	}
	}
	return -1;   
}
*/
int main(void)
{						
	int n,i,j;
	ZF *hc;
	HTNode * ht;
	char ch;
    FILE *fp;
    n=0;
    if((fp=fopen("huffman.txt","r"))==NULL)
    {
    	printf("Cannot open file strike any key exit");
    	getchar();
    	exit(1);
	} 
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch>='A'&&ch<='z'||(ch==',')||(ch=='.')||ch=='!'){
		w[ch]++;
		n++;
		}
    }
    hc=(ZF*)malloc(n*sizeof(ZF));
    j=0;
    for(i=0;i<M;i++){
		if(w[i]>0)
		{
			hc[j].data=i;
			hc[j++].weigh=w[i];
		}
	}
	fclose(fp);
	 ht=(HTNode *)malloc((2*n) * sizeof(HTNode));
	 n=j;
	 hc=CrtHuffmanTree(ht, hc, n);
	 CrtHuffmanCodel(ht, n,hc);
	 for(i=0;i<n;i++){
	 	printf("%c %d ",hc[i].data,hc[i].weigh);
	 	for(j=0;j<hc[i].num;j++)
	 	{
	 		printf("%d",hc[i].z[j]);
		 }
		 printf("\n");
	 }
	return 0;
}
