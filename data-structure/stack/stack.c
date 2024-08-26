#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack{
    int top;
    int data[MAX_SIZE];
};

typedef struct stack stack;

bool isEmpty(stack* st){
    if (st->top == -1){return true;}
    return false;
}

void push(stack *st, int _data){
    if (st->top >= MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    st->data[++st->top] = _data;
    return;
}

int peek(stack *st){
    if(isEmpty(st)){return INT_MIN;}
    return st->data[st->top];
}

int pop(stack *st){
    if(isEmpty(st)){return INT_MIN;}
    return st->data[st->top--];
}

void printStack(stack *st){
    if (isEmpty(st)){return;}
    int cur = st->top;
    while(cur >= 0){
        printf("%d <- ", st->data[cur--]);
    }
    printf("Bottom\n");
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

int main(void){

    stack *st = (stack *)malloc(sizeof(stack));
    
    st->top = -1;

    const char* menu = "\n1: isEmpty  2: push  3: peek  4: pop  5: Exit\n";

    while (1) {
        printf("\n-------\nCurrent Stack: ");
        printStack(st);

        int command = get_data(menu);
        printf("\n");

        if (command == 1) {
            if (isEmpty(st)){
                printf("The stack is currently empty.\n");
            }else{
                printf("The stack is currently not empty.\n");
            }

        } else if (command == 2) {
            int data = get_data("Input number to push: ");
            if (data != INT_MIN) {
                push(st, data);
            }
        } else if (command == 3) {
            int data = peek(st);
            if (data != INT_MIN){
                printf("Peeked data: %d\n", data);
            }else{
                printf("The stack is currently empty.\n");
            }
        } else if (command == 4) {
            int data = pop(st);
            if (data != INT_MIN) {
                printf("Popped data: %d\n", data);
            } else {
                printf("The stack is currently empty\n");
            }
        } else if (command == 5) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}