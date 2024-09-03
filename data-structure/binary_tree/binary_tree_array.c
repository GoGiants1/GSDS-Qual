#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// 배열 기반 이진 트리 순회 - 부모로부터 자식 노드 찾기
void traversal_from_root(char tree[], int size) {
    int i = 0;
    while (i < size) {
        if (tree[i] != '\0') { // '\0'은 빈 값을 나타냅니다.
            printf("Parent: %c", tree[i]);

            int left = 2 * i + 1;
            int right = left + 1;

            if (left < size && tree[left] != '\0') {
                printf(", Left: %c", tree[left]);
            }
            if (right < size && tree[right] != '\0') {
                printf(", Right: %c", tree[right]);
            }
            printf("\n");
        }
        i++;
    }
}

// 배열 기반 이진 트리 순회 - 자식으로부터 부모 노드 찾기
void traversal_from_leaf(char tree[], int size) {
    int i = size - 1;
    while (i > 0) {
        if (tree[i] != '\0') {
            printf("Parent of %c -> %c\n", tree[i], tree[(i - 1) / 2]);
        }
        i--;
    }
}

int main() {
    // 트리 배열 초기화
    char tree[MAX_SIZE];
    memset(tree, '\0', sizeof(tree)); // 모든 요소를 '\0'으로 초기화

    // 트리 데이터를 삽입
    tree[0] = 'A';
    tree[1] = 'B';
    tree[2] = 'C';
    tree[3] = 'D';
    tree[4] = 'E';
    tree[5] = 'F';
    tree[7] = 'G';

    // 부모에서 자식 노드 찾기
    printf("Finding children given parents.\n");
    traversal_from_root(tree, MAX_SIZE);
    printf("\n");

    // 자식에서 부모 노드 찾기
    printf("Finding parent given child.\n");
    traversal_from_leaf(tree, MAX_SIZE);

    return 0;
}