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
} MaxHeap;

// Node 생성 함수
Node* createNode(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// MaxHeap 초기화
MaxHeap* createMaxHeap() {
    MaxHeap *maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
    maxHeap->root = NULL;
    maxHeap->heapsize = 0;
    return maxHeap;
}

void swap(Node *a, Node *b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

void printHeap(Node *root) {
    if (!root) return;

    printf("MaxHeap: ");
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

// MaxHeap에 새로운 키 추가
void enqueue(MaxHeap *maxHeap, int k) {
    Node *newNode = createNode(k);
    if (maxHeap->root == NULL) {
        maxHeap->root = newNode;
    } else {
        int path = maxHeap->heapsize + 1;
        Node *current = maxHeap->root;
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
        while (newNode->parent && newNode->val > newNode->parent->val) {
            swap(newNode, newNode->parent);
            newNode = newNode->parent;
        }
    }
    maxHeap->heapsize++;
}

// MaxHeap에서 최댓값 제거
void dequeue(MaxHeap *maxHeap) {
    if (maxHeap->root == NULL) return;
    if (maxHeap->root->left == NULL && maxHeap->root->right == NULL) {
        free(maxHeap->root);
        maxHeap->root = NULL;
    } else {
        int path = maxHeap->heapsize;
        Node *current = maxHeap->root;
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

        maxHeap->root->val = lastNode->val;
        free(lastNode);

        // Heapify down
        Node *node = maxHeap->root;
        while (1) {
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
    maxHeap->heapsize--;
}

// MaxHeap의 최댓값 반환
Node* getMax(MaxHeap *maxHeap) {
    return maxHeap->root;
}

int main() {
    MaxHeap *maxHeap = createMaxHeap();

    // MaxHeap 테스트
    enqueue(maxHeap, 3);
    enqueue(maxHeap, 2);
    enqueue(maxHeap, 1);
    enqueue(maxHeap, 15);
    enqueue(maxHeap, 5);
    enqueue(maxHeap, 4);
    enqueue(maxHeap, 45);

    printHeap(maxHeap->root);
    printf("Max value: %d\n", getMax(maxHeap)->val);
    dequeue(maxHeap);
    printf("MaxHeap after dequeue: ");
    printHeap(maxHeap->root);

    return 0;
}
