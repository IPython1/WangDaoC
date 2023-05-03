#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
/**
 * 栈：先进后出 元素入栈&&元素出栈
 * 元素入栈：
 * S.top=-1;//栈为空
 * S.data[++S.top]=0;
 * 元素出栈：
 * x=S.data[S.top--];
 * 
 * 
 * 
*/
typedef struct 
{
    ElemType data[50];//数组
    int top;//始终指向栈顶的一个变量
}SqStack;
void InitStack(SqStack &S){
    S.top=-1;//初始化栈：使栈为空
}
bool StackEmpty(SqStack S){
    if ((S.top==-1))
    {
        return true;
    }
    return false;
     
}
//连续入栈
void PushStack(SqStack &S,ElemType x){
    //判断栈满
    while (S.top<1)//<1时可以读入2个数
    {   
        scanf("%d",&x);
        S.top=S.top+1;
        S.data[S.top]=x;
    }
    
}
//单个入栈
bool Push(SqStack &S,ElemType x){
    //判断栈满
    if (S.top==MaxSize-1)
    {
        printf("此时栈满");
        return false;
    }
    S.top=S.top+1;
    S.data[S.top]=x;
    return true;
}
//获取栈顶元素
bool GetTop(SqStack S,ElemType &m){
    if (StackEmpty(S))
    {
        return false;
    }
    m=S.data[S.top];
    return true;
}
//出栈
bool Pop(SqStack &S,ElemType &m){
    if (StackEmpty(S))
    {
        return false;
    }
    m=S.data[S.top--];//出栈 先m=S.data[S.top],后S.top=S.top--
    return true;
}
void print_all(SqStack S){
    // 从栈底到栈顶 输出
    int i;
    for (int i = 0; i <=S.top; i++)
    {
        printf("%2d",S.data[i]);
    }
    printf("\n");
    
}
int main()
{   
    SqStack S;
    InitStack(S);
    bool flag;
    
    ElemType x;
    
    Push(S,3);
    Push(S,4);
    Push(S,5);
    print_all(S);
    ElemType m;
    flag=GetTop(S,m);//获取栈顶元素 需要给m赋值所以需要加引用
    if (flag==true)
    {
        printf("get top%d\n",m);
    }
    flag=Pop(S,m);//弹出栈顶元素
    if (flag==true)
    {
        printf("pop element%d\n",m);
    }
    system("pause");
    return 0;
}
