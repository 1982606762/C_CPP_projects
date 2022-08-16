//
// Created by XuanLang Z on 2021/3/7.
//

#include <stdlib.h>
#include <stdio.h>

void hanoi(int n,char one,char two,char three)
{
    void move(char x,char y);
    if (n==1){move(one,three);}
    else{
        hanoi(n-1,one ,three,two);
        move(one,three);
        hanoi(n-1,two,one,three);
    }
}

void move(char x,char y)
{

}