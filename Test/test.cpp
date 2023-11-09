//
// Created by 24195 on 2023/11/7.
//
#include "../func.h"

void testing_list(){
    cout << "testing list: " << endl;
    vector<int> arr = {4, 2, 1, 5, 6, 3};
    ListNode *head = CreateList(arr);
    cout << "head: " << head->val << endl;
    ListNode *tail = get_tail(head);
    cout << "tail: " << tail->val << endl;

//    PrintList(head);
//    head = reverse_list(head);
//    PrintList(head);
//

    ListNode *node2 = new ListNode(4);
    ListNode *node1 = new ListNode(3);
    node1->next = node2;
    node2->next = head;

    cout << "cross node: " << list_cross_node(head, node1)->val << endl;

    ListNode *temp_head = swap_near_node(head);
    PrintList(temp_head);


}

void test_hash(){
    string s1 = "AHFGijkg";
    string s2 = "iAFGHbgj";
    cout << "is Iso Words: " << IsoWords(s1, s2) << endl;

    vector<int> arr1 = {1, 4, 4, 2, 3, 6, 5};
    vector<int> arr2 = {4, 4, 3, 6};
    vector<int> res = cross_arr(arr2, arr1);
    Print_vec_int(res);

    cout << "sum bits: " << sum_bits(82) << endl;
    int n = 19;
    cout << "Is happy? " << isHappy(n) << endl;

    string str1 = "aab";
    string str2 = "abcd";
    cout << "Is magazines: " << magezines(str1, str2) << endl;

}

void test_stack(){
    string str = "[";
    cout << "Valid buckets: " << effective_buckets(str) << endl;

    string temp_str = "abbaccddfeefhij";
    string res_str = delete_near_word(temp_str);
    cout << "res: " << res_str << endl;

    string s = "34*2/";
    cout << "polan res: " << PolanExpression(s) << endl;

    vector<int> arr = {4, 5, 1, 2, 3};

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

    vector<int> weights = {1, 3, 4};
    vector<int> prices = {10, 15, 20};
    int Volume = 4;

    cout << "max_prices: " << V_bags(weights, prices, Volume) << endl;
    cout << "max_prices_two: " << V_bags_two(weights, prices, Volume) << endl;

    vector<int> stones = {1, 1, 3, 4, 11};
    cout << "min_left_stone: " << left_min_stone(stones) << endl;

    vector<int> arr = {1, 1, 1, 1, 1};
    int target = 2;
    cout << "Valid operator: " << IsValidOperator(arr, target) << endl;

    cout << "split max multiply: " << split_max_int(9) << endl;

    vector<int> sum_arr = {4, 2, 1, 5, 2};
    cout << two_sum(sum_arr, 9).first << " " << two_sum(sum_arr, 9).second << endl;

    vector<vector<int>> res;
    vector<int> temp_arr = {5, 6, 7, 1, 2, 3, 4};
    res = Three_sum(temp_arr, 9);
    Print_two_vec_int(res);

}

void test_vector(){
    vector<int> arr = {6, 8, 10, 11, 12};
    int target = 8;
    cout << binary_search(arr, target) << endl;

    vector<int> temp_arr = {1, 2, 2, 2, 2, 4, 5, 6, 7};
    cout << "before size: " << temp_arr.size() << endl;
    cout << "after size: " << removeVal(temp_arr, 2) << endl;

    vector<int> temp_arr1 = {-2, -1, 0, 1, 2, 3};
    vector<int> res = square_of_nums(temp_arr1);
    Print_vec_int(res);

    vector<int> temp_arr2 = {2, 3, 1, 2, 4, 3};
    cout << "min_len_arr: " << min_len_arr(temp_arr2, 9) << endl;


    vector<vector<int>> spiral = spiral_array(6, 6);
    Print_two_vec_int(spiral);

}

void test_tree(){
    cout << "this is test tree: " << endl;

}

