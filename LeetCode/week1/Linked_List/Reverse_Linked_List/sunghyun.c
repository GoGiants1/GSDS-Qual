/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* currptr = head;
    struct ListNode* prev = NULL;

    while(currptr != NULL){
        struct ListNode* nextptr = currptr->next;
        currptr->next = prev;
        prev = currptr;
        if(nextptr == NULL){
            break;
        }
        currptr = nextptr;
    }

    return currptr;
}