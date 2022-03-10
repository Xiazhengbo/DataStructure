#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior;//前驱
    struct DNode *next;//后继
}DNode,*DLinkList;

DLinkList Dlist_head_insert(DLinkList &DL);
DLinkList Dlist_tail_insert(DLinkList &DL);
DNode *GetElem(DLinkList DL, int i);
bool DListFrontInsert(DLinkList DL, int i, ElemType e);
bool DListDelete(DLinkList DL, int i);
void PrintDList(DLinkList DL);

int main(){

    return 0;
}

//头插法
DLinkList Dlist_head_insert(DLinkList &DL){
    DNode *s;
    int x;
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->next = NULL;
    DL->prior = NULL;
    scanf("%d", &x);
    //从标准输入读取数据
    while(x!= 9999){
    //当输入9999时停止
        s = (DLinkList)malloc(sizeof(DNode));
        //申请一个空间，强制类型转换为DNode
        s->data = x;
        s->next = DL->next;
        if(DL->next != NULL){
            DL->next->prior = s;
        }
        s->prior = DL;
        DL->next = s;
        scanf("%d", &x);
    }
    return DL;
}

//尾插法
DLinkList Dlist_tail_insert(DLinkList &DL){
    int x;
    DL = (DLinkList)malloc(sizeof(DNode));
    DNode *s;
    DNode *r;
    r = DL;
    DL->prior = NULL;
    scanf("%d", &x);
    while(x != 9999){
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        r->next = s;
        s->prior = r;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    //尾结点的next指针赋值为NULL
    return DL;
}

//按序号查找
DNode *GetElem(DLinkList DL, int i){
    int j = 1;
    DNode *p = DL->next;
    if(i == 0){
        return DL;
    }
    if(j < 1){
        return NULL;
    }
    while (p&&j<1){
        p = p->next;
        j++;
    }
    return p;
}

//插入第i个位置
bool DListFrontInsert(DLinkList DL, int i, ElemType e){
    DLinkList p = GetElem(DL, i - 1);
    if(NULL == p){
        return false;
    }
    DLinkList s = (DLinkList)malloc(sizeof(DNode));
    //为新插入的结点申请空间
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//删除第i个位置
bool DListDelete(DLinkList DL, int i){
    DLinkList p = GetElem(DL, i - 1);
    if(p == NULL){
        return false;
    }
    DLinkList q;
    q = p->next;
    if(q == NULL){
        q->next->prior = p;
    }
    free(q);
    //释放删除结点的空间
    return true;
}

//链表打印
void PrintDList(DLinkList DL){
    DL = DL->next;
    while(DL != NULL){
        printf("%4d", DL->data);
        DL = DL->next;
    }
    printf("\n");
}