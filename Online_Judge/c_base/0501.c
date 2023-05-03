/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
int main()
{   int a[100];
    int n,total=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==2)
        {
            total++;
        }
        
    }
    printf("%d\n",total);
    system("pause");
    return 0;
}