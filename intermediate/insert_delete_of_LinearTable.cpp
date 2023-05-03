#include <stdio.h>
#include <stdlib.h>
//顺序表的初始化及代码实战(sequence table)

#define MaxSize 50 //定义线性表的长度
typedef int ElemType;//让顺序表存储其他元素类型时，可以快速完成代码修改
typedef struct 
{
    ElemType date[MaxSize]; //顺序表的元素
    int length; //顺序表的当前长度
}SqList; //顺序表的类型定义
//顺序表的插入，因为L会改变，因此我们这里要使用引用，i是插入的位置
bool ListInsert(SqList &L,int i,ElemType element){//遇见true即退出函数
   //判断i是否合法
    // if (i>=1&&i<=L.length+1)
    // {
    //     return true;
    // }
    //如果存储空间满了，不能插入
    if(L.length==MaxSize){
        return false;
    }
    //把后面的元素依次往后移动，空出位置
    for (int j = L.length; j >=i ; j--)
    {
        L.date[j]=L.date[j-1];
    }
    L.date[i-1]=element;
    L.length++;//顺序表长度+1
    return true;//插入成功返回true

}
//i是要删除元素的位置，e是为了获取被删除元素的值
bool ListDelete(SqList &L,int i,ElemType &e){
    //删除操作 从当前删除位置之后的元素向前覆盖
    //判断i是否合法
     if (i<1||i>L.length)
     {
         return false;
     }
    e=L.date[i-1];//保存要删除元素的值
    for (int j = i; j <L.length ; j++)
    {
        L.date[j-1]=L.date[j];
    }
    
    L.length--;//顺序表长度-1
    return true;//插入成功返回true
}
//查找某个元素的位置，找到了返回对应的位置，没找到返回0
int LocateElem(SqList L,ElemType element){
    int i;
    for( i=0;i<L.length;i++)
    {
        if(element==L.date[i]){//i是数组的下标
            return i+1;
        }
    }
    return 0;
}


//打印顺序表
void PrintList(SqList L){
    int i;
    for( i=0;i<L.length;i++)
    {
        printf("%3d",L.date[i]);
    }
    printf("\n");
}

int main()
{   SqList L;//顺序表的名称
    bool ret;//查看返回值，True or False
    ElemType del;//要删除的元素存入del中
    L.date[0]=1;
    L.date[1]=2;
    L.date[2]=3;
    L.length=3;
    PrintList(L);
    ret=ListInsert(L,2,60);//下划线命名法 驼峰命名法
    if(ret == true){
        printf("insert sqlist success\n");
        PrintList(L);
    }else{
        printf("insert sqlist failed\n");
    }
    // ListDelete(L,2,del);
    // PrintList(L);
    // printf("%d\n",del);
    int pos;//存储元素的位置
    pos=LocateElem(L,60);//根据值查找找位置
    printf("%d\n",pos);
    system("pause");
    return 0;
}
