//
// Created by XuanLang Z on 2021/8/3.
//
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout << *it<<"  ";
    }
    cout << endl;
    vector<int>::iterator it = v.begin();
    it = it + 4;
    v.insert(it, 4, 0);//插入4个0
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  " ;
    }
    cout << endl;
    v.erase(v.begin());
    v.erase(v.end() - 1);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }

    cout << endl;
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    return 0;

}