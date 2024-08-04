/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* oddList = NULL;
    struct ListNode* evenList = NULL;
    struct ListNode* evenHead = NULL;

    struct ListNode* cur = head;
    bool odd = true;
    while (cur) {
        if (odd) {
            if (oddList == NULL) {
                oddList = cur;
            }
            else {
                oddList->next = cur;
                oddList = oddList->next;
            }
            odd = false;
        }
        else {
            if (evenList == NULL) {
                evenList = evenHead = cur;
            }
            else {
                evenList->next = cur;
                evenList = evenList->next;
            }
            odd = true;
        }
        cur =cur->next;
    }
    if (oddList != NULL) {
        oddList->next = evenHead;
    }
    if (evenList != NULL) {
        evenList->next = NULL;
    }
    return head;
}
