/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode *node, TreeNode *p){
        if(node->val == p->val) return 1;
        else{
            int res = 0;
            if(node->left != nullptr) res = dfs(node->left, p);
            if(res == 0 and node->right != nullptr) res = dfs(node->right, p);
            return res;
        }
    }

    void search(TreeNode *node, TreeNode *p, TreeNode *q, TreeNode **lca, int lv, int *lca_lv){
        if(dfs(node, p)==1 && dfs(node, q)==1 && lv > *lca_lv){ 
            *lca = node;
            *lca_lv = lv;
        }

        if (node->left != nullptr) search(node->left, p, q, lca, lv+1, lca_lv);
        if (node->right != nullptr) search(node->right, p, q, lca, lv+1, lca_lv);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca = root;
        int lca_lv = 0;
        search(root, p, q, &lca, 0, &lca_lv);
        return lca;
    }
};
