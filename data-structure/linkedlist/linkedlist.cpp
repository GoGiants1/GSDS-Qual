#include <iostream>
#include <string>

class Node {
public:
    int data;
    Node* next;

    Node(int _data, Node* _next = nullptr)
        : data(_data), next(_next) {}
};

class LinkedList {
private:
    Node* head;
    int length;

public:
    LinkedList() : head(nullptr), length(0) {}

    int size() const {
        return length;
    }

    void appendleft(int data) {
        if (head == nullptr) {
            head = new Node(data);
        } else {
            head = new Node(data, head);
        }
        length++;
    }

    void append(int data) {
        if (head == nullptr) {
            head = new Node(data);
        } else {
            Node* node = head;
            while (node->next != nullptr) {
                node = node->next;
            }
            node->next = new Node(data);
        }
        length++;
    }

    std::string toString() const {
        std::string res = "Head";
        if (head == nullptr) {
            return res + " → None";
        }
        Node* node = head;
        while (node != nullptr) {
            res += " → " + std::to_string(node->data);
            node = node->next;
        }
        return res;
    }

    bool contains(int target) const {
        if (head == nullptr) {
            return false;
        }
        Node* node = head;
        while (node != nullptr) {
            if (node->data == target) {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    int popleft() {
        if (head == nullptr) {
            return -1; // Error value, list is empty
        }
        Node* node = head;
        head = head->next;
        int data = node->data;
        delete node;
        length--;
        return data;
    }

    int pop() {
        if (head == nullptr) {
            return -1; // Error value, list is empty
        }
        Node* prev = nullptr;
        Node* node = head;
        while (node->next != nullptr) {
            prev = node;
            node = node->next;
        }
        int data = node->data;
        if (prev == nullptr) {
            head = nullptr;
        } else {
            prev->next = nullptr;
        }
        delete node;
        length--;
        return data;
    }

    bool remove(int target) {
        Node* node = head;
        Node* prev = nullptr;
        while (node != nullptr && node->data != target) {
            prev = node;
            node = node->next;
        }
        if (node == nullptr) {
            return false;
        }
        if (node == head) {
            head = head->next;
        } else {
            prev->next = node->next;
        }
        delete node;
        length--;
        return true;
    }

    void insert(int idx, int data) {
        if (idx <= 0) {
            appendleft(data);
        } else if (idx >= length) {
            append(data);
        } else {
            Node* node = head;
            for (int i = 0; i < idx - 1; ++i) {
                node = node->next;
            }
            Node* new_node = new Node(data, node->next);
            node->next = new_node;
            length++;
        }
    }

    void reverse() {
        if (length < 2) {
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        Node* ahead = nullptr;

        while (current != nullptr) {
            ahead = current->next;
            current->next = prev;
            prev = current;
            current = ahead;
        }
        head = prev;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList my_list;
    int command, data, index;

    do {
        std::cout << "\n-------\nCurrent List: " << my_list.toString() << std::endl;

        std::cout << "1: appendleft  2: append  3: popleft  4: pop  5: search  6: insert  7: remove  8: reverse  9: Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> command;

        switch (command) {
        case 1:
            std::cout << "Input number to append at start: ";
            std::cin >> data;
            my_list.appendleft(data);
            break;
        case 2:
            std::cout << "Input number to append: ";
            std::cin >> data;
            my_list.append(data);
            break;
        case 3:
            data = my_list.popleft();
            if (data != -1) {
                std::cout << "Popped from start: " << data << std::endl;
            } else {
                std::cout << "Linked list is empty!" << std::endl;
            }
            break;
        case 4:
            data = my_list.pop();
            if (data != -1) {
                std::cout << "Popped from end: " << data << std::endl;
            } else {
                std::cout << "Linked list is empty!" << std::endl;
            }
            break;
        case 5:
            std::cout << "Input number to search: ";
            std::cin >> data;
            if (my_list.contains(data)) {
                std::cout << data << " exists." << std::endl;
            } else {
                std::cout << data << " does not exist." << std::endl;
            }
            break;
        case 6:
            std::cout << "Input number to insert: ";
            std::cin >> data;
            std::cout << "Input index to insert at: ";
            std::cin >> index;
            my_list.insert(index, data);
            break;
        case 7:
            std::cout << "Input number to remove: ";
            std::cin >> data;
            if (my_list.remove(data)) {
                std::cout << "Removed " << data << "." << std::endl;
            } else {
                std::cout << data << " does not exist." << std::endl;
            }
            break;
        case 8:
            my_list.reverse();
            std::cout << "Reversed the linked list." << std::endl;
            break;
        case 9:
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (command != 9);

    return 0;
}