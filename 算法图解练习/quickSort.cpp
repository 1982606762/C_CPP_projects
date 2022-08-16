//
// Created by XuanLang Z on 2022/2/24.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int>arr){
    vector<int>left,right;
    int temp;
    if (arr.size() < 2) {
        return arr;
    } else {
        temp = arr[0];
        for(int i = 1;i<arr.size();i++){
            if(arr[i]<temp || arr[i] == temp){
                left.push_back(arr[i]);
            } else {
                right.push_back(arr[i]);
            }
        }
        vector<int>aleft,aright;
        aleft = quickSort(left);
        aright = quickSort(right);
        aleft.push_back(temp);
        aleft.insert(aleft.end(),aright.begin(),aright.end());
        return aleft;
    }
}

int main()
{
    vector<int>v1 = {1,2,3,1,9,24,5};
    v1 = quickSort(v1);
    for(auto i:v1){
        cout<<i<<endl;
    }
    return 0;
}
