#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 이진 트리의 노드를 정의하는 구조체
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// 트리 구조체 정의
typedef struct Tree {
    Node* root;
    bool top_down; // top down: 재귀적, bottom up: 반복적
} Tree;

// 노드 생성 함수
Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// 트리 생성 함수
Tree* create_tree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->top_down = true; // 기본값은 top_down으로 설정
    return tree;
}

// 전위 순회 (Preorder Traversal)
void preorder_top_down(Node* node) {
    if (node == NULL) return;
    printf("%c ", node->data);
    preorder_top_down(node->left);
    preorder_top_down(node->right);
}

void preorder_bottom_up(Node* node) {
    if (node == NULL) return;

    Node* stack[100];
    int top = -1;
    stack[++top] = node;

    while (top >= 0) {
        node = stack[top--];
        if (node) {
            printf("%c ", node->data);
            if (node->right) stack[++top] = node->right;
            if (node->left) stack[++top] = node->left;
        }
    }
}

// 중위 순회 (Inorder Traversal)
void inorder_top_down(Node* node) {
    if (node == NULL) return;
    inorder_top_down(node->left);
    printf("%c ", node->data);
    inorder_top_down(node->right);
}

void inorder_bottom_up(Node* node) {
    if (node == NULL) return;

    Node* stack[100];
    int top = -1;
    Node* current = node;

    while (top >= 0 || current != NULL) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%c ", current->data);
        current = current->right;
    }
}

// 후위 순회 (Postorder Traversal)
void postorder_top_down(Node* node) {
    if (node == NULL) return;
    postorder_top_down(node->left);
    postorder_top_down(node->right);
    printf("%c ", node->data);
}

void postorder_bottom_up(Node* node) {
    if (node == NULL) return;

    Node* stack[100];
    int top = -1;
    Node* current = node;
    Node* last_visited = NULL;

    while (top >= 0 || current != NULL) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top];
        if (current->right == NULL || current->right == last_visited) {
            printf("%c ", current->data);
            last_visited = stack[top--];
            current = NULL;
        } else {
            current = current->right;
        }
    }
}

// 레벨 순서 순회 (Level Order Traversal)
void levelorder_top_down(Node* node, int level, char* res[], int* level_counts) {
    if (node == NULL) return;

    if (level == *level_counts) {
        res[level] = (char*)malloc(100 * sizeof(char));
        (*level_counts)++;
    }

    res[level][strlen(res[level])] = node->data;

    levelorder_top_down(node->left, level + 1, res, level_counts);
    levelorder_top_down(node->right, level + 1, res, level_counts);
}

void levelorder_bottom_up(Node* node) {
    if (node == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = node;

    while (front < rear) {
        Node* current = queue[front++];
        printf("%c ", current->data);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

// 트리 삽입 함수 (BFS로 빈 자리에 삽입)
void insert(Tree* tree, char data) {
    Node* new_node = create_node(data);
    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = tree->root;

    while (front < rear) {
        Node* node = queue[front++];

        if (node->left == NULL) {
            node->left = new_node;
            return;
        } else {
            queue[rear++] = node->left;
        }

        if (node->right == NULL) {
            node->right = new_node;
            return;
        } else {
            queue[rear++] = node->right;
        }
    }
}

// 트리 탐색 함수 (BFS로 탐색)
Node* search(Node* root, char key) {
    if (root == NULL) return NULL;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* node = queue[front++];
        if (node->data == key) {
            return node;
        }
        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
    return NULL;
}

// 트리 삭제 함수
void delete_node(Tree* tree, char key) {
    if (tree->root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = tree->root;

    Node* key_node = NULL;
    Node* last_node = NULL;

    while (front < rear) {
        last_node = queue[front++];
        if (last_node->data == key) {
            key_node = last_node;
        }
        if (last_node->left) queue[rear++] = last_node->left;
        if (last_node->right) queue[rear++] = last_node->right;
    }

    if (key_node) {
        key_node->data = last_node->data;
        free(last_node);
    }
}

// 주어진 노드를 삭제하는 헬퍼 함수
void delete_deepest(Node* root, Node* d_node) {
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* node = queue[front++];
        if (node->right) {
            if (node->right == d_node) {
                node->right = NULL;
                free(d_node);
                return;
            } else {
                queue[rear++] = node->right;
            }
        }
        if (node->left) {
            if (node->left == d_node) {
                node->left = NULL;
                free(d_node);
                return;
            } else {
                queue[rear++] = node->left;
            }
        }
    }
}

int main() {
    Tree* tree = create_tree();
    tree->root = create_node('A');
    tree->root->left = create_node('B');
    tree->root->right = create_node('C');
    tree->root->left->left = create_node('D');
    tree->root->left->right = create_node('E');
    tree->root->right->left = create_node('F');
    tree->root->left->left->left = create_node('G');
    tree->root->left->left->left->right = create_node('H');

    // 트리 출력
    printf("=====Traversal=====\n");
    printf("Preorder: ");
    tree->top_down ? preorder_top_down(tree->root) : preorder_bottom_up(tree->root);
    printf("\nInorder: ");
    tree->top_down ? inorder_top_down(tree->root) : inorder_bottom_up(tree->root);
    printf("\nPostorder: ");
    tree->top_down ? postorder_top_down(tree->root) : postorder_bottom_up(tree->root);
    printf("\nLevelorder: ");
    if (tree->top_down) {
        char* res[100];
        int level_counts = 0;
        levelorder_top_down(tree->root, 0, res, &level_counts);
        for (int i = 0; i < level_counts; i++) {
            printf("%s ", res[i]);
            free(res[i]);
        }
    } else {
        levelorder_bottom_up(tree->root);
    }
    printf("\n");

    printf("=====Manipulation=====\n");
    insert(tree, 'I');
    printf("Insert I: ");
    levelorder_bottom_up(tree->root);
    printf("\nSearch B: %c\n", search(tree->root, 'B')->data);
    delete_node(tree, 'B');
    printf("Delete B: ");
    levelorder_bottom_up(tree->root);
    printf("\nSearch B: %p\n", search(tree->root, 'B'));

    // 메모리 해제
    free(tree->root);
    free(tree);

    return 0;
}