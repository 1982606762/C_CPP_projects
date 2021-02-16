//
// Created by XuanLang Z on 2021/1/17.
//
#include<stdio.h>
#include<stdlib.h>

void my_scanf(char *str, int *ret) {
    int num = 0, flag = 0;
    if (str[0] == '-') str += 1, flag = 1;
    for (int i = 0; str[i]; i++) { num = num * 10 + (str[i] - '0'); }
    if (flag == 1) num = -num;
    *ret = num;
}

int main() {
    char str[1000];
    int n = 65;
    scanf("%s", str);
    my_scanf(str, &n);
    printf("n = %d\n", n);
    return 0;
}
