//
// Created by XuanLang Z on 2021/3/3.
//

#include <stdio.h>
int main()
{
    int i=1;
    float f=98.3;
    //输出两位，右对齐，加-号是左对齐，加02是前边加0.
    //输出4位，保留两位小数
    printf("%2d  %4.2f\n",i,f);
    printf("%d  %f\n",i,f);
    //输出10位
    
    printf("%10s","hello");

}