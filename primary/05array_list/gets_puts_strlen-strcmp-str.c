/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//gets一次读取一行
int main()
{   
    int len;
    char c[20];
    char d[100]="world";
    char e[100];
    gets(c);    //gets中放入字符数组的数组名即可 
    puts(c);    //puts等价于printf("%s\n",c);puts内放的参数是字符数组名
    len=strlen(c);//统计字符串的长度
    printf("%d\n",len);
    strcat(c,d);//把d与c拼接
    puts(c);
    strcpy(e,c);
    puts(e);
    printf("c?d %d\n",strcmp(c,d));//前者必须放数组名
    //字符串比较大小  比较规则为ASCII码值 c>d return 1（正值）相等返回0 小于返回-1
    system("pause");
    return 0;
}