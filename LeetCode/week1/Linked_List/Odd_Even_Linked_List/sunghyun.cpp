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
        ListNode odd = ListNode();
        ListNode even = ListNode();
        
        ListNode* oddlist = &odd;
        ListNode* evenlist = &even;

        ListNode* oddhead = oddlist;
        ListNode* evenhead = evenlist;

        while(head){
            oddlist->next = head;
            evenlist->next = head->next;

            oddlist = oddlist->next;
            evenlist = evenlist->next;

            if(evenlist){
                head = head->next->next;
            }
            else{
                head = nullptr;
            }
        }

        oddlist->next = evenhead->next;

        return oddhead->next;

        
    }
};