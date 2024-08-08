#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

struct List {
    Node *front;
    Node *rear;
    int length;
};

List* initList(void){
    List* list = (List *)malloc(sizeof(List));
    list->front = NULL;
    list->rear = NULL;
    list->length = 0;
    return list;
}

int isEmpty(List *list) {
    return list->length == 0;
}

void pushFront(List *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("[WARN] Failed to Allocate Memory.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->front;

    if (isEmpty(list)) {
        list->front = newNode;
        list->rear = newNode;
    } else {
        list->front->prev = newNode;
        list->front = newNode;
    }
    list->length++;
}

void pushRear(List *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("[WARN] Failed to Allocate Memory.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->rear;

    if (isEmpty(list)) {
        list->front = newNode;
        list->rear = newNode;
    } else {
        list->rear->next = newNode;
        list->rear = newNode;
    }
    list->length++;
}

int popFront(List *list) {
    if (isEmpty(list)) {
        printf("[WARN] Empty List.\n");
        exit(1);
    }

    int data = list->front->data;
    Node *temp = list->front;

    if (list->length == 1) {
        list->front = NULL;
        list->rear = NULL;
    } else {
        list->front = list->front->next;
        list->front->prev = NULL;
    }

    free(temp);
    list->length--;
    return data;
}

int popRear(List *list) {
    if (isEmpty(list)) {
        printf("[WARN] Empty List.\n");
        exit(1);
    }

    int data = list->rear->data;
    Node *temp = list->rear;

    if (list->length == 1) {
        list->front = NULL;
        list->rear = NULL;
    } else {
        list->rear = list->rear->prev;
        list->rear->next = NULL;
    }

    free(temp);
    list->length--;
    return data;
}

int getByIndex(List *list, int index) {
    if (isEmpty(list) || index < 0 || index >= list->length) {
        printf("[WARN] Invalid Index.\n");
        exit(1);
    }

    Node *current = list->front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void setByIndex(List *list, int index, int data) {
    if (isEmpty(list) || index < 0 || index >= list->length) {
        printf("[WARN] Invalid Index.\n");
        exit(1);
    }

    Node *current = list->front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = data;
}

void deleteByIndex(List *list, int index) {
    if (isEmpty(list) || index < 0 || index >= list->length) {
        printf("[WARN] Invalid Index.\n");
        exit(1);
    }

    Node *current = list->front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    if (current == list->front) {
        popFront(list);
    } else if (current == list->rear) {
        popRear(list);
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        list->length--;
    }
}

int isIn(List *list, int data) {
    Node *current = list->front;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void reverseList(List *list) {
    if (isEmpty(list)) {
        return;
    }

    Node *current = list->front;
    Node *temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        list->rear = list->front;
        list->front = temp->prev;
    }
}

void printList(List *list) {
    if (isEmpty(list)) {
        printf("[INFO] Empty List.\n");
    }
    Node *current = list->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List *list = initList();

    pushFront(list, 1);
    pushFront(list, 2);
    pushRear(list, 3);
    pushRear(list, 4);

    printf("List: ");
    printList(list);

    printf("Popped from front: %d\n", popFront(list));
    printf("Popped from rear: %d\n", popRear(list));

    printf("List: ");
    printList(list);

    printf("Element at index 1: %d\n", getByIndex(list, 1));
    setByIndex(list, 1, 10);
    printf("List after setting element at index 1 to 10: ");
    printList(list);

    printf("Is 10 inlist? %s\n", isIn(list, 10) ? "Yes" : "No");

    deleteByIndex(list, 1);
    printf("List after deleting element at index 1: ");
    printList(list);

    return 0;
}
