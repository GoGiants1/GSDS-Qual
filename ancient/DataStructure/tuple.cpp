#include <iostream>
#include <tuple>
#include <string>
using namespace std;

int main() {
    // Creating a tuple
    tuple<int, double, string> myTuple(42, 3.14, "Hello");

    // Accessing elements
    int firstElement = get<0>(myTuple);
    double secondElement = get<1>(myTuple);
    string thirdElement = get<2>(myTuple);
    cout << "Tuple Elements: " << firstElement << " " << secondElement << " " << thirdElement << endl;

    // Modifying elements
    get<0>(myTuple) = 99;
    get<1>(myTuple) = 2.718;

    cout << "Modified Tuple Elements: " << get<0>(myTuple) << " " << get<1>(myTuple) << " " << get<2>(myTuple) << endl;

    // Tuple size
    size_t tupleSize = tuple_size<decltype(myTuple)>::value;
    cout << "Tuple Size: " << tupleSize << endl;

    // Tuple concatenation
    tuple<int, char> tuple1(10, 'X');
    tuple<double> tuple2(7.5);
    auto concatenatedTuple = tuple_cat(tuple1, tuple2);
    cout << "Concatenated Tuple: " << get<0>(concatenatedTuple) << " " << get<1>(concatenatedTuple) << " " << get<2>(concatenatedTuple) << endl;

    return 0;
}
