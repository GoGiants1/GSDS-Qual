#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

typedef struct {
    Node *root;
    int heapsize;
} MinHeap;

// Node 생성 함수
Node* createNode(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// MinHeap 초기화
MinHeap* createMinHeap() {
    MinHeap *minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->root = NULL;
    minHeap->heapsize = 0;
    return minHeap;
}

void swap(Node *a, Node *b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

void printHeap(Node *root) {
    if (!root) return;

    printf("MinHeap: ");
    Node *currNode = root;
    Node *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear) {
        currNode = queue[front++];
        printf("%d ", currNode->val);
        if (currNode->left) {
            queue[rear++] = currNode->left;
        }
        if (currNode->right) {
            queue[rear++] = currNode->right;
        }
    }
    printf("\n");
}

// MinHeap에 새로운 키 추가
void enqueue(MinHeap *minHeap, int k) {
    Node *newNode = createNode(k);
    if (minHeap->root == NULL) {
        minHeap->root = newNode;
    } else {
        int path = minHeap->heapsize + 1;
        Node *current = minHeap->root;
        for (int shift = (int)log2(path) - 1; shift > 0; --shift) {
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
    minHeap->heapsize++;
}

// MinHeap에서 최솟값 제거
void dequeue(MinHeap *minHeap) {
    if (minHeap->root == NULL) return;
    if (minHeap->root->left == NULL && minHeap->root->right == NULL) {
        free(minHeap->root);
        minHeap->root = NULL;
    } else {
        int path = minHeap->heapsize;
        Node *current = minHeap->root;
        for (int shift = (int)log2(path) - 1; shift > 0; --shift) {
            if (path & (1 << shift)) {
                current = current->right;
            } else {
                current = current->left;
            }
        }
        Node *lastNode;
        if (path & 1) {
            lastNode = current->right;
            current->right = NULL;
        } else {
            lastNode = current->left;
            current->left = NULL;
        }

        minHeap->root->val = lastNode->val;
        free(lastNode);

        // Heapify down
        Node *node = minHeap->root;
        while (1) {
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
    minHeap->heapsize--;
}

// MinHeap의 최솟값 반환
Node* getMin(MinHeap *minHeap) {
    return minHeap->root;
}

int main() {
    MinHeap *minHeap = createMinHeap();

    // MinHeap 테스트
    enqueue(minHeap, 3);
    enqueue(minHeap, 2);
    enqueue(minHeap, 1);
    enqueue(minHeap, 15);
    enqueue(minHeap, 5);
    enqueue(minHeap, 4);
    enqueue(minHeap, 45);

    printHeap(minHeap->root);
    printf("Min value: %d\n", getMin(minHeap)->val);
    dequeue(minHeap);
    printf("MinHeap after dequeue: ");
    printHeap(minHeap->root);

    return 0;
}
