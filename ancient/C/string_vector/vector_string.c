#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **items;
    int size;
    int capacity;
} CharVector;

void initCharVector(CharVector *v, int capacity) {
    v->capacity = capacity;
    v->size = 0;
    v->items = (char **)malloc(sizeof(char *) * capacity);
}

void resizeCharVector(CharVector *v, int capacity) {
    char **items_new = (char **)realloc(v->items, sizeof(char *) * capacity);
    if (items_new) {
        v->items = items_new;
        v->capacity = capacity;
    }
}

void addToCharVector(CharVector *v, char *item) {
    if (v->size == v->capacity) {
        resizeCharVector(v, v->capacity * 2);
    }
    v->items[v->size++] = strdup(item);
}

void removeFromCharVector(CharVector *v, int index) {
    if (index < 0 || index >= v->size) return;
    free(v->items[index]);
    for (int i = index; i < v->size - 1; i++) {
        v->items[i] = v->items[i + 1];
    }
    v->size--;
}

void freeCharVector(CharVector *v) {
    for (int i = 0; i < v->size; i++) {
        free(v->items[i]);
    }
    free(v->items);
    v->items = NULL;
    v->size = 0;
    v->capacity = 0;
}

// 새로운 함수: 마지막 요소를 제거하는 함수 (pop_back과 유사)
void popBackCharVector(CharVector *v) {
    if (v->size > 0) {
        removeFromCharVector(v, v->size - 1);
    }
}

// 새로운 함수: 벡터의 모든 요소를 출력하는 함수
void printCharVector(CharVector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%s\n", v->items[i]);
    }
}

int main() {
    CharVector v;
    initCharVector(&v, 2);  // 초기 용량을 2로 설정

    addToCharVector(&v, "Hello");
    addToCharVector(&v, "World");
    addToCharVector(&v, "C Language");

    printf("Before pop_back:\n");
    printCharVector(&v);

    popBackCharVector(&v);  // 마지막 요소 제거

    printf("\nAfter pop_back:\n");
    printCharVector(&v);

    freeCharVector(&v);  // 메모리 해제

    return 0;
}
