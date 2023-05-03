#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
/**插入排序
 * 插入排序分为
 * 1、直接插入排序
 * 随着有序序列的不断增加，
 * 插入排序比较的次数也会增加，
 * 插入排序的执行次数也是从1加到N -1，
 * 总运行次数为N(N-I)/2，时间复杂度依然为O(n2)。
 * 因为未使用额外的空间（额外空间必须与输入元素的个数N相芡)，
 * 所以空间复杂为O(1)。
 * 如果数组本身有序，那么就是最好的时间复杂度O(n)。
 * 2、折半插入排序
 * 3、希尔排序
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
//
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
   ST_Init(ST,10);//申请十个元素的空间
   ElemType A[10]={64,94,95,79,69,84,18,22,12,78};
   //内存copy接口，当你copy整型数组，或者浮点型时，要共memcpy，不能用strcpy，初试考memcpy概率很低
   memcpy(ST.elem,A,sizeof(A));//这是为了降低调试难度，每饮数组数据固定两设计的
   ST_print(ST);//结果打印
   InsertSort(ST.elem,10);
   ST_print(ST);//排序后再次打印
   system("pause");
   return 0;

}

