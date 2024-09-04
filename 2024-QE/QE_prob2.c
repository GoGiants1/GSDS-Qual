#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int *arr;
  int size;
} Stack;

typedef struct ListNode {
  struct ListNode *next;
  struct Stack *stack;
  int stack_capacity;
} ListNode;

int list_size(ListNode *head) {
  // 원소가 채워져있는 스택의 개수

  ListNode *curr = head;
  int cnt = 0;
  while (curr != NULL) {
    if (curr->stack != NULL && curr->stack->size > 0) {
      cnt++;
    }
    curr = curr->next;
  }
  return cnt;
}

void push_los(ListNode *head, int val) {
  ListNode *curr = head;
  ListNode *prev = NULL;

  while (curr != NULL && curr->stack != NULL &&
         curr->stack->size == curr->stack_capacity) {
    prev = curr;
    curr = curr->next;
  }
  // 새 리스트 노드 필요한 경우
  if (curr == NULL) {
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->next = NULL;
    new_node->stack_capacity = prev->stack_capacity;
    prev->next = new_node;
    curr = new_node;
  }
  // 스택 생성 필요한 경우,
  if (curr->stack == NULL) {
    curr->stack = (Stack *)malloc(sizeof(Stack));
    curr->stack->size = 0;
    curr->stack->arr = (int *)malloc(sizeof(int) * curr->stack_capacity);
    *(curr->stack->arr + curr->stack->size) = val;
    curr->stack->size++;
  }
  // 새 스택 필요 없는 경우
  else {
    *(curr->stack->arr + curr->stack->size) = val;
    curr->stack->size++;
  }
}

int pop_los(ListNode *head) {
  // 리스트가 비어있는 경우
  if (head == NULL || head->stack == NULL || head->stack->size == 0) {
    return -9999;
  }

  ListNode *curr = head;
  ListNode *prev = NULL;

  while (curr != NULL && curr->stack != NULL && curr->stack->size > 0) {
    prev = curr;
    curr = curr->next;
  }

  // 현재 보고 있는 노드에 지울 것이 없을 경우, 이전 노드로 돌아감
  if (curr == NULL || curr->stack == NULL || curr->stack->size == 0) {
    curr = prev;
  }

  return curr->stack->arr[--curr->stack->size];
}

// int main() {
//   ListNode *head = (ListNode *)malloc(sizeof(ListNode));
//   head->next = NULL;
//   head->stack_capacity = 3;

//   printf("%d\n", list_size(head));

//   push_los(head, 10);
//   push_los(head, 5);
//   push_los(head, 4);

//   printf("%d\n", list_size(head));

//   push_los(head, 18);

//   printf("%d\n", list_size(head));

//   printf("%d\n", pop_los(head));
//   printf("%d\n", pop_los(head));

//   printf("%d\n", list_size(head));

//   printf("%d\n", pop_los(head));
//   printf("%d\n", pop_los(head));
//   printf("%d\n", pop_los(head));

//   printf("%d\n", list_size(head));
// }