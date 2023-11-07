//
// Created by 24195 on 2023/11/7.
//
#include "func.h"

int max_Volume(vector<int> heights){
    int i = 0;
    int j = heights.size() - 1;

    int max_value = 0;
    while (i < j){
        int current_value = min(heights[i], heights[j]) * (j - i);
        if (current_value > max_value){
            max_value = current_value;
        }

        if (heights[i] < heights[j]){
            i++;
        }
        else{
            j--;
        }
    }

    return max_value;

}

int binary_search(vector<int> &arr, int target){
    int left = 0;
    int right = arr.size() - 1;

    while (left < right - 1){
        int mid = (left + right) / 2;
        if (target < arr[mid]){
            right = mid;
        }
        else if (target > arr[mid]){
            left = mid;
        }
        else if (target == arr[mid]){
            return mid;
        }
    }
    return -1;
}


int removeVal(vector<int> &arr, int val){
    int fast = 0;
    int slow = 0;
    int size = arr.size();

    while (fast < size){
        while (arr[fast] == val){
            fast++;
        }
        arr[slow] = arr[fast];

        slow++;
        fast++;
    }
    return slow;
}

vector<int> square_of_nums(vector<int> &arr){
    int i = 0;
    int size = arr.size();
    int j = arr.size() - 1;
    vector<int> res(j + 1, 0);
    int k = 0;

    while (i < j){
        if (arr[i] * arr[i] > arr[j] * arr[j]){
            res[size - 1 - k] = arr[i] * arr[i];
            i++;
            k++;
        }
        else{
            res[size - 1 - k] = arr[j] * arr[j];
            j--;
            k++;
        }
    }
    return res;
}

int arr_sum(vector<int> &arr, int start, int end){
    int sum = 0;
    for (int i = start; i < end; i++){
        sum += arr[i];
    }
    return sum;
}

// 滑动窗口 起点和终点的不断移动过程,
int min_len_arr(vector<int> &arr, int target){
    int size = arr.size();
    int sum = 0;
    int i = 0;
    int res = INT32_MAX;
    for (int j = 0; j < size; j++){
        sum += arr[j];
        while (sum >= target){
            int temp = j - i + 1;
            if (temp < res){
                res = temp;
            }
            sum -= arr[i];
            i++;
        }
    }
    return res;
}

pair<int, int> two_sum(vector<int> &arr, int target){
    unordered_map<int, int> umap;

    for (int i = 0; i < arr.size(); i++){
        if (umap.find(target - arr[i]) == umap.end()){
            umap.insert(pair<int, int>{arr[i], i});
        }
        else{
            return pair<int, int>{umap[target - arr[i]], i};
        }
    }
    return pair<int, int> {0, 0};

}

vector<vector<int>> Three_sum(vector<int> &arr, int target){
    vector<int> path;
    vector<vector<int>> res;
    QuickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++){
        if (i > 0 and arr[i] == arr[i - 1]){
            continue;
        }
        else{
            int left = i + 1;
            int right = arr.size() - 1;
            while (left < right){
                if (arr[i] + arr[left] + arr[right] > target){
                    right--;
                }
                else if (arr[i] + arr[left] + arr[right] < target){
                    left++;
                }
                else if (arr[i] + arr[left] + arr[right] == target){
                    if (arr[right] == arr[right - 1]){
                        right--;
                    }
                    else if (arr[left] == arr[left + 1]){
                        left++;
                    }
                    else{
                        path.push_back(arr[i]);
                        path.push_back(arr[left]);
                        path.push_back(arr[right]);
                        res.push_back(path);
                        path.clear();
                        left++;
                        right--;
                    }
                }
            }
        }
    }
    return res;
}

