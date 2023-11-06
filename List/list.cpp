//
// Created by 24195 on 2023/11/6.
//
#include "func.h"

ListNode *CreateList(vector<int> &arr){
    ListNode *head = nullptr;
    ListNode *temp = nullptr;
    ListNode *node = nullptr;

    for (int i = 0; i < arr.size(); i++){
        node = new ListNode(arr[i]);
        if (head == nullptr){
            head = node;
            head->prev = nullptr;
        }
        else{
            temp->next = node;
            node->prev = temp;
        }

        temp = node;
        temp->next = nullptr;
    }
    return head; // 其中node可以表示尾指针，作为双向链表实现。
}

ListNode* add_list(ListNode *head, ListNode *node, int pos){
    if (pos == 0){
        node->next = head;
        return node;
    }

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *cur = dummy;
    ListNode *prev = nullptr;
    int i = 0;
    while (i <= pos){
        prev = cur;
        cur = cur->next;
        i++;
    }
    prev->next = node;
    node->next = cur;
    head = dummy->next;
    return head;
}

ListNode *find_list(ListNode *head, int pos){
    if (pos == 0){
        return head;
    }

    ListNode *cur = head;
    int i = 0;
    while (i < pos){
        cur = cur->next;
        i++;
    }
    return cur;
}

ListNode *delete_list(ListNode *head, int pos){
    if (pos == 0){
        return head->next;
    }

    ListNode *cur = head;
    ListNode *prev = nullptr;

    int i = 0;
    while (i < pos){
        prev = cur;
        cur = cur->next;
        i++;
    }
    prev->next = cur->next;
    return head;
}

ListNode *change_list(ListNode *head, ListNode *node, int pos){
    if (pos == 0){
        node->next = head->next;
        return node;
    }

    ListNode *cur = head;
    ListNode *prev = nullptr;

    int i = 0;
    while (i < pos){
        prev = cur;
        cur = cur->next;
        i++;
    }
    prev->next = node;
    node->next = cur->next;

    return head;
}

void PrintList(ListNode *head){
    ListNode *cur = head;
    while (cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

}