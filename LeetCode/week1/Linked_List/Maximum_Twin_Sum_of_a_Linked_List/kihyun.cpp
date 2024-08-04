#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* mid = head;
        ListNode* end = head;
        vector<int> sum_arr;
        while(end != nullptr){
            sum_arr.push_back(mid->val);
            mid = mid->next;
            end = end->next->next;
        }
        
        int max_val = 0;
        int idx = sum_arr.size()-1;

        while(mid != nullptr){
            sum_arr[idx] += mid->val;
            if (sum_arr[idx] > max_val){
                max_val = sum_arr[idx];
            }
            idx--;
            mid = mid->next;
        }
        return max_val;
    }
};