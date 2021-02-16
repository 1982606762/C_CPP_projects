//
// Created by XuanLang Z on 2021/1/31.
//
#include <stdio.h>

// 定义一个交换两个变量值的宏
define swap(a, b) {
    \
 __typeof(a) _t = a; \
 a = b, b = _t; \

}

// 实现大整数加法 a + b 的结果,存放在 c 中
void plus_big_integer(int *a, int *b, int *c) {
    // 让 a 指向位数较长的那个数字
    if (a[0] < b[0]) swap(a, b);
    // 大整数 c 的位数以 a 的位数为基准
    c[0] = a[0];
    // 循环模拟按位做加法
    for (int i = 1; i <= a[0]; i++) {
        if (i <= b[0])
            c[i] = a[i] + b[i];
        else c[i] = a[i];
    }
    // 处理每一位的进位过程
    for (int i = 1; i <= c[0]; i++) {
        if (c[i] < 10) continue;
        // 判断是不是最高位产生了进位
        // 如果是最高位产生进位,就进行初始化
        if (i == c[0]) c[++c[0]] = 0;
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    return;
}

int main(){

}