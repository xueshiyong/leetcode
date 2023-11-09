//
// Created by 24195 on 2023/11/7.
//

#include "../func.h"

bool IsPanic(string s, int start, int end){
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

void back_track_string(int &max_len, string s, int startIndex, vector<string> &path, vector<vector<string>>&res){
    res.push_back(path); // 回溯法求回文子串
    if (startIndex > s.size()){
        return;
    }

    for (int i = startIndex; i < s.size(); i++){
        if (IsPanic(s, startIndex, i)){
            string panic_str = s.substr(startIndex, i - startIndex + 1);
            if (panic_str.size() > max_len){
                max_len = panic_str.size();
            }
            path.push_back(panic_str);
        }
        else{
            continue;
        }

        back_track_string(max_len, s, i + 1, path, res);
        path.pop_back();
    }
}

void back_track_son_string_num(int &num, string s, int startIndex, vector<string> &path, vector<vector<string>> &res){
    res.push_back(path);
    if (startIndex > s.size()){
        return;
    }

    for (int i = startIndex; i < s.size(); i++){
        string str_sub = s.substr(i, startIndex - i + 1);
        path.push_back(str_sub);
        num++;
        back_track_son_string_num(num, s, i + 1, path, res);
        path.pop_back();
    }
}

string string_mul(string s_num, int base){
    int c1 = 0;
    for (int i = 0; i < s_num.size(); i++){
        int cur_data = s_num[i] - '0';
        int temp_data = cur_data * base;

        int bit_data = (temp_data + c1) % 10;
        s_num[i] = bit_data + '0';
        c1 = (temp_data + c1) / 10;

    }
    if (c1 != 0){
        s_num.push_back(c1 + '0');
    }
    return s_num;
}

string my_pow(int base, int index){
    string s_num;
    s_num.push_back(base + '0');
    for (int i = 1; i < index; i++){
        s_num = string_mul(s_num, base);
    }
    reverse(s_num.begin(), s_num.end());
    return s_num;
}




