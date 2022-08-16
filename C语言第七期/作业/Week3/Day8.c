//
// Created by XuanLang Z on 2021/8/3.
//

#define _CRT_SECURE_NO_WARNINGS
#define Maxsize 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//用链表实现栈
typedef struct Link_List {
    int num;
    struct Link_List *LNext;
}LNode, *pLNode;

typedef struct Stack {
    pLNode Shead;//栈顶指针
    int size;//栈的大小
}stack,*pstack;
//初始化栈
void init_stack(pstack s) {
    memset(s, 0, sizeof(stack));
}
//把元素压栈
void push(pstack s,int val) {
    pLNode newnode = (pLNode)calloc(1, sizeof(LNode));
    newnode->num = val;
    if (s->Shead == NULL) {
        s->Shead = newnode;
        s->size++;
    }
    else {
        newnode->LNext = s->Shead;
        s->Shead = newnode;
        s->size++;
    }
}
//元素弹栈
int pop(pstack s) {
    pLNode p;
    if (s->Shead != NULL) {
        p = s->Shead;
        s->Shead = s->Shead->LNext;
        s->size--;
        return p->num;
        free(p);
    }
    else {
        printf("empty\n");
        return -1;
    }
}
//取栈顶元素
int top(pstack s) {
    return s->Shead->num;
}
//判断栈是否为空
int empty(pstack s) {
    return !s->size;
}

void use_stack() {
    stack s;
    int val;
    init_stack(&s);
    if (empty(&s)) {
        printf("当前栈为空,请输入数据\n");
    }
    while (scanf("%d", &val) != EOF) {
        push(&s, val);
    }
    val = s.size;
    for (int i = 0; i < val; i++) {
        printf("%d", pop(&s));
    }
    pop(&s);
}
int main()
{
    use_stack();
    return 0;
}