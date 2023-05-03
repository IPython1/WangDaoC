/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
//程序启动称之为进程
//指针的使用场景:通常为传递和偏移
//在子函数内去改变主函数中某个变量的值
void change(int *j)
{
    *j=5;//*j等价于变量i  这里只是间接访问
}
int main()
{   int i=10;
    printf("before change=%d\n",i);
    change(&i);//此时传入i的地址
    //C语言的函数调用是值传递，实参赋值给形参 j=&i
    printf("after change=%d\n",i);

    system("pause");
    return 0;
}