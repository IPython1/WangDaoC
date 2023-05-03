/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
/*
f(n)=n*f(n-1)
递归的核心：
1.找公式
2.编写递归结束条件
*/
//递归求阶乘是为了了解递归
int f(int n){
    //一定要有结束条件
    if (1==n)
    {
        return 1;
    }
    else{
        return n*f(n-1);
    }
}
//到第N个台阶，有多少种走法
int step(int n){
    if (n==1||n==2)//当台阶为1or2个时 走法结束
    {
       return n;
    }
    return step(n-1)+step(n-2);
}

int main()
{   
    int n;
    int zoufa;
    scanf("%d",&n);
    zoufa=step(n);
    printf("%d\n",zoufa);
    system("pause");
    return 0;
}