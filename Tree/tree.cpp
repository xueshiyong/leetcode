//
// Created by 24195 on 2023/11/6.
//
#include "../func.h"

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
    cout << endl;
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

int get_max_depth(TreeNode *root){
    if (root == nullptr){
        return 0;
    }

    int left_depth = get_max_depth(root->left);
    int right_depth = get_max_depth(root->right);

    int depth = max(left_depth, right_depth) + 1;
    return depth;

}

// 二叉树翻转
TreeNode *inverse_tree(TreeNode *root){
    if (root == nullptr){
        return root;
    }

    swap(root->left, root->right);
    inverse_tree(root->left);
    inverse_tree(root->right);
    return root;
}

// 二叉树翻转栈

TreeNode* inverse_tree_sal(TreeNode *root){
    if (root == nullptr) return root;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* node = st.top();              // 中
        st.pop();
        swap(node->left, node->right);
        if(node->right) st.push(node->right);   // 右
        if(node->left) st.push(node->left);     // 左
    }
    return root;
}

// 二叉树翻转 队列
TreeNode *lever_inverse_tree(TreeNode *root){
    queue<TreeNode *> que;
    if (root == nullptr){
        return root;
    }
    que.push(root);

    while (!que.empty()){
        int size = que.size();
        for (int i = 0; i < size; i++){
            TreeNode *node = que.front();
            que.pop();
            swap(node->right, node->left);

            if (node->left){
                que.push(node->left);
            }

            if (node->right){
                que.push(node->right);
            }

        }
    }
    return root;
}

bool compare(TreeNode *left, TreeNode *right){
    if (left == nullptr and right == nullptr){
        return true;
    }
    else if (left != nullptr and right == nullptr){
        return false;
    }
    else if (left == nullptr and right != nullptr){
        return false;
    }
    else if (left->val != right->val){
        return false;
    }

    bool in_com = compare(left->right, right->left);
    bool out_com = compare(left->left, right->right);

    return in_com and out_com;

}

bool IsSym(TreeNode *root){
    if (root == nullptr){
        return true;
    }

    return compare(root->left, root->right);
}

bool que_is_sym(queue<TreeNode *> que){
    vector<int> arr;

    while (!que.empty()){
        arr.push_back(que.front()->val);
        que.pop();
    }

    int i = 0;
    int j = arr.size() - 1;
    while (i < j){
        if (arr[i] != arr[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;


}

bool lever_is_Sym(TreeNode *root){
    if (root == nullptr){
        return true;
    }

    queue<TreeNode *> que;
    que.push(root->left);
    que.push(root->right);

    while (!que.empty()){
        TreeNode *left = que.front();
        que.pop();
        TreeNode *right = que.front();
        que.pop();

        if (left == nullptr and right == nullptr){
            continue;
        }

        if ((left != nullptr and right == nullptr)){
            return false;
        }

        if (left == nullptr and right != nullptr){
            return false;
        }

        if (left->val != right->val){
            return false;
        }

        que.push(left->left);
        que.push(right->right);
        que.push(left->right);
        que.push(right->left);

    }
    return true;
}


int get_min_depth(TreeNode *root){
    if (root == nullptr){
        return 0;
    }

    int left_depth = get_min_depth(root->left);
    int right_depth = get_min_depth(root->right);

    if (root->left != nullptr and root->right == nullptr){
        return 1 + left_depth; // 如果左子树非空，右子树空，回复左边的最低点
    }

    if (root->right != nullptr and root->left == nullptr){
        return 1 + right_depth; //
    }

    return 1 + min(left_depth, right_depth); // 两者都不，就找左右子树的最低点
}

int lever_get_min_depth(TreeNode *root){
      int depth = 0;
      queue<TreeNode *> que;
      que.push(root);

      while (!que.empty()){
          int size = que.size();
          depth++;
          for (int i = 0; i < size; i++){
              TreeNode *node = que.front();
              que.pop();


              if (node->left == nullptr and node->right == nullptr){
                  return depth;
              }

              if (node->left){
                  que.push(node->left);
              }
              if (node->right){
                  que.push(node->right);
              }
          }
      }
      cout << "min_depth: " << depth << endl;

}

int nums_of_root(TreeNode *root){
    if (root == nullptr){
        return 0;
    }

    int nums_of_left = nums_of_root(root->left);
    int nums_of_right = nums_of_root(root->right);

    return 1 + nums_of_left + nums_of_right;
}

vector<vector<int>> lever_total_root_path(TreeNode *root){

}

void total_root_path(TreeNode *root, vector<int> &path, vector<vector<int>> &res){
    path.push_back(root->val);
    if (root->left == nullptr and root->right == nullptr){
        res.push_back(path);
        return;
    }


    if (root->left){
        total_root_path(root->left, path, res);
        path.pop_back(); // 回溯算法
    }


    if (root->right){
        total_root_path(root->right, path, res);
        path.pop_back();
    }

}

int lever_sum_left_grass(TreeNode *root){
    queue<TreeNode *> que;
    if (root == nullptr){
        return 0;
    }

    que.push(root);
    int sum = 0;
    while (!que.empty()){
        int size = que.size();
        for (int i = 0; i < size; i++){
            TreeNode *node = que.front();
            que.pop();
            if (i == 0){
                if (node->left == nullptr and node->right == nullptr){ // 每一行第一个左子叶
                    sum += node->val;
                }

            }


            if (node->left){
                que.push(node->left);
            }

            if (node->right){
                que.push(node->right);
            }
        }
    }
    return sum;

}

void sum_left_grass(TreeNode *root, int &sum){ // 左子叶点之和
    if (root == nullptr){
        return;
    }

    if (root->left != nullptr and root->left->left == nullptr and root->left->right == nullptr){
        sum += root->left->val;
    } // 中

    sum_left_grass(root->left, sum);
    sum_left_grass(root->right, sum);

}

//
TreeNode *bulid_max_tree(vector<int> arr) {
    if (arr.size() == 0){
        return nullptr;
    }
    int max_value = arr[0];
    int root_loc = 0;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] > max_value){
            max_value = arr[i];
            root_loc = i;
        }
    }

    vector<int> left_arr;
    for (int i = 0; i < root_loc; i++){
        left_arr.push_back(arr[i]);
    }

    vector<int> right_arr;
    for (int i = root_loc + 1; i < arr.size(); i++){
        right_arr.push_back(arr[i]);
    }

    TreeNode *root = new TreeNode(arr[root_loc]);
    root->left = bulid_max_tree(left_arr);
    root->right = bulid_max_tree(right_arr);

    return root;
}

TreeNode *find_search_tree_val(TreeNode *root, int val){
    if (root->val == val or root == nullptr){
        return root;
    }

    TreeNode *res = nullptr;
    if (val < root->val){
        res = find_search_tree_val(root->left, val);
    }
    if (val > root->val){
        res = find_search_tree_val(root->right, val);
    }

    return res;
}

TreeNode *find_tree_val_sal(TreeNode *root, int val){
    if (root == nullptr){
        return nullptr;
    }

    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty()){
        int size = que.size();
        for (int i = 0; i < size; i++){
            TreeNode *node = que.front();
            que.pop();

            if (node->val == val){
                return node;
            }

            if (node->left){
                que.push(node->left);
            }

            if (node->right){
                que.push(node->right);
            }

        }
    }
    cout << endl;
    return nullptr;
}

bool Is_Search_Tree(TreeNode *root){
    vector<int> res;
    Inorder(root, res);
    for (int i = 1; i < res.size(); i++){
        if (res[i] < res[i-1]){
            return false;
        }
    }
    return true;
}

int abs_value(int a, int b){
    if (a > b){
        return a - b;
    }
    else{
        return b - a;
    }
}


int min_absolute_diff_sal(TreeNode *root){
    if (root == nullptr){
        return -1;
    }

    int min_value = INT32_MAX;
    int left_value;
    int right_value;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()){
        int size = que.size();
        for (int i = 0; i < size; i++){
            TreeNode *node = que.front();
            que.pop();

            if (node->left){
                left_value = abs_value(node->val, node->left->val);
                que.push(node->left);
            }

            if(node->right){
                right_value = abs_value(node->val, node->right->val);
            }

            min_value = min(min_value, min(left_value, right_value));
        }
    }
    return min_value;

}

TreeNode *merge_root(TreeNode *root1, TreeNode *root2){

}
