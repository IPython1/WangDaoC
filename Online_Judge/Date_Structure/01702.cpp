#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 10
typedef int ElemType;
/**
 * 归并排序
 * MergeSort函数的递归次数是 logan.Merge函数的循环了n次，
 * 因此时间复杂度是O(nlogn)。
 * 归并排序最好、最坏、平均时间复杂度都是O(nlog以2为底的n)。
 * 归并排序的空间复杂度是o(n)，因为使用了数组B，它的大小与A一样，占用n个元素的空间。
 * 稳定性是指排序前后，相等的元素位置是否会被交换
 * 复杂性是指代码编写的难度
*/

//归并排序 考研考的都是两两归并
void Merge(ElemType *A,int low,int mid,int high){
    static ElemType B[N];
    int i,j,k;
    for ( i = low; i <= high; i++)//
    {
        B[i]=A[i];
    }
    k=low;
    for ( i = low,j=mid+1;i<=mid&&j<=high;)//合并两个有序数组
    {
        if (B[i]<B[j])
        {
            A[k]=B[i];
            i++;
            k++;
        }else
        {
            A[k]=B[j];
            j++;
            k++;
        }
    }
    //把某一个有序数组中剩余元素放进来
    while (i<=mid)
    {
        A[k]=B[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        A[k]=B[j];
        j++;
        k++;
    }
    
}
void MergeSort(ElemType *A,int low,int high){//递归分割
    if (low<high)
    {
        int mid=(low+high)/2;
        MergeSort(A,low, mid) ; //排序好前一半
        MergeSort(A,mid+1, high);//排序好后一半
        Merge(A,low,mid,high);//将两个排序好的数组合并

    }
    
}
void print(int* a){
    for(int i=0; i<N; i++){
        printf("%3d",a[i]);
    }
    printf("\n");
}
int main()
{
   ElemType A[N];
   for (int i = 0; i < N; i++)
   {
        scanf("%d",&A[i]);
   }
   MergeSort(A,0,9);
   print(A);   
   system("pause");
   return 0;

}

