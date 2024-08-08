// All about Binary Search Tree
// BFS Complexity = O(v)
// DFS 1. predorder 2. inorder 3. postorder Complexity = O(V)
// Searching O(h)
// Find min/max O(h)
// Find successr and predecessor O(h)
// Insertion O(h)
// Deletion O(h)

#include <iostream>
#include <queue>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : val(0),left(nullptr),right(nullptr),parent(nullptr){};
    TreeNode(int x, TreeNode*parent) : val(x), left(nullptr),right(nullptr),parent(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

void BFS(TreeNode *root){
    if (root == nullptr){return;}
    queue <TreeNode*> Q;
    Q.push(root);

    while(!Q.empty()){
        TreeNode *n = Q.front();
        Q.pop();
        cout<<n->val<<" ";

        if (n->left != nullptr){
            Q.push(n->left);
        }
        if (n->right != nullptr){
            Q.push(n->right);
        }
    }
}

void DFS(TreeNode *root){
    if (root == nullptr){
        return;
    }
    cout << root->val << " ";
    DFS(root->left);
    DFS(root->right);
}

TreeNode *search(TreeNode *root, int k){
    if(root->val == k || root==nullptr){
        return root;
    }
    if(root->val>k){
        return search(root->left,k);
    }
    else{
        return search(root->right,k);
    }
}

TreeNode *search_iter(TreeNode *root, int k){
    while(root!=nullptr && root->val!=k){
        if (root->val>k){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return root;
}

void minmax(TreeNode* root){
    TreeNode* min = root;
    TreeNode* max = root;
    while(min->left!=nullptr){
        min=min->left;
    }

    while(max->right!=nullptr){
        max=max->right;
    }

    cout<< "min: " << min->val <<endl;
    cout<< "max: " << max->val <<endl;
}

void predecessor(TreeNode* current){
    if(current->left == nullptr){
        TreeNode *y = current->parent;
        while(y!=nullptr && current == y->left){
            current = y;
            y = y->parent;
        }
        if(y!=nullptr){
            cout << "predecessor: " << y->val <<endl;
        }
        else{
            cout << "no predecessor" <<endl;
        }
    }
    else{
        current = current->left;
        while(current->right!=nullptr){
            current=current->right;
        }
        cout << "predecessor: " << current->val <<endl;
    }
}

void successor(TreeNode *current){
    if(current->right == nullptr){
        TreeNode *y = current->parent;
        while(y!=nullptr && current == y->right){
            current = y;
            y = y->parent;
        }
        if(y!=nullptr){
            cout << "successor: " << y->val <<endl;
        }
        else{
            cout << "no successor" <<endl;
        }
    }
    else{
        current = current->right;
        while(current->left!=nullptr){
            current = current->left;
        }
        cout << "successor: " << current->val << endl;
    }
}

void insert(TreeNode *root, int k){
    TreeNode* n = new TreeNode(k,nullptr);
    TreeNode *x = root;
    TreeNode *current;
    while(x!=nullptr){
        current = x;
        if(k<x->val){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    n->parent = current;
    if (current == nullptr){
        root = n ; // it is a root of a tree
    }
    else if (current->val>k){
        current->left = n;
    }
    else{
        current->right = n;
    }
}

void transplant(TreeNode*root, TreeNode*u, TreeNode*v){
    if (u->parent==nullptr){
        root = v;
    }
    else if (u==u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }
    if(v != nullptr){
        v->parent = u-> parent;
    }
}

void deletion(TreeNode *root, int k){
    // No child -> 그냥 remove
    // One child -> replace by my child
    // Two children -> replace by my successor
    TreeNode *del = root;

    while(del!=nullptr && del->val!=k){
        if (del->val <k){
            del = del->right;
        }
        else{
            del = del->left;
        }
    }
    if(del == nullptr){
        cout << "Node not exists"<<endl;
        return;
    }

    if(del->left==nullptr){
        transplant(root,del,del->right);
    }
    else if (del->right ==nullptr){
        transplant(root,del,del->left);
    }
    else{
        TreeNode* min = del->right;
        while(min->left!=nullptr){
            min=min->left;
        }

        if(min!=del->right){
            transplant(root,min,min->right);
            min->right = del->right;
            min->right->parent = min;
        }
        transplant(root,del,min);
        min->left = del->left;
        min->left->parent = min;

    }
}

int main(){
    TreeNode *root = new TreeNode(8,nullptr);
    insert(root,3);
    insert(root,10);
    insert(root,1);
    insert(root,6);
    insert(root,14);
    insert(root,4);
    insert(root,7);
    insert(root,13);

    DFS(root);


    cout << "BFS: " <<endl;
    BFS(root);
    cout<<endl;

    cout << "DFS: "<<endl;
    DFS(root);
    cout<<endl;

    cout << "Search: "<<endl;
    cout<< search(root,2)->val <<endl;

    cout << "Search iter: "<<endl;
    cout<< search_iter(root,2)->val <<endl;

    minmax(root);

    successor(root->right);
    predecessor(root->left->left);

    insert(root,50);
    cout<< root->right->right->right->val << endl;

    deletion(root,50);
    cout<< root->right->right->val << endl;

    return 0;
}