//
// Created by XuanLang Z on 2021/7/12.
//

#include <stdio.h>
void print1() {
    int i, j, n,k;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4 - i; j++) {
            printf(" ");
        }
        for (n = 0; n < 2 * i+1&&i!=0; n++) {
            if (n % 2 == 0) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        for (k = 0; k < 5 - i&&i!=0; k++) {
            printf(" ");
        }
        for (j = 0; j < 4 - i; j++) {
            printf(" ");
        }
        for (n = 0; n < 2 * i + 1 && i != 0; n++) {
            if (n % 2 == 0) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void print2() {
    int i, j, n;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < i+1; j++) {
            printf(" ");
        }
        for (n = 0; n < 18-2 * i; n++) {
            if (n % 2 == 0) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
int main()
{
    print1();
}