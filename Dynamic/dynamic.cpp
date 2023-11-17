//
// Created by 24195 on 2023/11/7.
//
#include "../func.h"

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

    for (int i = 1; i < size; i++){
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

int V_bags_two(vector<int> &weights, vector<int> &prices, int Volume) {
    int size = weights.size();
    vector<int> dp(Volume + 1, 0);

    for (int i = 0; i < size; i++) {
        for (int j = Volume; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + prices[i]);
        }
    }
    return dp[Volume];
}

int left_min_stone(vector<int> &stones){
    int sum = 0;
    for (int i = 0; i < stones.size(); i++){
        sum += stones[i];
    }
    int size = stones.size();

    QuickSort(stones, 0, stones.size() - 1);
    int target = sum / 2;
    vector<int> dp(target + 1, 0);

    for (int i = 0; i < size; i++){
        for (int j = target; j >= stones[i]; j--){
            dp[j] = max(dp[j-1], dp[j - stones[i]] + stones[i]);
        }
    }

    return sum - 2 * dp[target];
}

bool IsValidOperator(vector<int> &arr, int target){
    int size = arr.size();
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }

    int V = sum + target;
    if (V % 2 == 1 or target > sum){
        return false;
    }
    vector<int> dp(V / 2 + 1, 0);
    QuickSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = V / 2; j >= arr[i]; j--) {
            dp[j] = max(dp[j - 1], dp[j - arr[i]] + arr[i]);
        }

    }
    if (dp[V / 2] == V / 2){
        return true;
    }
    return false;

}

int split_max_int(int n){
    vector<int> dp(n + 1, 0);
    dp[2] = 1;

    for (int i = 3; i <= n; i++){
        for (int j = 1; j < i - 1; j++){
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }
    return dp[n];
}

int absolute_bags(vector<int> &weights, vector<int> &prices, int Volume){
    int m = weights.size();
    int n = Volume + 1;

    vector<int> dp(n, 0);
    for (int i = 0; i < m; i++){
        for (int j = weights[i]; j < n; j++){
            dp[j] = max(dp[j], dp[j - weights[i]] + prices[i]);
        }
    }
    return dp[n - 1];
}

int coins_change(vector<int> &coins, int amount){
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++){
        for (int j = coins[i]; j <= amount; j++){
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];

}

// 先遍历目标，再遍历数组，那么就有排列的方式
int sum_of_combination(vector<int> &nums, int target){
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < target + 1; j++){
        for (int i = 0; i < nums.size(); i++){
            if (j >= nums[i]){
                dp[j] += dp[j - nums[i]];
            }
        }
    }
    return dp[target];
}