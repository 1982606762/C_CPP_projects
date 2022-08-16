//
// Created by XuanLang Z on 2021/7/23.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* mystrcpy(char*a,char*b){
    char* result=a;
    while(*b){
        *a=*b;
        a++;
        b++;
    }
    return result;
}

int mystrcmp(char*a,char*b){
    while(*a==*b){
        a++;
        b++;
        if(*a=='\0')
            return 0;
    }
    if(*a-*b)
        return 1;
    else
        return -1;
}
char* mystrcat(char*a,char*b){
    char*result=a;
    while(*a){
        a++;
    }
    while(*b){
        *a=*b;
        b++;
        a++;
    }
    *a='\0';
    return result;
}

int mystrlen(char*a){
    int len=0;
    while(*a!='\0'){
        a++;
        len++;
    }
    len=len+1;
    return len;
}

int main(){
    char arr[100];
    char c;
    memset(arr, -1, sizeof(arr));
    printf("字符串：\n");
    int i = 0;
    while ((c = getchar()) != EOF&&c !='\n') {
        arr[i] = c;
        i++;
    }
    for (int  j = i-1; j >=0; j--)
    {
        putchar(arr[j]);
    }
    printf("\n");
}