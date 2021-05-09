//
// Created by XuanLang Z on 2021/3/5.
//
#include <stdio.h>

void use_const()
{
    const char* c1;
    char arr[10] = "hello";
    arr[0] = 'H';
    c1 = arr;
    //c1[0]='h';不可以更改
}

void use_const1()
{
    char arr[10] = "hello";
    char* const c1=arr;//必须在定义的时候初始化，之后指向的对象不能更改
    c1[0]='H';//可以改变内部的值

    //c1[0]='h';不可以更改
}
int main()
{
    use_const();
}
