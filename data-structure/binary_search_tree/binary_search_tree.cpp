#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int key) {
        if (root == nullptr) {
            root = new Node(key);
        } else {
            _insert(root, key);
        }
    }

    Node* search(int key) {
        return _search(root, key);
    }

    void deleteNode(int key) {
        root = _delete(root, key);
    }

    void inorder() {
        _inorder(root);
        cout << endl;
    }

    int find_min() {
        Node* minNode = _min_value_node(root);
        return minNode ? minNode->data : -1;
    }

    int find_max() {
        Node* current = root;
        while (current && current->right != nullptr) {
            current = current->right;
        }
        return current ? current->data : -1;
    }

    int height() {
        return _height(root);
    }

    int count_nodes() {
        return _count_nodes(root);
    }

    void print_given_level(int level) {
        _print_given_level(root, level);
        cout << endl;
    }

private:
    void _insert(Node* root, int key) {
        if (key < root->data) {
            if (root->left == nullptr) {
                root->left = new Node(key);
            } else {
                _insert(root->left, key);
            }
        } else if (key > root->data) {
            if (root->right == nullptr) {
                root->right = new Node(key);
            } else {
                _insert(root->right, key);
            }
        }
    }

    Node* _search(Node* root, int key) {
        if (root == nullptr || root->data == key)
            return root;

        if (key < root->data)
            return _search(root->left, key);

        return _search(root->right, key);
    }

    Node* _delete(Node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->data) {
            root->left = _delete(root->left, key);
        } else if (key > root->data) {
            root->right = _delete(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = _min_value_node(root->right);
            root->data = temp->data;
            root->right = _delete(root->right, temp->data);
        }

        return root;
    }

    Node* _min_value_node(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }

    void _inorder(Node* root) {
        if (root != nullptr) {
            _inorder(root->left);
            cout << root->data << " ";
            _inorder(root->right);
        }
    }

    int _height(Node* root) {
        if (root == nullptr)
            return 0;
        int left_height = _height(root->left);
        int right_height = _height(root->right);
        return 1 + max(left_height, right_height);
    }

    int _count_nodes(Node* root) {
        if (root == nullptr)
            return 0;
        return 1 + _count_nodes(root->left) + _count_nodes(root->right);
    }

    void _print_given_level(Node* root, int level) {
        if (root == nullptr)
            return;
        if (level == 1) {
            cout << root->data << " ";
        } else if (level > 1) {
            _print_given_level(root->left, level - 1);
            _print_given_level(root->right, level - 1);
        }
    }
};

int main() {
    BinarySearchTree bst;

    // 노드 삽입
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Inorder traversal 출력
    cout << "Inorder traversal of the BST:" << endl;
    bst.inorder();

    // 특정 값 검색
    cout << "\nSearch for 40 in the BST:" << endl;
    Node* node = bst.search(40);
    if (node) {
        cout << "Node found: " << node->data << endl;
    } else {
        cout << "Node not found" << endl;
    }

    // 노드 삭제
    cout << "\nDelete 20 from the BST" << endl;
    bst.deleteNode(20);
    cout << "Inorder traversal after deleting 20:" << endl;
    bst.inorder();

    cout << "\nDelete 30 from the BST" << endl;
    bst.deleteNode(30);
    cout << "Inorder traversal after deleting 30:" << endl;
    bst.inorder();

    cout << "\nDelete 50 from the BST" << endl;
    bst.deleteNode(50);
    cout << "Inorder traversal after deleting 50:" << endl;
    bst.inorder();

    cout << "Minimum value: " << bst.find_min() << endl;
    cout << "Maximum value: " << bst.find_max() << endl;

    // 트리의 높이 출력
    cout << "Height of the tree: " << bst.height() << endl;

    // 노드 개수 출력
    cout << "Total nodes in the tree: " << bst.count_nodes() << endl;

    // 특정 레벨의 노드 출력
    int level = 1;
    cout << "Nodes at level " << level << ": ";
    bst.print_given_level(level);

    level = 2;
    cout << "Nodes at level " << level << ": ";
    bst.print_given_level(level);

    level = 3;
    cout << "Nodes at level " << level << ": ";
    bst.print_given_level(level);

    return 0;
}