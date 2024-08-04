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
    void dfs(vector<int> &v, TreeNode *node, vector<int> &leaf){
        if(find(v.begin(), v.end(), node->val)==v.end()){
            v.push_back(node->val);
            if(node->left == nullptr && node->right == nullptr) leaf.push_back(node->val);
            else if(node->left != nullptr) dfs(v, node->left, leaf);
            else dfs(v, node->right, leaf);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leaf1(0), leaf2(0);
        vector<int> v(0);
        dfs(v, root1, leaf1);
        v.clear();
        dfs(v, root2, leaf2);

        return leaf1 == leaf2;
    }
};
