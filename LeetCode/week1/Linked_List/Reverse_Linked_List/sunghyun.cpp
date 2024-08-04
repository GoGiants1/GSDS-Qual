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
        ListNode* currptr = head;
        ListNode* prev = nullptr;

        while(currptr != nullptr){
            ListNode* nextptr = currptr->next;
            currptr->next = prev;
            prev = currptr;
            if(nextptr == nullptr){
                break;
            }
            currptr = nextptr;
        }

        return currptr;
    }
};