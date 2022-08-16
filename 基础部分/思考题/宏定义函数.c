//
// Created by XuanLang Z on 2021/1/25.
//
//请你完善下面代码中的 MAX 宏,
// MAX 宏的作用,就是接受两个元素,选择出两个元素中的最大值。
// 完善以后的 MAX 宏,输出需要与如下给出的输出样例一致,
// 注意,只能修改 MAX 宏的定义内容,不可以修改主函数中的内容。
#include <stdio.h>
#define P(item) printf("%s = %d\n", #item, item);
#define MAX(a, b) ({ \
__typeof(a) _a=(a),_b=(b); \
_a>_b?_a:_b;                     \
})

int main() {
    int a = 6;
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    P(MAX(a++, 5));
    P(a);
    return 0;
}