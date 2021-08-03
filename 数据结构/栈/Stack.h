//
// Created by XuanLang Z on 2021/7/23.
//

#ifndef C_CPP_PROJECTS_STACK_H
#define C_CPP_PROJECTS_STACK_H

#endif //C_CPP_PROJECTS_STACK_H
#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct tag{
    ElemType m_val;
    struct tag *next;
}Node *pNode;

//14到17行这么定义之后，这个结构体既可以用struct tag xxx;定义，也可以用 node xxx;定义
//pNode就是Node*的别名

typedef struct{
    pNode phead;
    int size;
}Stack,*pStack;

