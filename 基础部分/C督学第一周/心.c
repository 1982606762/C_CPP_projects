#include<stdio.h>
#include<stdlib.h>

int main()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int j = 0; j < 3-i; ++j) {
                printf(" ");
            }
            for (int j = 0; j < 2+i; ++j) {
                printf("* ");
            }
            for (int j = 0; j < 2-i; ++j) {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < i+1; ++j) {
            printf(" ");
        }
        for (int j = 0; j < 9 - i; ++j) {
            printf("* ");
        }
        for (int j = 0; j < i; ++j) {
            printf(" ");
        }
        printf("\n");
    }
}