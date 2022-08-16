#include <stdio.h>
int f[1001];
int main()
{
    int n;
    scanf("%d", &n);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i & (i - 1)] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", f[i]);
    }
    printf("\n");
    return 0;
}