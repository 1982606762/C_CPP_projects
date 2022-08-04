//
// Created by XuanLang Z on 2022/3/14.
//
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    string str;
    str.push_back('a');
    str.push_back('b');
    str.erase(str.begin());
    cout<<str;
    return 0;
}
