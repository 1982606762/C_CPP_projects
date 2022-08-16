//
// Created by XuanLang Z on 2022/3/21.
//
#include "../../bits.h"
using namespace std;

int main()
{
    string s;
    char t;
    while (cin>>t && t != '='){
        s += t;
        cout << s << endl;
    }

    return 0;
}
