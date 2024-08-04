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
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            n ++;
        }
        if (n == 1) {
            head = nullptr;
        }
        else if (n == 2)
        {
            head->next = nullptr;
        }
        else {
            int index = 0;
            int middle = n / 2;
            ListNode* cur = head;
            while (index < middle) {
                if (index == middle - 1) {
                    cur->next = cur->next->next;
                }
                cur = cur->next;
                index ++;
            }
        }
        return head;
    }
};
