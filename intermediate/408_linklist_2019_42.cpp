#include <stdio.h>
#include <stdlib.h>
/**
 * 循环队列（采用链式存储实现）
 * 
 * 
*/
#define MaxSize 50
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode*next;
}LNode,*LinkList;
typedef struct 
{
    LNode *front,*rear;//链表头，链表尾，也可以称为队头/队尾

}LinkQueue;//先进先出

//队列的初始化，使用的是带头结点的链表实现的
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkList)malloc(sizeof(LNode));
    Q.front->next=NULL;
}
//入队
void EnQueue(LinkList front,LinkList &rear,ElemType val){
    LinkList pnew;
    if(rear->next == front){//判断队列是不是满了
        //队列满，申请一个结点的空问，放入队列
        pnew= (LinkList)malloc(sizeof(LNode));
        rear->data = val;//把入队元素放入rear指向结点
        rear->next = pnew;//放了一个结点,其相当于做了分割
        pnew->next = front;
        rear = pnew;
    }else{//如果队列不满直接放值，让rear后移一个结点
        rear->data=val;
        rear=rear->next;
    }
}
//出队 头部删除法
void DeQueue(LinkList &front,LinkList rear){//需要拿原链表中element  所以x加引用
    if (rear==front)
    {   
        printf("队列为空\n");
    }else{
        printf("出队的值为%d\n",front->data);
        front=front->next;
    }
}
//循环队列操作的总流程
void CircleQueue(LinkList& front,LinkList& rear){
    //队列头和队列尾都指向一个结点，这时队列既是空的也是满的
    front=(LinkList)malloc(sizeof(LNode));
    rear=front;
    rear->next=front;//构造循环队列
    //入队
    EnQueue(front,rear,3);
    EnQueue(front,rear,4);
    //出队
    DeQueue(front,rear);
    DeQueue(front,rear);
    DeQueue(front,rear);
}
int main()
{
   LinkList front,rear;
   CircleQueue(front,rear);
   system("pause");
   return 0;
}
