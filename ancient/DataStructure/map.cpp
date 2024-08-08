#include <iostream>
#include <map>

int main() {
    // Create an empty map that maps integers to strings
    std::map<int, std::string> myMap;

    // Insert key-value pairs into the map
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";
    myMap[4] = "Four";

    // Access values by key
    std::cout << "Value at key 2: " << myMap[2] << std::endl;

    // Check if a key exists in the map
    int keyToCheck = 5;
    if (myMap.find(keyToCheck) != myMap.end()) {
        std::cout << "Key " << keyToCheck << " exists in the map." << std::endl;
    } else {
        std::cout << "Key " << keyToCheck << " does not exist in the map." << std::endl;
    }

    // Iterate over the map and print all key-value pairs
    std::cout << "All key-value pairs in the map:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // Erase a key-value pair from the map
    int keyToDelete = 3;
    myMap.erase(keyToDelete);

    // Check the map size
    std::cout << "Map size after erasing a key: " << myMap.size() << std::endl;

    return 0;
}
