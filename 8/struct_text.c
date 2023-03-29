//
// Created by 86199 on 2023/3/15.
//

#include "struct_text.h"
typedef struct student{
    int num;
    char name[20];
    char sex;
}stu,*psut;

typedef int INTEGER;

void struct_t()
{
    struct student s = {4,"aaa",'c'};
    //结构体对其，结构体大小是最大成员的整数倍
    //4+20+1=25 ，28是大于25的最小4的整数倍率
    printf("size of struct student is %d\n",sizeof (s));

    stu s1 = s;
    psut ps = &s1;
    printf("%d %s %c\n",ps->num,ps->name,ps->sex);

}