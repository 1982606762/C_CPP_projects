//
// Created by XuanLang Z on 2022/3/26.
//
#include "../../bits.h"
using namespace std;

int main()
{
    vector<int>vec;
    int i;
    while(cin >> i){
        vec.push_back(i);
        cout << "size: " << vec.size();
        cout << "capacity: " << vec.capacity();
    }
    return 0;
}
