/**
 * Definition for singly-linked list.
 */
#include <stdio.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
    int n = 0;
    struct ListNode* cur = head;
    while (cur) {
        n ++;
        cur = cur->next;
    }
    if (n == 1) {
        head = NULL;
    }
    else if (n == 2) {
        head->next = NULL;
    }
    else {
        cur = head;
        int index = 0;
        int middle = n / 2;
        while (index < middle) {
            if (index == middle - 1) {
                cur->next = cur->next->next;
            }
            cur = cur->next;
            index ++;
        }
    }
    return head;
}
