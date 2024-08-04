/**
 * Definition for singly-linked list.
**/
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;

    while (cur != NULL) {
        struct ListNode* tmp_next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp_next;
    }
    return prev;
}
