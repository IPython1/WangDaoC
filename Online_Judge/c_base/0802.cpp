#include <stdio.h>
#include <stdlib.h>//该头文件中包含 malloc函数
void change(char *&p){
    p=(char*)malloc(100);
    fgets(p, 100, stdin);//如果使用fgets传入的是一个指针变量，中间参数是指针指向的空间大小
}
int main()
{   char *p;//定义字符指针
    int n;
    change(p);
    puts(p);
    //调用方式是：puts(str)。其中str是字符串数组名或者字符串指针。实际上，数组名就是指针。
    system("pause");
    return 0;
}