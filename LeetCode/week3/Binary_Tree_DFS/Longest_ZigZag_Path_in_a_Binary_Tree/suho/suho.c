/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode *node, int *g_cnt, int tmp_cnt, char prev){
    if(prev == 'r' || prev == 'o'){
        if (node->left != NULL){ 
            int tcnt = tmp_cnt + 1;
            if(*g_cnt < tcnt) *g_cnt = tcnt;
            dfs(node->left, g_cnt, tcnt, 'l');
        }
        if (node->right != NULL) dfs(node->right, g_cnt, 1, 'r');
    }

    if(prev == 'l' || prev == 'o'){
        if (node->right != NULL){ 
            int tcnt = tmp_cnt + 1;
            if(*g_cnt < tcnt) *g_cnt = tcnt;
            dfs(node->right, g_cnt, tcnt, 'r');
        }
        if (node->left != NULL) dfs(node->left, g_cnt, 1, 'l');
    }
}

int longestZigZag(struct TreeNode* root) {
    int tmp_cnt = 0;
    int g_cnt = 0;
    char prev = 'o';
    dfs(root, &g_cnt, tmp_cnt, prev);
    return g_cnt;
}
