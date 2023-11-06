//
// Created by 24195 on 2023/10/27.
//

#ifndef LEETCODE_FUNC_H
#define LEETCODE_FUNC_H
#include <vector>
#include <cfloat>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

struct ListNode{
    int val;
    ListNode *next, *prev;
    ListNode(){}
    ListNode(int x):val(x), next(nullptr), prev(nullptr){}
};

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

void InsertTreeNode(TreeNode *&root, int x);
TreeNode *CreateSearchTree(vector<int> &arr);
TreeNode *CreateBiTree(vector<int> &arr, int index);

// 中序输出树
void Inorder(TreeNode *root);
// 层序输出树
void leverorder(TreeNode *root);
// 栈输出树
void preorderval(TreeNode *root);
void preorder_travesal(TreeNode *root);


// 链表相关函数
ListNode *CreateList(vector<int> &arr);
ListNode *add_list(ListNode *head, ListNode *node, int pos); //链表添加新的节点
ListNode *find_list(ListNode *head, int pos); // 查找链表的节点
ListNode *delete_list(ListNode *head, int pos); // 删除指定位置的节点
ListNode *change_list(ListNode *head, ListNode *node, int pos); // 修改指定位置的节点


void PrintList(ListNode *head);



typedef vector<vector<char>> char_Martix;
typedef vector<vector<double>> Martix;
typedef vector<double> Vector;

bool Is_vec_zeros(Vector vec);
Vector vec_scaler(Vector vec, double lamba, char op);
Vector vec_arithmetic_operation(Vector vec1, Vector vec2, double division, char op);
Vector vec_zeros(int n);
Vector vec_eyes(int n); //创建长度为n全为1.0的向量
Vector vec_create_range(double start, double end, double slide);
Vector vec_create_n(double start, double end, int n);
Vector mat_to_vec(Martix mat);

Martix mat_reshape(Martix mat, int single_shape, int axis);
Martix vec_to_mat(Vector vec, int single_shape, int axis);
Martix mat_add(Martix mat1, Martix mat2);
Martix mat_sub(Martix mat1, Martix mat2);
Martix mat_dot(Martix mat1, Martix mat2);
Martix mat_div(Martix mat1, Martix mat2);
Martix mat_product(Martix mat1, Martix mat2);
Martix mat_scalar(Martix mat, double lamda, char op);
Martix mat_transpose(Martix mat);
Martix mat_extract_row(Martix mat, int row);
Martix mat_extract_col(Martix mat, int col);
Martix mat_extract(Martix mat, int row, int col);
Martix merge(Martix mat1, Martix mat2);
Martix mat_merge(Martix mat1, Martix mat2, int axis);
Martix mat_swap(Martix mat, int start, int end, int axis);
Martix mat_inverse(Martix mat);
Martix mat_elementary(Martix mat);
void mat_elementary_part(Martix mat, Martix &mat_res, int mat_cols, bool IsSigle);
int elementary_matrix_rank(Martix mat);
double mat_det(Martix mat);
void PrintMartix(Martix mat);
void PrintVec(Vector vec);



int max_Volume(vector<int> heights);
bool IsPanic(string s, int start, int end);
void back_track_string(int &max_len, string s, int startIndex, vector<string> &path, vector<vector<string>>&res);
string string_mul(string s_num, int base);
string my_pow(int base, int index);

void back_track_son_string_num(int &num, string s, int startIndex, vector<string> &path, vector<vector<string>> &res);

// 回溯算法
bool IsValid(int row, int col, char_Martix chess);
void Queen(char_Martix &chess, int row, int n, vector<char_Martix> &res);
void max_len_of_sub_son(string &s, int &max_len, int startIndex, vector<string> &path, vector<vector<string>> &res); // 回溯算法子集



void Print_vec_string(vector<string> &path);
void Print_two_vec_string(vector<vector<string>> &res);

// 贪婪算法
int allocate_cookies(vector<int> children, vector<int> cookies);
bool jump_game(vector<int> &path);

// 排序算法
void BobbleSort(vector<int> &arr); // 1
void InsertSort(vector<int> &arr); // 2
void SelectSort(vector<int> &arr); // 3
void QuickSort(vector<int> &arr, int start, int end); // 4

void merge(vector<int> &arr, int start, int mid, int end);
void MergeSort(vector<int> &arr, int start, int end); // 5
void HeapSort(vector<int> &arr); //6
void ShellSort(vector<int> &arr); // 7
void BucketSort(vector<int> &arr); // 8
void CountSort(vector<int> &arr); // 9 计数排序
void BaseSort(vector<int> &arr); // 10 基数排序

void PrintSort(vector<int> &arr);

// 单调栈
int rainy(vector<int> &arr);
vector<int> next_max_value(vector<int> &arr); // 下一个最大值
vector<int> next_circle_max_value(vector<int> &arr);

#endif //LEETCODE_FUNC_H
