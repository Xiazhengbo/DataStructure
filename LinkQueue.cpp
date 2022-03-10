#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{
	LinkNode *front;//链表头
	LinkNode *rear;//链表尾
}LinkQueue;//先进先出 FILO

void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q, ElemType);
bool DeQueue(LinkQueue &Q, ElemType &x);

int main(){
	LinkQueue Q;
	bool ret;
	ElemType element;//存储出队元素
	InitQueue(Q);//初始化队列
	EnQueue(Q,3);
	EnQueue(Q,4);
	EnQueue(Q,5);
	EnQueue(Q,6);
	EnQueue(Q,7);
	ret=DeQueue(Q,element);
	if(ret){
		printf("出队成功,元素值为 %d\n",element);
	}else{
		printf("出队失败\n");
	}
}

//初始化空链表
void InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));//头和尾指向同一个结点
	Q.front->next=NULL;//头结点的next指针为NULL	
}

//判断是否为空
bool IsEmpty(LinkQueue Q){
	if(Q.front == Q.rear){
		return true;
	}else{
		return false;
	}
}

//入队，尾插
void EnQueue(LinkQueue &Q, ElemType x){
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;//rear指向尾部
	Q.rear = s;
}

//出队，头部
bool DeQueue(LinkQueue &Q, ElemType &x){
	if(Q.front==Q.rear){
		return false;//队列为空
	}
	LinkNode *p = Q.front->next; //头结点什么都没存，所以头结点的下一个节点才有数据
	x = p->data;
	Q.front->next = p->next; //断链
	if(Q.rear == p){//删除的是最后一个元素
		Q.rear = Q.front;//队列置为空
	}
	free(p);
	return true;
}