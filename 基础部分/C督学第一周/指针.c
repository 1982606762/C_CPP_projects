//
// Created by XuanLang Z on 2021/3/4.
//
#include <stdio.h>

void change(int *i)//j=&i
{
    *i=5;
}

void trans(){
    int i=10;
    printf("%d\n",i);
    change(&i);
    printf("%d",i);
}
int main()
{
    trans();
}

