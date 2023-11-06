//
// Created by 24195 on 2023/11/6.
//

#include "func.h"

void InsertTreeNode(TreeNode *&root, int x){ // &引用,使用root的地址
    if (root == nullptr){
        root = new TreeNode(x);             // 如果此时的root为空指针，将当前的数制作为节点并且连接到root上
        return;
    }

    if (x < root->val){
        InsertTreeNode(root->left, x);  // 如果当前的值小于root的值，则应该将这个指针连接到root的左边
    }

    if (x > root->val){
        InsertTreeNode(root->right, x);
    }
}

TreeNode *CreateSearchTree(vector<int> &arr){
    TreeNode *root = nullptr;
    for (int i = 0; i < arr.size(); i++){
        InsertTreeNode(root, arr[i]);
    }
    return root;
}

TreeNode *CreateBiTree(vector<int> &arr, int index){
    if (arr[index] == '#'){
        return nullptr; // 填补空缺位置，可以自定义
    }

    TreeNode *root = new TreeNode(arr[index]);

    int left_index = 2 * index + 1;
    int right_index = 2 * index + 2; // 数组转换为树的方式

    if (left_index < arr.size()){
        root->left = CreateBiTree(arr, left_index);
    }
    else{
        root->left = nullptr;
    }

    if (right_index < arr.size()){
        root->right = CreateBiTree(arr, right_index);
    }
    else{
        root->right = nullptr;
    }

    return root;

}

void Inorder(TreeNode *root){
    if (root == nullptr){
        return;
    }

    Inorder(root->left);
    cout << root->val << " ";
    Inorder(root->right);
}