//
// Created by XuanLang Z on 2021/5/11.
//

#include<stdio.h>
#include<stdlib.h>

#define RIGHT 1
#define ERROR 0
#define STARTSYMBOL 'E'
int count = 0;//语法分析步骤统计
char VT[9] = {'(', 'p', '*', '/', '+', '-', ')', '#','i'};//终结符集合
char stack[100], a[300] = {'p', '+', 'p', '*','(', 'p', '/', 'i', ')', '-', 'i', '#'};//输入串
char matrix[8][8] =
        {'<', '<', '<', '<', '<', '<', '=', 'e',
         'e', 'e', '>', '>', '>', '>', '>', '>',
         '<', '<', '>', '>', '>', '>', '>', '>',
         '<', '<', '>', '>', '>', '>', '>', '>',
         '<', '<', '<', '<', '>', '>', '>', '>',
         '<', '<', '<', '<', '>', '>', '>', '>',
         'e', 'e', '>', '>', '>', '>', '>', '>',
         '<', '<', '<', '<', '<', '<', 'e', '='};//算符优先矩阵
int CharToInt(char c)//识别字符并返回类型，便于在矩阵中查找
{
    switch (c) {
        case '(':
            return 0;
        case 'i':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '+':
            return 4;
        case '-':
            return 5;
        case ')':
            return 6;
        case '#':
            return 7;
        default:
            return -1;
    }
}

int IsHigherThan(char a, char b)//查看算符优先矩阵判断字符a与b的优先级高低
{
    int i = CharToInt(a), j = CharToInt(b);
    if (matrix[i][j] == '>')
        return 1;
    else
        return 0;
}

int IsLowerThan(char a, char b) {
    int i = CharToInt(a), j = CharToInt(b);
    if (matrix[i][j] == '<')
        return 1;
    else
        return 0;
}

int IsEqualTo(char a, char b) {
    int i = CharToInt(a), j = CharToInt(b);
    if (matrix[i][j] == '=')
        return 1;
    else
        return 0;
}

char Reduce(int begin, int end, int len)//归约函数，返回归约后的非终结符号
{
    if (len == 1) {
        switch (stack[begin]) {
            case 'i':
                return 'F';//i归约为F
            default:
                return ' ';
        }
    } else if (len == 3) {
        switch (stack[begin + 1]) {
            case '*':
            case '/':
                return 'T';
            case '+':
            case '-':
                return 'E';
            case 'E':
            case 'T':
                return 'F';
            default:
                return ' ';
        }
    } else {
        printf("ERROR!\n");
        exit(0);
        return ' ';
    }
}

int IsVt(char c)//判断是否为终结符号
{
    for (int i = 0; i < 9; i++) {
        if (c == VT[i])
            return 1;
    }
    return 0;
}

int parser() {
    int i, k;
    char r, NewVn;
    i = 0;
    k = 0;
    stack[0] = '#';
    do {
        int j;
        r = a[i++];
        if (IsVt(stack[k]))
            j = k;
        else
            j = k - 1;
        while (IsHigherThan(stack[j], r)) {
            char q;
            do {
                q = stack[j];
                if (IsVt(stack[j - 1]))
                    j--;
                else
                    j -= 2;
            } while (!IsLowerThan(stack[j], q));
            NewVn = Reduce(j + 1, k, k - j);
            count++;//NewVn为归约出的非终结符
            printf("%d.", count);//记录归约的步骤
            for (int m = j + 1; m <= k; m++)//输出要被归约的字符串
                printf("%c", stack[m]);
            printf("归约为:%c\n", NewVn);
            k = j + 1;
            stack[k] = NewVn;
        }
        if ((IsLowerThan(stack[j], r)) || (IsEqualTo(stack[j], r))) {
            stack[++k] = r;
            count++;
            printf("%d.移进:%c\n", count, r);//移进r入栈
        } else
            return ERROR;
    } while (r != '#');
    return RIGHT;
}

int main() {
    switch (parser()) {
        case ERROR:
            printf("ERROR!\n");
            break;
        case RIGHT:
            printf("RIGHT!\n");
            break;
        default:
            break;
    }
}