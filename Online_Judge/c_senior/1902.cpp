#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;

int main()
{
   ElemType num[5];
   for (int i = 0; i < 5; i++)
   {
        scanf("%d",&num[i]);
   }
   for (int i = 0; i < 5; i++)
   {
        printf("%d",num[i]); 
   }
   
   
   system("pause");
   return 0;
}
