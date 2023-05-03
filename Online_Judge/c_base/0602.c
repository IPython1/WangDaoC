/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
int main()
{   int n;
    char c;
    char *p;
    scanf("%d",&n);
    p=(char*)malloc(n);
    scanf("%c",&c);
    //注意在scanf和gets中间使用scanf("%c",&c),去除换行
    gets(p);
    puts(p);
    system("pause");
    return 0;
}