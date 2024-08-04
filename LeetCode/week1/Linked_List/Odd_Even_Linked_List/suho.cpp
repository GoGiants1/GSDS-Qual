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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_head = head, *even_head = nullptr, *odd = head, *even = nullptr, *beatle = head->next;
        int n = 2;

        while(beatle != nullptr){
            if(n%2 == 0){
                if(even_head == nullptr) even_head = beatle;
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
        if(even != nullptr) even->next = nullptr;

        return head;
    }
};
