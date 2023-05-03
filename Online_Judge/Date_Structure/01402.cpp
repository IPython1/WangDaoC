#include <stdio.h>
#include <stdlib.h>
typedef char BiElemType;
typedef struct BiTNode {
    BiElemType c;//c就是书籍上的data
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;
//tag结构体是辅助队列使用的
typedef struct tag
{
    BiTree p;//树的某一个结点的地址值
    struct tag *pnext;

}tag_t,*ptag_t;
void InOrder(BiTree p){
    if (p!=NULL)
    {
        
        InOrder(p->lchild);
        printf("%c",p->c);
        InOrder(p->rchild);
    }
}
void afterOrder(BiTree p){
    if (p!=NULL)
    {
        
        afterOrder(p->lchild);
        afterOrder(p->rchild);
        printf("%c",p->c);
    }
}

//队列的结构体
typedef BiTree ElemType;
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode*next;
}LinkNode;
typedef struct
{
    LinkNode *front,*rear;//链表头，链表尾，也可以称为队头/队尾

}LinkQueue;//先进先出
//队列的初始化，使用的是带头结点的链表实现的
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}
//判断队列是否为空 普通队列不是循环队列
bool isEmpty(LinkQueue  Q){
    return Q.rear==Q.front;
}
//入队
void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *pnew=(LinkNode*)malloc(sizeof(LinkNode));
    pnew->data=x;
    pnew->next=NULL;//要让next为null
    Q.rear->next=pnew;//Q为结构体 用 .,尾指针的next指向pnew，因为从尾部入队
    Q.rear=pnew;//rear要指向新的尾部

}
//出队 头部删除法
bool DeQueue(LinkQueue &Q,ElemType &x){//需要拿原链表中element  所以x加引用
    if (Q.rear==Q.front)
    {
        return false;//队列为空
    }
    LinkNode* q=Q.front->next;//拿到第一个结点 存入q
    x=q->data;//获取要出队的元素值
    Q.front->next=q->next;//让第一个结点断链
    if (Q.rear==q)//链表只剩一个结点时，删除后，要改变rear
    {
        Q.rear=Q.front;//队列置为空
    }
    free(q);
    return true;

}
//层序遍历
void levelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;//存储出队的结点
    EnQueue(Q,T);//树根入队
    while (!isEmpty(Q))
    {
        DeQueue(Q,p);
        putchar(p->c);
        if (p->lchild!=NULL)
        {
            EnQueue(Q,p->lchild);
        }
        if (p->rchild!=NULL)
        {
            EnQueue(Q,p->rchild);
        }
        
    }
    

}
int main()
{   
   BiTree pnew;//用来指向新申请的树结点
   
   BiTree tree=NULL;//tree是指向树根的，代表树
   char c;//abcdefghijk
   //phead就是队列头，ptail就是队列尾
   ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur=NULL;
   while (scanf("%c",&c))
   {
        if (c=='\n')
        {
            break;//读到换行就结束
        }
        //calloc 申请的空间大小是两个参数直接相乘，并对空间进行初始化，赋值为0
        pnew=(BiTree)calloc(1,sizeof(BiTNode));
        pnew->c=c;

        listpnew=(ptag_t)calloc(1,sizeof(tag_t));//给队列结点申请空间
        listpnew->p=pnew;
        //如果是树的第一个结点
        if (NULL==tree)
        {
            tree=pnew;//tree指向树的根节点
            phead=listpnew;//第一个结点既是队列头，也是队列尾
            ptail=listpnew;
            pcur=listpnew;//pcur要指向要进入树的父亲元素
        }else{
            //让元素先进入队列
            ptail->pnext=listpnew;
            ptail=listpnew;
            //接下来把b结点放入树中
            if(pcur->p->lchild==NULL){
                pcur->p->lchild=pnew;//pcur->p左孩子为空，就放入左孩子
            }else if (pcur->p->rchild==NULL)
            {
                pcur->p->rchild=pnew;//pcur->p右孩子为空，就放入右孩子
                pcur=pcur->pnext;//当前父亲结点左右孩子都有了，pcur就指向下一个结点
            }  
        }
   }
   InOrder(tree);
   printf("\n");
   afterOrder(tree);
   printf("\n");
   levelOrder(tree);
   printf("\n");
   system("pause");
   return 0;
}