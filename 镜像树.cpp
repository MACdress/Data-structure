#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	char data;
	struct node * Lchild;
	struct node * Rchild;
}BiTNode, *BiTree;
BiTree CreateBiTree(BiTree root) {
	char ch;
	ch = getchar();
	if (ch == '#')  root = NULL;
	else {
		root = (BiTree)malloc(sizeof(BiTNode));
		root->data = ch;
	root->Lchild=CreateBiTree(root->Lchild);
	root->Rchild=CreateBiTree(root->Rchild);
	}
	return root; 
}
BiTree JX(BiTree root){
	BiTree q,p;
	if(root){
		if(root->Lchild||root->Rchild){
	      q=JX(root->Lchild );
	      p=JX(root->Rchild);
	       root->Lchild=p;
		   root->Rchild=q; 
		}
	    return root; 
	}
	return NULL; 
	} 
void PreOrder(BiTree root){
	if(root){
		printf("%c",root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}
 int main(void){
 	BiTree root;
 	root=CreateBiTree(root);
 	PreOrder(root);
 	printf("\n");
 	root=JX(root);
 	PreOrder(root);
 	printf("\n");
 	return 0;
 }
