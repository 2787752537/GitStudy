//
// Created by 86199 on 2023/3/13.
//

#include "array.h"
void print1(int a[],int length)
{
    for(int i=0;i<length;i++)//无法传入数组的大小，sizeof的得到的是起始地址的指针，大小等于8字节
    {
        printf("a[%d]=%d ",i,a[i]);
    }
    printf("\n");
}
void print(int a[])
{
    for(int i=0;i<sizeof(a)/sizeof(int);i++)//无法传入数组的大小，sizeof的得到的是起始地址的指针，大小等于8字节
    {
        printf("a[%d]=%d ",i,a[i]);
    }
    printf("\n");
}
void printc(char c[])
{
    int i=0;
    while (c[i])
    {
        printf("%c",c[i]);
        i++;
    }
    printf("\n");
}
void scanfc()
{
    char c2[10];
    char c3[10];
    scanf("%s%s",c2,c3);
    printf("c2=%s,c3=%s\n",c2,c3);
}
void scanfc1()
{
    char c[20];
    gets(c);//一次读取一行
    puts(c);//等价于printf("%s\n",c);
    printf("%s\n",c);
}
//***str系列字符串操作，需要引用<string.h>
int mystrlen(char c[])
{
    int len=0;
    while (c[len])
    {
        len++;
    }
    return len;
}

void array_text()
{
    char c[20]={0};
    char c1[20]="world";
    gets(c);
    puts(c);
    int len=strlen(c);//不算/0，得到字符串长度，不包括/0
    printf("len=%d\n",len);
    printf("mylen=%d\n",mystrlen(c));
    strcat(c,c1);
    puts(c);
    char d[20];
    strcpy(d,c);
    puts(d);
    printf("c?d=%d\n", strcmp(c,d));
    printf("c?c1=%d\n", strcmp(c,c1));//前大返回正，这里是1，后大返回负，这里是-1，一样返回0
}

void array_text1()
{
    scanfc1();
    int a[5]={1,2,3,4,5};
    print(a);
    print1(a,5);
    int i = 5;
    int j = 7;
    a[7]=10;//访问越界，将i值修改
    printf("i=%d\n",i);
    printf("j=%d\n",j);

    char c[6]="hello";
    printf("%s\n",c);
    char c1[5]="hello";
    printf("%s\n",c1);
    printc(c);
}