//
// Created by 86199 on 2023/3/13.
//

#include "operator.h"

void ASMD()
{
    printf("4+5*2-6/3+10%%4=%d\n",4+5*2-6/3+10%4);
}
void relation()
{
    int i = 0;
    while (scanf("%d",&i))//读取成功返回1
    {
        if(i>3&&i<10)
        {
            printf("i is between 3 and 10\n");
        } else
        {
            printf("i is not between 3 and 10\n");
        }
    }
}
void logic()
{
    int year = 0;
    while (scanf("%d",&year))
    {
        if(year%4==0&&year%100!=0 || year%400==0)//记住优先级，不要多加括号
        {
            printf("%d is a leap year",year);
        } else
        {
            printf("%d is not a leap year",year);
        }
    }
}
void short_circuit()
{
    int i = 0;
    i&& printf("you can't see me!");
}