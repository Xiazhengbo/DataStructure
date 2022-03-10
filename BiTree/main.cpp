#include "function.h"

//�ݹ�ʵ��
//abdhiejcfg
void preOrder(BiTree p)
{
	if(p!=NULL)
	{
		putchar(p->c);//�ȼ���visit����
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
//�������  hdibjeafcg
void InOrder(BiTree p)
{
	if(p!=NULL)
	{
		InOrder(p->lchild);
		putchar(p->c);
		InOrder(p->rchild);
	}
}
//hidjebfgca
void PostOrder(BiTree p)
{
	if(p!=NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->c);
	}
}
//��������ǵݹ飬�ǵݹ�ִ��Ч�ʸ��ߣ����ĸ��ʺܵ�
void InOrder2(BiTree T)
{
	SqStack S;
	InitStack(S);BiTree p=T;
	while(p||!StackEmpty(S))//�߼���||
	{
		if(p)
		{
			Push(S,p);
			p=p->lchild;
		}else{
			Pop(S,p);putchar(p->c);
			p=p->rchild;
		}
	}
}
//��α���,������ȱ���
void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q,T);//�������
	while(!IsEmpty(Q))
	{
		DeQueue(Q,p);
		putchar(p->c);
		if(p->lchild!=NULL)
			EnQueue(Q,p->lchild);
		if(p->rchild!=NULL)
			EnQueue(Q,p->rchild);
	}
}
//������C��ѧӪ���γ�
//�������Ľ�������ν�������ǰ�����򡢺������������ǵݹ��������α���
int main()
{
	BiTree pnew;
	int i,j,pos;
	char c;
	BiTree tree=NULL;//����
	ptag_t phead=NULL,ptail=NULL,listpnew,pcur;//phead���Ƕ���ͷ��ptail���Ƕ���β
	//abcdefghij
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')
		{
			break;
		}
		pnew=(BiTree)calloc(1,sizeof(BiTNode));//calloc����ռ䲢�Կռ���г�ʼ������ֵΪ0
		pnew->c=c;//���ݷŽ�ȥ
		listpnew=(ptag_t)calloc(1,sizeof(tag_t));//�����н������ռ�
		listpnew->p=pnew;
		if(NULL==tree)
		{
			tree=pnew;//���ĸ�
			phead=listpnew;//����ͷ
			ptail=listpnew;//����β
			pcur=listpnew;
			continue;
		}else{
			ptail->pnext=listpnew;//�½�����������ͨ��β�巨
			ptail=listpnew;//ptailָ�����β��
		}//pcurʼ��ָ��Ҫ����Ľ���λ��
		if(NULL==pcur->p->lchild)//��ΰ��½�������
		{
			pcur->p->lchild=pnew;//���½��ŵ�Ҫ����������
		}else if(NULL==pcur->p->rchild)
		{
			pcur->p->rchild=pnew;//���½��ŵ�Ҫ��������ұ�
			pcur=pcur->pnext;//���Ҷ����˽���pcurָ����е���һ��
		}
	}
	printf("--------ǰ�����----------\n");
	preOrder(tree);
	printf("\n--------�������------------\n");
	InOrder(tree);
	printf("\n--------�������------------\n");
	PostOrder(tree);
	printf("\n--------��������ǵݹ�------\n");//��Ҫ�Ե�
	InOrder2(tree); 
	printf("\n--------��α���-----------\n");
	LevelOrder(tree);
	printf("\n");
} 