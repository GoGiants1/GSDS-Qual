/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(int fr[], int flen, struct TreeNode *node, int *g_cnt, int targetSum){
    fr[flen] = node->val;
    flen++;

    for(int i = 0; i < flen; i++){
        int sum = 0;
        for(int j = i; j < flen; j++) sum += fr[j];
        if(sum == targetSum) *g_cnt += 1;
    }
    if (node->left != NULL) dfs(fr, flen, node->left, g_cnt, targetSum);
    if (node->right != NULL) dfs(fr, flen, node->right, g_cnt, targetSum);
}

int pathSum(struct TreeNode* root, int targetSum) {
    int fr[10] = {0};
    int flen = 0;
    int g_cnt = 0;
    dfs(fr, flen, root, &g_cnt, targetSum);
    return g_cnt;
}
