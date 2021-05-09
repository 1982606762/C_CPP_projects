//
// Created by XuanLang Z on 2021/2/28.
//

#include <stdio.h>

int main()
{
    int flag = 1;

    for (int i = 0; i < 9; ++i) {

        flag==5||printf(" ");

        if (flag<=5){
            for (int k = 0; k < 4-flag; ++k) {
                printf(" ");
            }
            for (int j = 0; j < flag; ++j) {
                printf("* ");
            }
        } else{
            for (int k = 0; k < flag-6; ++k) {
                printf(" ");
            }
            for (int j = 10; j > flag; --j) {
                printf("* ");
            }
        }
        printf("\n");
        flag++;
    }
}