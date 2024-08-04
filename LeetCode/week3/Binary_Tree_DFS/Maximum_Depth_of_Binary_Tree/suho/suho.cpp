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
    int dfs(vector<int> &v, TreeNode *node, int depth){
        if(find(v.begin(), v.end(), node->val)==v.end()){
            v.push_back(node->val);
            int d = depth;
            if(node->left != nullptr){
                int tmp = dfs(v, node->left, depth+1);
                d = tmp > d ? tmp : d;
            }
            if(node->right != nullptr){
                int tmp = dfs(v, node->right, depth+1);
                d = tmp > d ? tmp : d;
            }
            return d;
        }
        else return depth;
    }
    int maxDepth(TreeNode* root) {
        vector<int> v(0);
        return dfs(v, root, 1);
    }
};
