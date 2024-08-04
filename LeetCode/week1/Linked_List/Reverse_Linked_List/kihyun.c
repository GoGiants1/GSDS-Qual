#include <stdio.h>
#include <stdlib.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL){
        return head;
    }
    else if (head->next->next == NULL){
        struct ListNode* new_head = head->next;
        head->next->next = head;
        head->next = NULL;
        head = new_head;
    }
    else{
        struct ListNode* back = head;
        struct ListNode* cur = head->next;
        struct ListNode* next1 = head->next->next;

        while (1){
            
            cur->next = head;
            back->next = next1;
            head = cur;
            cur = next1;

            if (next1 != NULL){
                next1 = next1->next;
            }
            else{
                break;
            }
            
        }
        
    }
    return head;
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


}