//
// Created by XuanLang Z on 2021/7/24.
//

#ifndef C_CPP_PROJECTS_TREE_H
#define C_CPP_PROJECTS_TREE_H

#endif //C_CPP_PROJECTS_TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct tag{
    char c;
    struct tag *pleft;
    struct tag *pright;
}Node,*pNode;

//利用队列层次建树
typedef struct queue{
    pNode insert_pos;
    struct queue *pNext;
}Queue,pQueue;

pNode initTree(){
    pNode root = NULL;
    char c[10] = "ABCDEFGHIJ";
    pNode p[10];
    int j;
    for (int i = 0; i < 10; ++i) {
//在内存的动态存储区中分配num个长度为size的连续空间，函数返回一个指向分配起始地址的指针；如果分配不成功，返回NULL。
//calloc在动态分配完内存后，自动初始化该内存空间为零，而malloc不做初始化，分配到的空间中的数据是随机数据。
        p[i] = (pNode) calloc(1,sizeof (Node));
        p[i]->c = c[i];
    }
    for (int i = 0; i < 10; ++i) {
        if (root==NULL){
            root = p[i];
            j=0;
        } else{
            if (p[j]->pleft==NULL){
                p[j]->pleft = p[i];
            } else if (p[j]->pright == NULL){
                p[j]->pright = p[i];
                j++;
            }
        }
    }
    return root;
}

void preorder(pNode root)
{
    if (root){
        putchar(root->c);
        preorder(root->pleft);
        preorder(root->pright);
    }
}

void inorder(pNode root)
{
    if (root)
    {
        inorder(root->pleft);
        putchar(root->c);
        inorder(root->pright);
    }
}

void endorder(pNode root)
{
    if (root)
    {
        endorder(root->pleft);
        endorder(root->pright);
        putchar(root->c);
    }
}