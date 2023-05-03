#include <stdio.h>
#include <stdlib.h>
/** 
    考研考的一切数据结构：增删查（改）crud
    单链表：逻辑上相邻的两个元素在物理位置上不相邻
    头指针:链表中第一个结点的 存储位置，用来标识单链表
    头结点:在单链表第一个节点之前附加的 一个结点，为了操作上的方便
**/
#define MaxSize 50 //定义线性表的长度
typedef int ElemType;//让顺序表存储其他元素类型时，可以快速完成代码修改

using namespace std;
typedef struct LNode //单链表结点类型
{
    ElemType data;       //数据域
    struct LNode *next;  //指针域  结构体类型指针 在内部不能省略结构体名
}LNode,*LinkList;
//表头中间插入操作
/**
q=(LNode*)malloc(sizeof(LNode));
q->next=p->next;
p->next=q;
**/
//尾部插入元素
/**
 * p->next=q
 * p->next=NULL
 * 
*/
//删除操作 断链（表头中间表尾 相同操作方法）

//查找操作 按序号查找结点值的算法
/**
 * 
 * LNode *p=L->next;
 * int j=1;
 * while(p&&j<i){
 *      p=p->next;
 *      j++;
 *  }
 * return p;
 * 
*/
/**按值查找结点的算法
 *LNode *p=L->next;
 * while(p！=NULL&&p->data!=e){
 *      p=p->next;
 *  }
 * return p;
*/

int main()
{
   
   system("pause");
   return 0;
}
