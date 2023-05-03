/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
#define N 5
//指针的偏移使用场景，也就是对指针进行  加or减
/*int main()
{
    //数组为构造数据类型 interesting，float，double等为基础数据类型
    int a[N]={1,2,3,4,5};//数组名内存储了数组的起始地址，a中存储的就是一个地址值
    int *p;//定义指针变量P p+1的值偏移的长度是其基类型的长度(也就是偏移sizeof(int))
    p=a;
    for(int i=0;i<N;i++){
        printf("%3d",*(p+i));
    }
    printf("\n-----------\n");
    p=&a[4];//指针变量P指向数组的最后一个元素 可以进行逆向输出
    //float *p;p的加减也是偏移4个字节
    system("pause");
    return 0;
}
*/
//指针与一维数组的传递和偏移
//数组名作为实参传递给子函数时，是弱化为指针的
void change(char *d){
    *d='H';
    d[1]='E';
    *(d+2)='L';
}
int main(){
    char c[10]="hello";
    change(c);
    puts(c);
    system("pause");
    return 0;
}