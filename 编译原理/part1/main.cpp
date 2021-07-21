#include "part2.h"
#include<iostream>

using namespace std;
int main()
{
    extern char ch; FILE * fp;
    if((fp=fopen("../data.txt","r"))==NULL) //打开⽂件 data.txt
    {
        printf("\nfile open error!\n"); exit(0);
    }
    part2(fp);
}