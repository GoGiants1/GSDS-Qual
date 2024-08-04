/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = NULL;
    
    if(head->next == NULL){ /*Edge case*/
        free(head);
        return NULL;
    }
    
    while(fast != NULL && fast->next != NULL){  /*Fast and slow pointer method*/
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    prev->next = slow->next;
    free(slow);
    
    return head;
}