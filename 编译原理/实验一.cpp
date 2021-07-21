#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define DIGIT 1
#define POINT 2
#define OTHER 3
#define POWER 4
#define PLUS 5
#define MINUS 6
#define UCON 7

#define LT 8
#define LE 9
#define EQ 10
#define NE 11
#define GT 12
#define GE 13
#define IS 14
#define MI 15
#define MU 16
#define DI 17
#define ID 18
#define BEGIN 19
#define END 20
#define IF 21
#define THEN 22
#define ELSE 23
#define L 24
#define R 25

char TOKEN[20];

#define ClassOther 200
#define EndState -1
int w, n, p, e, d;
int Class;  //Used to indicate class of the word
int ICON;
double FCON;
static int CurrentState;
int row = 1, col = 0;//记录出错字符的位置，row为行，col为列。
int GetChar(FILE *fp)//文件中获取字符，分析之后返回类型
{
    int c;
    c = fgetc(fp);
    col++;
    if (isdigit(c)) {
        d = c - '0';
        return DIGIT;
    }
    if (c == '.')
        return POINT;
    if (c == 'E' || c == 'e')
        return POWER;
    if (c == '+')
        return PLUS;
    if (c == '-')
        return MINUS;
    return OTHER;
}

int EXCUTE(int state, int symbol)//识别无符号数
{
    switch (state) {
        case 0:
            switch (symbol) {
                case DIGIT:
                    n = 0;
                    p = 0;
                    e = 1;
                    w = d;
                    CurrentState = 1;
                    Class = UCON;
                    break;
                case POINT:
                    w = 0;
                    n = 0;
                    p = 0;
                    e = 1;
                    CurrentState = 3;
                    Class = UCON;
                    break;
                default:
                    Class = ClassOther;
                    CurrentState = EndState;
            }
            break;
        case 1:
            switch (symbol) {
                case DIGIT:
                    w = w * 10 + d;
                    break;  //CurrentState=1
                case POINT:
                    CurrentState = 2;
                    break;
                case POWER:
                    CurrentState = 4;
                    break;
                default:
                    ICON = w;
                    CurrentState = EndState;
            }
            break;
        case 2:
            switch (symbol) {
                case DIGIT:
                    n++;
                    w = w * 10 + d;
                    break;
                case POWER:
                    CurrentState = 4;
                    break;
                default:
                    FCON = w * pow(10, e * p - n);
                    CurrentState = EndState;
            }
            break;
        case 3:
            switch (symbol) {
                case DIGIT:
                    n++;
                    w = w * 10 + d;
                    CurrentState = 2;
                    break;
                default:
                    printf("Error!\n");
                    CurrentState = EndState;
            }
            break;
        case 4:
            switch (symbol) {
                case DIGIT:
                    p = p * 10 + d;
                    CurrentState = 6;
                    break;
                case MINUS:
                    e = -1;
                    CurrentState = 5;
                    break;
                case PLUS:
                    CurrentState = 5;
                    break;
                default:
                    printf("Error!\n");
                    CurrentState = EndState;
            }
            break;
        case 5:
            switch (symbol) {
                case DIGIT:
                    p = p * 10 + d;
                    CurrentState = 6;
                    break;
                default:
                    printf("Error!\n");
                    CurrentState = EndState;
            }
            break;
        case 6:
            switch (symbol) {
                case DIGIT:
                    p = p * 10 + d;
                    break;
                default:
                    FCON = w * pow(10, e * p - n);
                    CurrentState = EndState;
            }
            break;
    }
    return CurrentState;
}

void LEX(FILE *fp) {
    int ch;
    CurrentState = 0;
    while (CurrentState != EndState) {
        ch = GetChar(fp);
        EXCUTE(CurrentState, ch);
    }
}

int lookup(char *a)//识别关键字
{
    if (strlen(a) == 5 && a[0] == 'b' && a[1] == 'e' && a[2] == 'g' && a[3] == 'i' && a[4] == 'n')
        return BEGIN;
    else if (strlen(a) == 3 && a[0] == 'e' && a[1] == 'n' && a[2] == 'd')
        return END;
    else if (strlen(a) == 2 && a[0] == 'i' && a[1] == 'f')
        return IF;
    else if (strlen(a) == 4 && a[0] == 't' && a[1] == 'h' && a[2] == 'e' && a[3] == 'n')
        return THEN;
    else if (strlen(a) == 4 && a[0] == 'e' && a[1] == 'l' && a[2] == 's' && a[3] == 'e')
        return ELSE;
    else
        return 0;
}

void out(int m, char *a, FILE *fp2)//词法分析结果输出到文件中
{
    fprintf(fp2, "(", fp2);
    switch (m) {
        case BEGIN:
            fputs("BEGIN", fp2);
            break;
        case END:
            fputs("END", fp2);
            break;
        case IF:
            fputs("IF", fp2);
            break;
        case THEN:
            fputs("THEN", fp2);
            break;
        case ELSE:
            fputs("ELSE", fp2);
            break;
        case ID:
            fputs("ID", fp2);
            break;
        case LT:
            fputs("LT", fp2);
            break;
        case LE:
            fputs("LE", fp2);
            break;
        case EQ:
            fputs("EQ", fp2);
            break;
        case NE:
            fputs("NE", fp2);
            break;
        case GT:
            fputs("GT", fp2);
            break;
        case GE:
            fputs("GE", fp2);
            break;
        case IS:
            fputs("IS", fp2);
            break;
        case PLUS:
            fputs("PL", fp2);
            break;
        case MI:
            fputs("MI", fp2);
            break;
        case MU:
            fputs("MU", fp2);
            break;
        case DI:
            fputs("DI", fp2);
            break;
        case L:
            fputs("L", fp2);
            break;
        case R:
            fputs("R", fp2);
            break;
    }
    if (a != " ")
        fprintf(fp2, ",'%s')\n", a);
    else
        fprintf(fp2, ",%s)\n", a);
}

void test1(FILE *fp1, FILE *fp2) {
    char ch;
    int i, c;
    ch = fgetc(fp1);
    std::cout<<ch;
    col++;
    if (isalpha(ch))//第一个字符为字母，则是关键字或者标识符
    {
        TOKEN[0] = ch;
        ch = fgetc(fp1);
        col++;
        i = 1;
        while (isalnum(ch))//为字母或数字时存入数组中
        {
            TOKEN[i] = ch;
            i++;
            ch = fgetc(fp1);
            col++;
        }
        TOKEN[i] = '\0';
        if (!feof(fp1)) {
            fseek(fp1, -1, 1);  //retract
            col--;
        }
        c = lookup(TOKEN);//c=0是标识符
        if (c == 0)
            out(ID, TOKEN, fp2);
        else
            out(c, " ", fp2);
    } else if (isdigit(ch))//第一个字符为数字，则是无符号数
    {
        fseek(fp1, -1, 1);
        col--;
        LEX(fp1);//调用无符号数识别程序
        if (ICON != 0)
            fprintf(fp2, "(UCON,%d)\n", ICON);
        if (FCON != 0.0)
            fprintf(fp2, "(UCON,%g)\n", FCON);
        if (!feof(fp1)) {
            fseek(fp1, -1, 1);
            col--;
        }
        ICON = 0;
        FCON = 0.0;
    } else {
        switch (ch) {
            case '<':
                ch = fgetc(fp1);
                col++;//<=、<>、<的分析
                if (ch == '=')
                    out(LE, " ", fp2);
                else if (ch == '>')
                    out(NE, " ", fp2);
                else {
                    fseek(fp1, -1, 1);
                    col--;
                    out(LT, " ", fp2);
                }
                break;
            case '=':
                out(EQ, " ", fp2);
                break;
            case '>':
                ch = fgetc(fp1);
                col++;//>=、>的分析
                if (ch == '=')out(GE, " ", fp2);
                else {
                    fseek(fp1, -1, 1);
                    col--;
                    out(GT, " ", fp2);
                }
                break;
            case '+':
                out(PLUS, " ", fp2);
                break;//算符分析
            case '-':
                out(MI, " ", fp2);
                break;
            case '*':
                out(MU, " ", fp2);
                break;
            case '/':
                out(DI, " ", fp2);
                break;
            case '(':
                out(L, " ", fp2);
                break;
            case ')':
                out(R, " ", fp2);
                break;
            case ':':
                ch = fgetc(fp1);
                col++;//:=的分析
                if (ch == '=')
                    out(IS, " ", fp2);
                else {
                    fseek(fp1, -1, -1);
                    col--;
                }
            case ' ':
            case '\t':
                col--;
                test1(fp1, fp2);
                break;
            case '\n': {
                row++;
                col = 0;
                test1(fp1, fp2);
                break;
            }//遇空格、制表符、回车跳过并继续扫描
            default:
                printf("第%d行第%d个字符Error:%c\n", row, col, ch);
                break;
        }
    }
}

int main() {
    FILE *fp1 = fopen("file1.txt", "rw");
    FILE *fp2 = fopen("file2.txt", "rw");
    if (fp1 == NULL || fp2 == NULL) {
        printf("error\n");
    }

    while (!feof(fp1))//文件结束之前执行词法分析扫描程序
    {
        test1(fp1, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}