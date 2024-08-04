/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    struct TreeNode *node = root;
    *returnSize = 0;
    while(node!=NULL){
        (*returnSize)+=1;
        node = node->right;
    }

    int *res = (int*)malloc(sizeof(int)*(*returnSize));
    node = root;
    for(int i = 0; i<(*returnSize);i++){
        res[i] = node->val;
        node = node->right;
    }

    return res;
}
