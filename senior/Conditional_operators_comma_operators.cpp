#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//三目运算符 max=a>b?a:b
/**
 * 如逻辑非运算符就是单目运算符。运算符也称操作符。
 * 三目运算符通过判断问号之前的表达式的真假，来确定整体表达式的值，
 * 如下例所示，如果a>b为真，那么三目表达式整体的值为a，所以 max的值等十a，
 * 如果 a>b为假，那么三日表达式整体的值为 b，
 * 所以 max的值等于b。
 * 条件运算符的优先级大于赋值运算符
 * 逗号运算符优先级最低 
 * 逗号表达式的整体值是最后一个表达式的值
 * 
*/
/**
 * 位运算符：
 * 位运算符<<、>>、~、|、^、s依次是左移、右移、按位取反、按位或、按位异或、按位与。
 * 位运算符只能用于对整型数据进行操作。
*左移:高位丢弃，低位补0，相当于乘以2。
*工作中很多时候申请内存时会用左移，例如要申请1GB大小的空间，可以使用malloc(l<<30)。
*右移:低位丢弃，正数的高位补0（无符号数我们认为是正数），负数的高位补1，相当于除以2。移位比乘法和除法的效率要高，负数右移，对偶数来说是除以2，但对奇数来说是先减1后除以2。例如，-0>>1，得到的是-4，但-7>>1得到的并不是-3而是-4。另外，对于-1来说，无论右移多少位，值水远为-1。
*c语言的左移和右移相当于是算术左移与算术右移。
考研中的逻辑左移与右移，左移和右移空位都补0。
异或:相同的数进行异或时，结果为0，任何数和0异或的结果是其本身。
按位取反:数位上的数是1变为0，0变为1。
按位与和按位或:用两个数的每一位进行与和或。
 * 
 * 
 * 
*/
int main()
{
   //位运算符测试 bit-caculate
   short i=5;//00 05 十六进制转二进制 0000 0000 0000 0101
   short j;
   j=i;
   j=i<<1;//一个变量移动以后自身不会变化
   printf("j=%d\n",j);//左移是乘2，结果为10
   j=i>>1;
   printf("j=%d\n",j);//右移是乘2，结果为2
   unsigned short s;//无符号数只能是整数或0，不能是复数

   system("pause");
   return 0;

}
