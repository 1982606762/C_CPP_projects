//
// Created by XuanLang Z on 2021/8/3.
//

#include <stdio.h>
#include <string.h>
int main()
{
    char a[100]="   hello my  wonderful world";
    char b[100];
    int n,i,len=0;
    int flag=0;
    n=strlen(a);
    for(i=0;i<=n;i++)
    {
        if((a[i]>='a'&&a[i]<='z'))
        {
            b[len++]=a[i];
            flag=1;
        }
        else if(a[i]=='\0')
        {
            b[len]='\0';

        }
        else if(flag){
            b[len]='_';
            len++;
            flag=0;
        }
    }
    puts(b);
}