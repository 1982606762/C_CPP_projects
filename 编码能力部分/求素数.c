//
// Created by XuanLang Z on 2021/1/30.
//
#include <stdio.h>

int prime[10000] = {0};

void init_prime() {
    for (int i = 2; i * i < 10000; ++i) {
        if (prime[i])continue;
        else {
            for (int j = i * 2; j < 10000; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int main() {
    init_prime();
    int sum = 0;
    for (int i = 2; i <= 10000; i++) {
        sum += i * (1 - prime[i]); // 素数累加
    }
    printf("%d\n", sum);
    return 0;
}