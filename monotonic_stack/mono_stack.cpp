//
// Created by 24195 on 2023/11/6.
//

#include "func.h"

vector<int> next_max_value(vector<int> &arr){
    vector<int> temp_arr(arr.size(), -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] <= arr[st.top()]){
            st.push(i);
        }
        else{
            while (!st.empty() and arr[i] > arr[st.top()]){
                int index = st.top();
                st.pop();
                temp_arr[index] = arr[i];
            }
            st.push(i);
        }
    }
    return temp_arr;
} // 下一个最大值

vector<int> next_circle_max_value(vector<int> &arr){
    int size = arr.size();
    stack<int> st;
    st.push(0);
    vector<int> temp_arr(arr.size(), -1);

    for (int i = 1; i < 2 * size; i++){
        if (arr[i % size] <= arr[st.top()]){
            st.push(i % size);
        }
        else{
            while (!st.empty() and arr[i % size] > arr[st.top()]){
                int index = st.top();
                st.pop();
                temp_arr[index] = arr[i % size];
            }
            st.push(i % size);
        }
    }
    return temp_arr;
}

// 接雨水的方法

int rainy(vector<int> &arr){
    stack<int> st;
    st.push(0);

    int sum = 0;
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] < arr[st.top()]){
            st.push(i);
        }
        else if (arr[i] == arr[st.top()]){
            st.pop();
            st.push(i);
        }
        else{
            while (!st.empty() and arr[i] > arr[st.top()]){
                int index = st.top();
                st.pop();
                if (!st.empty()){
                    int h = min(arr[i], arr[st.top()]) - arr[index];
                    int w = i - st.top() - 1;
                    sum += h * w;
                }
            }
            st.push(i);
        }
    }

    return sum;
}