/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL){}
    else if(head->next->next == NULL){
        head->next->next = head;
        head = head->next;
        head->next->next=NULL;
    }
    else{
        struct ListNode *forward = head->next;
        struct ListNode *save = forward->next;
        head->next = NULL;
        while(save != NULL){
            forward->next = head;
            head = forward;
            forward = save;
            save = save->next;
        }
        forward->next = head;
        head = forward;
    }
    return head;
}
