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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr){
            return nullptr;
        }
        ListNode* cur = head;
        ListNode* before_cur = head;
        ListNode* end = head;

        while(end->next != nullptr){
            before_cur = cur;
            cur = cur->next;
            end = end->next->next;
            if (end == nullptr) break;
        }
        before_cur->next = cur->next;

        return head;

    }
};