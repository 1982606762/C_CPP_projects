//
// Created by XuanLang Z on 2022/3/23.
//

#include "../../bits.h"
using namespace std;

int main()
{
    //使用insert向任意位置插入元素
    vector<int> vec;
    vec = {1,2,3,5,6,7,8};
    auto iter = vec.begin();
    for(int i = 0;i < vec.size() ; i++){
        if(*iter == 3){
            vec.insert(iter + 1,4);
        }
        iter ++;
    }

    //用emplace插入，使用的是默认的构造函数构造一个新对象
    auto iter2 = vec.begin();
    for(int j = 0 ; j < vec.size() ; j++){
        if(*iter2 == 3){
            iter2 ++;
            vec.emplace(iter2,10);
        }
        iter2 ++;
    }

    for(auto i : vec){
        cout << i;
    }

    //删除单个元素
    auto iter3 = vec.begin();
    for(int j = 0 ; j < vec.size() ; j++){
        if(*iter3 == 3){
            vec.erase(iter3);
        }
        iter3 ++;
    }

    for(auto i : vec){
        cout << i;
    }
    cout << endl;
    vector<int> vec2;
    //用作一个栈
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(3);
    cout << vec2.back();
    vec2.pop_back();
    cout << vec2.back();
    vec2.pop_back();
    cout << vec2.back();
    vec2.pop_back();

    //用作队列
    vec2.emplace(vec2.cbegin(),1);
    vec2.emplace(vec2.cbegin(),2);
    vec2.emplace(vec2.cbegin(),3);
    cout << vec2.back();
    vec2.pop_back();
    cout << vec2.back();
    vec2.pop_back();
    cout << vec2.back();
    vec2.pop_back();

    return 0;
}