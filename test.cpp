#include<stdio.h>
#include<stdlib.h>

typedef struct BiTreeNode{
	char data;
	struct BiTreeNode *lchild;
	struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;
void CreateBiTree(BiTree *T);
void PreOrderTravel(BiTree T);
void InOrderTravel(BiTree T);
void TailOrderTravel(BiTree T);
int main(){
	BiTree T;
	T = (BiTree)malloc(sizeof(BiTreeNode));
	printf("请以先序遍历顺序输入：\n");
	CreateBiTree(&T);//创建 
	printf("先序遍历为：\n");
 	PreOrderTravel(T);//先序
	printf("\n");
	printf("中序遍历为：\n");
	InOrderTravel(T);//中序 
	printf("\n");
	printf("后序遍历为：\n");
	TailOrderTravel(T);// 后序
	printf("\n");
	return 0;
}
void CreateBiTree(BiTree *T){
	char val;
	scanf("%c",&val);
	if(val == '#')
		*T=NULL;
	else{
		*T=(BiTree)malloc(sizeof(BiTreeNode));
		(*T)->data = val;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
void PreOrderTravel(BiTree T){//先序 
	if(T==NULL)
		return ;
	printf("%c",T->data);
	PreOrderTravel(T->lchild);
	PreOrderTravel(T->rchild);
}

void InOrderTravel(BiTree T){//中序 
	if(T==NULL)
		return ;
	InOrderTravel(T->lchild);
	printf("%c",T->data);
	InOrderTravel(T->rchild);
}

void TailOrderTravel(BiTree T){//后序 
	if(T==NULL)
		return ;
	TailOrderTravel(T->lchild);
	TailOrderTravel(T->rchild);
	printf("%c",T->data);
}
