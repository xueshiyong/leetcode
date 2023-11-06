//
// Created by 24195 on 2023/10/27.
//

#include "func.h"
#include "Math_fun/math_fun.h"

int main() {
    vector<int> arr = {4, 2, 5, 1, 6, 7, 3};
    TreeNode *root = CreateBiTree(arr, 0);
    Inorder(root);
}

