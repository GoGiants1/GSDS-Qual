#include <climits>
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
    int pairSum(ListNode* head) {
        int lllen = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            lllen++;
            temp = temp->next;
        }

        int mid = lllen / 2;

        ListNode* firstptr = head;
        int midval = 0;
        ListNode* secondptr = head;
        int maxsum = INT_MIN;

        while(midval != mid){
            secondptr = secondptr->next;
            midval++;
        }

        ListNode* prev = nullptr;
        ListNode* currptr = secondptr;

        while(true){
            ListNode* nextptr = currptr->next;
            currptr->next = prev;
            prev = currptr;
            if(nextptr == nullptr){
                break;
            }
            currptr = nextptr;
        }

        ListNode* reverseptr = currptr;

        while(reverseptr != nullptr){
            int pairsum = firstptr->val + reverseptr->val;
            if(pairsum > maxsum){
                maxsum = pairsum;
            }
            firstptr = firstptr -> next;
            reverseptr = reverseptr -> next;
        }

        return maxsum;
    }
};