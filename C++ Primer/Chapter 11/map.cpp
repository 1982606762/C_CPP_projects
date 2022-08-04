//
// Created by XuanLang Z on 2022/4/3.
//

#include "../../bits.h"
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> m;
    vector<int> ans;
    for(int i = 0;i< nums.size();i++){
        if(m.find(nums[i]) != m.end()){
            ans.push_back(i);
            ans.push_back(m[nums[i]]);
        }
        else{
            m.insert(make_pair(target - nums[i],i));
        }
    }
    return ans;
}
int main()
{
    string s = "anagram", t ="nagaram";
    unordered_map<char,int>m;
    for(auto i : s){
        m[i]++;
    }
    char i;
    while(cin >> i){
        if(m[i]>1){
            m[i]--;
        } else{
            m.erase(i);
        }

        auto j = m.begin();
        while(j != m.end()){
            cout << j->first << "---" << j->second << endl;
            j++;
        }
        cout <<"size:"<< m.size() << endl;

    }
    return 0;
}