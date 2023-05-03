/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
int change(int j){
    j=j/2;
    printf("%d\n",j);
}
int main()
{   
    int i;
    scanf("%d",&i);
    change(i);
    system("pause");
    return 0;
}