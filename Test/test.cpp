//
// Created by 24195 on 2023/11/7.
//
#include "func.h"

void testing_list(){
    vector<int> arr = {4, 2, 1, 5, 6, 3};
    ListNode *head = CreateList(arr);
    cout << "head: " << head->val << endl;
    ListNode *tail = get_tail(head);
    cout << "tail: " << tail->val << endl;

    PrintList(head);
    head = reverse_list(head);
    PrintList(head);

}

void testing_back_search(){
    vector<int> arr = {4, 3, 1, 6};
    vector<int> path;
    vector<vector<int>> res;
    vector<int> used(arr.size(), 0);
    back_track_arange_arr(arr, 2, used, path, res);
    Print_two_vec_int(res);

}

void test_dynamic(){
    int n = 10;
    cout << "febi: " << Febi(n) << endl;
    cout << "febi_dp: " << Febi_dp(n) << endl;
}