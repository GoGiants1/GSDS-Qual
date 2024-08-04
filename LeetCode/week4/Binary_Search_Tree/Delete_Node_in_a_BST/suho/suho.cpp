/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNodeSet {
    TreeNode *node;
    TreeNode *parent;
    TreeNodeSet(TreeNode *node, TreeNode *parent) : node(node), parent(parent) {}
};

class Solution {
public:
    TreeNodeSet search(TreeNode *root, int key){
        TreeNode *x = root;
        TreeNode *xp = nullptr;
        while(x != nullptr and x->val != key){
            if(x->val > key){
                xp = x;
                x = x->left;
            }
            else{
                xp = x;
                x = x->right;
            }
        }
        TreeNodeSet ret = TreeNodeSet(x, xp);
        return ret;
    }

    TreeNodeSet bst_min(TreeNode *x){
        TreeNode *p = nullptr;
        while(x->left != nullptr){
            p = x;
            x = x->left;
        }
        TreeNodeSet ret = TreeNodeSet(x, p);
        return ret;
    }
    
    TreeNodeSet succ(TreeNode *x){
        TreeNodeSet res = bst_min(x->right);
        if(res.parent == nullptr) res.parent = x;
        return res;
    }

    void trans(TreeNode *up, TreeNode *u, TreeNode *v){
        if(u == up->left) up->left = v;
        else up->right = v;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNodeSet zres = search(root, key);
        if(root == nullptr || zres.node == nullptr) return root;
        else if(zres.parent == nullptr){
            if(zres.node->left == nullptr) return zres.node->right;
            else if(zres.node->right == nullptr) return zres.node->left;
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
            if(zres.node->left == nullptr) trans(zres.parent, zres.node, zres.node->right);
            else if(zres.node->right == nullptr) trans(zres.parent, zres.node, zres.node->right);
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
};
