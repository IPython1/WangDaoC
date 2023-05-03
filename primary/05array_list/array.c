#include <stdio.h>
#include <stdlib.h>
/*数组访问越界与数组的传递*/

/*1.数组访问越界*/

// int main(){
//     int a[5]={1,2,3,4,5};
//     int j=20;
//     int i=10;
//     a[5]=6; //越界访问 a:int[5]
//     a[6]=7; //越界访问会造成数据异常
//     printf("%d\n",i); //输出结果为7
//     system("pause");//防止运行后自动退出，需要头文件stdlib.h
//     return 0;
// }

/*2.数组的传递*/
//子函数 形参 把某一个常用功能  封装起来
//数组名传递到子函数后 子函数的形参接收到的是数组的起始地址  因此不能把数组的长度传递给子函数
void print(int a[],int length){
    int i;
    for ( i = 0; i < length ; i++)
    {
        printf("%3d",a[i]); 
    }
    a[3]=20;//子函数中也可以改变数组中的值

    printf("\n");

}
//主函数
int main(){
    int a[5]={1,2,3,4,5};
    // for ( int i = 0; i < sizeof(a)/sizeof(int); i++)//20/4 一个整型为4个字节
    // {
    //     printf("%d\n",a[i]); 
    // }
    print(a,5);//通过数组名传递
    printf("a[3]=%d",a[3]);
    printf("\n");
    system("pause");//防止运行后自动退出，需要头文件stdlib.h
    return 0;

}