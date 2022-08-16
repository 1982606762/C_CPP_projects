//
// Created by XuanLang Z on 2021/3/10.
//
#include <stdio.h>
#include <string.h>
char *mystrcpy(char *p,char *q)
{
    char *tmp = p;
    while((*p++ = *q++)!= '\0');

    return tmp;
}

int mystrcmp(char*a,char*b)
{
    while (*a==*b)
    {
        if (*a=='\0')return 0;
        a++;b++;
    }
    return *a-*b;
}

char *mystrcat(char *a, char *b)
{
    char *p;
    for(p=a;*p!='\0';p++);
    for(;*b!='\0';p++,b++)
        *p=*b;
    *p='\0';
    return a;
}

int mystrlen(char*a)
{
    int res=0;
    char *p=a;
    for (; *p!='\0'; p++) {
        res+=1;
    }
    return res;
}
int main()
{
    char a[]="hello",b[]="helq";
    mystrcpy(a,"hello");
    printf("%d",mystrcmp(a,b));
    mystrcat(a,b);
    puts(a);
    int aa = mystrlen(a);
    printf("%d",aa);
}

