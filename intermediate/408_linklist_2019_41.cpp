#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
/**
 * 分为两个链表  后一半链表逆置后进行重新组合
 * 
 * 
*/
typedef struct LNode //单链表结点类型
{
    ElemType data;       //数据域
    struct LNode *next;  //指针域  结构体类型指针 在内部不能省略结构体名
}LNode,*LinkList;
void list_tail_insert(LinkList &L){
   L=(LinkList)malloc(sizeof(LNode));
   LNode *r=L;
   ElemType x;
   scanf("%d",&x);
   LinkList s;
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
//找到链表中间结点，并设置好L2链表
void find_middle(LinkList L,LinkList &L2){
   L2=(LinkList)malloc(sizeof(LNode));//第二条链表的头结点
   LinkList pcur,ppre;//双指针法(考研初试常考)
   //ppre去指向中间结点（寻找）
   pcur=ppre=L->next;//双指针均指向了第一个结点
   while (pcur)
   {
      pcur=pcur->next;
      if(pcur==NULL){
         break;
      }
      pcur=pcur->next;
      if(pcur==NULL){//为了偶数个时，ppre依然指向中间结点的前一个结点
         break;
      }
      ppre=ppre->next;
   }
   L2->next=ppre->next;//由L2头结点指向后面一半链表
   ppre->next=NULL;//前一半链表的最后一个结点，next要为NULL

}
//对L2链表进行逆置
void reverse(LinkList L2){//仅逆转一半链表 2分之N次，
   LinkList r,s,t;
   r=L2->next;
   if (r==NULL)
   {
      return ;//链表为空
   }
   s=r->next;
   if (s==NULL)
   {
      return ;//链表只有一个结点 直接返回
   }
   t=s->next;
   while (t!=NULL)
   {
      s->next=r;//原地逆置
      r=s;//以下3句是三个指针同时往下走一步 r,s进行交替互相指向
      s=t;
      t=t->next; 
   }
   s->next=r;
   L2->next->next=NULL;//逆置后的链表尾部结点的next为NULL
   L2->next=s;//s为新的逆置后链表的第一个结点
}
void merge(LinkList L,LinkList L2){
   LinkList pcur,p,q;
   pcur=L->next;//pcur始终指向新链表的链表尾
   p=pcur->next;//P用来遍历L1链表
   q=L2->next;//q指向L2的第一个结点 q用来遍历L2链表
   while (p!=NULL&&q!=NULL)//相对于最初链表遍历的长度只是一半 就是2分之N次，所以时间复杂度为O(n)
   {
      pcur->next=q;
      q=q->next;//指向下一个

      pcur=pcur->next;
      pcur->next=p;
      p=p->next;//指向下一个
      pcur=pcur->next;
   }
   //多余结点放置末尾
   if(p!=NULL){
      pcur->next=p;
   }
   if(q!=NULL){
      pcur->next=q;
   }
   
}
void print_all(LinkList L){
   L=L->next;
   while (L!=NULL)
   {
      printf("%3d",L->data);
      L=L->next;
   }
   printf("\n");
}
//分析代码的时间复杂度
/**
 * 
 * 
 * 
 * 
*/
int main()
{
   LinkList L;//链表头是结构体指针类型
   list_tail_insert(L);
   print_all(L);
   printf("--------------\n");
   //寻找中间节点并返回第二条链表
   LinkList L2=NULL;
   find_middle(L,L2);//只有一个结点时，L2中是没有结点的
   print_all(L);
   print_all(L2);
   printf("--------------\n");
   reverse(L2);
   print_all(L2);
   printf("--------------\n");
   //merge(L,L2)12.5-真题代码实战 33分50秒描述是否加引用
   merge(L,L2);
   free(L2);
   print_all(L);
   system("pause");
   return 0;
}
