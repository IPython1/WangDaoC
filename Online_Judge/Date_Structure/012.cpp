#include <stdio.h>
#include <stdlib.h>


#define MaxSize 50
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
void list_tail_insert(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
    ElemType x;
    LinkList r=L;
    L->next=NULL;
    scanf("%d",&x);
    LNode  *s;

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
//查找某个位置的值（按位置查找）
LinkList GetElem(LinkList L,int SearchPos){
    int j=0;
    if (SearchPos<0)
    {
        return NULL;
    }
    while (L!=NULL&&j<SearchPos)
    {
        L=L->next;
        j++;
    }
    return L;
}

//向某个位置插入元素
bool insert_something_pos(LinkList L,ElemType i,ElemType  InsertVal){
    LinkList p=GetElem(L,i-1);
    if(p==NULL){
        return false;
    }
    LinkList q;
    q=(LinkList)malloc(sizeof(MaxSize));
    q->data=InsertVal;
    //插入任何一个位置 均适用
    q->next=p->next;
    p->next=q;
    return true;
}

//删除某个位置的元素 i-1指向i+1
bool delete_something_pos(LinkList L,ElemType i){
    LinkList p=GetElem(L,i-1);
    LinkList q=GetElem(L,i);
    // if (p==NULL)
    // {
    //     return false;
    // }
    // LinkList q=p->next;
    p->next=q->next;//断链操作
    free(q);//释放被删除结点的空间
    return true;
}

void PrintList(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}
int main()
{   LinkList L;
    list_tail_insert(L);
    bool ret;
    LinkList res;
    res=GetElem(L,2);
    printf("%d\n",res->data);
    ret=insert_something_pos(L,2,99);
    if(ret!=true){
        printf("failed insert something_pos");
    }else{
        PrintList(L);
    }
    delete_something_pos(L,4);
    PrintList(L);
    system("pause");
    return 0;
}
