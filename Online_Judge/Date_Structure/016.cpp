#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
/**
 * 
 * 排序算法分为交换类排序，插入类排序，选择类排序，归并类排序
 * 交换类排序：1.冒泡排序 2.快速排序
 * 
 * 
*/
typedef struct 
{
   ElemType *elem;//存储元素的起始地址
   int TableLen;//元素个数
}SSTable;
//init进行了随机数生成,随机数生成考研不会考
void ST_Init(SSTable &ST,int len){
    ST.TableLen=len;
    ST.elem= (ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    int i;
    srand(time(NULL));//随机数生成，考研不需耍掌揖
    for (i = 0; i <ST.TableLen; i++)
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

//12 63 58 95 41 35 65  0 38 44
//冒泡排序 最坏，平均时间复杂度O(n^2)1+2+3+...+n-1=n*(n+1)/2,空间复杂度O(1)
//最好的时间复杂度：O(n)//原本有序
//往往采用两层循环 优先写内层循环再写外层循环
//交换两个元素
void swap(int &a,int &b){
   int tmp;
   tmp=a;
   a=b;
   b=tmp;
}
void BubbleSort(ElemType *A,int n){
   int i,j;
   bool flag;
   for ( i = 0;i<n-1; i++)//控制有序数的数目
   {  
      flag=false;
      for (j=n-1;j>i;j--)//内层控制比较和交换
      {
         if (A[j-1]>A[j])
         {
            swap(A[j-1],A[j]);
            flag=true;
         }
      }
      if (flag==false)//如果一趟比较没有发生任何交换，说明数组本身就是有序，提前结束排序
      {
         return;
      }
      
   }
   
}
//快速排序
int partition(ElemType *A,int low,int high){
   ElemType pivot=A[low];//拿最左边的作为分隔值，并存储下来
   while (low<high)
   {
      while (low<high&&A[high]>=pivot)//从后往前遍历，找到一个比分隔值小的
      {
         high--;
      }
      A[low]=A[high];
      while (low<high&&A[low]<=pivot)//从前往后遍历，找到一个比分隔值大的
      {
         low++;
      }
      A[high]=A[low];
   }
   A[low]=pivot;//把分隔值放在中间位置，因为左边比他小，右边比他大
   return low;//返回分隔值所在下标

}
void QuickSort(ElemType *A,int low,int high){
   if (low<high)
   {
      int pivot=partition(A,low,high);//pivot用来存分隔值的位置
      QuickSort(A,low,pivot-1);
      QuickSort(A,pivot+1,high);
   }
   
}
//插入排序
void InsertSort(ElemType *A,int n){
    int i,j,insertVal;
    for ( i = 0; i < n; i++)//外层控制要插入的数
    {
        insertVal=A[i];//保存要插入的数
        //内层循环控制比较，j要大于等于0，同时A[j]>insertval时，A[j]元素向后覆盖
        for ( j = i-1; j >=0&&A[j]>insertVal; j--)
        {
            A[j+1]=A[j];   
        }
        A[j+1]=insertVal;//把要插入的元素放到对应的位置
    }

}
int main()
{
   SSTable ST;
   ST_Init(ST,10);
//    ElemType A[10]={12,63,58,95,41,35,65,0,38,44};
    ElemType A[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&A[i]);
    }
   //内存copy接口，当你copy整型数组，或者浮点型时，要共memcpy，不能用strcpy，初试考memcpy概率很低
   memcpy(ST.elem,A,sizeof(A));//这是为了降低调试难度，每饮数组数据固定两设计的
   BubbleSort(ST.elem,10);
   ST_print(ST);//冒泡排序后的结果打印

   QuickSort(ST.elem,0,9);
   ST_print(ST);//快速排序后的结果打印

   InsertSort(ST.elem,10);
   ST_print(ST);//插入排序后的结果打印
   system("pause");
   return 0;

}
