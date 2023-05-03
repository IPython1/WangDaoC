#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define MaxSize 50
typedef int ElemType;
typedef struct LNode //单链表结点类型
{
    ElemType data;       //数据域
    struct LNode *next;  //指针域  结构体类型指针 在内部不能省略结构体名
}LNode,*LinkList;
//LNode*是结构体指针，与LinkList完全等价的
//输入3，4，5，6，7，9999
//头插法新建链表
void list_head_insert(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));//申请头节点空间，头指针指向头节点
    L->next=NULL;
    ElemType x;

    scanf("%d",&x);
    LNode *s;//用来指向申请的新结点
    while (x!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;//s.next指向链表的第一个结点
        L->next=s;//头结点的next指向新结点 =左右两边均为指针变量
        scanf("%d",&x);
    }

}
//尾插法 新建链表
void list_tail_insert(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));//申请头节点空间，头指针指向头节点
    LNode* r=L;//定义伪指针 始终指向链表尾部
    L->next=NULL;
    
    ElemType x;
    scanf("%d",&x);
    LNode *s;//用来指向申请的新结点
    while (x!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));//插入结点
        s->data=x; 
        r->next=s;//新结点 给 尾结点的next指针
        r=s;//r指向新的尾部
        scanf("%d",&x);
    }
    r->next=NULL;//让尾结点的next为NULL
}
//按位置查找与按值查找 即遍历链表 查找值
LinkList GetElem(LinkList L,ElemType SearchPos){
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
//按值查询
LinkList LocateElem(LinkList L,ElemType SearchValue){
    while (L!=NULL)
    {
        if (L->data==SearchValue)//如果找到对应的值，就返回那个结点的地址
        {
            return L;
        }else{
            L=L->next;
        }  
    }
    return NULL;
}
//向第i个位置插入元素
bool ListFrontInsert(LinkList L,ElemType i,ElemType  InsertVal){
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
void print_list(LinkList L){
    L=L->next;
    while (L!=NULL)
    {
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
    
}

int main()
{   
   LinkList L;//L是链表头指针，是结构体指针类型
   LinkList search;//用来存储拿到的某一个结点
   list_head_insert(L);
   print_list(L);
   list_tail_insert(L);
   print_list(L);//链表打印


//    search=GetElem(L,2);//将L赋值给search 按位置查找
//    if (search!=NULL)
//    {
//     printf("Succeed in searching by serial number\n");
//     printf("%d\n",search->data);
//    }

//    search=LocateElem(L,6);//将L赋值给search 按值查找
//    if (search!=NULL)
//    {
//     printf("Succeed in searching by value number\n");
//     printf("%d\n",search->data);
//    }else{
//     printf("未找到所查询值");
//    }
    // bool ret;
    // ret=ListFrontInsert(L,10,99);
    // print_list(L);
    system("pause");
    return 0;
}
