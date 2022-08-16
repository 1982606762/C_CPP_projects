//
// Created by XuanLang Z on 2021/1/30.
//
#include <stdio.h>
int fib1(int n){
    int a1=1,a2=1,res=0;
    for (int i = 0; i < n-2; ++i) {
        res=a1+a2;
        a1=a2;
        a2=res;
    }
}

int fib2(int n){
    if (n==1||n==2){return 1;}
    else{
        return fib2(n-2)+fib2(n-1);
    }
}

int main(){
    int res,n;
    scanf("%d",&n);
    res = fib2(n);
    printf("%d",res);
}