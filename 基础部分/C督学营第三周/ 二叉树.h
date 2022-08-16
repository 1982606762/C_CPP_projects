//
// Created by XuanLang Z on 2021/3/20.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    char c;
    struct node *left;
    struct node *right;
}tnode,*pNode;

void pre_order(pNode tree);
void mid_order(pNode tree);
void lat_order(pNode tree);


