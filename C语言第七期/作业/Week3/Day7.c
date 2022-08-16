//
// Created by XuanLang Z on 2021/8/3.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int elemtype;
typedef struct list {
    elemtype data;
    struct list* next;
}LNode,*linklist;
void list_head_insert(linklist *phead,linklist *ptail,int val) {
    linklist pnew = (linklist)calloc(sizeof(LNode),1);
    pnew->data = val;
    if (NULL == *phead) {
        *phead = pnew;
        *ptail = pnew;
    }
    else {
        pnew->next = *phead;
        *phead = pnew;
    }
}
void list_tail_insert(linklist* phead, linklist* ptail, int num) {
    linklist pnew = (linklist)calloc(sizeof(LNode),1);
    pnew->data = num;
    //pnew->next = NULL;
    if (NULL == *phead) {
        *phead = pnew;
        *ptail = pnew;
    }
    else {
        (*ptail)->next = pnew;
        *ptail = pnew;
    }
}
void list_sort_insert(linklist* phead, LNode** ptail, int num) {
    linklist pnew = (linklist)calloc(sizeof(LNode), 1);
    pnew->data = num;
    linklist pcur = *phead;
    linklist ppre = *phead;
    if (NULL== *phead) {
        *phead = pnew;
        *ptail = pnew;
    }
    else if (num < pcur->data)//插到头部
        {
        pnew->next = pcur;
        *phead = pnew;
        }
    else {//插入中部
        while (pcur) {
            if (num < pcur->data) {
                ppre->next = pnew;
                pnew->next = pcur;
                break;
            }
            ppre = pcur;//大哥先让小弟记住自己的位置
            pcur = pcur->next;
        }
        if (NULL == pcur) {
            (*ptail)->next = pnew;
            *ptail = pnew;
        }
    }
}
void list_print(linklist phead) {
    while (phead) {
        printf("%3d", phead->data);
        phead = phead->next;
    }
    printf("\n");
}
void list_delete(linklist* phead, LNode** ptail, int num) {
    linklist p=*phead,pre=*phead;
    if(num == p->data) {
        (*phead )= p->next;
        free(p);
        p = NULL;
    }
    else {
        while (p) {
            if (p->data == num) {
                pre->next = p->next;
                free(p);
                break;
            }
            pre = p;
            p = p->next;
        }
        if (NULL == p) {
            printf("this val is not in list\n");
        }
        p = NULL;
    }

}
int main() {
    //头插法
    linklist phead = NULL, ptail = NULL;
    int val;
    while (scanf("%d", &val) != EOF) {
        list_head_insert(&phead, &ptail, val);
    }
    list_print(phead);
//    //尾插法
//    int num;
//    while (scanf("%d", &num) != EOF) {
//        list_tail_insert(&phead, &ptail, num);
//    }
//    list_print(phead);
//    //有序插入
//    int num;
//    linklist phead = NULL, ptail = NULL;
//    while (scanf("%d", &num) != EOF) {
//        list_sort_insert(&phead, &ptail, num);
//    }
//    list_print(phead);
//    printf("----------------------\n");
//    //删除
//    list_delete(&phead, &ptail, 2);
//    list_print(phead);
    return 0;
}