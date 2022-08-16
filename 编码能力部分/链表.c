//
// Created by XuanLang Z on 2021/2/14.
//
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *head, int ind, struct Node *a) {
    struct Node ret, *p = &ret;
    ret.next = head;
    // 从【虚拟头节点】开始向后走 ind 步
    while (ind--) p = p->next;
    // 完成节点的插入操作
    a->next = p->next;
    p->next = a;
    // 返回真正的链表头节点地址
    return ret.next;
}

struct Node *erase(struct Node *head, int ind){

}