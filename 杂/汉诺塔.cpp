//
// Created by XuanLang Z on 2021/9/15.
//

#include <iostream>
using namespace std;
int times = 0;
void hanoi(int n, char a, char b, char c)
{

    /* 如果剩下一个盘子，直接从a-->c */
    if(1 == n)
    {
        cout << n << ":" << a << "-->" << c << endl;
    }
    else
    {
        /* 把n-1个盘子从a移动到b借助于c */
        hanoi(n-1,a,c,b);

        /* 把第n和盘子从a移动c */
        cout << n << ":" << a << "-->" << c << endl;
        times++;
        cout << "now:" << times << endl;
        /* 把n-1个盘子从b移动到c借助于a */
        hanoi(n-1,b,a,c);
    }
}
int main()
{
    int num = 0;
    cin >> num;
    hanoi(num,'a','b','c');
    return 0;
}

