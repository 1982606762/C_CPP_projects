//
// Created by XuanLang Z on 2021/3/3.
//
#include <stdio.h>

int main()
{
    int i;
    char c;
    float f;
    scanf("%d %c%f",&i,&c,&f);

    printf("i=%d\nc=%c\nf=%f\n",i,c,f);
    c=getchar();
    printf("%c",c);
}
