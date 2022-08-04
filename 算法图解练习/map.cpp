//
// Created by XuanLang Z on 2022/2/26.
//
#include <map>
#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main()
{
    vector<int> v,q;

    v = {1,2,3,3,4};

/************************************set****************************************/

    set<int> s,s2;
    s2.insert(1);
    s2.emplace(2);
    s2.erase(1);
    if(s2.find(2) != s2.end()) cout<<s2.size()<<endl;

    s.insert(v.begin(),v.end());


    for(auto i : s){
        cout<<i;
    }
    cout << endl;

/*************************************map****************************************/
    map<int,string> m;
    m[1] = "apple";
    m[2] = "pair";
    m.insert(pair<int,string>{3,"banana"});
    m.insert(pair<int,string>{4,"orange"});

    for(auto i : m){
        cout << i.first << i.second << endl;
    }

    m.erase(4);

    for(auto i : m){
        cout << i.first << i.second << endl;
    }

    if(m.find(3) != m.end()){
        cout << m[3];
    }

    if(m.find(4) != m.end()){
        cout << m[4];
    }else{
        m[4] = "4";
    }

    cout << m[4];
    return 0;
}