//
// Created by XuanLang Z on 2021/3/5.
//

#include <stdlib.h>
#include <stdio.h>


void b(){
    printf("qwe");
}

void a(void(*p)())
{
    p();
}

void func_pointer()
{
    void (*p)();//定义一个函数指针
    p=b;
    a(p);
}
void change(int*p,int**q)
{
    *q=p;
}
int main()
{
    //func_pointer();
    int i;
    while (scanf("%d",&i)!=EOF)
    {
        printf("%d\n",i);
    }
}