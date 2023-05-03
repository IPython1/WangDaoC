#include <stdio.h>

#define MaxSize 50
typedef int ElemType;
typedef struct 
{
    ElemType date[MaxSize]; //顺序表的元素
    int length; //顺序表的当前长度
}SqList;
bool insert_LinearTable(SqList &l,int i,ElemType element){
    if (i<1||i>l.length)
    {
        return false;
    }
    if (l.length==MaxSize)
    {
        return false;
    }
    for(int j=l.length;j>=i;j--){
        l.date[j]=l.date[j-1];
    }

    l.date[i-1]=element;
    l.length++;
    return true;

}
bool delete_LinearTable(SqList &l,int i){
    if (i<1||i>l.length)
    {
        return false;
    }
    if (l.length==MaxSize)
    {
        return false;
    }
    for (int j = i; j < l.length; j++)
    {
        l.date[j-1]=l.date[j];
    }
    l.length--;
    return true;
}
void print_all(SqList l){
    for (int i = 0; i < l.length; i++)
    {
        printf("%3d",l.date[i]);
    }
    printf("\n");
}
int main()
{
   SqList l;
   ElemType i=2,element,del_pos;
   bool ret;
   l.date[0]=1;
   l.date[1]=2;
   l.date[2]=3;
   l.length=3;
   scanf("%d",&element);
   ret=insert_LinearTable(l,i,element);
   if(ret == true){
        print_all(l);
    }else{
        printf("false\n");
    }
   
   scanf("%d",&del_pos);
   ret=delete_LinearTable(l,del_pos); 
   if(ret == true){
        print_all(l);
    }else{
        printf("false\n");
    }
   return 0;
}
