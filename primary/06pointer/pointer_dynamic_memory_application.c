/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>//malloc使用的头文件
#include <string.h>
//栈空间与堆空间的差异
/*堆空间不会因为函数执行结束而释放
char* print_malloc(){
    char *p;
    p=(char*)malloc(20);
    strpy(p,"I am print_malloc");
    puts(p);
    return p;
}
*/
int main()
{   int size;//size 代表我们申请多大字节的空间
    char *p,*q;//void* 类型的指针不能偏移的 因此不会定义无类型指针
    scanf("%d",&size);//输入需要申请空间的大小
    //malloc返回的void*代表无类型指针 后进行强制类型转换
    p=(char*)malloc(size);//malloc 返回对应堆空间的首地址
    // p[0]='H';
    // p[1]='O';
    // p[2]='W';
    // p[3]='\0';
    strcpy(p,"malloc success!");
    puts(p);
    free(p);//释放申请的空间时，给的地址，必须是最初malloc返回给我们的地址     free时 必须使用malloc申请时返回的指针值,不能进行任何偏移
    //只有free时，堆空间才会释放
    printf("free success!\n");
    system("pause");
    return 0;
}