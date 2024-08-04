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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddList = nullptr;
        ListNode* evenList = nullptr;
        ListNode* evenHead = nullptr;

        ListNode* cur = head;
        bool odd = true;
        while (cur) {
            if (odd) {
                if (oddList == nullptr) {
                    oddList = cur;
                }
                else {
                    oddList->next = cur;
                    oddList = oddList->next;
                }
                odd = false;
            }
            else {
                if (evenList == nullptr) {
                    evenList = evenHead = cur;
                }
                else {
                    evenList->next = cur;
                    evenList = evenList->next;
                }
                odd = true;
            }
            cur =cur->next;
        }
        if (oddList != nullptr) {
            oddList->next = evenHead;
        }
        if (evenList != nullptr) {
            evenList->next = nullptr;
        }
        return head;
    }
};
