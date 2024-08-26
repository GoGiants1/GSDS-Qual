#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct LinkedList{
    int length;
    struct Node* head;
};

typedef struct LinkedList LinkedList;
typedef struct Node Node;

Node* createNode(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(LinkedList* p, int data){
    Node* new_node = createNode(data);
    p->length++;
    if (p->head == NULL){
        p->head = new_node;
        return;
    }
    Node* cur = p->head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = new_node;
    return;
}

void appendLeft(LinkedList* p, int data){
    Node* new_node = createNode(data);
    p->length++;
    if (p->head == NULL){
        p->head = new_node;
        
        return;
    }
    new_node->next = p->head;
    p->head = new_node;
    return;
}

void insert(LinkedList* p, int index, int data){
    Node* new_node = createNode(data);
    if(p->head == NULL || index == 0){
        new_node->next = p->head;
        p->head = new_node;
        p->length++;
        return;
    }
    Node* cur = p->head;
    index = index >= p->length ? p->length : index;
    for (int i = 0; i<index-1; i++){ // 삽입하려는 위치 전까지 이동해야 함
        cur = cur->next;
    }
    new_node->next = cur->next;
    cur->next = new_node;
    p->length++;
    return;
}

int pop(LinkedList* p){
    if (p->head == NULL){
        return INT_MIN;
    }
    Node* prev = NULL;
    Node* node = p->head;

    while (node->next != NULL) {
        prev = node;
        node = node->next;
    }

    // 리스트에 하나의 노드만 있는 경우
    if (prev == NULL) {
        p->head = NULL;
    } else {
        prev->next = NULL;
    }

    int data = node->data;
    free(node);
    p->length--;

    return data;
}

int popLeft(LinkedList* p){
    if (p->head == NULL){
        return INT_MIN;
    }
    int data = p->head->data;
    p->head = p->head->next;
    p->length--;

    return data;
}

int search(LinkedList* p, int query){
    if (p->head == NULL){
        return 0;  // not found; false
    }
    Node* cur = p->head;
    while (cur != NULL) {
        if (cur->data == query) {
            return 1; // found; true
        }
        cur = cur->next; 
    }
    return 0;  // not found; false
}

void removeNode(LinkedList* p, int data){
    if(p->head == NULL){
        return;
    }
    Node* cur = p->head;
    if(cur->data == data){
        p->head = cur->next;
        free(cur);
        p->length--;
        return;
    }
    while(cur->next != NULL){
        if(cur->next->data == data){
            Node* temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
            p->length--;
            return;
        }
        cur = cur->next;
    }
    return;
}

void reverse(LinkedList* p){
    if (p->length < 2){
        return;
    }
    Node* prev = NULL;
    Node* ahead = p->head->next;
    while(ahead){
        p->head->next = prev;
        prev = p->head;
        p->head = ahead;
        ahead = ahead->next;
    }
    p->head->next = prev;
}

void printList(LinkedList* p){
    if(p->head == NULL){
        printf("Empty List\n");
        return;
    }
    Node* cur = p->head;
    while(cur != NULL){
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("None\n");
    return;
}

int get_data(const char* msg) {
    int data;
    printf("%s", msg);
    if (scanf("%d", &data) != 1) {
        while (getchar() != '\n');
        return INT_MIN;
    }
    return data;
}

int main(){

    LinkedList my_list = {0, NULL};

    const char* menu = "\n1: appendleft  2: append  3: popleft  4: pop  5: search  6: insert  7: remove  8: reverse\n9: Exit\n";

    while (1) {
        printf("\n-------\nCurrent List: ");
        printList(&my_list);

        int command = get_data(menu);
        printf("\n");

        if (command == 1) {
            int data = get_data("Input number to append at start: ");
            if (data != INT_MIN) {
                appendLeft(&my_list, data);
            }
        } else if (command == 2) {
            int data = get_data("Input number to append: ");
            if (data != INT_MIN) {
                append(&my_list, data);
            }
        } else if (command == 3) {
            int data = popLeft(&my_list);
            if (data != INT_MIN) {
                printf("Popped from start: %d\n", data);
            } else {
                printf("Linked list is empty!\n");
            }
        } else if (command == 4) {
            int data = pop(&my_list);
            if (data != INT_MIN) {
                printf("Popped from end: %d\n", data);
            } else {
                printf("Linked list is empty!\n");
            }
        } else if (command == 5) {
            int data = get_data("Input number to search: ");
            if (data != INT_MIN) {
                if (search(&my_list, data)) {
                    printf("%d exists in the list.\n", data);
                } else {
                    printf("%d does not exist in the list.\n", data);
                }
            }
        } else if (command == 6) {
            int data = get_data("Input number to insert: ");
            if (data != INT_MIN) {
                int index = get_data("Input index to insert at: ");
                if (index != INT_MIN) {
                    insert(&my_list, index, data);
                }
            }
        } else if (command == 7) {
            int data = get_data("Input number to remove: ");
            if (data != INT_MIN) {
                removeNode(&my_list, data);
            }
        } else if (command == 8) {
            reverse(&my_list);
            printf("Reversed the linked list.\n");
        } else if (command == 9) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}