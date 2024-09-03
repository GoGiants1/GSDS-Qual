#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char color; // 'R' for Red, 'B' for Black
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

typedef struct {
    Node* NIL;
    Node* root;
} RedBlackTree;

Node* create_node(int data, char color, Node* NIL) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->color = color;
    node->left = NIL;
    node->right = NIL;
    node->parent = NULL;
    return node;
}

RedBlackTree* create_rbt() {
    RedBlackTree* rbt = (RedBlackTree*)malloc(sizeof(RedBlackTree));
    rbt->NIL = create_node(0, 'B', NULL);
    rbt->root = rbt->NIL;
    return rbt;
}

void left_rotate(RedBlackTree* rbt, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != rbt->NIL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        rbt->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void right_rotate(RedBlackTree* rbt, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != rbt->NIL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        rbt->root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

void fix_insert(RedBlackTree* rbt, Node* node) {
    while (node != rbt->root && node->parent->color == 'R') {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            if (uncle->color == 'R') {
                node->parent->color = 'B';
                uncle->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    left_rotate(rbt, node);
                }
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                right_rotate(rbt, node->parent->parent);
            }
        } else {
            Node* uncle = node->parent->parent->left;
            if (uncle->color == 'R') {
                node->parent->color = 'B';
                uncle->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    right_rotate(rbt, node);
                }
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                left_rotate(rbt, node->parent->parent);
            }
        }
    }
    rbt->root->color = 'B';
}

void insert(RedBlackTree* rbt, int data) {
    Node* new_node = create_node(data, 'R', rbt->NIL);
    
    Node* parent = NULL;
    Node* current = rbt->root;

    while (current != rbt->NIL) {
        parent = current;
        if (new_node->data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    new_node->parent = parent;
    if (parent == NULL) {
        rbt->root = new_node;
    } else if (new_node->data < parent->data) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    fix_insert(rbt, new_node);
}

Node* search(RedBlackTree* rbt, int data) {
    Node* current = rbt->root;
    while (current != rbt->NIL) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

Node* minimum(RedBlackTree* rbt, Node* node) {
    while (node->left != rbt->NIL) {
        node = node->left;
    }
    return node;
}

void rb_transplant(RedBlackTree* rbt, Node* u, Node* v) {
    if (u->parent == NULL) {
        rbt->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void fix_delete(RedBlackTree* rbt, Node* x) {
    while (x != rbt->root && x->color == 'B') {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                left_rotate(rbt, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == 'B' && w->right->color == 'B') {
                w->color = 'R';
                x = x->parent;
            } else {
                if (w->right->color == 'B') {
                    w->left->color = 'B';
                    w->color = 'R';
                    right_rotate(rbt, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->right->color = 'B';
                left_rotate(rbt, x->parent);
                x = rbt->root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                right_rotate(rbt, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 'B' && w->left->color == 'B') {
                w->color = 'R';
                x = x->parent;
            } else {
                if (w->left->color == 'B') {
                    w->right->color = 'B';
                    w->color = 'R';
                    left_rotate(rbt, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->left->color = 'B';
                right_rotate(rbt, x->parent);
                x = rbt->root;
            }
        }
    }
    x->color = 'B';
}

void delete_node(RedBlackTree* rbt, int data) {
    Node* node = search(rbt, data);
    if (node == NULL) {
        return;
    }

    Node* y = node;
    Node* x;
    char y_original_color = y->color;

    if (node->left == rbt->NIL) {
        x = node->right;
        rb_transplant(rbt, node, node->right);
    } else if (node->right == rbt->NIL) {
        x = node->left;
        rb_transplant(rbt, node, node->left);
    } else {
        y = minimum(rbt, node->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == node) {
            x->parent = y;
        } else {
            rb_transplant(rbt, y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }

        rb_transplant(rbt, node, y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;
    }

    if (y_original_color == 'B') {
        fix_delete(rbt, x);
    }

    free(node);
}

void inorder_traversal(Node* node, Node* NIL) {
    if (node != NIL) {
        inorder_traversal(node->left, NIL);
        printf("%d ", node->data);
        inorder_traversal(node->right, NIL);
    }
}

int main() {
    RedBlackTree* rbt = create_rbt();

    insert(rbt, 10);
    insert(rbt, 20);
    insert(rbt, 30);
    insert(rbt, 15);
    insert(rbt, 25);
    insert(rbt, 5);

    printf("Inorder Traversal of the tree:\n");
    inorder_traversal(rbt->root, rbt->NIL);
    printf("\n");

    Node* search_result = search(rbt, 15);
    if (search_result != NULL) {
        printf("Node with data %d found with color %c\n", search_result->data, search_result->color);
    } else {
        printf("Node not found\n");
    }

    return 0;
}