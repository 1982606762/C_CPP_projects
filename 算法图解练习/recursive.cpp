#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
int calc(vector<int> arr){
    vector<int>temp1 = arr;
    if(arr.empty())return 0;
    if(arr.size()==1)return arr[0];
    int temp = arr[arr.size()-1];
    temp1.pop_back();
    return temp+calc(temp1);
}

int count(const vector<int>& arr){
    vector<int>temp = arr;
    if (arr.empty())return 0;
    temp.pop_back();
    return 1 + count(temp);
}

int max(vector<int> arr){
    vector<int>temp = arr;
    if (arr.size()==1){
        return arr[0];
    }
    int last = temp.back();
    temp.pop_back();
    return max(last,max(temp));
}
int main()
{
    vector<int> arr = {6,1,2,3,4,5};
    cout<<calc(arr)<<endl;
    cout<<count(arr)<<endl;
    cout<<max(arr)<<endl;
}
