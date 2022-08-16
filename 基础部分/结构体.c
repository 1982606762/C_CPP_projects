#include<stdio.h>
struct point
{
    int x,y;
}a[2];

int main(){
    struct point *p=a;
    int* point0 = &a[1].x;
    int* point1 = &p[1].x;
    //地址加一是数组下一位
    int* point2 = &a[0].y+1;

    printf("%d\n",point0==point2);
    printf("%p\n",point2);
    printf("%p\n",point0);

}