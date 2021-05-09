#include <stdio.h>
int max(int array[100][100],int m,int n,int k)
{
    int f1=0,f2=0;
    for (int i = m; f1<k; ++f1) {
        for (int j = n; f2 < k; ++f2) {
            printf("%d ",array[i][j]);
        }
    }
    printf("\n");
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int in[100][100],out[100][100];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&in[i][j]);
        }
    }
    max(in,0,1,k);
//    for (int i = 0; i < m - k + 1; ++i) {
//        for (int j = 0; j < m - k + 1; ++j) {
//            out[i][j]=max(in,i,j,k);
//        }
//    }
}