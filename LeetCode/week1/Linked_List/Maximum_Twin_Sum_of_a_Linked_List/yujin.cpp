/**
 * Definition for singly-linked list.
 */
#include <vector>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nodeArray;
        ListNode* cur = head;
        while (cur != nullptr) {
            nodeArray.push_back(cur->val);
            cur = cur->next;
        }

        int maxTwinSum = 0;
        for (int i = 0; i < nodeArray.size() / 2; i++) {
            int twinSum = nodeArray[i] + nodeArray[nodeArray.size() / 2 - 1 - i];
            if (maxTwinSum < twinSum) { maxTwinSum = twinSum; }
        }
        return maxTwinSum;
    }
};
