//
// Created by XuanLang Z on 2022/2/8.
//

#include <string>
#include <iostream>

using namespace std;
int main()
{
    string s;
//    while(getline(cin,s))
//        cout<<s;
//    while(cin>>s && s != "q")
//        cout<<s<<endl;
    string s2 = "Upper strIng test";
    for(auto i = s2.begin();i!=s2.end();++i){
        if(!isspace(*i))
            *i = toupper(*i);
    }
    cout<<s2;
}