//
// Created by 24195 on 2023/11/8.
//

#include "func.h"

bool effective_buckets(string &str){
    stack<char> st;

    for (int i = 0; i < str.size(); i++){
        if (str[i] == '('){
            st.push(')');
        }
        else if (str[i] == '['){
            st.push(']');
        }
        else if (str[i] == '{'){
            st.push('}');
        }
        else{
            if (!st.empty()){
                if (st.top() == str[i]){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if (st.empty()){
        return true;
    }
    else{
        return false;
    }
}


string delete_near_word(string &str){
    stack<char> st;
    st.push(str[0]);
    for (int i = 1; i < str.size(); i++){
        if (!st.empty()){
            if (st.top() == str[i]){
                st.pop();
            }
            else{
                st.push(str[i]);
            }
        }
        else{
            st.push(str[i]);
        }
    }
    int size = st.size();
    string s(size, '0');
    if (size == 0){
        return s;
    }
    for (int i = size - 1; i >= 0; i--){
        s[i] = st.top();
        st.pop();
    }
    return s;
}

int PolanExpression(string &str){
    stack<char> st;

    for (int i = 0; i < str.size(); i++){
        if (str[i] == '*' or str[i] == '/' or str[i] == '+' or str[i] == '-'){
            char c2 = st.top();
            st.pop();
            char c1 = st.top();
            st.top();

            int c2_int = c2 - '0';
            int c1_int = c1 - '0';
            int c_ans;
            if (str[i] == '*'){
                c_ans = c1_int * c2_int;
            }
            else if (str[i] == '/'){
                c_ans = c1_int / c2_int;
            }
            else if (str[i] == '+'){
                c_ans = c1_int + c2_int;
            }
            else if (str[i] == '-'){
                c_ans = c1_int - c2_int;
            }
            st.push(c_ans + '0');
        }
        else{
            st.push(str[i]);
        }
    }
    return st.top() - '0';
}
// 单调队列
vector<int> max_slide_window_arr(vector<int> &arr, int k){


}
