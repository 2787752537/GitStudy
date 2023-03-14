//
// Created by 86199 on 2023/3/14.
//

#include "pointer.h"
//***需要使用指针的两个场景，传递和便宜
void transfer(int *j)
{
    *j=5;
}
//***数组传递将会弱化为指针传递，只会传递数组首地址
void offset(int *p,int len)
{
    for(int i=0;i<len;i++,p++)
    {
        printf("a[%d]=%d\n",i,*p);
    }
    p--;
    for(int i=0;i<len;i++)
    {
        printf("a[%d]=%d\n",len-i,*(p-i));
    }
}

void *print_stack()
{
    char c1[10]="hello";//函数体内有效
    return c1;
}
void *print_malloc()
{
    char *c2=(char *)malloc(10);//整个进程有效
    strcpy(c2,"hello");
    return c2;
}

void pointer_text()
{
    char *c1=print_stack();
    char *c2=print_malloc();
    printf("c1 = %s\n",c1);
    printf("c2 = %s\n",c2);
    free(c2);


    int size=0;
    char *p;
    scanf("%d",&size);
    //malloc会返回一个void类型指针，需要强转为自己需要的
    //void *不能偏移，不能做加减，不强转无法使用
    p= (char *)malloc(size);
    fflush(stdin);
    gets(p);
    puts(p);
    //释放空间,必须与申请时的地址一样，否则无法归还
    free(p);

    int i=10;
    printf("before passing i is equal to %d\n",i);
    transfer(&i);
    printf("After passing i is equal to %d\n",i);

    int a[ARRAY_LEN]={1,2,3,4,5};
    offset(a,ARRAY_LEN);
}