/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
int main()
{   int year;
    scanf("%d",&year);
    if ((year%4==0&&year%100!=0)||year%400==0)
    {
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
    system("pause");
    return 0;
}