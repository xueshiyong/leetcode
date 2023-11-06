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

// 贪婪算法
int allocate_cookies(vector<int> children, vector<int> cookies);
bool jump_game(vector<int> &path);

// 排序算法
void BobbleSort(vector<int> &arr);
void InsertSort(vector<int> &arr);
void SelectSort(vector<int> &arr);
void QuickSort(vector<int> &arr, int start, int end);

void merge(vector<int> &arr, int start, int mid, int end);
void MergeSort(vector<int> &arr, int start, int end);
void HeapSort(vector<int> &arr);


#endif //LEETCODE_FUNC_H
