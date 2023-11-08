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

void PostOrder(TreeNode *root){
    if (root == nullptr){
        return;
    }

    Inorder(root->left);
    Inorder(root->right);
    cout << root->val << " ";
}


void leverorder(TreeNode *root){
    if (root == nullptr){
        return;
    }

    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty()){
        int size = que.size();
        for (int i = 0; i < size; i++){
            TreeNode *node = que.front();
            que.pop();
            cout << node->val << " ";
            if (node->left){
                que.push(node->left);
            }

            if (node->right){
                que.push(node->right);
            }
        }
        cout << endl;
    }
}


void preorderval(TreeNode *root){
    stack<TreeNode *> st;
    if (root == nullptr){
        return;
    }
    st.push(root);

    while (!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        cout << node->val << " ";
        if (node->left){
            st.push(node->left);
        }

        if (node->right){
            st.push(node->right);
        }
    }
}

void Inorder(TreeNode *root, vector<int> &in_arr){
    if (root == nullptr){
        return;
    }
    Inorder(root->left, in_arr);
    in_arr.push_back(root->val);
    Inorder(root->right, in_arr);
}

void Preorder(TreeNode *root, vector<int> &pre_arr){
    if (root == nullptr){
        return;
    }

    pre_arr.push_back(root->val);
    Preorder(root->left, pre_arr);
    Preorder(root->right, pre_arr);
}

void PostOrder(TreeNode *root, vector<int> &post_arr){
    if (root == nullptr){
        return;
    }

    PostOrder(root->left, post_arr);
    PostOrder(root->right, post_arr);
    post_arr.push_back(root->val);
}

// 中序和前序
TreeNode *rebuilt_tree(vector<int> &in_arr, vector<int> &pre_arr){
    if (in_arr.size() == 0){
        return nullptr;
    }
    TreeNode *root = new TreeNode(pre_arr[0]);

    vector<int> left_in_arr, left_pre_arr;
    vector<int> right_in_arr, right_pre_arr;

    int start = 0;
    while (in_arr[start] != pre_arr[0]){
        start++;
    } // 获得根节点的位置

    int root_location = start;
    for (int i = 0; i < root_location; i++){
        left_in_arr.push_back(in_arr[i]);
    }
    for (int i = root_location + 1; i < in_arr.size(); i++){
        right_in_arr.push_back(in_arr[i]);
    }

    for (int i = 1; i <= root_location; i++){
        left_pre_arr.push_back(pre_arr[i]);
    }

    for (int i = root_location + 1; i < pre_arr.size(); i++){
        right_pre_arr.push_back(pre_arr[i]);
    }

    root->left = rebuilt_tree(left_in_arr, left_pre_arr);
    root->right = rebuilt_tree(right_in_arr, right_pre_arr);

    return root;

}

// 中序和后序

TreeNode *rebuilt_tree_other(vector<int> &in_arr, vector<int> &post_arr){
    if (in_arr.size() == 0){
        return nullptr;
    }

    TreeNode *root = new TreeNode(post_arr[post_arr.size() - 1]);

    vector<int> left_in_arr, right_in_arr;
    vector<int> left_post_arr, right_post_arr;

    int start = 0;

    while (in_arr[start] != post_arr[post_arr.size() - 1]){
        start++;
    }

    int root_location = start;
    for (int i = 0; i < root_location; i++){
        left_in_arr.push_back(in_arr[i]);
        left_post_arr.push_back(post_arr[i]);
    }

    for (int i = root_location + 1; i < in_arr.size(); i++){
        right_in_arr.push_back(in_arr[i]);
    }

    for (int i = root_location; i < post_arr.size() - 1; i++){
        right_post_arr.push_back(post_arr[i]);
    }

    root->left = rebuilt_tree_other(left_in_arr, left_post_arr);
    root->right = rebuilt_tree_other(right_in_arr, right_post_arr);
    return root;

}

