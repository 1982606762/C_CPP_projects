//
// Created by XuanLang Z on 2022/3/23.
//

#include "../../bits.h"
using namespace std;

int main()
{
    vector<int> v(26,0);
    string s = "aaaaabbbbccc";
    for (auto i:s) {
        int temp = i - 'a';
        v[temp]++;
    }
    cout << v[0];
    return 0;
}