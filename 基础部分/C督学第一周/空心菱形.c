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
                printf("* ");
            for (int j = 0; j < 2*(flag-1)-1; ++j) {
                printf(" ");
            }
                flag==1||printf("*");
        } else{
            for (int k = 0; k < flag-6; ++k) {
                printf(" ");
            }
                printf("* ");
            for (int j = 0; j < 2*(9-flag)-1; ++j) {
                printf(" ");
            }
                flag==9||printf("*");
        }
        printf("\n");
        flag++;
    }
}