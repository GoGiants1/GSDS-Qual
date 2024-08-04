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
    void dfs(vector<int> fr, TreeNode *node, int *g_cnt, int targetSum){
            fr.push_back(node->val);
            for(int i = 0; i < fr.size(); i++){
                if(accumulate(fr.begin()+i, fr.end(), 0) == targetSum) *g_cnt += 1;
                cout << accumulate(fr.begin(), fr.end(), 0) << endl;
                //#include <numeric>
            }
            if (node->left != nullptr) dfs(fr, node->left, g_cnt, targetSum);
            if (node->right != nullptr) dfs(fr, node->right, g_cnt, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> fr(0);
        int g_cnt = 0;
        dfs(fr, root, &g_cnt, targetSum);
        return g_cnt;
    }
};
