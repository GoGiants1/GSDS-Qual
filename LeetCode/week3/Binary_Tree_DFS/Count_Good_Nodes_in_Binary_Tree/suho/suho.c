/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(int fr[], int fr_len, struct TreeNode *node, int *g_cnt){
    fr[fr_len] = node->val;
    fr_len ++;
    int is_max = 1;
    for(int i = 0; i < fr_len; i++){
        if(fr[i] > node->val) is_max = 0;
    }
    if(is_max == 1) *g_cnt += 1;
    if (node->left != NULL) dfs(fr, fr_len, node->left, g_cnt);
    if (node->right != NULL) dfs(fr, fr_len, node->right, g_cnt);
}

int goodNodes(struct TreeNode* root) {
    int fr[15] = {0};
    int fr_len = 0;
    int g_cnt = 0;
    dfs(fr, fr_len, root, &g_cnt);
    return g_cnt;
}
