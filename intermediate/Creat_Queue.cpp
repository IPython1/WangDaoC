#include <stdio.h>
#include <stdlib.h>
/***
 * 队列  只允许从表的一端进行插入 而在表的另一端进行删除
 * 入队/进队
 * 删除元素称为出队/离队
 * FIFO
 * Front队头允许删除的一端
 * Rear队尾允许插入的一端
 * 
 * 牺牲一个存储单元
 * (Q.rear+1)%MaxSize==Q.front;//判断队列满的方法
 * 增（入队）
 * 删（出队）
*/

/**队列的链式表示称为链队列
 * 实际上是一个同时 带有 队头指针 和 队尾指针 的单链表
 * 头指针指向队头结点，尾指针指向队尾结点。即单链表的最后一个结点
 *
 * 
*/
#define MaxSize 6
typedef int ElemType;
//循环队列代码实战
typedef struct 
{
    ElemType data[MaxSize];//数组 存储MAXSIZE-1个元素
    int front,rear;//队列头，队列尾
}SqQueue;
//初始化循环队列
void InitQueue(SqQueue &Q){//会改变Q 所以加引用
    Q.front=Q.rear;//初始化循环队列，就是让头和尾都指向0号元素
}
//判断循环队列是否为空
bool isEmpty(SqQueue Q){
    return Q.rear==Q.front;
}
bool EnQueue(SqQueue &Q,ElemType x){
    if ((Q.rear+1)%MaxSize==Q.front)//判断循环队列是否满，满了不能入队
    {
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;//rear+1，如果大于了数组最大下标，回到开头
    
}
//出队
bool DeQueue(SqQueue &Q,ElemType &x){
    if (Q.rear==Q.front)//队列为空无法出队
    {
        return false;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    
}
int main()
{
   SqQueue Q;
   bool ret;
   ret=isEmpty(Q);
   if (ret)
   {
    printf("Squeue is Empty");
   }
   EnQueue(Q,5);
   EnQueue(Q,5);
   EnQueue(Q,6);
   ret=EnQueue(Q,7);
   if (ret)
   {
    printf("Enqueue success！");
   }else{
    printf("Enqueue failed！");
   }
   ElemType element;//存储出队元素
   ret=DeQueue(Q,element);
   if (ret)
   {
        printf("DEqueue success！");
   }else{
        printf("DEqueue failed！");
   }
   system("pause");
   return 0;
}
