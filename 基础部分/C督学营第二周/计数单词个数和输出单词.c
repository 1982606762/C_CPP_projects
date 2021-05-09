//
// Created by XuanLang Z on 2021/3/13.
//
#include <stdio.h>
#include <string.h>
int count_num(char*a)
{
    char*p=a;
    int res=0;
    for (int i = 0; i < 100; ++i) {
        if (p[i]>='a'&&p[i]<='z'&&(p[i+1]==' '||p[i+1]=='\0'))res++;
    }
    return res;
}

void print_num(char*a)
{
    int i=0;
    while (a[i]!='\0'&&i<100){
        if (a[i] != ' ')
            a[i + 1] != ' ' ? printf("%c", a[i]) : printf("%c\n", a[i]);
        i++;    }
}

void reverse_word(char*a)
{
    for (int i = strlen(a) - 1; i >= 0; i--) {
        if (a[i] != ' ' && a[i - 1] == ' ')
            for (int j = i; a[j] != ' ' && a[j] != '\0'; j++) printf("%c", a[j]);
        if (a[i] == ' ' || i == 0) printf("%c", a[i]);
    }
}
int main()
{
    char a[100];
    gets(a);
    int i = count_num(a);
    print_num(a);
    printf("%d",i);
    reverse_word(a);
}
