#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// 이진 트리의 노드를 정의하는 클래스
class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char key) : data(key), left(nullptr), right(nullptr) {}
};

// 이진 트리를 정의하는 클래스
class Tree {
public:
    Node* root;
    bool top_down; // top down: 재귀적, bottom up: 반복적

    Tree() : root(nullptr), top_down(true) {}

    // 전위 순회 (Preorder Traversal)
    void preorder() {
        if (top_down)
            preorder_top_down(root);
        else
            preorder_bottom_up(root);
    }

    void preorder_top_down(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder_top_down(node->left);
        preorder_top_down(node->right);
    }

    void preorder_bottom_up(Node* node) {
        if (node == nullptr) return;

        stack<Node*> stk;
        stk.push(node);

        while (!stk.empty()) {
            node = stk.top();
            stk.pop();
            if (node) {
                cout << node->data << " ";
                if (node->right) stk.push(node->right);
                if (node->left) stk.push(node->left);
            }
        }
    }

    // 중위 순회 (Inorder Traversal)
    void inorder() {
        if (top_down)
            inorder_top_down(root);
        else
            inorder_bottom_up(root);
    }

    void inorder_top_down(Node* node) {
        if (node == nullptr) return;
        inorder_top_down(node->left);
        cout << node->data << " ";
        inorder_top_down(node->right);
    }

    void inorder_bottom_up(Node* node) {
        if (node == nullptr) return;

        stack<Node*> stk;
        Node* current = node;

        while (!stk.empty() || current != nullptr) {
            while (current != nullptr) {
                stk.push(current);
                current = current->left;
            }
            current = stk.top();
            stk.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    // 후위 순회 (Postorder Traversal)
    void postorder() {
        if (top_down)
            postorder_top_down(root);
        else
            postorder_bottom_up(root);
    }

    void postorder_top_down(Node* node) {
        if (node == nullptr) return;
        postorder_top_down(node->left);
        postorder_top_down(node->right);
        cout << node->data << " ";
    }

    void postorder_bottom_up(Node* node) {
        if (node == nullptr) return;

        stack<Node*> stk;
        Node* current = node;
        Node* last_visited = nullptr;

        while (!stk.empty() || current != nullptr) {
            while (current != nullptr) {
                stk.push(current);
                current = current->left;
            }
            current = stk.top();
            if (current->right == nullptr || current->right == last_visited) {
                cout << current->data << " ";
                last_visited = stk.top();
                stk.pop();
                current = nullptr;
            } else {
                current = current->right;
            }
        }
    }

    // 레벨 순서 순회 (Level Order Traversal)
    void levelorder() {
        if (top_down) {
            levelorder_top_down(root);
        } else {
            levelorder_bottom_up(root);
        }
    }

    void levelorder_top_down(Node* node) {
        if (node == nullptr) return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    void levelorder_bottom_up(Node* node) {
        if (node == nullptr) return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    // 노드를 삽입하는 함수
    void insert(char key) {
        Node* new_node = new Node(key);
        if (root == nullptr) {
            root = new_node;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node->left == nullptr) {
                node->left = new_node;
                break;
            } else {
                q.push(node->left);
            }

            if (node->right == nullptr) {
                node->right = new_node;
                break;
            } else {
                q.push(node->right);
            }
        }
    }

    // 노드를 검색하는 함수
    Node* search(char key) {
        if (root == nullptr) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node->data == key) {
                return node;
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return nullptr;
    }

    // 노드를 삭제하는 함수
    void delete_node(char key) {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        Node* key_node = nullptr;
        Node* last_node = nullptr;

        while (!q.empty()) {
            last_node = q.front();
            q.pop();

            if (last_node->data == key) {
                key_node = last_node;
            }

            if (last_node->left) q.push(last_node->left);
            if (last_node->right) q.push(last_node->right);
        }

        if (key_node) {
            key_node->data = last_node->data;
            delete_deepest(root, last_node);
        }
    }

    // 가장 깊은 노드를 삭제하는 함수
    void delete_deepest(Node* root, Node* d_node) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node->right) {
                if (node->right == d_node) {
                    delete node->right;
                    node->right = nullptr;
                    return;
                } else {
                    q.push(node->right);
                }
            }

            if (node->left) {
                if (node->left == d_node) {
                    delete node->left;
                    node->left = nullptr;
                    return;
                } else {
                    q.push(node->left);
                }
            }
        }
    }
};

int main() {
    Tree tree;
    tree.root = new Node('A');
    tree.root->left = new Node('B');
    tree.root->right = new Node('C');
    tree.root->left->left = new Node('D');
    tree.root->left->right = new Node('E');
    tree.root->right->left = new Node('F');
    tree.root->left->left->left = new Node('G');
    tree.root->left->left->left->right = new Node('H');

    // 트리 출력
    cout << "=====Traversal=====" << endl;
    cout << "Preorder: ";
    tree.preorder();
    cout << endl << "Inorder: ";
    tree.inorder();
    cout << endl << "Postorder: ";
    tree.postorder();
    cout << endl << "Levelorder: ";
    tree.levelorder();
    cout << endl;

    cout << "shifting implementation to bottom_up" << endl;
    tree.top_down = false;
    cout << "Preorder: ";
    tree.preorder();
    cout << endl << "Inorder: ";
    tree.inorder();
    cout << endl << "Postorder: ";
    tree.postorder();
    cout << endl << "Levelorder: ";
    tree.levelorder();
    cout << endl;

    // 삽입 및 삭제 작업
    cout << "=====Manipulation=====" << endl;
    tree.insert('I');
    cout << "Insert I: ";
    tree.levelorder();
    cout << endl << "Search B: " << tree.search('B')->data << endl;
    tree.delete_node('B');
    cout << "Delete B: ";
    tree.levelorder();
    cout << endl << "Search B: " << (tree.search('B') ? "Found" : "Not Found") << endl;

    return 0;
}