//
// Created by XuanLang Z on 2021/3/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
void print_(int arr[])
{
    for (int i = 0; i < N; ++i) {
        printf("%3d",arr[i]);
    }
    printf("\n");
}

void choose_sort(int arr[])
{
    int min;
    for (int i = 0; i < N - 1; ++i) {
        min=i;
        for (int j = i+1; j <N; ++j) {
            if (arr[j]<arr[min]){
                min =  j;
            }
        }
        int t = arr[i];
        arr[i] = arr[min];
        arr[min] = t;
    }
}

void insert_sort(int arr[])
{
    int temp,j;
    for (int i = 0; i < N; ++i) {
        temp = arr[i];
        for (j = i-1; j >=0; j--) {
            if (arr[j]>temp)
            {
                arr[j+1]=arr[j];
            } else{
                break;
            }
        }
        arr[j+1]=temp;

    }
}

void shell_sort(int arr[])
{
    int gap,i,j,val;
    for (gap=N>>1;gap>0;gap>>=1)
    {
        for (i=gap;i<N;i++)
        {
            val = arr[i];
            for (j=i-gap;j>=0;j=j-gap)
            {
                if (val<arr[j])
                {
                    arr[j+gap]=arr[j];
                } else
                {
                    break;
                }
            }
            arr[j+gap]=val;
        }
    }
}
int main()
{
    int arr[N];
    srand(time(NULL));

    for (int i = 0; i < N; ++i) {
        arr[i]=rand()%100;
    }
    print_(arr);
//    choose_sort(arr);
    insert_sort(arr);
    print_(arr);
}
