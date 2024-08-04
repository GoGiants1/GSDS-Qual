#include <iostream>
#include <vector>
#include <string>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};