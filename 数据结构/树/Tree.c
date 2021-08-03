//
// Created by XuanLang Z on 2021/7/24.
//

#include "Tree.h"

int main()
{
    pNode root = initTree();
    preorder(root);
    inorder(root);
    return 0;
}