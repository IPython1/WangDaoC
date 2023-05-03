/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
//字符数组的初始化及赋值 字符数组一般存储字符串
/*C语言规定字符串的结束标志为'\0'
    （'\0'可能访问越界）  */
//输出字符串乱码时，需查看字符数组中是否存储了结束符‘\0’
//模拟printf（%s,c）操作
void print(char d[]){
    int i=0;
    while (d[i])//当走到结束符时，循环结束
    {
        printf("%c",d[i]);//%c 输出单个字符
        i++;
    }
    printf("\n");
    d[0]='H';
}
//如何初始化字符数组，字符串如何输出
int main()
{   
    // char c[10]={'I','a','m','h','a','p','p','y'};//此种字符初始化操作不常用 可能会输出乱码
    // char c[10]="Iamhappy";//常使用这种方式进行初始化字符数组
    char c[6]="hello";//使用这种方式初始化字符数组 注意访问越界 ‘\0’ 避免乱码
    char d[4]="how";
    printf("%s\n",c);//使用%s来输出一个字符串 直接把字符数组名放在后边的位置
    print(d);
    printf("%c\n",d[0]);
    system("pause");//防止运行后自动退出，需要头文件stdlib.h
    return 0;
}
