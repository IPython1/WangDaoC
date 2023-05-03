#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;

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
//堆排序
//把某个子树调整为大根堆
void AdjustDown1(ElemType A[],int k,int len){
    //                            0      2还剩两个元素时
    int dad=k;//父亲的下标 0        
    int son=2*dad+1;//左孩子的下标 1
    while (son<len)
    {
        if (son+1<len&&A[son]<A[son+1])//保证右孩子存在，后进行判断
        {
            son++;//拿右孩子
        }
        if (A[son]>A[dad])//如果孩子大于父亲
        {
            swap(A[son],A[dad]);
            dad=son;//son重新作为dad，判断下面的子树是否符合大根堆
            son=2*dad+1;
        }else{
            break;
        }
    }

}
void HeapSort1(ElemType *A,int len){
    int i;
    //就是把堆调整为大根堆
    for ( i = len/2-1; i >=0; i--)//i 4 3 2 1 0
    {
        AdjustDown1(A,i,len);
    }
    swap(A[0],A[len-1]);//交换根部元素和最后一个元素
    for ( i = len-1; i >1; i--)//i代表的是剩余的无序数的数组的长度
    {
        AdjustDown1(A,0,i);//调整剩余元素变为大根堆
        swap(A[0],A[i-1]);//交换根部元素,和无序数的数组的最后一个元素
    }
    
}
int main()
{

   SSTable ST;
   ST_Init(ST,10);//申请十个元素的空间
   ElemType A[10];
   for (int i = 0; i < 10; i++)
   {
        scanf("%d",&A[i]);
   }
   //内存copy接口，当你copy整型数组，或者浮点型时，要共memcpy，不能用strcpy，初试考memcpy概率很低
   memcpy(ST.elem,A,sizeof(A));//这是为了降低调试难度，每饮数组数据固定两设计的
   SelectSort(ST.elem,10);
   ST_print(ST);//排序后再次打印
   HeapSort1(ST.elem,10);
   ST_print(ST);//排序后再次打印
   system("pause");
   return 0;

}

