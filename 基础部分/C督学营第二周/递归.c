//
// Created by XuanLang Z on 2021/3/22.
#include <stdio.h>

int stairs(int n)
{
    if (n==1)
    {
        return 1;
    }
    if (n==2)
    {
        return 2;
    }
    return stairs(n-1)+stairs(n-2);
}


long long count(long m,long n)
{
    if (m==0&&n==0){
        return 0;
    } else if (m==0||n==0){
        return 1;
    } else{
        return count(m-1,n)+count(m,n-1);
    }
}

int main()
{
//    for (int i = 0; i < 5; ++i) {
//        int temp;
//        scanf("%d",&temp);
//        printf("%d\n",stairs(temp));
//    }
    for (int i = 0; i < 5; ++i) {
        long long m,n;
        scanf("%lld%lld",&m,&n);
        printf("%lld\n",count(m,n));
    }
}
