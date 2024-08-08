#include <iostream>
using namespace std;

int main() {

  int numbers[] = {1, 2, 3, 4, 5};

  // ITER
  for (int i = 0; i < 5; i++) {
      cout << numbers[i] << " ";
  }

  // Access and modify an element
  numbers[2] = 10;
  cout << "\nModified element at index 2: " << numbers[2] << endl;
  
  // SIZE
  int size = sizeof(numbers) / sizeof(numbers[0]);
  cout << "Size of the array: " << size << endl;

  // INIT
  int myArray[5]; // Declare an integer array of size 5
  int numbers[] = {1, 2, 3, 4, 5}; // Declare and initialize an array
  int zeros[5] = {0}; // Initialize all elements to 0
  int ones[5] = {1}; // Initialize the first element to 1, others to 0

  // ACCESS
  int myArray2[5] = {10, 20, 30, 40, 50};
  int firstElement = myArray2[0]; // Access the first element
  int thirdElement = myArray2[2]; // Access the third element

  // CHANGE
  myArray2[0] = 42; // Modify the first element
  myArray2[1] = 73; // Modify the second element

  // MULTIDIM
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int element = matrix[1][2]; // Access the element at row 1, column 2

  return 0;
}
