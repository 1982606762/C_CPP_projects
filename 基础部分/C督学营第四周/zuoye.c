//
// Created by XuanLang Z on 2021/3/28.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
#define M 100
int compare(const void* left, const void* right)
{
    int* p1 = (int*)left;
    int* p2 = (int*)right;
    return *p1 - *p2;
}

void arrPrint(int* arr)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    int* arr = (int*)malloc(N * sizeof(int));
    time_t start, end;
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {
        arr[i] = rand() % M;
    }
    arrPrint(arr);
    printf("rand success\n");
    start = time(NULL);
    qsort(arr, N, sizeof(int), compare);
    end = time(NULL);
    arrPrint(arr);
    printf("use time=%d\n", end - start);
    return 0;
}