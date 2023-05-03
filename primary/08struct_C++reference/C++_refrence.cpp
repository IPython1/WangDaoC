#include <stdio.h>
#include <stdlib.h>
// #include <iostream>
// using namespace std;
/*
C++的(quote)引用讲解&&C++的布尔类型
链表二叉树（子函数内修改主函数的一级指针变量）
*/
//在子函数中修改主函数普通变量的值
/*void modify_num(int &b){//形参中写& 称为引用
    b=b+1;
}
int main()
{
   int a=10;
   modify_num(a);
   printf("after modify_num a=%d\n",a);
//    cout<<"hello world";
   system("pause");
   return 0;
}
*/
//子函数内修改主函数的一级指针变量的值
void modify_num(int *&p,int *q){//形参中写& 称为引用
    p=q;
}
int main()
{
   int *p=NULL;
   int i=10;
   int *q=&i;
   modify_num(p,q);
   printf("%d\n",*q);
   printf("after modify_num *p=%d\n",*p);
   system("pause");
   return 0;
}
