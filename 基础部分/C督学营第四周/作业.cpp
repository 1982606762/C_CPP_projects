//
// Created by XuanLang Z on 2021/3/29.
//
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list<int> test;
    test.push_back(1);
    test.push_back(1);
    test.push_front(0);
    test.push_back(2);

    auto it = test.begin();
    for (int count = 0; it != test.end() && count < 2; it++, count++);
    test.insert(it, 3);
    for (auto &i : test)
        cout << i << endl;
    for (auto it = test.begin(); it != test.end();) {
        if (*it != 2)
            it++;
        else
            it = test.erase(it);
    }
    return 0;
}