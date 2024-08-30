#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next; // 충돌 시 연결 리스트로 처리
} HashNode;

typedef struct HashTable {
    int size;
    HashNode **table;
} HashTable;

// hash 함수 정의 (사용자 정의)
unsigned int hashFunction(const char *key, int tableSize) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++; // polynomial rolling hash
    }
    return hash % tableSize;
}

HashTable* createHashTable(int size) {
    HashTable *hashTable = (HashTable*) malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (HashNode**) malloc(sizeof(HashNode*) * size);
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(HashTable *hashTable, const char *key, int value) {
    unsigned int index = hashFunction(key, hashTable->size);
    HashNode *newNode = (HashNode*) malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

int search(HashTable *hashTable, const char *key) {
    unsigned int index = hashFunction(key, hashTable->size);
    HashNode *node = hashTable->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // 키가 존재하지 않는 경우
}

void delete(HashTable *hashTable, const char *key) {
    unsigned int index = hashFunction(key, hashTable->size);
    HashNode *node = hashTable->table[index];
    HashNode *prev = NULL;

    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                // 첫 번째 노드를 삭제하는 경우
                hashTable->table[index] = node->next;
            } else {
                // 중간 또는 마지막 노드를 삭제하는 경우
                prev->next = node->next;
            }
            free(node->key);
            free(node);
            printf("Key '%s' deleted.\n", key);
            return;
        }
        prev = node;
        node = node->next;
    }
    printf("Key '%s' not found.\n", key);
}

void freeHashTable(HashTable *hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        HashNode *node = hashTable->table[i];
        while (node != NULL) {
            HashNode *temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

int main() {
    HashTable *hashTable = createHashTable(10);

    insert(hashTable, "apple", 100);
    insert(hashTable, "banana", 200);
    insert(hashTable, "cherry", 300);

    printf("apple: %d\n", search(hashTable, "apple"));
    printf("banana: %d\n", search(hashTable, "banana"));
    printf("cherry: %d\n", search(hashTable, "cherry"));

    delete(hashTable, "banana");
    printf("banana: %d\n", search(hashTable, "banana"));

    freeHashTable(hashTable);

    return 0;
}