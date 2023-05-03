/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{   
    char a[20];
    char b[20];
    gets(a);

    for (int i = 0; i <strlen(a); i++)
    {
        b[i]=a[strlen(a)-i-1];
    }
    b[strlen(a)]='\0';

    int result = strcmp(a, b);
    if (result < 0)
    {
        printf("%d\n",-1);
    }
    else if (result > 0)
    {
        printf("%d\n", 1);
    }
    else {
        printf("%d\n", 0);
    }
    system("pause");
    return 0;
}