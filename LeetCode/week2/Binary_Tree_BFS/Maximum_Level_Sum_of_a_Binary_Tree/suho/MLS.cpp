/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> visit(0);
        vector<TreeNode*> queue(0);
        vector<int> lv_queue(0);
        vector<int> sum(0);
  
        queue.push_back(root);
        lv_queue.push_back(1);
  
        while(queue.size()!=0){
            TreeNode *node = queue.back();
            int lv = lv_queue.back();
            queue.pop_back();
            lv_queue.pop_back();

            if(find(visit.begin(), visit.end(), node) == visit.end()){
                visit.push_back(node);
                if(sum.size() < lv) sum.push_back(node->val);
                else sum[lv-1] += node->val;
                if(node->left != nullptr){
                    queue.push_back(node->left);
                    lv_queue.push_back(lv+1);
                }
                if(node->right != nullptr){
                    queue.push_back(node->right);
                    lv_queue.push_back(lv+1);
                }
            }
        }

        return max_element(sum.begin(), sum.end()) - sum.begin() + 1;
    }
};
