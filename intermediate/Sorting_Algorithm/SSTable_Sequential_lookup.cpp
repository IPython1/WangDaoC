#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    ST.TableLen=len+1;
    ST.elem= (ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    int i;
    srand(time(NULL));//随机数生成，考研不需耍掌揖
    for (i = 1; i <ST.TableLen; i++)//因为第0个是哨兵，所以从1随机
    {
        ST.elem[i] = rand() % 100;//为了随机生成的数都在0-99之间
    }
}
void ST_print(SSTable ST){
    int i;
    for(i=1;i<ST.TableLen ;i++){
        printf("%3d", ST.elem[i]);
    }
    printf("\n");
}
int Search_Seq(SSTable ST,ElemType key){
    ST.elem[0]=key;//key存在0号位置，作为哨兵
    int i;
    for ( i = ST.TableLen-1; ST.elem[i]!=key; --i);
    return i;
    
    
}
//顺序查找
int main()
{
   SSTable ST;
   ST_Init(ST,10);
   ST_print(ST);
   ElemType key;
   printf("please input search key:\n");
   scanf("%d", &key);
   int pos;
   pos=Search_Seq(ST,key) ;
   if(pos)
   {
    printf("find success!pos=%d\n",pos);
   }else
   {
    printf("find failed!\n");
   }
   system("pause");
   return 0;
}
