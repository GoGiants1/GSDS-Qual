
/*
  you must write C functions that implement a list of stacks and its interfaces.
  A list of stacks should be composed of multiple stacks that store positive integer values and create a new stack once the previous one exceeds capacity.
  A new stack is added to the end of the list.
  The list of stacks provides two operations, push and pop, and they should behave identically to a single stack. In other words, pop must return the same values as if there were just a single stack.
  Use the following list node data structure in your code.
  You can freely implement the struct Stack data structure as long as it behaves as a stack.
  stack capacity determines the maximum size of the stack. we assume the same capacity for all stacks in the list.

  you can only include <stdio.h> and <stdlib.h>

  given:
    typedef struct ListNode {
      struct ListNode *next;
      struct Stack *stack;
      int stack_capacity;
    } ListNode;

  implement:

    typedef struct Stack {
      //
    } Stack;

    int list_size(ListNode *head) {}
        // returns the number of non-empty stacks in the list

    void push_los(ListNode *head, int val) {}
        // takes a head node of the list and pushes the value into the data structure

    int pop_los(ListNode *head) {}
        // takes a head node of the list and pops a value as if it were a single stack.
        // it the list is empty and no value can be popped, the function must return -9999 to indicate an error status



*/

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