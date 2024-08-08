#include <iostream>
#include <deque>

int main() {
    std::deque<int> myDeque;

    // Push elements to the front and back of the deque
    myDeque.push_front(1);
    myDeque.push_back(2);
    myDeque.push_back(3);
    myDeque.push_front(0);

    // Display the deque elements
    std::cout << "Deque elements: ";
    for (const int& num : myDeque) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Accessing elements by index
    std::cout << "Element at index 2: " << myDeque[2] << std::endl;

    // Getting the front and back elements
    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;

    // Pop elements from the front and back of the deque
    myDeque.pop_front();
    myDeque.pop_back();

    // Display the modified deque
    std::cout << "Modified deque elements: ";
    for (const int& num : myDeque) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Check if the deque is empty
    if (myDeque.empty()) {
        std::cout << "Deque is empty." << std::endl;
    } else {
        std::cout << "Deque is not empty." << std::endl;
    }

    // Get the size of the deque
    std::cout << "Deque size: " << myDeque.size() << std::endl;

    return 0;
}
