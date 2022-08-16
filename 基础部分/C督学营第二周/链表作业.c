#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
    int num;
    char name[10];
    int l1, l2, l3;
    struct student *pNext;
} stu;


void print1(stu s[]) {
    int nums[5];
    int idx = 0, idx_c = 0, i, j;
    for (i = 0; i < 5; i++)
    {
        for (idx_c = i - 1;idx_c >= 0; idx_c--)
        {
            if (s[i].num > s[nums[idx_c]].num) break;
        }
        j = i;
        for (;j > idx_c; j--)
        {
            nums[j + 1] = nums[j];
        }
        nums[idx_c + 1] = i;
    }
    for (i = 0; i < 5; i++) printf("%d %s %d, %d, %d\n", s[nums[i]].num, s[nums[i]].name, s[nums[i]].l1, s[nums[i]].l2, s[nums[i]].l3);
}


void print2(stu sarr []) {
    int i;
    stu best[3] = {sarr[0], sarr[0], sarr[0]};
    for (i = 0; i < 5; i++)
    {
        if (sarr[i].l1 > best[0].l1)
        {
            best[0] = sarr[i];
        }
        if (sarr[i].l2 > best[1].l2)
        {
            best[1] = sarr[i];
        }
        if (sarr[i].l3 > best[2].l3)
        {
            best[2] = sarr[i];
        }
    }
    printf("l1: %s, l2: %s, l3: %s\n", best[0].name, best[1].name, best[2].name);
}


void print_lesson_mean(stu sarr[]) {
    float res[3] = {0};
    int i, j;
    for (i = 0; i < 5; i++)
    {
        res[0] += sarr[i].l1;
        res[1] += sarr[i].l2;
        res[2] += sarr[i].l3;
    }
    for (j = 0; j < 3; j++)
    {
        res[j] /= 5;
    }
    printf("l1_mean: %.2f, l2_mean: %.2f, l3_mean: %.2f\n", res[0], res[1], res[2]);
}


void print_total_rank(stu sarr[]) {
    stu *p = sarr;
    stu temp;
    int i, j;
    float t_j, t_j_1;
    for (i = 0; i < 5; i++)
    {
        for (j = 4; j > i; j--)
        {
            t_j = p[j].l1 + p[j].l2 + p[j].l3;
            t_j_1 = p[j-1].l1 + p[j-1].l2 + p[j-1].l3;
            if (t_j_1 > t_j)
            {
                temp = p[j];
                p[j] = p[j - 1];
                p[j - 1] = temp;
            }
        }
    }
    for (i = 0; i < 5; i++) printf("%s,", p[i].name);

}

void tail(stu **head, stu **tail, int num) {
    stu *node;
    node = (stu *) malloc(sizeof(stu));
    memset(node, 0, sizeof(stu));
    node->num = num;
    if ((*tail) == NULL) {
        *head = node;
        *tail = node;
    } else {
        (*tail)->pNext = node;
        *tail = node;
    }
    (*tail)->pNext = NULL;
}

void head(stu **head, stu **tail, int num) {
    stu *node;
    node = (stu*)malloc(sizeof(stu));
    memset(node, 0, sizeof(stu));
    node->num = num;
    if ((*tail) == NULL)
    {
        *head = node;
        *tail = node;
    }
    else
    {
        node->pNext = *head;
        *head = node;
    }
}

void sort(stu **head, stu **tail, int num) {
    stu *p = *head;
    stu *node;
    node = (stu*)malloc(sizeof(stu));
    memset(node, 0, sizeof(stu));
    node->num = num;
    if ((*tail) == NULL)
    {
        *head = node;
        *tail = node;
    }
    else
    {
        if (num < p->num)
        {
            node->pNext = *head;
            *head = node;
        }
        else
        {
            while (1)
            {
                if (p->pNext != NULL)
                {
                    if (num < p->pNext->num)
                    {
                        node->pNext = p->pNext;
                        p->pNext = node;
                        break;
                    }
                }
                else
                {
                    p->pNext = node;
                    *tail = node;
                    break;
                }
                p = p->pNext;
            }
        }
    }
    (*tail)->pNext = NULL;
}


void del(stu **head, stu **tail, int num) {
    stu *p = *head;
    stu *temp;
    if ((*tail) != NULL)
    {
        if (num == p->num)
        {
            temp = *head;
            *head = (*head)->pNext;
            free(temp);
        }
        else
        {
            while (p->pNext != NULL)
            {
                if (num == p->pNext->num)
                {
                    temp = p->pNext;
                    p->pNext = p->pNext->pNext;
                    free(temp);
                    break;
                }
                p = p->pNext;
            }
        }
    }
}
int main()
{
    stu sarr[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d %s %d %d %d", &(sarr[i].num), sarr[i].name, &(sarr[i].l1), &(sarr[i].l2), &(sarr[i].l3));
    }
    print_total_rank(sarr);

    return 0;
}