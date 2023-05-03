/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
int main()
{   
    int i;
    char j;
    float k;
    scanf("%d %c %f",&i,&j,&k);
    // scanf("%c",&j);
    // scanf("%ld",&k);
    printf("%.2f\n",i+j+k);
    system("pause");
    return 0;
}