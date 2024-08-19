#include <stdio.h>
#include <stdlib.h>

// 양방향 연결 리스트 노드 구조체 정의
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// 리스트의 앞에 노드를 추가하는 함수
void push(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    newNode->prev = NULL;

    if ((*headRef) != NULL)
        (*headRef)->prev = newNode;

    (*headRef) = newNode;
}

// 양방향 연결 리스트를 출력하는 함수
void printList(struct Node* node) {
    struct Node* last;
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}

// 중간 노드를 찾는 함수 (fast/slow 포인터 사용)
struct Node* getMiddle(struct Node* head) {
    if (head == NULL) 
        return head;

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

// 두 개의 정렬된 리스트를 병합하는 함수
struct Node* sortedMerge(struct Node* first, struct Node* second) {
    // 기본 케이스
    if (!first)
        return second;
    if (!second)
        return first;

    // 정렬된 리스트를 병합
    if (first->data <= second->data) {
        first->next = sortedMerge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = sortedMerge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

// 양방향 연결 리스트에 대한 Merge Sort 구현
struct Node* mergeSort(struct Node* head) {
    if (!head || !head->next)
        return head;

    struct Node* middle = getMiddle(head);
    struct Node* nextOfMiddle = middle->next;

    middle->next = NULL; // 리스트를 두 개로 분할

    struct Node* left = mergeSort(head);
    struct Node* right = mergeSort(nextOfMiddle);

    return sortedMerge(left, right);
}

int main() {
    struct Node* a = NULL;

    // 예제 데이터 삽입
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    printf("Unsorted Linked List is: \n");
    printList(a);

    // 병합 정렬 수행
    a = mergeSort(a);

    printf("\nSorted Linked List is: \n");
    printList(a);

    return 0;
}
