/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL){
        return head;
    }
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* even_head = even;
    while(true){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;

        if (odd->next == NULL || even->next == NULL){
            break;
        }
    }
    odd->next = even_head;

    return head;
}