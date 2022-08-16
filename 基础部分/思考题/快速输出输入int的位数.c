//
// Created by XuanLang Z on 2021/1/25.
//
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("has %d digits\n", printf("%d",n));
    // 先运行后边的printf输出数字，返回值是数字的位数然后再运行前边的输出
    char output[50];
    int ret = sprintf(output, "%d", n);
    printf("%d\n", ret); // 无多余输出
    return 0;
}
