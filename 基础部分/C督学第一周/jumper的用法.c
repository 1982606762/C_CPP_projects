//
// Created by XuanLang Z on 2021/3/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>


void b(jmp_buf envbuf){
    printf("bbb");
    longjmp(envbuf,5);
}

void a(jmp_buf envbuf){
    printf("aaa");
    b(envbuf);
    printf("abababab");
}

int main()
{
    int i=0;
    jmp_buf envbuf;
    i=setjmp(envbuf);
    if (i==0){
        a(envbuf);

    }
}