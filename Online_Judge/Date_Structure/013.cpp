#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];//数组
    int top;
}SqStack;
//栈初始化
void InitStack(SqStack& S)
{
    S.top = -1;//代表栈为空
}
 
//入栈
bool Push(SqStack& S, ElemType x)
{
    if (S.top == MaxSize - 1)//数组的大小不能改变，避免访问越界
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}
//出栈
bool Pop(SqStack& S, ElemType& x)
{
    if (-1 == S.top)
        return false;
    x = S.data[S.top--];
    printf(" %d", x);
    return true;
}
//队列
typedef struct {
    ElemType data[5];//数组，存放MaxSize-1个元素
    int front, rear;//队列头，队列尾
}SqQueue;
//队列初始化
void InitQueue(SqQueue& Q)//初始化队列
{
    Q.rear = Q.front = 0;
}
//入队
bool EnQueue(SqQueue& Q, ElemType x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)//判断是否队满
        return false;
    Q.data[Q.rear] = x;//3 4 5 6 7
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
//出队
bool DeQueue(SqQueue& Q, ElemType& x)
{
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];//先进先出
    Q.front = (Q.front + 1) % MaxSize;
    printf(" %d", x);
    return true;
}
int main()
{
    SqStack S;//后进先出LIFO
    ElemType m;//用来存放拿出的元素
    InitStack(S);//初始化
    ElemType a, b, c;
    scanf("%d %d %d\n", &a, &b, &c);
    Push(S, a);
    Push(S, b);
    Push(S, c);
    SqQueue Q;
    ElemType element;//存储出队元素
    InitQueue(Q);//初始化队列
    //入队
    int n = 1;
    int n1;
    while (n < 5)
    {
        scanf("%d", &n1);
        EnQueue(Q, n1);
        n = n + 1;
    }
    Pop(S, m);
    Pop(S, m);
    Pop(S, m);
    printf("\n");
    if (n > 4)printf("false\n");
    for(int i=1;i<n;i++)
    {
        DeQueue(Q, element);
    }
    system("pause");
    return 0;
 
}