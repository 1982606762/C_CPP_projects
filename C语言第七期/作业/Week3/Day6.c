//
// Created by XuanLang Z on 2021/8/3.
//
#include<stdlib.h>
#include<stdio.h>

int step(int n)
{
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else {
        return step(n - 1) + step(n - 2);
    }
}




int main()
{
    int n,m;
    while (scanf("%d", &n) != EOF) {
        m = step(n);
        printf("%d", m);
    }
    system("pause");
    return 0;
}
