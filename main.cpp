//
// Created by 24195 on 2023/10/27.
//

#include "func.h"
#include "Math_fun/math_fun.h"

int main() {
    cout << "testing mode: " << endl;
    vector<int> arr = {1, 3, 2, 5, 4, 2, 6};
    vector<int> temp_arr = next_max_value(arr);
    PrintSort(temp_arr);
}

