#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode *lchild, *rchild;
}BSTpode,*BiTree;
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
void InOrder(BiTree T,KeyType str[],int &pos){
    if (T!=NULL)
    {
        InOrder(T->lchild,str,pos);
        printf("%3d ",T->key);
        str[pos++]=T->key;//输出的同时存入数组
        InOrder(T->rchild,str,pos);
    }
}
//折半查找 已排序的数组
typedef int ElemType;
typedef struct 
{
    ElemType* elem;//整型指针，申请的堆空间的起始地址存入elem
    int TableLen;//存储动态数组里边元素的个数
}SSTable;
int Binary_Search(SSTable L, ElemType key)
{
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.elem[mid] == key)
            return mid;
        else if (L.elem[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
   BiTree T=NULL;
   int x;
   for (int i = 0; i < 10; i++)
   {
        scanf("%d",&x);
        BST_Insert(T,x);
   }
   KeyType str[10];
   int pos=0;
   InOrder(T,str,pos);
   printf("\n");
//    for (int i = 0; i < 10; i++)
//    {
//         printf("%d ",str[i]);
//    }
//    printf("\n");
    SSTable L;
    L.elem = str;
    L.TableLen = 10;
    pos = Binary_Search(L, 21);
    printf("%d\n", pos);
    system("pause");
    return 0;
}