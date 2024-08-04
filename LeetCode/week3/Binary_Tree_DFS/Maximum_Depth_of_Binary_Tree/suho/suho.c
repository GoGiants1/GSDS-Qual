/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(int *v, int *vlen, struct TreeNode *node, int depth){
        int isin = 0;
        for(int i = 0; i < *vlen; i++){
            if(v[i]==node->val) isin = 1;
        }
        if(isin != 1){
            v[*vlen] = node->val;
            *vlen += 1;
            int d = depth;

            if(node->left != NULL){
                int tmp = dfs(v, vlen, node->left, depth+1);
                d = tmp > d ? tmp : d;
            }
            if(node->right != NULL){
                int tmp = dfs(v, vlen, node->right, depth+1);
                d = tmp > d ? tmp : d;
            }
            return d;
        }
        else return depth;
    }

int maxDepth(struct TreeNode* root) {
    int *v = (int*)malloc(sizeof(int)*10010);
    int vlen = 0;
    return dfs(v, &vlen, root, 1);
}
