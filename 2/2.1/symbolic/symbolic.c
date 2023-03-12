//
// Created by 86199 on 2023/3/12.
//
#include "symbolic.h"
int circle_area(int r){
    int s=r*r*PI;
    return s;
}

void character_string_type(){
    int r = 3;
    printf("%c size is %d\n",'r',sizeof(r));
    printf("The area of a circle with radius %d is: ",r);
    printf("%d\n",circle_area(r));
    printf("The number corresponding to %c is %d\n ",'A','A');
    printf("The number corresponding to %c is %d\n ",'a','a');
    printf("The number corresponding to %s is %d\n ","a - A",'a'-'A');//字符a和A对应的整数
    printf("%s size is %d\n","\"a\"",sizeof("a"));//字符串后面有\0
}

void use_of_printf(){
    printf("id=%d,sorce=%f\n",133,90.34);
    printf("id=%d,sorce=%f\n",13366,96.3432);
    printf("id=%5d,sorce=%5.2f\n",133,132290.34);//格式话输出
    printf("id=%-5d,sorce=%5.2f\n",133,132290.34);
    printf("id=%5d,sorce=%9.2f\n",13366,96.3432);
}

void cast(){
    printf("5/2 is %f\n",5/2);//注意运算的时候强制类型转换
    printf("5/2 is %f\n",(float)(5/2));//注意运算的时候强制类型转换
    printf("(float)5/2 is %f\n",(float)5/2);
    printf("5.0/2 is %f\n",5.0/2);
}
//char* convert_to_binary(int num){
//    char* s="";
//    int temp=0;
//    while(num!=0){
//        temp = num%2;
//        if(temp){
//            s=strcat("1",s);
//        }
//        else
//        {
//            s=strcat("0",s);
//        }
//        num=num/2;
//    }
//    return s;
//}

void Conversion(){
//    printf("The binary of %d is %s\n",123,convert_to_binary(123));
    int i=123;//八进制前加0//十六进制前加0x
    printf("The octal of %d is %o\n",123,i);
    printf("The hexadecimal of %d is %x\n",123,123);
}

void use_of_scanf(){
    int i =0;
    char c = 'a';
    float f;
    scanf("%d",&i);
    printf("%d\n",i);//整形和浮点型会忽略\n和空格，字符型不忽略需要手动清空。
    fflush(stdin);//清空标准输入缓冲区
    scanf("%c",&c);
    printf("%c\n",c);

    scanf("%d %c%f",&i,&c,&f);//ret表示读取成功的个数，%c前面加空格
    printf("%d,%c,%f",i,c,f);
}