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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL )
            return head;
        if(head->next==NULL)
            return nullptr;
        int s=0;
        ListNode* temp =head;
        while(temp!=NULL){
            s++;
            temp=temp->next;
        }
        int n=s/2;
        int i=1;
        
        temp=head;
        while(temp!=NULL){
            if(i==n){
                temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
            i++;
        }
        return head;
    }
};