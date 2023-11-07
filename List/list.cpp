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
//            head->prev = nullptr;
        }
        else{
            temp->next = node;
//            node->prev = temp;
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


ListNode *last_k_list(ListNode *head, int k){
    ListNode *cur = head;
    ListNode *prev = head;

    int i = 0;
    while (i < k){
        cur = cur->next;
        i++;
    }

    while (cur != nullptr){
        cur = cur->next;
        prev = prev->next;
    }

    return prev;
}

ListNode *get_tail(ListNode *head){
    return last_k_list(head, 1);
}

int length_of_list(ListNode *head){
    int i = 0;
    ListNode *cur = head;

    while (cur != nullptr){
        i++;
        cur = cur->next;
    }
    return i;
}

ListNode *two_sum_of_list(ListNode *head1, ListNode *head2){
    if (length_of_list(head1) < length_of_list(head2)){
        swap(head1, head2);
    }

    ListNode *cur1 = head1;
    ListNode *cur2 = head2;

    ListNode *prev1 = nullptr;
    ListNode *prev2 = nullptr;

    int c1 = 0;
    while (cur2 != nullptr) {
        int temp = cur1->val + cur2->val + c1;
        c1 = temp / 10;
        cur1->val = temp % 10;

        prev1 = cur1;
        prev2 = cur2;

        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    if (cur1 == nullptr){
        if (c1 != 0){
            ListNode *temp_node = new ListNode(c1);
            prev1->next = temp_node;
            return head1;
        }
        else{
            return head2;
        }

    }
    else{
        while (cur1 != nullptr){
            int temp = cur1->val + c1;
            c1 = temp / 10;
            cur1->val = temp % 10;

            prev1 = cur1;
            cur1 = cur1->next;
        }

        if (c1 == 0){
            return head1;
        }
        else{
            ListNode *temp_node = new ListNode(c1);
            prev1->next = temp_node;
            return head1;
        }


    }

}

void PrintList(ListNode *head){
    ListNode *cur = head;
    while (cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}


ListNode *CreateCircleList(vector<int> &arr){
    ListNode *head = CreateList(arr); // 创建单向链表
    ListNode *tail = get_tail(head);
    tail->next = head;
    return head;
}

void PrintCircleList(ListNode *head){
    ListNode *cur = head;

    while (cur->next != head){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << cur->val;
    cout << endl;
}

bool IsCircleList(ListNode *head){
    ListNode *fast = head;
    ListNode *slow = head;

    fast = fast->next->next;
    slow = slow->next;

    while (fast != slow) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == nullptr){
            return false;
        }
    }

    return true;
}

ListNode *CrossIndexList(ListNode *head){
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow){
            ListNode *index1 = slow;
            ListNode *index2 = head;

            while (index1 != index2){
                index1 = index1->next;
                index2 = index2->next;
                if (index1 == slow){
                    return nullptr;
                }
            }
            return index1;
        }
    }
}

ListNode *reverse_list(ListNode *head){
    ListNode *cur = head;
    ListNode *prev = nullptr;
    ListNode *temp = nullptr;

    while (cur != nullptr){
        temp = cur->next;
        cur->next = prev;

        prev = cur;
        cur = temp;
    }
    return prev;
} // 链表翻转

