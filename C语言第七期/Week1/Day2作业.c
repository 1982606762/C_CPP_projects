//
// Created by XuanLang Z on 2021/7/12.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

//十进制到二进制
void intobinary() {
    printf("输入十进制数，将输出二进制");
    int num;
    scanf("%d", &num);
    int flag = 0;
    char res[200];
    while (num) {
        res[flag++] = num % 2 ? '1' : '0';
        num /= 2;
    }
    for (int i = flag - 1; res[i] != '\0'; --i) {
        printf("%c", res[i]);
    }
}

//二进制到十进制
void intodecimal() {
    printf("输入二进制数，将输出十进制");
    int flag = 0, num = 0;
    char binary[100];
    scanf("%s", binary);
    for (int i = strlen(binary)-1; i >= 0; --i) {
        num += (binary[i] - '0') * pow(2, flag++);
    }
    printf("%d", num);
}

//十进制到十六进制
void tohex() {
    printf("输入十进制数，将输出十六进制");
    int num, flag = 0;
    char hex[100];
    scanf("%d", &num);
    while (num) {
        hex[flag++] = num % 16 > 9 ? num % 16 - 10 + 'A' : num % 16 + '0';
        num /= 16;
    }
    hex[flag++] = 'x';
    hex[flag++] = '0';
    for (int i = flag - 1; i >= 0; --i) {
        printf("%c", hex[i]);
    }

}

//十六进制到十进制
void hex_to_dec() {
    printf("输入十六进制数，将输出十进制");
    char s[50];
    scanf("%s", s);
    int t = strlen(s);
    long sum = 0;
    for (int i = 0; i < t; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (int) (s[i] - 'A') + 10 + '0';
        sum += ((s[i] - '0') * (pow(16, t - 1 - i)));
    }
    printf("%ld\n", sum);
}

void 小写() {
    int ret;
    char lit, upp;
    while (fflush(stdin), (ret = scanf("%c", &lit)) != EOF) {
        upp = lit + 'A' - 'a';
        printf("THE UPPER is %c\n", upp);
    }
}

int main() {
//    小写();
    intobinary();
    intodecimal();
    hex_to_dec();
    tohex();

}