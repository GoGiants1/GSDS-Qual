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

// MaxHeap 클래스
class MaxHeap {
    Node *root;
    int heapsize;

public:
    // Constructor
    MaxHeap();

    // Returns the node pointer that includes the maximum value (root node)
    Node* getMax();

    // Inserts a new key 'k'
    void enqueue(int k);

    // Delete the maximum value (root node)
    void dequeue();

    void printHeap();

    void swap(Node *a, Node *b);
};


// MaxHeap 함수 구현
MaxHeap::MaxHeap() {
    root = nullptr;
    heapsize = 0;
}

Node* MaxHeap::getMax() {
    return root;
}

void MaxHeap::printHeap() {
    if (!root) return;

    Node *currNode = root;
    queue<Node*> q;

    q.push(root);
    std::cout << "MaxHeap: ";
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

void MaxHeap::swap(Node *a, Node *b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

void MaxHeap::enqueue(int k) {
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
        while (newNode->parent && newNode->val > newNode->parent->val) {
            swap(newNode, newNode->parent);
            newNode = newNode->parent;
        }
    }
    heapsize++;
}

void MaxHeap::dequeue() {
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
            Node *largest = node;
            if (node->left && node->left->val > largest->val) {
                largest = node->left;
            }
            if (node->right && node->right->val > largest->val) {
                largest = node->right;
            }
            if (largest != node) {
                swap(node, largest);
                node = largest;
            } else {
                break;
            }
        }
    }
    heapsize--;
}



int main() {
    MaxHeap maxHeap;

    // MaxHeap 테스트
    maxHeap.enqueue(3);
    maxHeap.enqueue(2);
    maxHeap.enqueue(1);
    maxHeap.enqueue(15);
    maxHeap.enqueue(5);
    maxHeap.enqueue(4);
    maxHeap.enqueue(45);

    std::cout << "MaxHeap: ";
    maxHeap.printHeap();
    std::cout << "Max value: " << maxHeap.getMax()->val << std::endl;
    maxHeap.dequeue();
    std::cout << "MaxHeap after dequeue: ";
    maxHeap.printHeap();

    return 0;
}
