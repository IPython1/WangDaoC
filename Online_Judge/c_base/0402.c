/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
int main()
{   int n;
    int result=1;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        result*=i;
    }
    printf("%d\n",result);
    system("pause");
    return 0;
}