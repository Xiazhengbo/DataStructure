#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList LinkList_HeadInsert(LinkList &L);
LinkList LinkList_TailInsert(LinkList &L);
LNode *GetElem(LinkList L, int i);
LNode *LocateElem(LinkList L, ElemType e);
bool ListInsert(LinkList L, int i);
bool DelList(LinkList L, int i);
int SizeofList(LinkList L);
void PrintList(LinkList L);

int main(){
    LinkList L;
    LinkList_HeadInsert(L);
    PrintList(L);
    return 0;
}

//采用头插法建立单链表
LinkList LinkList_HeadInsert(LinkList &L){      //逆向建立单链表
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));        //创建头结点
    L->next = NULL;                             //初始化空链表
    scanf("%d", &x);                            //输入结点的值
    while (x!=9999){                           //输入9999表示结束
        s = (LNode *)malloc(sizeof(LNode));     //创建新结点，LNode*等价于LinkList
        s->data = x;
        s->next = L->next;
        L->next = s;                            //将新结点插入表中，L为头指针
        scanf("%d", &x);
    }
    return L;
}

//尾插法建立单链表
LinkList LinkList_TailInsert(LinkList &L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s;
    LNode *r = L;
    scanf("%d", &x);
    while (x!=9999){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;              //r指向新的表尾结点
        scanf("%d", &x);
    }
    r->next = NULL;         //尾结点的next指针赋为NULL
    return L;
}

//按序号查找结点值
LNode *GetElem(LinkList L, int i){
    int j = 1;                      //计数，初始化为1
    LNode *p = L->next;             //第一个结点指针赋给p
    if (i == 0){
        return L;                   //若i等于0，则返回头结点
    }
    if (i < 1){
        return NULL;                //若i无效，则返回NULL
    }
    while (p && j < i){             //从第一个结点开始找，查找第i个结点
        p = p->next;
        j++;
    }
    return p;                       //返回第i个结点的指针，若i大于表长，则返回NULL
}

//按值查找表结点
LNode *LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    while( p != NULL && p->data != e){          //从第一个结点开始查找data域为e的结点
        p = p->next;
    }
    return p;                                   //找到后返回该结点指针，否则返回NULL
}

//插入结点
bool ListInsert(LinkList L, int i, ElemType e){
    LinkList p;
    p = GetElem(L, i - 1);                  //查找插入位置的前驱结点
    if(p == NULL){
        return false;
    }
    LinkList s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;                      
    p->next = s;
    return true;
}

//删除结点
bool DelList(LinkList L, int i){          
    LinkList p = GetElem(L, i - 1);         //查找删除位置的前驱结点
    if (p == NULL){
        return false;
    }
    LinkList q;
    q = p->next;                            //令q指向被删除结点
    p->next = q->next;                      //将*q结点从链中“断开”
    free(q);                                //释放结点的存储空间
    return true;
}

    //求表长
int SizeofList(LinkList L){
        int len = 0;
        LNode *p;
        p = L->next;
        while (p != NULL)
        {
            len++;
            p = p->next;
        }
        return len;
}

//输出链表
void PrintList(LinkList L){
    L = L->next;
    while(L != NULL){
        printf("%4d", L->data);
        L = L->next;
    }
    printf("\n");
}