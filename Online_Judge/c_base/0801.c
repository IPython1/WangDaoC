#include <stdio.h>
struct student{//结构体类型名
     int id;
     char name[20];
     char sex;
 };//结构体声明，注意最后一定要加分号
 int main(){
    struct student s;
    scanf("%d%s %c",&s.id,s.name,&s.sex);
    printf("%d %s %c\n",s.id,s.name,s.sex);
    return 0;
}