//
// Created by 86199 on 2023/3/15.
//

#include "recurrence .h"
//void Common_errors()
//{
//    {
//        int j=0;
//    }
//    printf("%d",j);//无法访问j，局部变量只在大括号内有效
//    for(int i=0;i<8;i++);
//    printf("%d",i);//无法访问i
//
//}

int footstep(int n)
{
    if(1==n||0==n)
    {
        return 1;
    }
    return footstep(n-1)+footstep(n-2);
}
void recurrence_text()
{
    int n=0;
    scanf("%d",&n);
    int num = footstep(n);
    printf("There are %d ways to walk on the %d-step ladder",num,n);
}