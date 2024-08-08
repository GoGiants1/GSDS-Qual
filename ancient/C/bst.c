#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

TreeNode* findMax(TreeNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

TreeNode* find(TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key == root->val) {
        return root;
    } else if (key < root->val) {
        return find(root->left, key);
    } else {
        return find(root->right, key);
    }
}

TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->val);
    }
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    printf("Inorder traversal before deletion:\n");
    inorderTraversal(root);
    printf("\n");
    
    root = deleteNode(root, 50);
    
    printf("Inorder traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal:\n");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postorderTraversal(root);
    printf("\n");

    int key_to_find = 60;
    TreeNode* found = find(root, key_to_find);
    if (found) {
        printf("%d found in the tree.\n", key_to_find);
    } else {
        printf("%d not found in the tree.\n", key_to_find);
    }
    key_to_find = 10;
    found = find(root, key_to_find);
    if (found) {
        printf("%d found in the tree.\n", key_to_find);
    } else {
        printf("%d not found in the tree.\n", key_to_find);
    }

    TreeNode* minVal = findMin(root);
    printf("Minimum value in the tree: %d\n", minVal->val);

    TreeNode* maxVal = findMax(root);
    printf("Maximum value in the tree: %d\n", maxVal->val);
    
    return 0;
}
