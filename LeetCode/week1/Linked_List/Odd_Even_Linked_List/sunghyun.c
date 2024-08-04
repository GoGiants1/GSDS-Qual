/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode odd;
    struct ListNode even;

    struct ListNode* oddlist = &odd;
    struct ListNode* evenlist = &even;

    struct ListNode* oddhead = oddlist;
    struct ListNode* evenhead = evenlist;

    while(head){
        oddlist->next = head;
        evenlist->next = head->next;

        oddlist = oddlist->next;
        evenlist = evenlist->next;

        if(evenlist){
            head = head->next->next;
        }
        else{
            head = NULL;
        }
    }

    oddlist->next = evenhead->next;

    return oddhead->next;
}