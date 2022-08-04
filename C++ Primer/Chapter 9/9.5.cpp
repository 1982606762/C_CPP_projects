//
// Created by XuanLang Z on 2022/3/26.
//

#include "../../bits.h"
using namespace std;


void replace(string &s,const string& olds,const string& news)
{
    int size = olds.size();
    auto it1 = s.begin();
    auto it2 = news.begin();
    auto it3 = news.end();
    for (it1 ; it1 < (s.end() - olds.size() + 1) ; it1 ++)
    {
        if(s.substr(it1 - s.begin(),size) == olds)
        {
            s.erase(it1,it1 + size);
            s.insert(it1,news.begin(),news.end());
            it1 += size;
        }
    }
}


void replace2(string &s,const string& olds,const string& news)
{
    int size = olds.size();
    auto it1 = s.begin();
    auto it2 = news.begin();
    auto it3 = news.end();
    for (it1 ; it1 < (s.end() - olds.size() + 1) ; it1 ++)
    {
        if(s.substr(it1 - s.begin(),size) == olds)
        {
            s.replace(it1,it1 + size,news);
            it1 += size;
        }
    }
}

void change(string &name,const string& pre,const string& suffix)
{
    name.insert(name.begin(),pre.begin(),pre.end());
    name.insert(name.end(),suffix.begin(),suffix.end());
}
int main()
{
    //9.5.1
    vector<char> vec = {'1','2','3'};
    string ss(vec.begin(),vec.end());
    //9.5.2
    string ss1 = "asasthoughasa" , ss2 = "though" , ss3 = "tho" , ss4 = "asasthoughasa";
    replace(ss1,ss2,ss3);
    replace2(ss4,ss2,ss3);
    cout << (ss1 == ss4);
    cout << endl;
    string name = "zhaoxl" , pre = "Mr." , suffix = " Jr.";
    change(name,pre,suffix);
    cout << name;
    //9.5.3
    string s = "ab2c3d7R4E6";
    string number = "0123456789";
    unsigned pos = 0;
    //循环中我犯了一个错误，没有将pos=左右加括号，导致无线循环
    while ((pos = s.find_first_of(number,pos)) != string::npos)//注意有两个参数，从pos开始查找
    {
        cout<<"在第"<<pos+1<<"个位置找到数字"<<s[pos]<<endl;
        ++pos;
    }
    pos = 0;//重新置零
    while ((pos = s.find_first_not_of(number,pos)) != string::npos)//注意有两个参数，从pos开始查找
    {
        cout << "在第" << pos + 1 << "个位置找到英文字母" << s[pos] << endl;
        ++pos;
    }
    return 0;
}