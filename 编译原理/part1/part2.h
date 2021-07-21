//
// 递归下降法
//

#ifndef PART1_PART2_H
#define PART1_PART2_H

#endif //PART1_PART2_H

#include<iostream>
#include<string>
#include "part1.h"

using namespace std;

string str;
FILE * fp;
void E();  // E->TX;
void X();  // X->+TX | e
void T();  // T->FY
void Y();  // Y->*FY | e
void F();  // F->(E) | i

void part2(FILE * fpoint) {
    fp = fpoint;
    str = part1_Read(fp);

    E();

    keyWord_position++;
    str = part1_Read(fp);
    if (str == "#")
        cout<<"正确语句"<<endl;
    else {
        cout<<"分析失败!"<<endl;
        //cout<<"分析失败位置："<<" "<<read_position;
    }

}
void E() {
    T();
    X();
}
void X() {
    if (str == "PL" || str == "MI") {
        str = part1_Read(fp);
        T();
        X();
    }
}
void T() {
    F();
    Y();
}
void Y() {
    if (str == "MU" || str == "DI") {
        str = part1_Read(fp);
        F();
        Y();
    }
}
void F() {
    if (str == "ID" || str == "INT" || str == "REAL") {
        str = part1_Read(fp);
    } else if (str == "BL") {
        str = part1_Read(fp);
        E();
        if (str == "BR") {
            str = part1_Read(fp);
        } else {
            printf("分析失败!\n");
            //cout<<"分析失败位置："<<" "<<read_position;
            exit(0);
        }
    } else {
        printf("分析失败!\n");
        //cout<<"分析失败位置："<<" "<<read_position;
        exit(0);
    }

}

