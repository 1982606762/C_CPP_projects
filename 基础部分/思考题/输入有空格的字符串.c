//
// Created by XuanLang Z on 2021/1/25.
//
#include <stdio.h>
char str[100];

int main() {
    scanf("%[^\n]s", str);//中括号内是集合，非/n都输入，
    // 也可以比如[a-z]输入小写字母
    printf("%s\n", str);
    return 0;
}
