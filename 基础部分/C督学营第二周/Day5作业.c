//
// Created by XuanLang Z on 2021/3/13.
//
//1.将包含字符数字的字符串分开,使得分开后的字符串前一部分是数字后一部分是字母。例
//如“h1ell2o3” ->”123hello”
//2.将 字 符 串 中 的 空 格 替 换 成 “%020” ， 例 如 “hello world how ”
//->”hello%020%020%020world%020%020%020how%020%020%020%020”
//3.删除字符串中指定的字符。 例如 “abcdaefaghiagkl“ 删除‘a’,以后： “bcdefghigkl”
//4.删除一个有序数组中重复的元素。例如 1 ,2, 2,2,3,3,3,4,4,5,5,5,6,6,6 -> 1,2,3,4,5,6
//5.将 字 符 串 中 的 相 邻 的 多 余 空 格 去 掉 ， 例 如 （空 格 用 下 划 线 表示）：
// ”___hello____world___how_are_you__” ->”hello_world_how_are_you”
//6.求一个字符串数组的最大值和次大值  void big(char *arr[],int size ,char** big11,char** big22)
#include <stdio.h>
#include <string.h>
#define MAX 10000

char* split_string(char*a)
{
    char*p=a;
    char num[MAX],word[MAX];
    int n=0,w=0;
    while (*p!='\0')
    {
        if (*p>='0'&&*p<='9'){num[n++]=*p;}
        else if (*p>='a'&&*p<='z'){word[w++]=*p;}
        p++;
    }
    puts(num);
    puts(word);
    return p;
}

char* change_blank(char*a)
{
    char b[MAX],*s="%020";
    char*p=a;
    int i=0;
    while (*p!='\0')
    {
        if (*p!=' '){b[i++]=*p;}
        else{strcat(b,s);i+=strlen(s);}
        p++;
    }
    puts(b);
    return p;
}

char* remove_char(char*a)
{
    char*p=a,s='a';
    char b[MAX];
//    char*b=NULL;
    int i=0;
    while (*p!='\0')
    {
        while (*p==s)p++;
        if (*p!=s)
        {
            b[i]=*p;
//            *b=*p;
//            b++
        }
        i++;
        p++;
    }
    puts(b);
}

void remove_same(char*a)
{
    char*p=a;
//    printf("%c",*p);
    char b[MAX];
    int i=0;
    b[i++]=*p;
    while (*p!='\0')
    {
        if (*p>b[i-1])b[i++]=*p;
        p++;
    }
    puts(b);
}

void remove_blank(char*a)
{
    char *p=a;
    char b[MAX];
    int i=0;
    while (*p!='\0')
    {
        if (*p!=' '){b[i++]=*p++;}
        else{
            b[i++]=' ';
            p++;
            while (*p==' ')p++;
        }
    }
    puts(b);
}


void big(char *arr[],int size ,char** big11,char** big22)
{
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], *big11) > 0) {
            *big22 = *big11;
            *big11 = arr[i];
        }
    }
}

int main()
{
    char a[MAX];
    gets(a);
//    split_string(a);
//    change_blank(a);
//    remove_char(a);
//    remove_same(a);
//    remove_blank(a);
    char*big1,*big2;
    big(*a,MAX,&big1,&big2);
}