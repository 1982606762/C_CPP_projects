#include<stdio.h>
int main(){
    char str1[100];
    int i=0;
    sscanf(str1,"qweqweqwe");
    printf("%c\n",str1[i]);
    while (str1[i]!='\0')
    {
        printf("%c\n",str1[i]);
        i++;
    }
    return 0;
}