//
// Created by XuanLang Z on 2021/3/12.
//


#include <stdlib.h>
#include <stdio.h>


typedef struct student{
    int id;
    float score;
    struct student *next;
}stu,*pstu;

void list_print(pstu head)
{
    while (head)
    {
        printf("%3d",head->id);
        printf("  %3.2f\n",head->score);
        head=head->next;
    }
}
//头插法
void head_insert(pstu *head,pstu *tail,int val)
{
    pstu temp = (pstu)calloc(sizeof (pstu),1);//申请大小是pstu*1
    temp->id = val;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head=temp;
        *tail=temp;
    } else{
        temp->next=*head;
        *head = temp;
    }
}

//尾插法
void tail_insert(pstu *head,pstu *tail,int val)
{
    pstu temp = (pstu)calloc(sizeof (pstu),1);//申请大小是pstu*1
    temp->next=NULL;
    temp->id=val;
    if (*head==NULL)
    {
        *head = temp;
        *tail = temp;
    } else{
        (*tail)->next = temp;//箭头函数优先级高
        (*tail) = temp;
    }
}

//有序插入
void sort_insert(pstu *head,pstu *tail,int val)
{
    pstu temp = (pstu)calloc(sizeof (pstu),1);
    pstu pcur = *head;
    pstu ppre = pcur;
    temp->next=NULL;
    temp->id = val;
    if (*head == NULL)
    {
        *head = temp;
        *tail = temp;
    } else if (pcur->id>val){
            temp->next = pcur;
            *head = temp;
        } else{
            while (pcur)
            {
                if (pcur->id>val)
                {
                    ppre->next=temp;
                    temp->next=pcur;
                    break;
                }
                ppre=pcur;
                pcur=pcur->next;
            }
        if (pcur==NULL)
        {
            ppre->next = temp;
            *tail = temp;
        }
        }
}

//删除
void delete_list(pstu* pphead,pstu* pptail,int del_val)
{
    pstu pcur=*pphead;
    pstu ppre=pcur;
    if(NULL==pcur)
    {
        printf("list is empty\n");
        return;
    }
    if(del_val==pcur->id)//删除的是头部
    {
        *pphead=pcur->next;
        if(NULL==*pphead)
        {
            *pptail=NULL;//删除以后链表为空，所以修改尾指针
        }
    }else{
        //删除的是尾部或中间
        while(pcur)
        {
            if(pcur->id==del_val)
            {
                ppre->next=pcur->next;
                break;
            }
            ppre=pcur;
            pcur=pcur->next;
        }

    }
    if(NULL==pcur)
    {
        printf("this val is not in list\n");
        return;
    }
    if(ppre->next==NULL)//删除的是链表最后一个节点，所以修改尾指针
    {
        *pptail=ppre;
    }
    free(pcur);
    pcur=NULL;
}

//修改
void modify_list(pstu phead,int val,float score)
{
    while (phead)
    {
        if (phead->id==val)
        {
            phead->score = score;
            break;
        }
        phead = phead->next;
    }
    if (phead==NULL)
    {
        printf("no id");
    }
}