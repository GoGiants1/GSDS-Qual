/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(int *v, int *vlen, struct TreeNode *node, int *l, int *llen){
    int isin = 0;
    for(int i = 0; i < *vlen; i++){
        if(v[i]==node->val) isin = 1;
    }
    if(isin != 1){
        v[*vlen] = node->val;
        *vlen += 1;

        if(node->left == NULL && node->right == NULL){
            l[*llen] = node->val;
            *llen += 1;
        }
        else if(node->left != NULL) dfs(v, vlen, node->left, l, llen);
        else dfs(v, vlen, node->right, l, llen);
    }
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int *l1 = (int*)malloc(sizeof(int)*10010);
    int *l2 = (int*)malloc(sizeof(int)*10010);
    int llen1 = 0, llen2 = 0;
    
    int *v = (int*)malloc(sizeof(int)*10010);
    int vlen = 0;
    dfs(v, &vlen, root1, l1, &llen1);
    vlen = 0;
    dfs(v, &vlen, root2, l2, &llen2);
    
    bool same = true;
    if(llen1 != llen2) return false;
    else{
        for(int i = 0; i < llen1; i++){
            if(l1[i]!=l2[i]) same = false;
        }
        return same;
    } 
}
