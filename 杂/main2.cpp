#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
int calc(vector<int>& arr){
    if(arr.size()==0)return 0;
    if(arr.size()==1)return arr[0];
    int temp = arr[arr.size()-1];
    arr.pop_back();
    return temp+calc(arr);
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    cout<<calc(arr);
}
