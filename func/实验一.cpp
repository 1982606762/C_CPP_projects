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
const char* table1[] = { " ","begin","end","if","then","else","while","do" };//��Źؼ���
const char* table2[] = { " ","BEGIN","END","IF","THEN","ELSE","WHILE","DO","ID","UCON","LT","LE","EQ","NE","GT","GE","IS","PL","MI","MU","DI" };//����������������Ƿ�
char TOKEN[20];//�������δ��һ�����ʴ����еĸ����ַ���

int lookup(char a[])/*��ؼ����Ƿ���ڣ�ÿ����һ�Σ����� TOKEN �е��ַ����鱣���ֱ����鵽���ͽ���Ӧ�ؼ��ֵ�����븳�����ͱ��� c������ c ��Ϊ�㡣*/
{
    int i;
    for (i = 1; i <= 7; i++)//���1
    {
        if (strcmp(a, table1[i]) == 0)return i;
    }
    if (i == 8)return 0;
}
void out(int a, const char b[])
/*һ����ڽ�����̬ʱ���ô˺��������õ���ʽΪ OUT(c��VAL)��
���У�ʵ�� c Ϊ��Ӧ���ʵ���������Ƿ���ʵ�� VAL Ϊ TOKEN�������ģ���Ϊ�մ�������Ǳ�ʶ���͸��㳣����value�ֶ��Ǿ���ֵ���ؼ��ֺ������value�ֶ�Ϊ��
���� OUT �Ĺ����ǣ����ͳ�һ�����ʵ��ڲ���ʾ֮�󣬷��ص����øôʷ�����������Ǹ�����*/
{
    ofstream fout("./result.txt", fstream::app);
    char temp = ' ';
    if (a == 8 || a == 9)//��ʶ���򸡵㳣��
    {
        fout << "��" << table2[a] << "��" << b << "��" << endl;
    }
    else//����
    {
        fout << "��" << table2[a] << " ��" << temp << "��" << endl;
    }

    fout.close();
}

void report_error(void)//���ش���
{
    ofstream fout("./result.txt", fstream::app);
    fout << "���벻�Ϲ淶��";
    fout.close();
    exit(0);
}
void scanner_example(FILE* fp)//ʶ�����뵥�ʴ�������#����
{
    char ch;
    int i, c, flag = 0;;
    //ch = fgetc(fp);
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ' ')ch = fgetc(fp);
        if (ch == '\n')ch = fgetc(fp);
        if (ch == '#')break;
        if (isalpha(ch)) //�ж��ַ��Ƿ�Ϊ��ĸ��ʶ���ʶ���͹ؼ���
        {
            TOKEN[0] = ch; ch = fgetc(fp); i = 1;
            while (isalnum(ch))//����������ַ��Ƿ�����ĸ������
            {
                TOKEN[i] = ch; i++;
                ch = fgetc(fp);
            }
            TOKEN[i] = '\0';//������
            fseek(fp, -1, 1); //���ļ���ǰλ�ú���һ���ַ�
            c = lookup(TOKEN);//�����ڵڶ������е�λ�ã�����ǹؼ��ַ����±꣬��ʶ������0
            if (c == 0) out(8, TOKEN);//ʶ���ʶ��
            else out(c, TOKEN);//ʶ��ؼ���
        }
        else if (isdigit(ch))//�ж��ַ��Ƿ�Ϊ�����ַ�
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
            out(9, TOKEN);//ʶ������
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
        printf("���ļ�ʧ�ܣ�");
    }
    scanner_example(fp1);

    cout << "���ʽΪ��" << endl;
    ifstream myfile1("./test.txt", ios::in);
    string temp;
    if (!myfile1.is_open())
    {
        cout << "δ�ɹ����ļ�" << endl;
    }
    while (getline(myfile1, temp))
    {
        cout << temp<<endl;
    }
    myfile1.close();

    cout << "�ʷ��������Ϊ��" << endl;
    ifstream myfile2("./result.txt", ios::in);
    if (!myfile2.is_open())
    {
        cout << "δ�ɹ����ļ�" << endl;
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
