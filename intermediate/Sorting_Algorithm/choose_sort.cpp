#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
/**
 * 
 * 选择排序分为
 * 1、简单选择排序
 *  （牛客网）插入排序的原理：始终定义第一个元素为有序的，将元素逐个插入到有序排列之中，其特点是要不断的移动数据，空出一个适当的位置，把待插入的元素放到里面去。
    选择排序的原理：每次在无序队列中“选择”出最小值，放到有序队列的最后，并从无序队列中去除该值（具体实现略有区别）。
    在第 i 次排序中，前 i - 1 个元素始终是有序的，此时只需把第i个元素插入到有序的序列中即可，故代码中体现的是插入排序的思想。代码中对当前 a[i]>a[j]（0<=k<i-1）是否成立进行判断，若成立则将 a[j] 往后移（即大的数排在前面，小的数排在后面），故代码中的排序原则为降序排。
 * 2、堆排序   ---重要
 * 选择排序虽然减少了交换次数，
 * 但是循环比较的次数依然和冒泡排序的数量是一样的，都是从1加到N-1，
 * 总运行次数为N(N-1)/2。
 * 我们忽略循环内语句的数量，因为我们在计算时间复杂度时，
 * 主要考虑与N有关的循环，如果循环内交换得多，例如有5条语句，那么最终得到的无非是5n';
 * 循环内交换得少，例如有﹖条语句，那么得到的就是2n2，但是时间复杂度计算是忽略首项系数的，因此最终还是on')。
 * 因此，选择排序的时间复杂度依然为o(n2)。
 * 因为未使用额外的空间(额外空问必须与输入元素的个数N相关)，
 * 所以空间复杂为O(1)。
 * 另外考研初试问时间复杂度，
 * 直接写最终结果即可，不用分析过程，
 * 除非清晰说明需要给出计算过程，
   或者分析过程（但是日前直都没有这个要求)。
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
//选择排序
void swap(ElemType &a,ElemType &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void SelectSort(ElemType* A,int n){
     int i,j,min;
     for ( i = 0; i<n-1; i++)
     {  
        min=i;//开始我们认为0号元素最小
        for ( j = i+1;j<n; j++)//找到从i开始到最后序列最小值的下标
        {
            if (A[j]<A[min])//当某个元素小于最小元素
            {
                min=j;//将下标j赋值给min，min就记录下来了最小值的下标
            }
        }
        if (min!=i)
        {   
            //遍历完毕找到最小值的位置后，与A[i]交换，这样最小值被放到了最前面
            swap(A[i],A[min]);
        }    
     }
}

int main()
{

   SSTable ST;
   ST_Init(ST,10);//申请十个元素的空间
   ElemType A[10]={64,94,95,79,69,84,18,22,12,78};
   //内存copy接口，当你copy整型数组，或者浮点型时，要共memcpy，不能用strcpy，初试考memcpy概率很低
   memcpy(ST.elem,A,sizeof(A));//这是为了降低调试难度，每饮数组数据固定两设计的
   ST_print(ST);//结果打印
   SelectSort(ST.elem,10);
   ST_print(ST);//排序后再次打印
   system("pause");
   return 0;

}

