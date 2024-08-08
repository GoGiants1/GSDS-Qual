#include <iostream>
#include <utility> // Include the utility header for pair

using namespace std;

int main() {
    pair<int, string> student;
    student = make_pair(1, "Alice");

    pair<double, double> point(3.5, 2.0);

    cout << "Student ID: " << student.first << ", Name: " << student.second << endl;
    cout << "X-coordinate: " << point.first << ", Y-coordinate: " << point.second << endl;

    pair<int, int> a(2, 3);
    pair<int, int> b(3, 4);
    if (a < b) {
        cout << "a is less than b." << endl; // answer
    } else {
        cout << "a is not less than b." << endl;
    }

    pair<int, int> c(5, 6);
    pair<int, int> d(7, 8);
    swap(c, d);
    cout << "c: " << c.first << ", " << c.second << endl;
    cout << "d: " << d.first << ", " << d.second << endl;

    return 0;
}
