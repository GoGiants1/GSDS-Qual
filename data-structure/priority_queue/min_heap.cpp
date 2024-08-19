#include <iostream>
#include <climits>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
};

// MinHeap 클래스
class MinHeap {
    Node *root;
    int heapsize;

public:
    // Constructor
    MinHeap();

    // Returns the node pointer that includes the minimum value (root node)
    Node* getMin();

    // Inserts a new key 'k'
    void enqueue(int k);

    // Delete the minimum value (root node)
    void dequeue();

    void printHeap();

    void swap(Node *a, Node *b);
};

// MinHeap 함수 구현
MinHeap::MinHeap() {
    root = nullptr;
    heapsize = 0;
}

Node* MinHeap::getMin() {
    return root;
}

void MinHeap::printHeap() {
    if (!root) return;

    Node *currNode = root;
    queue<Node*> q;

    q.push(root);
    std::cout << "MinHeap: ";
    while (!q.empty()) {
        std::cout << q.front()->val << " ";
        if (q.front()->left) {
            q.push(q.front()->left);
        }
        if (q.front()->right) {
            q.push(q.front()->right);
        }
        q.pop();
    }
    std::cout << std::endl;
}

void MinHeap::swap(Node *a, Node *b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

void MinHeap::enqueue(int k) {
    Node *newNode = new Node();
    newNode->val = k;
    if (root == nullptr) {
        root = newNode;
    } else {
        int path = heapsize + 1;
        Node *current = root;
        for (int shift = static_cast<int>(log2(path)) - 1; shift > 0; --shift) {
            if (path & (1 << shift)) {
                current = current->right;
            } else {
                current = current->left;
            }
        }
        if (path & 1) {
            current->right = newNode;
        } else {
            current->left = newNode;
        }
        newNode->parent = current;

        // Heapify up
        while (newNode->parent && newNode->val < newNode->parent->val) {
            swap(newNode, newNode->parent);
            newNode = newNode->parent;
        }
    }
    heapsize++;
}

void MinHeap::dequeue() {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        delete root;
        root = nullptr;
    } else {
        int path = heapsize;
        Node *current = root;
        for (int shift = static_cast<int>(log2(path)) - 1; shift > 0; --shift) {
            if (path & (1 << shift)) {
                current = current->right;
            } else {
                current = current->left;
            }
        }
        Node *lastNode;
        if (path & 1) {
            lastNode = current->right;
            current->right = nullptr;
        } else {
            lastNode = current->left;
            current->left = nullptr;
        }

        root->val = lastNode->val;
        delete lastNode;

        // Heapify down
        Node *node = root;
        while (true) {
            Node *smallest = node;
            if (node->left && node->left->val < smallest->val) {
                smallest = node->left;
            }
            if (node->right && node->right->val < smallest->val) {
                smallest = node->right;
            }
            if (smallest != node) {
                swap(node, smallest);
                node = smallest;
            } else {
                break;
            }
        }
    }
    heapsize--;
}


int main() {
    MinHeap minHeap;
    
    // MinHeap 테스트
    minHeap.enqueue(3);
    minHeap.enqueue(2);
    minHeap.enqueue(1);
    minHeap.enqueue(15);
    minHeap.enqueue(5);
    minHeap.enqueue(4);
    minHeap.enqueue(45);

    std::cout << "MinHeap: ";
    minHeap.printHeap();
    std::cout << "Min value: " << minHeap.getMin()->val << std::endl;
    minHeap.dequeue();
    std::cout << "MinHeap after dequeue: ";
    minHeap.printHeap();

    return 0;
}
