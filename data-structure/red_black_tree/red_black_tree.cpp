#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    string color; // "red" or "black"
    Node* left;
    Node* right;
    Node* parent;

    Node(int data, string color = "red") {
        this->data = data;
        this->color = color;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class RedBlackTree {
public:
    Node* NIL;
    Node* root;

    RedBlackTree() {
        NIL = new Node(0, "black");
        NIL->left = NIL->right = NIL;
        root = NIL;
    }

    void insert(int data) {
        Node* new_node = new Node(data);
        new_node->left = NIL;
        new_node->right = NIL;

        Node* parent = nullptr;
        Node* current = root;

        while (current != NIL) {
            parent = current;
            if (new_node->data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        new_node->parent = parent;
        if (parent == nullptr) {
            root = new_node;
        } else if (new_node->data < parent->data) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }

        new_node->color = "red"; // 삽입 시 항상 빨간색으로 설정
        fix_insert(new_node);
    }

    void fix_insert(Node* node) {
        while (node != root && node->parent->color == "red") {
            if (node->parent == node->parent->parent->left) {
                Node* uncle = node->parent->parent->right;
                if (uncle->color == "red") {
                    node->parent->color = "black";
                    uncle->color = "black";
                    node->parent->parent->color = "red";
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        left_rotate(node);
                    }
                    node->parent->color = "black";
                    node->parent->parent->color = "red";
                    right_rotate(node->parent->parent);
                }
            } else {
                Node* uncle = node->parent->parent->left;
                if (uncle->color == "red") {
                    node->parent->color = "black";
                    uncle->color = "black";
                    node->parent->parent->color = "red";
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        right_rotate(node);
                    }
                    node->parent->color = "black";
                    node->parent->parent->color = "red";
                    left_rotate(node->parent->parent);
                }
            }
        }
        root->color = "black";
    }

    void left_rotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != NIL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void right_rotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != NIL) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == nullptr) {
            root = x;
        } else if (y == y->parent->right) {
            y->parent->right = x;
        } else {
            y->parent->left = x;
        }
        x->right = y;
        y->parent = x;
    }

    Node* search(int data) {
        Node* current = root;
        while (current != NIL) {
            if (data == current->data) {
                return current;
            } else if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return nullptr;
    }

    void deleteNode(int data) {
        Node* node = search(data);
        if (node == nullptr) {
            return;
        }

        Node* y = node;
        Node* x;
        string y_original_color = y->color;

        if (node->left == NIL) {
            x = node->right;
            rb_transplant(node, node->right);
        } else if (node->right == NIL) {
            x = node->left;
            rb_transplant(node, node->left);
        } else {
            y = minimum(node->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == node) {
                x->parent = y;
            } else {
                rb_transplant(y, y->right);
                y->right = node->right;
                y->right->parent = y;
            }

            rb_transplant(node, y);
            y->left = node->left;
            y->left->parent = y;
            y->color = node->color;
        }

        if (y_original_color == "black") {
            fix_delete(x);
        }
    }

    Node* minimum(Node* node) {
        while (node->left != NIL) {
            node = node->left;
        }
        return node;
    }

    void rb_transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void fix_delete(Node* x) {
        while (x != root && x->color == "black") {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == "red") {
                    w->color = "black";
                    x->parent->color = "red";
                    left_rotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == "black" && w->right->color == "black") {
                    w->color = "red";
                    x = x->parent;
                } else {
                    if (w->right->color == "black") {
                        w->left->color = "black";
                        w->color = "red";
                        right_rotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = "black";
                    w->right->color = "black";
                    left_rotate(x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left;
                if (w->color == "red") {
                    w->color = "black";
                    x->parent->color = "red";
                    right_rotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == "black" && w->left->color == "black") {
                    w->color = "red";
                    x = x->parent;
                } else {
                    if (w->left->color == "black") {
                        w->right->color = "black";
                        w->color = "red";
                        left_rotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = "black";
                    w->left->color = "black";
                    right_rotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = "black";
    }

    vector<int> inorder_traversal(Node* node) {
        vector<int> result;
        if (node != NIL) {
            vector<int> left = inorder_traversal(node->left);
            result.insert(result.end(), left.begin(), left.end());
            result.push_back(node->data);
            vector<int> right = inorder_traversal(node->right);
            result.insert(result.end(), right.begin(), right.end());
        }
        return result;
    }
};

// 사용 예제
int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    rbt.insert(5);

    cout << "Inorder Traversal of the tree:" << endl;
    vector<int> traversal = rbt.inorder_traversal(rbt.root);
    for (int data : traversal) {
        cout << data << " ";
    }
    cout << endl;

    Node* search_result = rbt.search(15);
    if (search_result) {
        cout << "Node with data " << search_result->data << " found with color " << search_result->color << endl;
    } else {
        cout << "Node not found" << endl;
    }

    return 0;
}