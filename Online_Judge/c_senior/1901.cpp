#include <stdio.h>
#include <stdlib.h>

int main()
{
   //位运算符测试 bit-caculate
   short i;//00 05 十六进制转二进制 0000 0000 0000 0101
   short j;
   scanf("%d",&i);
   j=i;
   j=i<<1;//一个变量移动以后自身不会变化
   printf("%2d\n",j);//左移是乘2，结果为10
   j=i>>1;
   printf("%2d\n",j);//右移是乘2，结果为2




   system("pause");
   return 0;

}
