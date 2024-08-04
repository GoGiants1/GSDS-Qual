/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode *bf_mid = head, *mid = head, *end = head;
    while(end->next != NULL){
        end = end->next->next == NULL ? end->next : end->next->next;
        bf_mid = mid;
        mid = mid->next;
    }
    bf_mid->next = mid->next;
    free(mid);
    return head;
}
