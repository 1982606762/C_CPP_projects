//
// Created by XuanLang Z on 2021/10/19.
//
#include<stdio.h>
void zero_back(int start[], int array[], int *zero_place, int length)
{
    int i;
    int temp;
    for (i = 0; i < length-1; i++)
    {
        temp = start[*zero_place];
        start[*zero_place] = start[array[i + 1]];
        start[array[i + 1]] = temp;
        *zero_place = array[i + 1];
    }
    temp = start[*zero_place];
    start[*zero_place] = start[array[0]];
    start[array[0]] = temp;
    *zero_place = array[0];
    return;
}

void zero_move(int start[], int array[], int *zero_place, int length, int _flag)
{
    int i;
    int j = 0;
    int temp;
    for (i = 0; i < length; i++)
    {
        if (array[i] == *zero_place)
        {
            j = i;
            break;
        }
    }
    if (j < length - 1)
    {
        temp = start[*zero_place];
        start[*zero_place] = start[array[j + 1]];
        start[array[j + 1]] = temp;
        *zero_place = array[j + 1];
    }
    else
    {
        if (_flag == 1)
        {
            temp = start[*zero_place];
            start[*zero_place] = start[array[0]];
            start[array[0]] = temp;
            *zero_place = array[0];
        }
        else
        {
            temp = start[*zero_place];
            start[*zero_place] = start[array[5]];
            start[array[5]] = temp;
            *zero_place = array[5];
        }
    }
    return;
}

void _input(int start[])
{
    int i;
    printf("输入初始状态：\n");
    for (i = 0; i < 9; i++)
    {
        scanf("%d", &start[i]);
        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
    }
}
void _print(int start[])
{
    int i;
    for (i = 0; i < 9; i++)
    {
        printf("%d\t", start[i]);
        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
    }
}

int main()
{
    int i;
    int switch_case;
    int start[9];
    int zero_place;

    int array_m[9] = { 8,7,6,3,0,1,2,5,4 };
    int array_a[8] = { 0,3,6,7,8,5,4,1 };
    int array_b[8] = { 3,6,7,8,5,2,1,4 };
    int array_c[6] = { 3,6,7,8,5,4 };
    int array_d[8] = { 3,0,1,4,5,2,1,0 };
    int array_e[6] = { 3,6,7,8,5,4 };
    int array_f[4] = { 3,6,7,4 };
    int array_g[13] = { 3,0,1,2,5,4,7,8,5,2,1,0,3 };
    int array_h[4] = { 3,6,7,4 };

    _input(start);
    for (i = 0; i < 9; i++)
    {
        if (start[i] == 0)
        {
            zero_place = i;
            break;
        }
    }
    switch_case = 1;
    while (switch_case < 10)
    {
        switch (switch_case)
        {
            case 1:
                for (i = 0; i < 50; i++)
                {
                    if (start[2] != 0 && start[2] != 1)
                    {
                        switch_case = 2;
                        break;
                    }
                    else
                    {
                        zero_move(start, array_m, &zero_place, 9, 0);
                    }
                }
                printf("step 1\n");
                _print(start);
                break;
            case 2:
                for (i = 0; i < 50; i++)
                {
                    if (start[0] == 1)
                    {
                        switch_case = 3;
                        break;
                    }
                    else
                    {
                        zero_move(start, array_a, &zero_place, 8, 1);
                    }
                }
                printf("step 2\n");
                _print(start);
                break;
            case 3:
                for (i = 0; i < 50; i++)
                {
                    if (start[1] == 2)
                    {
                        if (start[2] == 3)
                        {
                            switch_case = 6;
                        }
                        else
                        {
                            switch_case = 4;
                        }
                        break;
                    }
                    else
                    {
                        zero_move(start, array_b, &zero_place, 8, 1);
                    }
                }
                printf("step 3\n");
                _print(start);
                break;
            case 4:
                for (i = 0; i < 50; i++)
                {
                    if (start[4] == 3)
                    {
                        switch_case = 5;
                        break;
                    }
                    else
                    {
                        zero_move(start, array_c, &zero_place, 6, 1);
                    }
                }
                printf("step 4\n");
                _print(start);
                break;
            case 5:
                zero_back(start, array_d, &zero_place, 8);
                switch_case = 6;
                printf("step 5\n");
                _print(start);
                break;
            case 6:
                for (i = 0; i < 50; i++)
                {
                    if (start[5] == 4)
                    {
                        if (start[8] == 5)
                        {
                            switch_case = 9;
                        }
                        else
                        {
                            switch_case = 7;
                        }
                        break;
                    }
                    else
                    {
                        zero_move(start, array_e, &zero_place, 6, 1);
                    }
                }
                printf("step 6\n");
                _print(start);
                break;
            case 7:
                for (i = 0; i < 100; i++)
                {
                    if (start[4] == 5)
                    {
                        switch_case = 8;
                        break;
                    }
                    else
                    {
                        zero_move(start, array_f, &zero_place, 4, 1);
                    }
                }
                printf("step 7\n");
                _print(start);
                break;
            case 8:
                zero_back(start, array_g, &zero_place, 13);
                switch_case = 9;
                printf("step 8\n");
                _print(start);
                break;
            case 9:
                for (i = 0; i < 50; i++)
                {
                    if (start[7] == 6&&start[4]==0)
                    {
                        if (start[3] == 8 && start[6] == 7)
                        {
                            printf("问题有解，达到目标状态\n");
                        }
                        else
                        {
                            printf("问题无解，达不到目标状态\n");
                        }
                        switch_case = 10;
                        break;
                    }
                    else
                    {
                        zero_move(start, array_h, &zero_place, 4, 1);
                    }
                }
                printf("step 9\n");
                _print(start);
                break;
            default:
                break;
        }
    }
}
