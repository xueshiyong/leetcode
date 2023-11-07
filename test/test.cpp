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


}