//
// Created by 24195 on 2023/11/8.
//

#include "func.h"

bool IsoWords(string s1, string s2){
    int len1 = s1.size();
    int len2 = s2.size();

    if (len1 != len2){
        return false;
    }

    vector<int> hash(128, 0);
    for (int i = 0; i < s1.size(); i++){
        int index = s1[i] - '!';
        hash[index]++;
    }

    for (int i = 0; i < s2.size(); i++){
        int index = s2[i] - '!';
        hash[index]--;
    }

    for (int i = 0; i < 128; i++) {
        if (hash[i] != 0){
            return false;
        }
    }
    return true;
}

vector<int> cross_arr(vector<int> &arr1, vector<int> &arr2){
    unordered_set<int> uset;
    vector<int> res;
    if (arr1.size() < arr2.size()){
        swap(arr1, arr2);
    }

    for (int i = 0; i < arr1.size(); i++){
        uset.insert(arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++){
        if (uset.find(arr2[i]) != uset.end()){
            res.push_back(arr2[i]);
            uset.erase(arr2[i]);
        }
    }
    return res;
}

int sum_bits(int n){
    int sum = 0;
    while (n >= 1){
        int bit = n % 10;
        sum += bit * bit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n){
    unordered_set<int> uset;
    while (n > 1){
        n = sum_bits(n);
        if (uset.find(n) == uset.end()){
            uset.insert(n);
        }
        else{
            return false;
        }
    }
    return true;

}
