#include<iostream>
using namespace std;
int main(){
    for (int i = 0; i <= 6; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<"*"<<i<<"="<<i*j<<'\t';
        }
        cout<<"\n";
    }
    return 0;
}