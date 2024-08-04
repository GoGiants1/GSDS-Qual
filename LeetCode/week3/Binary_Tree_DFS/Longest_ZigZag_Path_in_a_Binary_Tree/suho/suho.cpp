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
    void dfs(TreeNode *node, int *g_cnt, int tmp_cnt, char prev){
        if(prev == 'r' or prev == 'o'){
            if (node->left != nullptr){ 
                int tcnt = tmp_cnt + 1;
                if(*g_cnt < tcnt) *g_cnt = tcnt;
                dfs(node->left, g_cnt, tcnt, 'l');
            }
            if (node->right != nullptr) dfs(node->right, g_cnt, 1, 'r');
        }

        if(prev == 'l' or prev == 'o'){
            if (node->right != nullptr){ 
                int tcnt = tmp_cnt + 1;
                if(*g_cnt < tcnt) *g_cnt = tcnt;
                dfs(node->right, g_cnt, tcnt, 'r');
            }
            if (node->left != nullptr) dfs(node->left, g_cnt, 1, 'l');
        }
    }

    int longestZigZag(TreeNode* root) {
        int tmp_cnt = 0;
        int g_cnt = 0;
        char prev = 'o';
        dfs(root, &g_cnt, tmp_cnt, prev);
        return g_cnt;
    }
};
