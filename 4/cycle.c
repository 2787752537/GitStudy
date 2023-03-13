//
// Created by 86199 on 2023/3/13.
//

#include "cycle.h"
void symmetrical_number()
{
    int num =0;
    while (scanf("%d",&num)) {
        int renum=0;
        int temp = num;
        while (0 != temp) {
            int remainder = temp % 10;
            temp /= 10;
            renum = renum * 10 + remainder;
        }
        if (num == renum) {
            printf("%d is a symmetrical number\n", num);
        } else {
            printf("%d is not a symmetrical number\n", num);
        }
    }
}
void exchange_money()
{
    int total = 0;
    int num = 0;
    for(int i=1;i<=7;i++)
    {
        for (int j=1;j<21;j++)
        {
            for(int k=1;k<37;k++)
            {
                   total = i*10+j*5+k*2+40-i-j-k;
                   if(100==total&&i+j+k<40)
                   {
                       num++;
                   }
                   total=0;
            }
        }
    }
    printf("%d",num);
}