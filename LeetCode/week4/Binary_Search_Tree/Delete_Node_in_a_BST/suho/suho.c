/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNodeSet TreeNodeSet;
typedef struct TreeNode TreeNode;
struct TreeNodeSet {
    TreeNode *node;
    TreeNode *parent;
};

TreeNodeSet search(TreeNode *root, int key){
    TreeNode *x = root;
    TreeNode *xp = NULL;
    while(x != NULL && x->val != key){
        if(x->val > key){
            xp = x;
            x = x->left;
        }
        else{
            xp = x;
            x = x->right;
        }
    }
    TreeNodeSet ret = {x, xp};
    return ret;
}

TreeNodeSet bst_min(TreeNode *x){
    TreeNode *p = NULL;
    while(x->left != NULL){
        p = x;
        x = x->left;
    }
    TreeNodeSet ret = {x, p};
    return ret;
}

TreeNodeSet succ(TreeNode *x){
    TreeNodeSet res = bst_min(x->right);
    if(res.parent == NULL) res.parent = x;
    return res;
}

void trans(TreeNode *up, TreeNode *u, TreeNode *v){
    if(u == up->left) up->left = v;
    else up->right = v;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    TreeNodeSet zres = search(root, key);
    if(root == NULL || zres.node == NULL) return root;
    else if(zres.parent == NULL){
        if(zres.node->left == NULL) return zres.node->right;
        else if(zres.node->right == NULL) return zres.node->left;
        else{
            TreeNodeSet yres = succ(zres.node);
            if(yres.node != zres.node->right){
                trans(yres.parent, yres.node, yres.node->right);
                yres.node->right = zres.node->right;
            }
            yres.node->left = zres.node->left;
            return yres.node;
        }
    }
    else{
        if(zres.node->left == NULL) trans(zres.parent, zres.node, zres.node->right);
        else if(zres.node->right == NULL) trans(zres.parent, zres.node, zres.node->right);
        else{
            TreeNodeSet yres = succ(zres.node);
            if(yres.node != zres.node->right){
                trans(yres.parent, yres.node, yres.node->right);
                yres.node->right = zres.node->right;
            }
            trans(zres.parent, zres.node, yres.node);
            yres.node->left = zres.node->left;
        }
        return root;
    }
}
