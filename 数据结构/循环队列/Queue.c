//
// Created by XuanLang Z on 2021/7/23.
//

#include "Queue.h"
void useQueue(){
    sqQueue q1;
    initQueue(&q1);
    EnQueue(&q1,1);
    EnQueue(&q1,2);
    EnQueue(&q1,3);
    EnQueue(&q1,4);
    EnQueue(&q1,5);
    printf("%d\n", DeQueue(&q1));
    printf("%d\n", DeQueue(&q1));
    printf("%d\n", DeQueue(&q1));
    printf("%d\n", DeQueue(&q1));
    printf("%d\n", DeQueue(&q1));

}
int main(){
    useQueue();
}