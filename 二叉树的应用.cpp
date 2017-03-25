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
//����������ķ�ï��
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
//ɾ�������� 
void Delete(BiTree root){
	if(root){
		Delete(root->Lchild);
		Delete(root->Rchild);
		free(root);
	}
}
//������ 
int main(void)
{
	BiTree root,Froot;
	char In[MAX],Po[MAX];
	int I,P,high,tag,flag=0;
	char ch;
	FILE *fp;
	I=P=0;
	printf("�����ʵ�ֵĹ����У�\n");
	printf("1.������\n");
	printf("2.�������򣬺��������������\n");
	printf("3.��α�����������\n");
	printf("4.ͳ��Ҷ�ӽڵ������\n");
	printf("5.�õ��������ĸ߶ȡ�\n");
	printf("6.����״��ӡ��������\n");
	printf("7.��������������\n");
	printf("8.�ж��Ƿ�����ȫ��������\n");
	printf("9.�õ��������ķ��ٶ�.\n");
	printf("10.ɾ���������Ķ�������\n");
	printf("0.�������ܡ�\n");
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
			I=strlen(In);//ͳ������ĳ���
			P=strlen(Po);//ͳ�ƺ��򳤶� 
			root=CreateBiTree(In,I,Po,P);
			flag=1;
			printf("�����ɹ���\n"); 
			high=PostTreeDepth(root);
		}
		else{
		if(flag)
		{
			if(tag==2)
			{
				printf("������Ϊ��\n"); 
				PreOrder(root);//����ǵݹ���� 
				printf("������Ϊ��\n");
				InOrder(root);//����ǵݹ����
				printf("������Ϊ��\n"); 
				PostOrder(root);//����ǵݹ����
			}
			if(tag==3)
			{
				printf("��α������Ϊ:\n");
				LevelOrder(root);//��α���
			}
			if(tag==4)
			{
				printf("Ҷ�ӽ�����Ϊ��");
				Leaf(root);//ͳ��Ҷ�ӽڵ���� 
			}	
			if(tag==5)
			{
				printf("���ĸ߶�Ϊ��");
				high=PostTreeDepth(root);
				printf("%d\n",high);//������ĸ߶� 
			}
			if(tag==6)
			{
				printf("����״��ӡ��������\n");
				PrintTree(root,1);//����״��ӡ������
			}
			if(tag==7)
			{
				//ʵ�������������������Ľ��� 
				printf("��������������ԭ����Ϊ\n");
				PrintTree(root,1);
				printf("\n");
				printf("����֮��Ľ��Ϊ��\n");
				Froot=ExchangeBiTree(root);//�ж��Ƿ�����ȫ������ 
				PrintTree(Froot,1);
			}	
			if(tag==8)
			{
				if(Judge(root))
				{
					printf("��һ����ȫ��������\n"); 
				}
				else
				{
					printf("����һ����ȫ��������\n");
				}
			}
			if(tag==9)
			{
				printf("�������ķ��ٶ�Ϊ��\n");//�õ��������ķ��ٶ� 
				Level_num(root,1);
				printf("%d\n",fanmaonode(root,high));
			}
			if(tag==10){
				Delete(root);
			    printf("ɾ���ɹ���\n");
			    flag=0;
		    	root=NULL;
			}
		}
		else
		{
			if(tag)
			{
				printf("���Ƚ�����\n");
		    }
		}
	}
		scanf("%d",&tag); 
	}
		printf("��л����ʹ�ã�\n"); 
	return 0; 
} 
