//
// Created by XuanLang Z on 2021/1/31.
//
#include <stdio.h>

int sum[10005] = {0};

void init_sum() {
    // 循环遍历 1 到 10000 的所有数字
    for (int i = 1; i <= 10000; i++) {
        // 用 j 循环枚举数字 i 可能的因数
        for (int j = 1; j <=
                        i; j++) {
            // 当 i%j 不等于 0 时,说明 j 不是 i 的因数
            if (i % j) continue;
            sum[i] += j;
        }
    }
    return;
}

int main() {
    init_sum();
    printf("hello world\n");
    return 0;
}