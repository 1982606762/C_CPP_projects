//
// Created by XuanLang Z on 2021/3/18.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tag
{
    int num;
    struct tag *next;
}node,*sNode;

typedef struct
{
    sNode head;
    int size;
}stack,*pstack;

void init_stack(pstack s);
void pop(pstack s);
void push(pstack s,int i);
