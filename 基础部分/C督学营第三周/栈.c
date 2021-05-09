//
// Created by XuanLang Z on 2021/3/18.
//

#include "stack.h"

void init_stack(pstack s)
{
    memset(s,0,sizeof (stack));
}

void push(pstack s,int num)
{
    sNode tag = (sNode)calloc(1,sizeof(node));
    tag->num=num;
    tag->next=NULL;
    if (!s->head)
    {
        s->head=tag;
    } else{
        tag->next=s->head;
        s->head=tag;
    }
    s->size++;
}

void pop(pstack s)
{
    sNode ss=s->head;
    if (!s->size)
    {
        printf("empty");
        return;
    }
    s->head=s->head->next;
    s->size--;
    free(ss);
}

int main()
{
    stack stack1;
    init_stack(&stack1);
    push(&stack1,2);
    push(&stack1,3);
    pop(&stack1);
}