#include <stdio.h>
#include <stdlib.h>
/**
 * 二叉排序树（也称二叉查找树）或者是一棵空树
 * 或者是具有下列特性的二叉树:
 * 1）若左子树非空，则左子树上所有结点的值均小于根结点的值。
 * 2）若右子树非空，则右子树上所有结点的值均人于根结点的值。
 * 3）左、右子树也分别是一棵二叉排序树。
*/
typedef int ElemType;
typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode *lchild, *rchild;
}BSTpode,*BiTree;
//二叉排序树新建，中序遍历，查找
//非递归的创建二叉查找树 树中不放相等元素
int BST_Insert(BiTree& T,KeyType k){
    BiTree TreeNew= (BiTree)calloc( 1,sizeof(BSTNode));//新结点申请空间
    TreeNew->key=k;//把值放入
    if(NULL==T)//树为空，新结点作为树的根
    {
        T=TreeNew ;
        return 0;
    }
    BiTree p=T,parent;//p用来查找树
    while(p){
        parent=p;//parent用来存P的父亲
        if(k>p->key){
            p=p->rchild;
        }else if(k<p->key){
            p=p->lchild;
        }else{
            return -1;//相等的元素不会放入查找树，考研不考相等元素放入问题
        }
    }
    //接下来判断放到父亲的左边还是右边
    if(k>parent->key)//放到父亲左边
    {
    parent->rchild=TreeNew;
    }else{//放到父亲左边
    parent->lchild=TreeNew;
    }
    return 0;
}    
void Create_BST(BiTree& T,KeyType* str,int len){
    int i;
    for ( i = 0; i < len; i++)
    {
        BST_Insert(T,str[i]);
    }
    
}
//二叉排序树的查找
//也可以用递归实现，只不过循环查找已经简单清晰，用递归必要性不强
BiTree BST_Search(BiTree T,KeyType k,BiTree &parent){
    parent=NULL;//避免空树 parent无法进入循环
    while (T!=NULL&&k!=T->key)
    {
        parent=T;
        if (k>T->key)
        {
            T=T->rchild;
        }else
        {
            T=T->lchild;
        }
    }
    return T;
    
}
void InOrder(BiTree T){
    if (T!=NULL)
    {
        InOrder(T->lchild);
        printf("%d ",T->key);
        InOrder(T->rchild);
    }
}

//二叉排序树的删除
void DeleteNode(BiTree &root,KeyType x){
    if (root==NULL)
    {
        return;
    }
    if (root->key>x)//当前结点大于删除的结点，往左子树找
    {
        DeleteNode(root->lchild,x);
    }else if (root->key<x)
    {
        DeleteNode(root->rchild,x);
    }else//找到了删除的结点
    {
        if (root->lchild==NULL)//左子树为空，右子树直接顶上去
        {
            BiTree tempNode =root;
            root=root->rchild;
            free(tempNode);
        }else if (root->rchild==NULL)//右子树为空，左子树直接顶上去
        {
            BiTree tempNode =root;//临时指针
            root=root->lchild;
            free(tempNode);
        }else{//当前结点左右子树均不为空时
        //一般的删除策略：
        //(采用左子树的最右结点即最大数据)代替要删除的结点
            BiTree tempNode=root->lchild;
            while (tempNode->rchild!=NULL)//向右找到最大的
            {
                tempNode=tempNode->rchild;
            }
            root->key=tempNode->key;//把temoNode对应的值替换到要删除的值的位置上
            DeleteNode(root->lchild,tempNode->key);//在左子树中找到tempNode的值删除tempNode
        }
    
    }
    

}
int main()
{
   BiTree T=NULL;
   KeyType str[7]={54,20,66,40,28,79,58};//将要插入二叉排序树的元素值
   Create_BST(T,str,7);
   InOrder(T);//中序遍历二叉查找树是由小到大的
   printf("\n");
   BiTree search,parent;
   search=BST_Search(T,40,parent);
   if (search)
   {
    printf("find key %d\n",search->key);
   }else
   {
    printf("find failed!\n");
   }
   DeleteNode(T,40);
   InOrder(T);
   system("pause");
   return 0;
}
