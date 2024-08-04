/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *odd_head = head, *even_head = NULL, *odd = head, *even = NULL, *beatle = head->next;
    int n = 2;

    while(beatle != NULL){
        if(n%2 == 0){
            if(even_head == NULL) even_head = beatle;
            else even->next = beatle;
            even = beatle;
        }
        else{
            odd->next = beatle;
            odd = beatle;
        }
        beatle = beatle->next;
        n++;
    }

    odd->next = even_head;
    if(even != NULL) even->next = NULL;

    return head;
}
