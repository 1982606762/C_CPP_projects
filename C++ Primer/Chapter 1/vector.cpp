//
// Created by XuanLang Z on 2022/2/9.
//

#include <vector>
#include <iostream>

using namespace std;
int main(){
    vector<unsigned> scores(11,0);
    unsigned grade;
//    用下标实现
//    while (cin>>grade){
//        if(grade<=100){
//            scores[grade/10]++;
//        }
//    }
    while (cin>>grade){
        auto i = scores.begin();
        if(grade<=100){
            int a = grade/10;
            i = i+a;
            *i = *i+1;
        }
    }
    for(auto i : scores){
        cout<<i;
    }

}