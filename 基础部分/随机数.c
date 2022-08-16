#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", rand() % 100);
            srand(rand() % 1000);
            /* 
            int a = time(0);
            printf("%d\t", a); */
        }
        printf("\n");
    }
}