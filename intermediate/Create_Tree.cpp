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
/**
 * 树：主要是二叉树，二叉树的链式存储
 * 
 * 
 * 
*/
//二叉树的实战
//abcdefghij
//前序遍历 就是深度优先遍历
void PreOrder(BiTree p){
    if (p!=NULL)
    {
        printf("%c",p->c);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}
//中序遍历
void InOrder(BiTree p){
    if (p!=NULL)
    {
        InOrder(p->lchild);
        printf("%c",p->c);
        InOrder(p->rchild);
    }
}
//后序遍历
void PostOrder(BiTree p){
    if (p!=NULL)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%c",p->c);
    }
}
//层次（序）遍历 即广度优先遍历

//二叉树的建树（层次建树）
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
   PreOrder(tree);
   printf("\n");
   InOrder(tree);
   printf("\n");
   PostOrder(tree);
   printf("\n");
   system("pause");
   return 0;
}
