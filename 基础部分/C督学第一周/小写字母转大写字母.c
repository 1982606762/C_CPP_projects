//
// Created by XuanLang Z on 2021/3/1.
//
#include <stdio.h>
#include <string.h>

int main() {
    char c[100];
    scanf("%s",c);
    for (int i = 0; c[i]!='\0'; ++i) {
        if (c[i]>='a'&&c[i]<='z')
        {
            c[i]-=32;
        }
    }
    for (int i = 0; c[i]!='\0'; ++i) {
        printf("%c",c[i]);
    }
        return 0;
}
