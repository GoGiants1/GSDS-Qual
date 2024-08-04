/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode *x = root;
    while(x != NULL && x->val != val){
        if(x->val > val) x = x->left;
        else x = x->right;
    }
    return x;
}
