//
// Created by 24195 on 2023/10/27.
//
#include "BackSearch/back_search.cpp"
#include "Dynamic/dynamic.cpp"
#include "Greedy/greedy.cpp"
#include "HashSet/hash.cpp"
#include "List/list.cpp"
#include "Mat/My_Mat.cpp"
#include "Math_fun/mymath.cpp"
#include "monotonic_stack/mono_stack.cpp"
#include "Sort/sort.cpp"
#include "Stack/mystack.cpp"
#include "String/mystring.cpp"
#include "Test/test.cpp"
#include "Tree/tree.cpp"
#include "Vector/vector.cpp"



int main(){
    cout << "hello world. " << endl;
    vector<int> arr = {4, 5, 3, 1, 2, 7, 6};
    QuickSort(arr, 0, arr.size() - 1);
    PrintSort(arr);
//    test_tree();
//    testing_back_search();
}

