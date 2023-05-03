/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
//scanf读取字符串操作 会自动向字符数组存放\0
int main()
{
    char c[10];
    char d[10];
    // scanf("%s",c);//字符数组名c中存储了数组的起始地址，因此不需要取地址
    // printf("%s\n",c);
    scanf("%s%s",c,d);
    printf("c=%s,d=%s\n",c,d);
    system("pause");
    return 0;
}