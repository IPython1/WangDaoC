/*@Author JieJie*/
#include <stdio.h>
#include <stdlib.h>
/*
    将不同类型的数据组合为一个整体
    C语言提供结构体 管理不同类型的数据组合
    结构体的大小必须是其最大基础成员的整数倍 4 20 1（增加） 4 4 30（增加） 
    结构体对齐后63+3+2=68个字节
    结构体对齐的目的是 为了cpu高效的去取内存上的数据
    
*/
//for instance

struct student_type1{
    short age;//short 整型  占2个字节
    double score;//double是一种浮点类型，8个字节，浮点分为float(4个字节)，double（8个字节）
    
};
struct student_type2{
    double score;
    char height;//如果两个小存储之和是小于最大长度8，那么它们就结合在一起
    short age;
};
struct student_type3{
    int height;
    char sex;
    short age;
};
struct student4{//结构体类型名
     int num;
     char name[20];
     char sex;
     int age;
     float score;
     char addr[30];
 };//结构体声明，注意最后一定要加分号
 struct student5{//结构体类型名
     int num;
     char name[20];
     char sex;
     short age;
     float score;
     char addr[30];
 };
int main(){
    struct student_type1 s1;
    struct student_type2 s2;
    struct student_type3 s3;
    struct student4 s4;
    struct student5 s5;

    printf("%d\n",sizeof(s1));
    printf("%d\n",sizeof(s2));
    printf("%d\n",sizeof(s3));
    printf("%d\n",sizeof(s4));
    printf("%d\n",sizeof(s5));
    system("pause");
    return 0;

}



// struct student{//结构体类型名
//     int num;
//     char name[20];
//     char sex;
//     int age;
//     float score;
//     char addr[30];
// };//结构体声明，注意最后一定要加分号
// //访问结构体成员：结构体变量名.成员名

// int main()
// {   /*
//     1001 lele M 20 85.4 Shenzhen
//     2000 lili F 20 88.6 Beijing
//     2001 lilei M 21 88.88 Shanghai
//     */
//     struct student s={1001,"lele",'M',20,85.4,"Shenzhen"};
//     struct student sarr[3];//定义结构体数组变量
//     int i;
//     // printf("%d %s %c %d %f %s\n",s.num,s.name,s.sex,s.age,s.score,s.addr);
//     for(i=0;i<3;i++){

//         scanf("%d%s %c%d%f%s",&sarr[i].num,sarr[i].name,&sarr[i].sex,&sarr[i].age,&sarr[i].score,sarr[i].addr);

//     }
//     // scanf("%d%s %c%d%f%s",&s.num,s.name,&s.sex,&s.age,&s.score,s.addr);//%d%f%s 自动忽略空格

//     for(i=0;i<3;i++){//结构体数组的输出

//         printf("%d %s %c %d %f %s\n",sarr[i].num,sarr[i].name,sarr[i].sex,sarr[i].age,sarr[i].score,sarr[i].addr);

//     }
//     // printf("%d %s %c %d %f %s\n",s.num,s.name,s.sex,s.age,s.score,s.addr);
//     system("pause");
//     return 0;
// }