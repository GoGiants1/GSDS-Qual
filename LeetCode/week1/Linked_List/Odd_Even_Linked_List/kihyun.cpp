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
        if (head == nullptr || head->next ==nullptr || head->next->next ==nullptr){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;
        while(true){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;

            if (odd->next == nullptr || even->next == nullptr){
                break;
            }
        }
        odd->next = even_head;

        return head;
    }
};