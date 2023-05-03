#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
//打印链表中每个结点的值
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
//头插入
void list_head_insert(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));//申请头节点空间，头指针指向头节点
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LNode   *s;
    while (x!=9999)
    {   
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    
}
//尾插入
void list_tail_insert(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));//申请头节点空间，头指针指向头节点
    LinkList r=L;
    L->next=NULL;
    
    
    ElemType x;
    scanf("%d",&x);
    LNode *s;
    while (x!=9999)
    {   
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    
}
void PrintList(LinkList L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%d",L->data);//打印当前结点数据
        L=L->next;//指向下一个结点
        if(L!=NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}


int main()
{   
    LinkList L;
    list_head_insert(L);
    PrintList(L);
    list_tail_insert(L);
    PrintList(L);
    system("pause");
    return 0;
}
