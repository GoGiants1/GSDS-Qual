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
        if (head == nullptr or head->next == nullptr){}
        else if(head->next->next == nullptr){
            head->next->next = head;
            head = head->next;
            head->next->next=nullptr;
        }
        else{
            ListNode *forward = head->next;
            ListNode *save = forward->next;
            head->next = nullptr;
            while(save != nullptr){
                forward->next = head;
                head = forward;
                forward = save;
                save = save->next;
            }
            forward->next = head;
            head = forward;
        }
        return head;
    }
};
