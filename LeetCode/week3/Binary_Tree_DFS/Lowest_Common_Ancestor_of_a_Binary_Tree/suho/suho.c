/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode *node, struct TreeNode *p){
    if(node->val == p->val) return 1;
    else{
        int res = 0;
        if(node->left != NULL) res = dfs(node->left, p);
        if(res == 0 && node->right != NULL) res = dfs(node->right, p);
        return res;
    }
}

void search(struct TreeNode *node, struct TreeNode *p, struct TreeNode *q, struct TreeNode **lca, int lv, int *lca_lv){
    if(dfs(node, p)==1 && dfs(node, q)==1 && lv > *lca_lv){ 
        *lca = node;
        *lca_lv = lv;
    }

    if (node->left != NULL) search(node->left, p, q, lca, lv+1, lca_lv);
    if (node->right != NULL) search(node->right, p, q, lca, lv+1, lca_lv);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *lca = root;
    int lca_lv = 0;
    search(root, p, q, &lca, 0, &lca_lv);
    return lca;
}
