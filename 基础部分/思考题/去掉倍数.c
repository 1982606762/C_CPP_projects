//
// Created by XuanLang Z on 2021/1/29.
//
//设计一个去掉倍数的程序,要求如下:
//首先读入两个数字 n 和 m,n 的大小不会超过 10,m 的大小都不会超过 10000;
//接下来读入 n 个各不相同的正整数,输出 1 到 m 中,有哪些数字无法被这 n 个正整数中任意的一个整除。
#include <stdio.h>

int check[10005] = {0};

int main() {
    int n, m, num;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        for (int j = num; j <= m; j += num) { check[j] = 1; }
    }
    for (int i = 1; i <= m; i++) {
        if (check[i] == 1) continue;
        printf("%d ", i);
    }
    return 0;
}