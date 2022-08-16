//
// Created by XuanLang Z on 2021/7/12.
//
//1.打印九九乘法表
//2.打印如下图形
#include <stdio.h>

void chengfabiao(){
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j!=1)
            {
                printf(" ");
            }
            printf("%d*%d=%d", j, i, i * j);
        }
        printf("\n");
    }
}

void shixinlingxing(){
    for (int i = 1; i <= 5;i++)
    {
        for (int j = 5 - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            if (j != 1)
            {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i <= 5 - 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 5 - i; j++)
        {
            if (j != 1)
            {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
}

int kongxinlingxing(){
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 5 - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            if (j != 1)
            {
                printf(" ");
            }
            if (j == 1 || j == i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 1; i <= 5 - 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 5 - i; j++)
        {
            if (j != 1)
            {
                printf(" ");
            }
            if (j == 1 || j == 5 - i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
int main()
{
    chengfabiao();
    shixinlingxing();
    kongxinlingxing();
    return 0;
}