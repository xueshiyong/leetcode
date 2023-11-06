//
// Created by 24195 on 2023/10/27.
//

#include "func.h"
#include "Math_fun/math_fun.h"

int main() {
    vector<int> arr = {4, 2, 5, 1, 6, 7, 3};
    ListNode *head = CreateList(arr);
    ListNode *node = new ListNode(10);
    head = add_list(head, node, 0);
    PrintList(head);

    ListNode *find_node = find_list(head, 0);
    cout << "find_node: " << find_node->val << endl;

    head = delete_list(head, 0);
    PrintList(head);


    ListNode *node1 = new ListNode(20);
    head = change_list(head, node1, 0);
    PrintList(head);
}

