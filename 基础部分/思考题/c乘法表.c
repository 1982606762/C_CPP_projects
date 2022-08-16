//
// Created by XuanLang Z on 2021/1/25.
//

#include <stdio.h>

int main() {
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= i; j++) {
            j == 1 || printf("\t");
            printf("%d * %d = %d", j, i, i * j);
        }
        printf("\n");
    }
    return 0;
}