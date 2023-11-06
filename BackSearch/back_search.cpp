//
// Created by 24195 on 2023/10/30.
//

#include "func.h"

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
