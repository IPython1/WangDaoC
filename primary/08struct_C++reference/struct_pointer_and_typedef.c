/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
/*
结构体指针与typedef的使用
*/
//结构体变量指针 该变量所占据的内存段的起始地址
//可以通过结构体指针快速访问结构体内的每个成员
struct student
{
    int num;

    char name[20];

    char sex;

};
//结构体指针的练习
int main()
{   
    struct student s={1001,"wangle",'M'};
    struct student sarr[3]={1001,"lilei",'M',1005,"zhangsan",'M',1007,"lili",'F'};
    struct student *p;//定义了一个结构体指针变量
    p=&s;
    // printf("%d %s %c \n",s.num,s.name,s.sex);
    // printf("%d %s %c \n",(*p).num,(*p).name,(*p).sex);//方式1通过结构体指针去访问成员
    printf("%d %s %c \n",p->num,p->name,p->sex);
    printf("---------------------------------\n");
    p=sarr;//等价于p=&sarr[0]
    p=p+1;
    printf("%d %s %c \n",p->num,p->name,p->sex);
    p=sarr;//等价于p=&sarr[0]
    p=p+2;
    printf("%d %s %c \n",p->num,p->name,p->sex);

    system("pause");
    return 0;
}
/*
typedef的使用 typedef起别名
typedef struct student
//stu 等价于 struct student;pstu等价于struct student*
{
    int num;

    char name[20];

    char sex;

}stu,*pstu;
typedef int INGETER;//特定的地方起别名
int main(){

    stu s={0};
    stu *p=&s;//定义了一个结构体指针变量
    pstu p1=&s;//定义了一个结构体指针变量
    return 0;

}
*/