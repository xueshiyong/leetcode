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



