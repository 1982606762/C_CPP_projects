//
// Created by XuanLang Z on 2021/6/29.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <cassert>
#include <vector>
using namespace std;
const char* table1[] = { " ","begin","end","if","then","else","while","do" };//存放关键字
const char* table2[] = { " ","BEGIN","END","IF","THEN","ELSE","WHILE","DO","ID","UCON","LT","LE","EQ","NE","GT","GE","IS","PL","MI","MU","DI" };//存放所有类别码的助记符
char TOKEN[20];//用来依次存放一个单词词文中的各个字符。

int lookup(char a[])/*查关键字是否存在，每调用一次，就以 TOKEN 中的字符串查保留字表，若查到，就将相应关键字的类别码赋给整型变量 c；否则将 c 置为零。*/
{
    int i;
    for (i = 1; i <= 7; i++)//查表1
    {
        if (strcmp(a, table1[i]) == 0)return i;
    }
    if (i == 8)return 0;
}
void out(int a, const char b[])
/*一般仅在进入终态时调用此函数，调用的形式为 OUT(c，VAL)。
其中，实参 c 为相应单词的类别码助记符；实参 VAL 为 TOKEN（即词文）或为空串。如果是标识符和浮点常数，value字段是具体值，关键字和运算符value字段为空
函数 OUT 的功能是，在送出一个单词的内部表示之后，返回到调用该词法分析程序的那个程序。*/
{
    ofstream fout("./result.txt", fstream::app);
    char temp = ' ';
    if (a == 8 || a == 9)//标识符或浮点常数
    {
        fout << "（" << table2[a] << "，" << b << "）" << endl;
    }
    else//其他
    {
        fout << "（" << table2[a] << " ，" << temp << "）" << endl;
    }

    fout.close();
}

void report_error(void)//返回错误
{
    ofstream fout("./result.txt", fstream::app);
    fout << "输入不合规范！";
    fout.close();
    exit(0);
}
void scanner_example(FILE* fp)//识别输入单词串，遇到#结束
{
    char ch;
    int i, c, flag = 0;;
    //ch = fgetc(fp);
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ' ')ch = fgetc(fp);
        if (ch == '\n')ch = fgetc(fp);
        if (ch == '#')break;
        if (isalpha(ch)) //判断字符是否为字母，识别标识符和关键字
        {
            TOKEN[0] = ch; ch = fgetc(fp); i = 1;
            while (isalnum(ch))//检查所传的字符是否是字母和数字
            {
                TOKEN[i] = ch; i++;
                ch = fgetc(fp);
            }
            TOKEN[i] = '\0';//结束符
            fseek(fp, -1, 1); //从文件当前位置后退一个字符
            c = lookup(TOKEN);//查找在第二个表中的位置，如果是关键字返回下标，标识符返回0
            if (c == 0) out(8, TOKEN);//识别标识符
            else out(c, TOKEN);//识别关键字
        }
        else if (isdigit(ch))//判断字符是否为数字字符
        {
            TOKEN[0] = ch; ch = fgetc(fp); i = 1;
            while (isdigit(ch) || ch == '.')
            {
                if (ch == '.')
                {
                    if (flag == 0)
                    {
                        flag = 1;
                        TOKEN[i] = ch; i++;
                    }
                    else report_error();
                }
                else
                {
                    TOKEN[i] = ch; i++;

                }
                ch = fgetc(fp);
            }
            TOKEN[i] = '\0';
            fseek(fp, -1, 1);
            out(9, TOKEN);//识别数字
        }
        else
            switch (ch)
            {
                case '<': ch = fgetc(fp);
                    if (ch == '=')out(11, TOKEN);//<=
                    else if (ch == '>') out(13, TOKEN);//<>
                    else
                    {
                        fseek(fp, -1, 1);
                        out(10, TOKEN);//<
                    }
                    break;
                case '=': ch = fgetc(fp);
                    if (ch == '=')out(12, TOKEN);//==
                    else
                    {
                        fseek(fp, -1, 1);
                        out(16, TOKEN);//=
                    }
                    break;
                case '>': ch = fgetc(fp);
                    if (ch == '=')out(15, TOKEN);//>=
                    else
                    {
                        fseek(fp, -1, 1);
                        out(14, TOKEN);//>
                    }
                    break;
                case '+':out(17, TOKEN); break;
                case '-':out(18, TOKEN); break;
                case '*':out(19, TOKEN); break;
                case '/':out(20, TOKEN); break;
                default: report_error(); break;
            }

    }
    return;
}

int main()
{
    FILE* fp1;
    FILE* fp2;
    fp2 =fopen("./result.txt", "w");
    fclose(fp2);
    fp1 = fopen("./test.txt", "r");
    if (!fp1)
    {
        printf("打开文件失败！");
    }
    scanner_example(fp1);

    cout << "表达式为：" << endl;
    ifstream myfile1("./test.txt", ios::in);
    string temp;
    if (!myfile1.is_open())
    {
        cout << "未成功打开文件" << endl;
    }
    while (getline(myfile1, temp))
    {
        cout << temp<<endl;
    }
    myfile1.close();

    cout << "词法分析结果为：" << endl;
    ifstream myfile2("./result.txt", ios::in);
    if (!myfile2.is_open())
    {
        cout << "未成功打开文件" << endl;
    }
    while (getline(myfile2, temp))
    {
        cout << temp << endl;
    }
    myfile2.close();

    fclose(fp1);
    fclose(fp2);
    return 0;
}
