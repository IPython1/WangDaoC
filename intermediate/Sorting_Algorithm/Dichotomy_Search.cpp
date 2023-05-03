#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/***
 * 折半查找（二分查找）：仅适用于有序的顺序表
 * 
 * 
 * 
 * 
*/
#define MaxSize 50
typedef int ElemType;
typedef struct 
{
    ElemType* elem;//整型指针，申请的堆空间的起始地址存入elem
    int TableLen;//存储动态数组里边元素的个数
}SSTable;
//init进行了随机数生成,随机数生成考研不会考
void ST_Init(SSTable &ST,int len){
    //多申请了一个位置,为了存哨兵，不使用哨兵战可以，为了和王道书保持一致
    ST.TableLen=len;
    ST.elem= (ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    int i;
    srand(time(NULL));//随机数生成，考研不需耍掌揖
    for (i = 0; i <ST.TableLen; i++)//因为第0个是哨兵，所以从1随机
    {
        ST.elem[i] = rand() % 100;//为了随机生成的数都在0-99之间
    }
}
void ST_print(SSTable ST){
    int i;
    for(i=0;i<ST.TableLen ;i++){
        printf("%3d", ST.elem[i]);
    }
    printf("\n");
}
//两数名中存储的是函数的入口地址,也是一个传针,是函数指针类型 
//left指针和right指针是指向数组中的任意两个元素
//qsort规定如果Left.指针指向的值大于right指针指向的值,返回正值,小于,返回负值,相等返回0
int compare(const void *left, const void *right)
{
    return *(int*)left-*(int*)right;
    //return *(ElemType*)right - *(ElenType*)left; //从大到小排序
}
//实现二分查找
int BinarySearch(SSTable L,ElemType key){
    int low=0;
    int high=L.TableLen-1;
    int mid;
    while (low<=high)//low<=high,可以让mid既能取到low,也能取到high
    {
        mid=(low+high)/2;
        if (key>L.elem[mid])//如果目标值大于中位数
        {
            low=mid+1;
        }else if (key<L.elem[mid])
        {
            high=mid-1;
        }else
        {
            return mid; 
        }
    }
    return -1;
}
int main()
{
   SSTable ST;
   ST_Init(ST,10);
   qsort(ST.elem,ST.TableLen,sizeof(ElemType),compare);
   ST_print(ST);
   ElemType key;
   printf("please input search key:\n");
   scanf("%d",&key);
   int pos=BinarySearch(ST,key);
   if (pos!=-1)
   {
    printf("find key%d\n",pos);
   }
   system("pause");
   return 0;
}
