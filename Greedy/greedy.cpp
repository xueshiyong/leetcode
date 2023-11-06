//
// Created by 24195 on 2023/10/31.
//

#include "func.h"

int allocate_cookies(vector<int> children, vector<int> cookies){ // 能偶满足孩子胃口的饼干数
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    int i = children.size() - 1;
    int j = cookies.size() - 1;

    int num = 0;
    while (j >= 0 and i >= 0){
        if (cookies[j] >= children[i]){
            num++;
            j--;
            i--;
        }
        else{
            i--;
        }

    }
    return num;

}

bool jump_game(vector<int> path){
    int start = 0;
    int cover = 0 + path[0];
    for (int i = start; i <= cover; i++){
        int cur_cover = i + path[i];
        if (cur_cover >= path.size() - 1){
            return true;
        }
        if (cur_cover >= cover){
            start = i;
            cover = cur_cover;
        }
    }
    return false;
}

