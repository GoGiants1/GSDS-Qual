#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
     int val;
     struct ListNode *next;
};
 
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode* mid = head;
    struct ListNode* before_mid = head;
    struct ListNode* end = head;
    if (head == NULL || head->next == NULL){
        return NULL;
    }

    while(end->next != NULL){
        before_mid = mid;
        mid = mid->next;
        end = end->next->next;
        if (end == NULL) break;
    }
    before_mid->next = mid->next;
    return head; 
}

