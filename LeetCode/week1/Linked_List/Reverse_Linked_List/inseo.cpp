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
    ListNode* reverseList(ListNode* head) {
          if(head == NULL)
             return head;

          ListNode* prev = NULL ;
          ListNode* present = head ;
          ListNode* next = present->next ;

            while(present!=NULL){
                present->next = prev ;
                prev = present ;
                present = next ;
                if(next!=NULL){
                    next=next->next ;
                }
            }
           return prev ;
    }
};