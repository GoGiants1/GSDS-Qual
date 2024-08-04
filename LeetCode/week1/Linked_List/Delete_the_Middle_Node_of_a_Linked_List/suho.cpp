/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *bf_mid = head, *mid = head, *end = head;
        while(end->next != nullptr){
            end = end->next->next == nullptr ? end->next : end->next->next;
            bf_mid = mid;
            mid = mid->next;
        }
        bf_mid->next = mid->next;
        delete mid;
        return head;
    }
};
