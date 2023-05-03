#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 10
typedef int ElemType;
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

