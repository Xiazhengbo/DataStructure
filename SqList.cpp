#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct sqlist{
    ElemType data[MAXSIZE];
    int length;
}sqlist;

void print_sqlist(sqlist L);
bool create_sqlist(sqlist &L, int n);
bool insert_sqlist(sqlist &L, int pos, ElemType e);
bool del_sqlist(sqlist &L, int pos, ElemType &e);
int locate_sqlist(sqlist L, ElemType e);

int main(){
    sqlist L;
    
    return 0;
}

/*输出线性表*/
void print_sqlist(sqlist L){
    for (int i = 0; i < L.length; i++){
        printf("%d", L.data[i]);
    }
    printf("\n");
}

/*赋初值*/
bool create_sqlist(sqlist &L, int n){       //初始化线性表
    for (int i = 0; i < n; i++){
        scanf("%d", &L.data[i]);
        L.length = n;
    }
}

/*插入操作*/
bool insert_sqlist(sqlist &L, int pos, ElemType e){
    if (pos < 1 || pos > L.length + 1){          //是否在范围内
        return false;
    }
    if (L.length == MAXSIZE){                   //数组是否已满
        return false;
    }
    for (int j = L.length; j >= pos; j--){     //将第POS个元素及以后的元素后移
        L.data[j] = L.data[j - 1];
    }
    L.data[pos - 1] = e;                    //在位置pos处放入e
    L.length++;                                //线性表长度加1
    return true;
}

/*删除线性表中元素*/
bool del_sqlist(sqlist &L, int pos, ElemType &e){
    if (pos < 1 || pos > L.length){            //判断pos的位置是否有效
        return false;   
    }
    e = L.data[pos - 1];                    //将被删除的元素赋给e
    for (int j = pos; j < L.length-1; j++){    //将第pos个位置后元素前移
        L.data[j - 1] = L.data[j];
    }
    L.length--;                                //线性表长度减1
    return true;
}

/*按值查找(顺序查找)*/
int locate_sqlist(sqlist L, ElemType e){
    int i;
    for ( i = 0; i < L.length; i++){
        if(L.data[i] == e){
            return i + 1;
        }
    }
    return 0;
}