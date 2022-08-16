//
// Created by XuanLang Z on 2021/3/19.
//

#include "queue.h"

void initqueue(sqQueue *q)
{
    q->front=q->rear=0;
}

void enqueue(sqQueue* q,int val)
{
    if( (q->rear+1)%Maxsize==q->front){
        printf("full\n");
        return;
    }
    q->data[q->rear]=val;
    q->rear=(q->rear+1)%Maxsize;
}

int dequeue(sqQueue* q)
{
    if (q->front==q->rear)
    {
        printf("empty");
        return 0;
    }
    int res;
    res = q->data[q->front];
    q->front=(q->front+1)%Maxsize;
    return res;
}

int main()
{
    sqQueue queue;
    initqueue(&queue);
    enqueue(&queue,1);
    enqueue(&queue,2);
    enqueue(&queue,3);
    enqueue(&queue,4);
    printf("%d",dequeue(&queue));
    printf("%d",dequeue(&queue));
    printf("%d",dequeue(&queue));
    printf("%d",dequeue(&queue));

    return 0;
}