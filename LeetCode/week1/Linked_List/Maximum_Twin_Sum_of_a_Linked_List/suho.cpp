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
    int pairSum(ListNode* head) {
        vector<int> vals(0);
        ListNode *beatle = head;

        while(beatle != nullptr){
            vals.push_back(beatle->val);
            beatle = beatle->next;
        }

        for(int i = 0; i < vals.size()/2; i++){
            vals[i] += vals[vals.size()-i-1];
        }

        return *max_element(vals.begin(), vals.end());
    }
};
