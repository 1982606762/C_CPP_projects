//
// Created by XuanLang Z on 2021/3/5.
//
#include <stdio.h>
#include <stdlib.h>

void arr_print(int (*p)[4],int row)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < sizeof(*p)/sizeof(int) ;   ++j) {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}
void arr_pointer()
{
    int (*p)[4];//数组指针4字节
    //int *p[4];//指针数组16字节
    int a[3][4] = {1,2,3,4,4,5,6,6,7,7,8,9 };
    int b[4] = {1,2,3,4};
    p=a;
    p=&b;//此处需要取地址b，因为p是数组类型指针，需要直接代表数组
    arr_print(p,5);
}



int main()
{
    arr_pointer();
}
