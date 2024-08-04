/**
 * Definition for singly-linked list.
 */
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int pairSum(struct ListNode* head) {
    int nodeArray[100000];
    struct ListNode* cur = head;
    int nodeCnt = 0;
    while (cur != NULL) {
        nodeArray[nodeCnt] = cur->val;
        cur = cur->next;
        nodeCnt++;
    }
    int maxTwinSum = 0;
    int twinSum;
    for (int i = 0; i < nodeCnt / 2; i++) {
        twinSum = nodeArray[i] + nodeArray[nodeCnt - 1 - i];
        if (maxTwinSum < twinSum) {
            maxTwinSum = twinSum;
        }
    }
    return maxTwinSum;
}

int main() {
    struct ListNode b;
    b.val = 1000;
    b.next = NULL;
    struct ListNode a;
    a.val = 1;
    a.next = &b;
    struct ListNode* A = &a;
    pairSum(A);
}
