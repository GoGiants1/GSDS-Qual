/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
    struct TreeNode *visit[10010];
    int nvisit = 0;
    struct TreeNode *queue[10010];
    int lv_queue[10010];
    int sum[10010];
    int nsum = 0;
  
    queue[0] = root;
    int nqueue = 1;
    lv_queue[0] = 1;
  
    while(nqueue!=0){
        struct TreeNode *node = queue[nqueue-1];
        int lv = lv_queue[nqueue-1];
        nqueue--;

        int v = 0;
        for(int i = 0; i<nvisit; i++){
            if(visit[i]==node) v=1;
        }

        if(v==0){
            visit[nvisit] = node;
            nvisit++;
            if(nsum < lv){
                sum[nsum]=node->val;
                nsum++;
            }
            else sum[lv-1] += node->val;
            if(node->left != NULL){
                queue[nqueue]=node->left;
                lv_queue[nqueue] = lv+1;
                nqueue++;
            }
            if(node->right != NULL){
                queue[nqueue]=node->right;
                lv_queue[nqueue] = lv+1;
                nqueue++;
            }
        }
    }
    int index = 0;
    int tmp = 0;
    for(int i = 0; i<nsum; i++){
        if(sum[i]>tmp){
            index = i;
            tmp = sum[i];
        }
    }
    return index+1;
}
