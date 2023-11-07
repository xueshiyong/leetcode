//
// Created by 24195 on 2023/10/30.
//

#include "func.h"
vector<string> digits = {"__", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

bool IsValid(int row, int col, char_Martix chess){
    for (int i = 0; i < row; i++){
        if (chess[i][col] == 'Q'){
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--){
        if (chess[i][j] == 'Q'){
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 and j <= chess[0].size(); i--, j++){
        if (chess[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}
void Queen(char_Martix &chess, int row, int n, vector<char_Martix> &res){
    if (row == n){
        res.push_back(chess);
    }

    for (int col = 0; col < n; col++){
        if (IsValid(row, col, chess)){
            chess[row][col] = 'Q';
            Queen(chess, row + 1, n, res);
            chess[row][col] = '.';
        }
    }
}

bool IsPalic(string s, int start, int end){
    int i = start;
    int j = end;

    while (i < j){
        if (s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void max_len_of_sub_son(string &s, int &max_len, int startIndex, vector<string> &path, vector<vector<string>> &res){
    if (startIndex > s.size()){
        return;
    }
    res.push_back(path);

    for (int i = startIndex; i < s.size(); i++){
        if (IsPalic(s, startIndex, i)){
            string s_sub = s.substr(startIndex, i - startIndex + 1);
            path.push_back(s_sub);
            if (i - startIndex + 1 > max_len){
                max_len = i - startIndex + 1;
            }
        }
        else{
            continue;
        }
        max_len_of_sub_son(s, max_len, i + 1, path, res);
        path.pop_back();
    }

}

void back_combination_digits(string s, int startIndex, vector<char> &path, vector<vector<char>> &res){
    if (startIndex >= s.size()){
        if (startIndex == s.size()){
            res.push_back(path);
        }
        return;
    }

    int index = s[startIndex] - '0';
    string str = digits[index];

    for (int i = 0; i < str.size(); i++){
        path.push_back(str[i]);
        back_combination_digits(s, startIndex + 1, path, res);
        path.pop_back();
    }
}

void back_track_son_arr(vector<int> &arr, int k, int startIndex, vector<int> &path, vector<vector<int>> &res) {
    if (path.size() == k){
        res.push_back(path);
        return;
    }

    for (int i = startIndex; i < arr.size(); i++){
        path.push_back(arr[i]);
        back_track_son_arr(arr, k, i + 1, path, res);
        path.pop_back();
    }
}

void back_track_arange_arr(vector<int> arr, int k, vector<int> &used, vector<int> &path, vector<vector<int>> &res){
    if (path.size() == k){
        res.push_back(path);
        return;
    }

    for (int i = 0; i < arr.size(); i++){
        if (used[i] == 0){
            path.push_back(arr[i]);
            used[i] = 1;
            back_track_arange_arr(arr, k, used, path, res);
            used[i] = 0;
            path.pop_back();
        }
    }
}


void Print_vec_char(vector<char> &path){
    for (int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

void Print_two_vec_char(vector<vector<char>> &res){
    for (int i = 0; i < res.size(); i++){
        Print_vec_char(res[i]);
    }
    cout << endl;
}

void Print_vec_string(vector<string> &path){
    int size = path.size();
    for (int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

void Print_two_vec_string(vector<vector<string>> &res){
    for (int i = 0; i < res.size(); i++){
        Print_vec_string(res[i]);
    }
    cout << endl;
}

void Print_vec_int(vector<int> &path){
    for (int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;

}
void Print_two_vec_int(vector<vector<int>> &res){
    for (int i = 0; i < res.size(); i++){
        Print_vec_int(res[i]);
    }
    cout << endl;
}
