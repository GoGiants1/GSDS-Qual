#include <queue>
#include <iostream>
using namespace std;


int main(){
  queue<int> myQueue; // Declare an empty integer queue
  queue<string> names; // Declare an empty string queue

  // PUSH
  queue<int> numbers;
  numbers.push(42); // Push an element to the back of the queue
  numbers.push(73);

  // POP
  queue<int> numbers2;
  numbers2.push(42);
  numbers2.push(73);
  numbers2.pop(); // Remove the front element

  // ACCESS
  queue<string> fruits;
  fruits.push("apple");
  fruits.push("banana");
  string frontFruit = fruits.front(); // Access the front element
  cout << frontFruit << endl;

  // EMPTY
  queue<int> data;
  if (data.empty()) {
      cout << "Queue is empty" << endl;
  }

  // SIZE
  queue<char> characters;
  int size = characters.size(); // Get the number of elements in the queue

  // ITER
  queue<int> numbers3;
  numbers3.push(1);
  numbers3.push(2);
  numbers3.push(3);
  while (!numbers3.empty()) {
      cout << numbers3.front() << " "; // Access and print the front element
      numbers3.pop(); // Remove the front element
  }

  // SWAP
  queue<int> queue1, queue2;
  queue1.push(1);
  queue1.push(2);
  queue2.push(3);
  queue2.push(4);
  queue1.swap(queue2); // Swap the contents of queue1 and queue2

  // EMPLACE
  queue<pair<int, string>> items;
  items.emplace(1, "apple"); // Emplace elements
  items.emplace(2, "banana");

  // CLEAR
  queue<int> example;
  example.push(4);
  example.push(5);
  example = queue<int>(); // Clear the queue

  return 0;
}