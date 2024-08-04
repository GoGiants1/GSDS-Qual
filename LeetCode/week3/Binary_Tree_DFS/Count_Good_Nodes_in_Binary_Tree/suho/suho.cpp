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
    void dfs(vector<int> fr, TreeNode *node, int *g_cnt){
        fr.push_back(node->val);
        if(fr.size()==1 or *max_element(fr.begin(), fr.end()) <= node->val) *g_cnt += 1;
        // <algorithm>
        if (node->left != nullptr) dfs(fr, node->left, g_cnt);
        if (node->right != nullptr) dfs(fr, node->right, g_cnt);
    }

    int goodNodes(TreeNode* root) {
        vector<int> fr(0); 
        int g_cnt = 0;
        dfs(fr, root, &g_cnt);
        return g_cnt;
    }
};
