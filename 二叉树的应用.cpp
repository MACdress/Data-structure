#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int levelnum[MAX];
typedef struct node {
	char data;
	struct node * Lchild;
	struct node * Rchild;
}BiTNode, *BiTree;

BiTree  CreateBiTree(char * s1,int n1, char * s2,int n2)
{
	int i;
	BiTree root;
	if (n1<=0||n2<=0)   return NULL;
	for (i = 0; i < n1 && (s1[i] - s2[n2-1]); i++);
	if (i == n1)  return  NULL;
	else {
		root = (BiTree )malloc(sizeof(BiTNode));
		root->data = s2[n2-1];
		root->Lchild = CreateBiTree(s1 , i, s2, i);
		root->Rchild = CreateBiTree(s1 + 1 + i, n1 - 1 - i, s2 + i, n2 - i - 1);
	 }
	 return root;
}
 
void  PreOrder(BiTree root) {
	BiTree s[MAX];
	BiTree p;
	int top=-1;
	p = root;
	while (p ||top!=-1 ) 
	{
		while (p) 
		{
			printf("%c", p->data);
			s[++top]=p;
			p = p->Lchild;
		}
		if (top!=-1) 
		{
			p=s[top--];
			p = p->Rchild;
		}
	}
	printf("\n");
}

void InOrder(BiTree root)
{
	BiTree s[MAX];
	BiTree p;
	int top;
	top=-1;
	p=root;
	while(p||top!=-1)
	{
		while(p){
			s[++top]=p;
			p=p->Lchild;
		}
		if(top!=-1){
			p=s[top--];
			printf("%c",p->data);
			p=p->Rchild;
		}
	}
	printf("\n");
} 
 
void PostOrder(BiTree root) 
{
	BiTree s[MAX];
	BiTree p, q;
	int top;
	top=-1;
	p = root; 
	q = NULL;
	while (p || top != -1) 
	{
		while (p)
		{
			s[++top] = p;
			p = p->Lchild;
		}
		if (top != -1) 
		{
			p = s[top];
			if (!p->Rchild || (p->Rchild == q)) 
			{
				p = s[top--];
				printf("%C", p->data);
				q = p;
				p = NULL;
			}
			else  p = p->Rchild;
		}
	}
	printf("\n");
}
 
void DPreOrder(BiTree root)
{
	if(root)
	{
		printf("%c",root->data);
		DPreOrder(root->Lchild);
		DPreOrder(root->Rchild);
	}
}

void DInOrder(BiTree root)
{
	if(root)
	{
		DInOrder(root->Lchild);
		printf("%c",root->data);
		DInOrder(root->Rchild);
	}
}
 
void DPostOrder(BiTree root)
{
	if(root)
	{
		DPostOrder(root->Lchild);
		DPostOrder(root->Rchild);
		printf("%c",root->data);
		}
}

void  LevelOrder(BiTree root ) 
{
	BiTree s[MAX];
	BiTree p;
	int rear,front;
	rear = front = -1;
	s[++rear] = root;
	p = root;
	if(p==NULL)
	{
		return;
	}
	while (rear - front) 
	{
			p = s[(++front) % 20];
			printf("%c", p->data);
		if (p->Lchild) s[(++rear) % 20] = p->Lchild;
		if (p->Rchild)  s[(++rear) % 20] = p->Rchild;
	}
	printf("\n");
}

BiTree ExchangeBiTree(BiTree root)
{
	BiTree p,q;
	if(root-NULL)
	{
	if(root->Lchild||root->Rchild)
	{
		p=ExchangeBiTree(root->Lchild);
		q=ExchangeBiTree(root->Rchild);
		root->Lchild=q;
		root->Rchild=p;
	}
}
	return root;
} 

void  Leaf(BiTree root) {
	BiTree s[MAX];
	BiTree p;
	int top,top0;
	top=-1;
	top0=-1;
	p = root;
	while (p || top != -1) {
		while (p) {
			if (!p->Lchild && !p->Rchild)
			{
				++top0;
			}
			s[++top] = p;
			p = p->Lchild;
		}
		if (top != -1) {
			p = s[top--];
			p = p->Rchild;
		}
	}
	printf("%d\n", top0+1);
}

int  PostTreeDepth(BiTree root)
{
	int hl,hr,h;
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		hl=PostTreeDepth(root->Lchild);
		hr=PostTreeDepth(root->Rchild);
		h=(hl>hr?hl:hr)+1;
		return h;
	}
} 

void PrintTree(BiTree root,int h)
{
	int i;
	if(root==NULL)
	{
		return;
	}
	else{
		PrintTree(root->Lchild,h+1);
		for(i=0;i<h;i++)
		{
			printf("  ");
		}
		printf("%c \n",root->data);
		PrintTree(root->Rchild,h+1); 
	}
}

int Judge(BiTree root)
{
	BiTree s[MAX];
	BiTree p,q;
	int front,rear,bj,cm;
	front=rear=-1;
	bj=cm=1;
	p=root;
	if(p==NULL)
	{
		return 0;
	}
	s[++rear]=p;
	while(rear-front)
	{
		p=s[++front];
	   if(p->Lchild==NULL)
	   {
	   		bj=0;
	   		if(p->Rchild)
			{
	   			cm=0;
			}
	   }
	   else{
	   	if(bj==1){
			s[++rear]=p->Lchild;
	   		if(p->Rchild==NULL)
	   		{
	   			bj=0;
	  		 }
	   		else
	   		{
	   			s[++rear]=p->Rchild;
	   		}
	   	}
	  	 else{
	   		cm=0;
	   	}
	}
}
	return cm;
} 
 
void  Level_num(BiTree root,int level)
{
	if(root)
	{
		levelnum[level]++;
		Level_num(root->Lchild,level+1);
		Level_num(root->Rchild,level+1);
	}
}
//求出二叉树的繁茂度
int fanmaonode(BiTree root,int high)
{
	int sum,i;
	if(root==NULL){
		return 0;
	}
	for(i=1;i<=high;i++)
	{
		sum+=levelnum[i]*(i-1);
	}
	return sum;
} 
//删除二叉树 
void Delete(BiTree root){
	if(root){
		Delete(root->Lchild);
		Delete(root->Rchild);
		free(root);
	}
}
//主函数 
int main(void)
{
	BiTree root,Froot;
	char In[MAX],Po[MAX];
	int I,P,high,tag,flag=0;
	char ch;
	FILE *fp;
	I=P=0;
	printf("你可以实现的功能有：\n");
	printf("1.建树。\n");
	printf("2.先序，中序，后序遍历二叉树。\n");
	printf("3.层次遍历二叉树。\n");
	printf("4.统计叶子节点个数。\n");
	printf("5.得到二叉树的高度。\n");
	printf("6.按树状打印二叉树。\n");
	printf("7.交换左右子树。\n");
	printf("8.判断是否是完全二叉树。\n");
	printf("9.得到二叉树的繁荣度.\n");
	printf("10.删除所建立的二叉树！\n");
	printf("0.结束功能。\n");
	printf("*******\t*******\t*******\n"); 
	scanf("%d",&tag);
	while(tag)
	{
		if(tag==1)
		{
			if((fp=fopen("zhongxu.txt","rt"))==NULL)
			{
				printf("Cannot open file strike any key exit!");
				getchar();
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF)
			{
				In[I++]=ch;
			}
			fclose(fp);
			I=I+1;
    		if((fp=fopen("houxu.txt","rt"))==NULL)
			{
				printf("Cannot open file strike any key exit!");
				getchar();
				exit(1);
			}
			while((ch=fgetc(fp))!=EOF)
			{
				Po[P++]=ch;
			}
			fclose(fp);
			P=P+1;
			I=strlen(In);//统计中序的长度
			P=strlen(Po);//统计后序长度 
			root=CreateBiTree(In,I,Po,P);
			flag=1;
			printf("建树成功！\n"); 
			high=PostTreeDepth(root);
		}
		else{
		if(flag)
		{
			if(tag==2)
			{
				printf("先序结果为：\n"); 
				PreOrder(root);//先序非递归遍历 
				printf("中序结果为：\n");
				InOrder(root);//中序非递归遍历
				printf("后序结果为：\n"); 
				PostOrder(root);//后序非递归遍历
			}
			if(tag==3)
			{
				printf("层次遍历结果为:\n");
				LevelOrder(root);//层次遍历
			}
			if(tag==4)
			{
				printf("叶子结点个数为：");
				Leaf(root);//统计叶子节点个数 
			}	
			if(tag==5)
			{
				printf("树的高度为：");
				high=PostTreeDepth(root);
				printf("%d\n",high);//输出树的高度 
			}
			if(tag==6)
			{
				printf("按树状打印二叉树：\n");
				PrintTree(root,1);//按树状打印二叉树
			}
			if(tag==7)
			{
				//实现树的左子树右子树的交换 
				printf("交换左右子树的原序列为\n");
				PrintTree(root,1);
				printf("\n");
				printf("交换之后的结果为：\n");
				Froot=ExchangeBiTree(root);//判断是否是完全二叉树 
				PrintTree(Froot,1);
			}	
			if(tag==8)
			{
				if(Judge(root))
				{
					printf("是一棵完全二叉树！\n"); 
				}
				else
				{
					printf("不是一颗完全二叉树！\n");
				}
			}
			if(tag==9)
			{
				printf("二叉树的繁荣度为：\n");//得到二叉树的繁荣度 
				Level_num(root,1);
				printf("%d\n",fanmaonode(root,high));
			}
			if(tag==10){
				Delete(root);
			    printf("删除成功！\n");
			    flag=0;
		    	root=NULL;
			}
		}
		else
		{
			if(tag)
			{
				printf("请先建树！\n");
		    }
		}
	}
		scanf("%d",&tag); 
	}
		printf("感谢您的使用！\n"); 
	return 0; 
} 
