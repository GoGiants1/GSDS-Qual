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
    ListNode* start;
    int ans = 0;
    
    void help(ListNode* node){
        
        if(node == NULL)
            return;
        help(node->next);
        ans = max(ans, start->val+node->val);
        start = start->next;
    }
    int pairSum(ListNode* head) {
        start = head;   
        help(head);
        return ans;
    }
};