//
// Created by XuanLang Z on 2021/3/11.
//

#include <stdio.h>
#include <stdlib.h>
//定义结构体把小字节放在最后
typedef struct student{
    int id;
    char name[20];
}stu,*p;//stu是别名

int main()
{
    struct student s={10,"zhao"};
    //结构体指针
    struct student*p;
    p=&s;
    printf("%d %s \n",p->id,p->name);
    int num;
    num=p->id++;//这里加的是p的id
    printf("%d %d\n",num,p->id);
    num=p++->id;//加一个结构体的大小，先num=p;然后p++然后p->id;
    printf("%d %d\n",num,p->id);
}