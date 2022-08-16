//
// Created by XuanLang Z on 2021/7/23.
//

#ifndef C_CPP_PROJECTS_QUEUE_H
#define C_CPP_PROJECTS_QUEUE_H

#endif //C_CPP_PROJECTS_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxsize 5
typedef int ElemType;

typedef struct {
    ElemType data[Maxsize];
    int rear,front;
}sqQueue;

void initQueue(sqQueue* queue){
    queue->front = queue->rear = 0;
}

void EnQueue(sqQueue* queue,ElemType val){
    if ((queue->rear+1)%Maxsize==queue->front){ printf("满\n"); return;}
    queue->data[queue->rear]=val;
    queue->rear=(queue->rear+1)%Maxsize;
}

int DeQueue(sqQueue* queue){
    if (queue->rear==queue->front){ printf("空\n");return 0;}
    ElemType elem = queue->data[queue->front];
    queue->front = (queue->front+1)%Maxsize;
    return elem;
}