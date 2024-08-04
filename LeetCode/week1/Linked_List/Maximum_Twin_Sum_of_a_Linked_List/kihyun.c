/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//Definition for singly-linked list.
#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};



int pairSum(struct ListNode* head) {
    struct ListNode *mid = head;
    struct ListNode *end = head;
    int max = 0;
    int half_len = 0;

    int half_arr[60001];

    while(end != NULL){
        half_arr[half_len] = mid->val;
        mid = mid->next;
        end = end->next->next;
        half_len++;
    }
    int back_idx = half_len-1;


    while (mid != NULL){
        if (max < half_arr[back_idx] + mid->val){
            max = half_arr[back_idx] + mid->val;
        }
        // if 문 밖에 있어야 한다
        mid = mid->next;
        back_idx--;

    }
    return max;
}

int main(){
    struct ListNode ptr0;
    struct ListNode ptr1;
    struct ListNode ptr2;
    struct ListNode ptr3;
    ptr0.val = 0;
    ptr0.next = &ptr1;

    ptr1.val = 1;
    ptr1.next = &ptr2;

    ptr2.val = 2;
    ptr2.next = &ptr3;

    ptr3.val = 3;
    ptr3.next = NULL;
    int ans = pairSum(&ptr0);
    return 0;
}