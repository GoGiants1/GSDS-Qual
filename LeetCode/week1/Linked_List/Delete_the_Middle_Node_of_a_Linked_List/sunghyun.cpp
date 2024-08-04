#include <cmath>
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
    ListNode* deleteMiddle(ListNode* head) {
        int lllen = 0;
        ListNode* curptr = head;

        while(curptr != nullptr){
            lllen++;
            curptr = curptr->next;
        }

        int delind = floor(lllen/2);

        if (delind == 0){
            return nullptr;
        }

        curptr = head;

        while(delind > 1){
            curptr = curptr -> next;
            delind--;
        }
        curptr->next = curptr-> next ->next;

        return head;
    }
};