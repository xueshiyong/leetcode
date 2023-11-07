//
// Created by 24195 on 2023/11/7.
//
#include "func.h"

int map_path(int rows, int cols){
    vector<vector<int>> dp(rows, vector<int>(cols, 1));
    for (int i = 1; i < rows; i++){
        for (int j = 1; j < cols; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[rows - 1][cols - 1];
}

int map_obstacle_path(vector<vector<int>> &map, vector<vector<int>> &obstacles){
    int rows = map.size();
    int cols = map[0].size();

    vector<vector<int>> dp(rows, vector<int> (cols, 1));

    int i = 0;
    while (i < rows){
        if (obstacles[i][0] == 1){
            break;
        }
        dp[i][0] = 1;
        i++;
    }

    int temp_x = i;
    for (int row = temp_x; row < rows; row++){
        dp[row][0] = 0;
    }

    int j = 0;
    while (j < cols){
        if (obstacles[0][j] == 1){
            break;
        }
        dp[0][j] = 1;
        j++;
    }

    int temp_y = j;
    for (int col = temp_y; col < cols; col++){
        dp[0][col] = 0;
    }

    for (i = 1; i < rows; i++){
        for (int j = 1; j < cols; j++){
            if (obstacles[i][j] == 1){
                dp[i][j] = 0;
            }
            dp[i][j] = dp[i - 1][j]  + dp[i][j - 1];
        }
    }
    return dp[rows - 1][cols - 1];

}

int Febi(int n){
    if (n == 0){
        return 1;
    }

    if (n == 1){
        return 1;
    }

    return Febi(n - 1) + Febi(n - 2);
}

int Febi_dp(int n){
    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int V_bags(vector<int> &weights, vector<int> &prices, int Volume){
    int size = weights.size();
    vector<vector<int>> dp(size, vector<int>(Volume + 1, 0));

    for (int j = weights[0]; j <= Volume; j++){
        dp[0][j] = prices[0];
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j <= Volume; j++){
            if (j >= weights[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i]] + prices[i]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[size - 1][Volume];
}