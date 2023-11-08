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
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct ListNode{
    int val;
//    string str;
    ListNode *next, *prev;
    ListNode(){}
    ListNode(int x):val(x), next(nullptr), prev(nullptr){}
}; // 实现链表节点，链表节点内容可以自定义

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
}; // 实现树的节点，树节点内容可以自定义

// 数组
pair<int, int> two_sum(vector<int> &arr, int target);
vector<vector<int>> Three_sum(vector<int> &arr, int target);
int binary_search(vector<int> &arr, int target);
int removeVal(vector<int> &arr, int val);
vector<int> square_of_nums(vector<int> &arr);
int min_len_arr(vector<int> &arr, int target);

vector<vector<int>> spiral_array(int m, int n);




// 创建树
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

// 测试函数
void testing_list();
void testing_back_search();
void test_dynamic();
void test_vector();
void test_hash();

// 单向链表相关函数
ListNode *CreateList(vector<int> &arr);
ListNode *add_list(ListNode *head, ListNode *node, int pos); //链表添加新的节点
ListNode *find_list(ListNode *head, int pos); // 查找链表的节点
ListNode *delete_list(ListNode *head, int pos); // 删除指定位置的节点
ListNode *change_list(ListNode *head, ListNode *node, int pos); // 修改指定位置的节点
int length_of_list(ListNode *head); // 链表的长度

// 循环链表相关函数
ListNode *CreateCircleList(vector<int> &arr);
ListNode *CrossIndexList(ListNode *head);
bool IsCircleList(ListNode *head);
// 链表题目
ListNode *last_k_list(ListNode *head, int k);
ListNode *get_tail(ListNode *head);
ListNode *two_sum_of_list(ListNode *head1, ListNode *head2);
ListNode *reverse_list(ListNode *head);
ListNode *list_cross_node(ListNode *head1, ListNode *head2);
ListNode *swap_near_node(ListNode *head);

// 哈希表
bool IsoWords(string s1, string s2);
vector<int> cross_arr(vector<int> &arr1, vector<int> &arr2);
int sum_bits(int n);
bool isHappy(int n);


// 矩阵算法题目
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
void back_combination_digits(string s, int startIndex, vector<char> &path, vector<vector<char>> &res);
bool IsValid(int row, int col, char_Martix chess);
void Queen(char_Martix &chess, int row, int n, vector<char_Martix> &res);
void max_len_of_sub_son(string &s, int &max_len, int startIndex, vector<string> &path, vector<vector<string>> &res);
void back_track_son_arr(vector<int> &arr, int k, int startIndex, vector<int> &path, vector<vector<int>> &res);
void back_track_arange_arr(vector<int> arr, int k, vector<int> &used, vector<int> &path, vector<vector<int>> &res);


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

// 动态规划
int map_path(int rows, int cols);
int map_obstacle_path(vector<vector<int>> &map, vector<vector<int>> &obstacles);
int Febi(int n);
int Febi_dp(int n);
int V_bags(vector<int> &weights, vector<int> &prices, int Volume);
int V_bags_two(vector<int> &weights, vector<int> &prices, int Volume);
int left_min_stone(vector<int> &stones);
bool IsValidOperator(vector<int> &arr, int target);
int split_max_int(int n);


// 输出
void PrintCircleList(ListNode *head);
void PrintList(ListNode *head);
void Print_vec_char(vector<char> &path);
void Print_two_vec_char(vector<vector<char>> &res);
void Print_vec_string(vector<string> &path);
void Print_two_vec_string(vector<vector<string>> &res);
void Print_vec_int(vector<int> &path);
void Print_two_vec_int(vector<vector<int>> &res);

#endif //LEETCODE_FUNC_H
