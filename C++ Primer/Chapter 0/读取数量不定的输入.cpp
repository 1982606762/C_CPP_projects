//
// Created by XuanLang Z on 2022/1/25.
//

#include <iostream>
int main()
{
    int sum = 0,value = 0;
    //可以最后输入0.0来终止，while读取的是输入流的状态
    while (std::cin>>value){
        sum+=value;
    }
    std::cout<<sum;

    return 0;
}