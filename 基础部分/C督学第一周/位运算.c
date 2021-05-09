//
// Created by XuanLang Z on 2021/3/1.
//

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("按位与：%d，按位或：%d，按位异或：%d，a按位取反：%d,b按位取反：%d\n",a&b,a|b,a^b,~a,~b);
    printf("a左移1：%d,a右移1:%d",a<<1,a>>1);
}