#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char data) {
        Node* node = new Node(data);
        if (top == nullptr) {
            top = node;
        } else {
            node->next = top;
            top = node;
        }
        cout << "Push data = " << peek() << endl;
    }

    char pop() {
        if (top == nullptr) {
            return '\0';  // null character for empty stack
        }
        Node* node = top;
        top = top->next;
        char data = node->data;
        delete node;
        return data;
    }

    char peek() {
        if (top == nullptr) {
            return '\0';  // null character for empty stack
        }
        return top->data;
    }

    bool is_empty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;

    for (int i = 0; i < 3; i++) {
        s.push('A' + i);
    }
    cout << endl;

    while (!s.is_empty()) {
        cout << "Pop data = " << s.pop() << endl;
    }
    cout << endl;

    cout << "Peek data = " << s.peek() << endl;

    return 0;
}