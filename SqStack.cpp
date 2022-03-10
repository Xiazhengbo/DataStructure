#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct SqStack{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S);//构造空栈S
bool StackEmpty(SqStack &S);//判断是否为空栈
bool Push(SqStack &S, ElemType x);//入栈，插入元素x作为新的栈顶元素
bool Pop(SqStack &S,ElemType &x);//出栈，删除栈顶元素，并返回其值
bool GetTop(SqStack &s,ElemType &x);//读取栈顶元素

int main(){
    
	SqStack S;//先进后出 FILO  LIFO
	bool flag;
	ElemType m;//用来存放拿出的元素
	InitStack(S);//初始化
	flag=StackEmpty(S);
	if(flag){
		printf("栈是空的\n");
	}
	Push(S,3);//入栈元素3
	Push(S,4);//入栈元素4
	Push(S,5);
	flag=GetTop(S,m);//获取栈顶元素
	if(flag){
		printf("获取栈顶元素为 %d\n",m);
	}
	flag=Pop(S,m);//弹出栈顶元素
	if(flag){
		printf("弹出元素为 %d\n",m);
	}
    return 0;
}

//构造空栈S
void InitStack(SqStack &S){
    S.top = -1;//代表栈为空
}

//判断是否为空栈
bool StackEmpty(SqStack &S){
    if(S.top == -1){
        return true;
    }else{
        return false;
    }
}

//入栈
bool Push(SqStack &S, ElemType x){
    if (S.top == MaxSize - 1){//数组大小不可变，判断是否满栈，避免访问越界
        return false;
    }
    S.data[++S.top] = x;
    /*
    S.top = S.top + 1;
    S.data[S.top] = x;
    */
    return true;
}

//出栈
bool Pop(SqStack &S,ElemType &x){
    if(S.top == -1){
        return false;
    }
    x = S.data[S.top--];
    /*
    x = S.data[S.top];
    S.top = S.top - 1;
    */
    return true;
}

//读取栈顶元素
bool GetTop(SqStack &S,ElemType &x){
    if(-1 == S.top){
        return false;
    }
    x = S.data[S.top];
    return true;
}