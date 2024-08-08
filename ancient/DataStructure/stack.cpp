#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Print the top element
    cout << "Top element: " << myStack.top() << endl;

    // Pop elements from the stack
    myStack.pop();

    // Check if the stack is empty
    if (myStack.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    // TOP
    stack<string> fruits;
    fruits.push("apple");
    fruits.push("banana");
    string topFruit = fruits.top(); // Access the top element
    cout << topFruit << endl;

    // ITER
    stack<int> numbers;
    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    while (!numbers.empty()) {
        cout << numbers.top() << " "; // Access and print the top element
        numbers.pop(); // Pop the top element
    }

    // SIZE
    int size = numbers.size(); // Get the number of elements in the stack

    // SWAP
    stack<int> stack1, stack2;
    stack1.push(1);
    stack1.push(2);
    stack2.push(3);
    stack2.push(4);
    stack1.swap(stack2); // Swap the contents of stack1 and stack2

    // EMPLACE
    stack<pair<int, string>> items;
    items.emplace(1, "apple"); // Emplace elements
    items.emplace(2, "banana");

    return 0;
}
