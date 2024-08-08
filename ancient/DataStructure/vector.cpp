#include <vector>
#include <iostream>
using namespace std;

// Custom comparator function to sort in descending order
bool compareDescending(int a, int b) {
    return a > b;
}

int main(){
  // INIT
  vector<int> myVector; // Declare an empty vector of integers
  vector<string> names(5); // Declare a vector of 5 empty strings
  vector<double> prices = {10.5, 20.0, 5.99}; // Declare and initialize with values

  // ADD
  vector<int> numbers;
  numbers.push_back(42); // Add an element at the end
  numbers.push_back(73);
  numbers.insert(numbers.begin() + 1, 55); // Insert at a specific position

  // ACCESS
  vector<int> scores = {90, 85, 78, 92};
  int firstScore = scores[0]; // Access by index (No bounds check)
  int secondScore = scores.at(1); // Access by index with bounds check
  int lastScore = scores.back(); // Get the last element

  // SIZE
  vector<int> data = {1, 2, 3, 4, 5};
  int size = data.size(); // Get the number of elements
  int capacity = data.capacity(); // Get the current capacity

  // REMOVE 
  vector<int> values = {10, 20, 30, 40, 50};
  values.pop_back(); // Remove the last element
  values.erase(values.begin() + 2); // Remove element at a specific position

  // ITER
  vector<string> fruits = {"apple", "banana", "cherry"};
  for (int i = 0; i < fruits.size(); i++) {
      cout << fruits[i] << " ";
  }
  for (const string& fruit : fruits) {
      cout << fruit << " ";
  }

  // SORT
  vector<int> data = {5, 2, 9, 1, 5};
  sort(data.begin(), data.end()); // Sort in ascending order
  // Sort in descending order using the custom comparator function
  sort(numbers.begin(), numbers.end(), compareDescending);

  // SEARCH
  vector<string> words = {"apple", "banana", "cherry"};
  auto it = find(words.begin(), words.end(), "banana");
  if (it != words.end()) {
      cout << "Found " << *it << endl;
  } else {
      cout << "Not found" << endl;
  }

  // CLEAR
  vector<int> items = {1, 2, 3, 4, 5};
  items.clear(); // Remove all elements, vector is empty

  // EMPTY
  vector<int> data;
  if (data.empty()) {
      cout << "Vector is empty" << endl;
  }

}