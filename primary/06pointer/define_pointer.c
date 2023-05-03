/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
int main()
{   //说某个变量的地址时  指的是起始地址
    int i=5;
    // printf("i=%d\n",i);//直接访问：按变量地址 存取 变量值的方式
    // 间接访问：指针变量 存储地址
    //一个变量的 地址 称为该变量的 指针 位置范围（64位的电脑为8个字节，考研中一般为32位的程序为4个字节）
    //int *i_pointer;//定义一个指针变量 这里的*表示i_pointer是一个指针变量
    // i_pointer=&i;//&i是将i的地址赋值给指针变量i_pointer
    // printf("%d\n",*i_pointer);//输出值为2000，这里的*表示指针，即可以通过指针变量里面i的地址取到i变量的值
    int *i_pointer=&i;
    //定义了一个指针变量，i_pointer为指针变量名
    //指针变量的初始化是某个变量取地址来赋值，不能随机写个数
    printf("*i_pointer=%d\n",*i_pointer);//间接访问 *为单目运算符
    system("pause");
    return 0;

}