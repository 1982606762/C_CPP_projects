//
// Created by XuanLang Z on 2021/1/16.
//

#include <stdio.h>
int main()
{
    int num = 0x61626364;
    int *pp = &num;
    char *qq = (char*)&num;
    //printf("%x %c",*pp,*qq);
    int a, *p = &a;
    char *q = &a;
    printf("%p %p\n", p, q);
    printf("%p %p", p + 1, q + 1);
}