//
// Created by XuanLang Z on 2021/3/11.
//
#include "./list.c"

int main(){
    pstu Phead = NULL,ptail = NULL;
    int val;
    float score;
    for (int i = 0; i < 5; ++i) {
        scanf("%d",&val);
        sort_insert(&Phead,&ptail,val);
//        head_insert(&Phead,&ptail,val);
//        tail_insert(&Phead,&ptail,val);
    }
    list_print(Phead);
    for (int i = 0; i < 3; ++i) {
        scanf("%d",&val);
        delete_list(&Phead,&ptail,val);
        list_print(Phead);
    }
//    for (int i = 0; i < 3; ++i) {
//        scanf("%d %f",&val,&score);
//        modify_list(Phead,val,score);
//        list_print(Phead);
//    }
    return 0;
}