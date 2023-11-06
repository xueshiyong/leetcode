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

