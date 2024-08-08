// RedBlack Tree
// Rules: 1. red or black 2. root = black 3. leaf = black 4. if i am red, my children are black 5. always same black height
// Rotation = O(1)
// Insertion = O(lgn)
// Deletion = O(lgn)

#include <iostream>

enum Color { RED, BLACK };

class TreeNode {
public:
    int key;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    Color color;

    TreeNode(int key) : key(key), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
    TreeNode(int key,TreeNode* parent,Color color) : key(key), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
};

class RedBlackTree {

    void leftRotate(TreeNode* x);
    void rightRotate(TreeNode* x);
    void fixInsertion(TreeNode* x);
    void fixDeletion(TreeNode* x);
    void transplant(TreeNode* u, TreeNode* v);
    TreeNode* treeMinimum(TreeNode* x);
    void inorderTraversal(TreeNode* x, int depth);
    void rbtransplant(TreeNode* u, TreeNode* v);

    public:
        TreeNode* root;
        RedBlackTree() : root(nullptr) {}

        void insert(TreeNode* newNode);
        void deletion(TreeNode* obj);
        void printInorder();
        TreeNode* search(int key);
};

void RedBlackTree::transplant(TreeNode* u, TreeNode *v) {
    if (u ->parent == nullptr) {
        root = v;
    }
    else if (u == u->parent ->left) {
        u -> parent -> left = v;
    }
    else {
        u -> parent -> right = v;
    }
    if (v != nullptr) {
        v -> parent = u -> parent;
    };
}

TreeNode* RedBlackTree::treeMinimum(TreeNode* x) {
    while(x->left != nullptr) {
        x = x->left;
    }
    return x;
}

void RedBlackTree::inorderTraversal(TreeNode* x, int depth) {
    if (x != nullptr) {
        inorderTraversal(x->right, depth + 1);

        for (int i = 0; i < depth; ++i)
            std::cout << "        ";

        std::cout << x->key << "(";
        if (x->color == Color::RED)
            std::cout << "RED";
        else
            std::cout << "BLACK";
        std::cout << ")" << std::endl;

        inorderTraversal(x->left, depth + 1);
    }
}

void RedBlackTree::leftRotate(TreeNode* x) {
    TreeNode* y = x ->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y -> parent = x-> parent;
    if (x->parent == nullptr) {
        root = y;
    }
    else if (x == x->parent -> left) {
        x->parent->left = y;
    }
    else {
        x -> parent -> right = y;
    }
    y ->left = x;
    x ->parent = y;
}

void RedBlackTree::rightRotate(TreeNode* x) {
    TreeNode* y = x -> left;
    x -> left = y -> right;
    if (y->right != nullptr) {
        y->right -> parent = x;
    }
    y -> parent = x -> parent;
    if (x->parent == nullptr) {
        root = y;
    }
    else if (x== x-> parent -> right) {
        x -> parent -> right = y;
    }
    else {
        x -> parent -> left = y;
    }
    y -> right = x;
    x -> parent = y;
}

void RedBlackTree::insert(TreeNode* newNode) {
    TreeNode* x = root;
    TreeNode* y = nullptr;
    while (x != nullptr) {
        y = x;
        if (newNode->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    newNode->parent = y;
    if (y == nullptr) {
        root = newNode;
    }
    else if (newNode->key < y->key) {
        y->left = newNode;
    }
    else {
        y->right = newNode;
    }
    
    fixInsertion(newNode);

}


void RedBlackTree::fixInsertion(TreeNode* z) {
    TreeNode* y = nullptr;
    //NIL 객체가 아니라, nullptr을 없는 노드로 사용하므로, z != root 조건이 없으면, segmentation fault 발생
    while (z != root && z -> parent -> color == Color::RED) {
        if (z->parent == z-> parent -> parent -> left) {
            y = z-> parent -> parent-> right;
            if(y != nullptr && y->color == Color::RED) {
                z->parent->color = Color::BLACK;
                y->color = Color::BLACK;
                z->parent->parent->color = Color::RED;
                z = z->parent -> parent;

            }
            else {
                if (z== z->parent ->right) {
                    z = z -> parent;
                    leftRotate(z);
                }
                z->parent->color = Color::BLACK;
                z->parent->parent->color = Color::RED;
                rightRotate(z -> parent->parent);
            }
        }
        else {
            y = z->parent->parent -> left;
            if (y != nullptr && y->color == Color::RED) {
                z -> parent -> color = Color::BLACK;
                y -> color = Color::BLACK;
                z -> parent -> parent -> color = Color::RED;
                z = z-> parent ->parent;
            }
            else {
                if (z== z->parent -> left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = Color::BLACK;
                z -> parent -> parent -> color = Color::RED;
                leftRotate(z -> parent->parent);
            }
        }
    }
    root -> color = Color::BLACK;
}
void RedBlackTree::rbtransplant(TreeNode* u, TreeNode* v) {
    if(v != nullptr) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent ->left) {
            u->parent -> left = v;
        }
        else {
            u->parent -> right = v;
        }
        v->parent = u->parent;
    }
    else {
        
    }
}

void RedBlackTree::deletion(TreeNode* obj) {
    TreeNode* y = obj;
    Color y_origin = y->color;
    TreeNode* x;
    
    
    if (obj -> left == nullptr) {
        x = obj -> right;
        transplant(obj, obj -> right);
    }
    else if(obj -> right == nullptr) {
        x = obj -> left;
        transplant(obj, obj -> left);
    }
    else {
        y = treeMinimum(obj -> right);
        y_origin = y->color;
        x = y -> right;
        if (y != obj -> right) {
            transplant(y, y->right);
            y -> right = obj -> right;
            y -> right -> parent = y;
 
        }
        else {
            //NIL 대신, nullptr을 사용하고 있기 때문에, x!=nullptr 조건 필요
            if (x!= nullptr) {
                x->parent = y;
            }
        }
        transplant(obj, y);
        y -> left = obj -> left;
        y -> left -> parent = y;
        y -> color = obj -> color;
        
    }
    //NIL 대신, nullptr을 사용하고 있기 때문에, x!=nullptr 조건 필요
    if (x!= nullptr && y_origin == Color::BLACK) {
        fixDeletion(x);
    }
}


void RedBlackTree::fixDeletion(TreeNode* x) {
    TreeNode* w; 
    //NIL 대신, nullptr을 사용하고 있기 때문에, x!=root 조건 필요 
    while (x != root && x->color == Color::BLACK) {
        if (x == x->parent->left) {
            w = x->parent->right;
            if (w->color == Color::RED) {
                w->color = Color::BLACK;
                x->parent->color = Color::RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            //NIL 대신, nullptr을 사용하고 있기 때문에, ==BLACK 찾을 시, or nullptr 함께 넣어주어야함.
            if ((w->left == nullptr || w->left->color == Color::BLACK) &&
                (w->right == nullptr || w->right->color == Color::BLACK)) {
                w->color = Color::RED;
                x = x->parent;
            } else {
                if (w->right == nullptr || w->right->color == Color::BLACK) {
                    if (w->left != nullptr)
                        w->left->color = Color::BLACK;
                    w->color = Color::RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = Color::BLACK;
                if (w->right != nullptr)
                    w->right->color = Color::BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            w = x->parent->left;
            if (w->color == Color::RED) {
                w->color = Color::BLACK;
                x->parent->color = Color::RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if ((w->right == nullptr || w->right->color == Color::BLACK) &&
                (w->left == nullptr || w->left->color == Color::BLACK)) {
                w->color = Color::RED;
                x = x->parent;
            } else {
                if (w->left == nullptr || w->left->color == Color::BLACK) {
                    if (w->right != nullptr)
                        w->right->color = Color::BLACK;
                    w->color = Color::RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = Color::BLACK;
                if (w->left != nullptr)
                    w->left->color = Color::BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    if (x != nullptr)
        x->color = Color::BLACK;
}





void RedBlackTree::printInorder() {
    inorderTraversal(root, 0);
}

TreeNode* RedBlackTree::search(int key) {
    TreeNode* current = root;
    while (current != nullptr && current->key != key) {
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}


int main(){

    RedBlackTree tree;

    // Test case 1: Insertion and inorder traversal
    tree.insert(new TreeNode(10));
    tree.insert(new TreeNode(20));
    tree.insert(new TreeNode(30));
    tree.insert(new TreeNode(40));
    tree.insert(new TreeNode(50));

    std::cout <<"-----------------------------" << std::endl;
    std::cout <<"NodeKey(NodeColor, Depth) 형식" << std::endl;
    std::cout <<"-----------------------------" << std::endl;

    std::cout << "Inorder traversal: ";
    std::cout << std::endl;
    tree.printInorder(); // Output: 10 20 30 40 50

    std::cout << std::endl;
    // Test case 2: Deletion and inorder traversal
    TreeNode* nodeToDelete = tree.search(30);
    tree.deletion(nodeToDelete);


    std::cout << "Inorder traversal after deletion: ";
    std::cout << std::endl;
    tree.printInorder(); // Output: 10 20 40 50
    std::cout << std::endl;

    // Test case 3: Insertion and deletion

    tree.insert(new TreeNode(35));
    tree.insert(new TreeNode(25));

    std::cout << "Inorder traversal before deletion: ";
    std::cout << std::endl;
    tree.printInorder(); // Output: 10 20 25 35 40 50

    std::cout << std::endl;
    TreeNode* nodeToDelete2 = tree.search(20);
    tree.deletion(nodeToDelete2);

    std::cout << "Inorder traversal after deletion: ";
    std::cout << std::endl;
    tree.printInorder(); // Output: 10 25 35 40 50


    return 0;
    
}