/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
int main()
{   
    int a,b,c,tmp;
    while (scanf("%d",&a)!=EOF)
    {
        b=0;
        c=a;
        while (a)//每次都拿出最后一位
        {
            tmp=a%10;//个位（最末位）
            b=b*10+tmp;
            a=a/10;
        }
        if (c == b)
        {
            printf("yes\n");
        }
        else{
            printf("no\n");
        }  
    }
    system("pause");
    return 0;
}