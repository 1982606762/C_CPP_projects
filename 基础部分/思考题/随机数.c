//
// Created by XuanLang Z on 2021/1/29.
//
#include <stdio.h>

int main() {
    int n = 5;
    for (int i = 1; i <= 100; i++) {
        printf("%2d ", n);
        if (i % 10 == 0) printf("\n");
        n = (n * 3) % 101;
    }
    return 0;
}
