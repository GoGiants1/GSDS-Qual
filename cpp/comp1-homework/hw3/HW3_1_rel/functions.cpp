#include "functions.hpp"

#include <climits>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

MaxHeap::MaxHeap() { root = nullptr; }

Node *MaxHeap::getMax() { return root; }

void MaxHeap::printHeap() {
  Node *currNode = root;
  queue<Node *> q;

  q.push(root);
  std::cout << "Print Heap: ";
  while (!q.empty() && q.front()) {
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

Node *findLastNode(Node *root, int heapsize) {
  if (!root) return nullptr;

  // 찾으려는 노드 레벨
  int height = log2(heapsize);
  int path_bit_mask = (1 << height) - 1;
  // 찾으려는 노드의 경로를 나타내는 비트 (0: left, 1: right)
  int path = heapsize & path_bit_mask;
  Node *curr = root;

  int i = height - 1;
  while (curr->left != nullptr && curr->right != nullptr) {
    if (path & (1 << i)) {
      curr = curr->right;
    } else {
      curr = curr->left;
    }
    i--;
  }
  return curr;
}

// Inserts a new key 'k'
void MaxHeap::enqueue(int k) {
  // 1. Make New node

  Node *new_node = new Node();
  new_node->val = k;
  Node *curr;
  if (root == nullptr) {
    root = new_node;
    heapsize = 1;
  } else if (heapsize == 1) {
    root->left = new_node;
    new_node->parent = root;
    heapsize++;
  } else if (heapsize == 2) {
    root->right = new_node;
    new_node->parent = root;
    heapsize++;
  } else {
    // 2. Append Last
    // case 1: last's parent has null right
    heapsize++;
    if (last_node->parent->left != nullptr &&
        last_node->parent->right == nullptr) {
      last_node->parent->right = new_node;
      new_node->parent = last_node->parent;
    }
    // 리프 노드가 있는 레벨도 다 찼을 경우, 리프 노트의 맨 왼쪽에 삽입.
    else {
      curr = findLastNode(root, heapsize);
      curr->left = new_node;
      new_node->parent = curr;
    }
  }
  last_node = new_node;
  // 3. Max heapify (up heap)
  curr = last_node;
  while (curr != nullptr && curr->parent != nullptr &&
         curr->val > curr->parent->val) {
    swap(curr, curr->parent);
    curr = curr->parent;
  }
}

// Removes the root node and heapify
void MaxHeap::dequeue() {
  if (root == nullptr) {
    return;
  }
  swap(root, last_node);
  heapsize--;
  Node *curr = nullptr;
  if (last_node->parent == nullptr) {
    delete root;
    root = nullptr;
    last_node = nullptr;
    return;
  }

  if (last_node->parent->right == last_node) {
    last_node->parent->right = nullptr;
    curr = last_node->parent->left;
    delete last_node;
    last_node = curr;
  } else {
    if (last_node->parent->left == last_node) {
      last_node->parent->left = nullptr;
      delete last_node;
    }

    curr = findLastNode(root, heapsize);
    last_node = curr;
  }

  // 3. Max heapify (down heap)
  curr = root;
  while (!(curr->left == nullptr && curr->right == nullptr)) {
    bool is_left = false;
    bool is_swap = false;
    if (curr->left != nullptr && curr->val < curr->left->val) {
      is_swap = true;
      is_left = true;
    }
    if (curr->right != nullptr && curr->val < curr->right->val) {
      is_swap = true;
      if (is_left == true) {
        if (curr->left->val < curr->right->val) {
          is_left = false;
        }
      } else {
        is_left = false;
      }
    }
    if (is_swap == true) {
      if (is_left == true) {
        swap(curr, curr->left);
        curr = curr->left;
      } else {
        swap(curr, curr->right);
        curr = curr->right;
      }
    } else {
      break;
    }
  }
}
