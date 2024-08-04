#include <limits.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    int lllen = 0;
    struct ListNode* temp = head;

    while(temp != NULL){
        lllen++;
        temp = temp->next;
    }

    int mid = lllen / 2;

    struct ListNode* firstptr = head;
    int midval = 0;
    struct ListNode* secondptr = head;
    int maxsum = INT_MIN;

    while(midval != mid){
        secondptr = secondptr->next;
        midval++;
    }

    struct ListNode* prev = NULL;
    struct ListNode* currptr = secondptr;

    while(true){
        struct ListNode* nextptr = currptr->next;
        currptr->next = prev;
        prev = currptr;
        if(nextptr == NULL){
            break;
        }
        currptr = nextptr;
    }

    struct ListNode* reverseptr = currptr;

    while(reverseptr != NULL){
        int pairsum = firstptr->val + reverseptr->val;
        if(pairsum > maxsum){
            maxsum = pairsum;
        }
        firstptr = firstptr -> next;
        reverseptr = reverseptr -> next;
    }

    return maxsum;
}