#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 이진 탐색 트리의 노드를 나타내는 구조체
typedef struct Node {
    char key[100];
    char value[100];
    struct Node* left;
    struct Node* right;
} Node;

// 새로운 노드를 생성하는 함수
Node* create_node(const char* key, const char* value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->left = new_node->right = NULL;
    return new_node;
}

// 이진 탐색 트리에 키-값 쌍을 삽입하는 함수
Node* insert(Node* root, const char* key, const char* value) {
    if (root == NULL) {
        return create_node(key, value);
    }

    if (strcmp(key, root->key) < 0) {
        root->left = insert(root->left, key, value);
    } else if (strcmp(key, root->key) > 0) {
        root->right = insert(root->right, key, value);
    }

    return root;
}

// 이진 탐색 트리에서 키를 기반으로 값을 검색하는 함수
char* search(Node* root, const char* key) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(key, root->key) == 0) {
        return root->value;
    }

    if (strcmp(key, root->key) < 0) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// 이진 탐색 트리에서 최소값을 가진 노드를 찾는 함수
Node* find_min(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// 이진 탐색 트리에서 키를 기반으로 노드를 삭제하는 함수
Node* delete_node(Node* root, const char* key) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(key, root->key) < 0) {
        root->left = delete_node(root->left, key);
    } else if (strcmp(key, root->key) > 0) {
        root->right = delete_node(root->right, key);
    } else {
        // 삭제할 노드를 찾음
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // 오른쪽 서브트리에서 최소값을 찾아 현재 노드와 교체
        Node* temp = find_min(root->right);
        strcpy(root->key, temp->key);
        strcpy(root->value, temp->value);
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}


// 중위 순회(Inorder Traversal)를 통해 이진 탐색 트리의 내용을 출력하는 함수
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("(%s, %s) ", root->key, root->value);
        inorder(root->right);
    }
}

// 메모리 해제를 위한 함수
void free_tree(Node* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    char* countries[] = {"Korea", "America", "China", "England", "Türkiye"};
    char* cities[] = {"Seoul", "Washington", "Beijing", "London", "Ankara"};
    int n = sizeof(countries) / sizeof(countries[0]);

    // 키-값 쌍 삽입
    for (int i = 0; i < n; ++i) {
        root = insert(root, countries[i], cities[i]);
    }

    // 이진 탐색 트리 출력 (중위 순회)
    printf("이진 탐색 트리의 상태\n");
    printf("====================\n");
    inorder(root);
    printf("\n\n");

    // 키를 기반으로 값 검색
    printf("이진 탐색 트리의 검색 결과\n");
    printf("=========================\n");
    printf("Capital of America = %s\n", search(root, "America"));
    printf("Capital of Korea = %s\n", search(root, "Korea"));
    printf("Capital of England = %s\n", search(root, "England"));
    printf("Capital of China = %s\n", search(root, "China"));
    printf("Capital of Japan = %s\n", search(root, "Japan")); // Japan은 트리에 없음
    printf("Capital of Türkiye = %s\n", search(root, "Türkiye"));

    // 메모리 해제
    free_tree(root);

    return 0;
}