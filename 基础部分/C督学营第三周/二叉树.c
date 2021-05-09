//
// Created by XuanLang Z on 2021/3/20.
//
#include " 二叉树.h"
#define N 10
void build_tree()
{
    pNode tree_root = NULL;
    char c[N+1]="ABCDEFGHIJ";
    pNode p[N+1];
    int j;
    for (int i = 0; i < N; ++i) {
        p[i] = (pNode)calloc(1,sizeof (tnode));
        p[i]->c=c[i];
    }
    for (int i=0;i<N;i++)
    {
        if (tree_root==NULL)//树为空
        {
            tree_root=p[i];
            j=0;
        } else{
            if (p[j]->left==NULL)//判断左边是否有东西，双指针j用来选当前加子元素的节点，i用来表示要加的东西
            {
                p[j]->left=p[i];
            } else if (p[j]->right==NULL)
            {
                p[j]->right=p[i];
                j++;
            }
        }
    }
    pre_order(tree_root);
    printf("\n----------------------\n");
    mid_order(tree_root);
    printf("\n----------------------\n");

    lat_order(tree_root);
}

void pre_order(pNode tree)
{
    if (tree)
    {
        putchar(tree->c);
        pre_order(tree->left);
        pre_order(tree->right);
    }
}

void mid_order(pNode tree)
{
    if (tree)
    {
        pre_order(tree->left);
        putchar(tree->c);
        pre_order(tree->right);
    }
}

void lat_order(pNode tree)
{
    if (tree)
    {
        pre_order(tree->left);
        pre_order(tree->right);
        putchar(tree->c);
    }
}

void build_new_tree()
{
    pNode
}

int main()
{
    build_tree();
}