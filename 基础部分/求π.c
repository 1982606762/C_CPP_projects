#include<stdlib.h>
#include<stdio.h>

int main(){
    int m=0,n=0;
    for (long i = 0; i < 1000000; i++)
    {
        double a = 1.0*rand()/RAND_MAX;
        double b = 1.0*rand()/RAND_MAX;
        if (a*a+b*b<=1)
        {
            m+=1;
        }
        n+=1;
    }
    printf("%lf",4.0*m/n);
}