#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
/**
 * 快速排序的核心是分治思想:
 * 假设我们的目标依然是按从小到大的顺序排列，
 * 我们找到数组中的一个分割值，把比分割值小的数都放在数组的左边，
 * 把比分割值大的数都放在数组的右边，这样分割值的位置就被确定。
 * 数组一分为二，我们只需排前一半数组和后一半数组,复杂度直接减半。
 * 采用这种思想,不断地进行递归，最终分割得只剩一个元素时，整个序列白然就是有序的。
 * 最好，平均时间复杂度nlog以2为底n 最坏（已经排序好的）时间复杂度为O(N^2)
 * 空间复杂度8*log以2为底n
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
//快速排序的核心函数
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

int main()
{
   SSTable ST;
   ST_Init(ST,10);
   ElemType A[10]={64,94,95,79,69,84,18,22,12,78};
   //内存copy接口，当你copy整型数组，或者浮点型时，要共memcpy，不能用strcpy，初试考memcpy概率很低
   memcpy(ST.elem,A,sizeof(A));//这是为了降低调试难度，每饮数组数据固定两设计的
   ST_print(ST);//结果打印
   QuickSort(ST.elem,0,9);
   ST_print(ST);//排序后的结果打印
   system("pause");
   return 0;

}

