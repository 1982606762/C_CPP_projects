#include <stdio.h>
int main()
{
    double num;
    int n;
    char str[100];
    scanf("%lf%d", &num, &n);
    sprintf(str, "%%.%dlf\n", n); // %% 代表输出一个 %
    printf(str, num);
    return 0;
}