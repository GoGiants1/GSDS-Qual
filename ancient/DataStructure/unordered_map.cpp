#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> ages;

    // Insert key-value pairs
    ages["Alice"] = 25;
    ages["Charlie"] = 28;
    ages["Bob"] = 30;

    // Retrieve values by key
    std::cout << "Alice's age: " << ages["Alice"] << std::endl;

    // Check if a key exists
    if (ages.find("David") != ages.end()) {
        std::cout << "David's age: " << ages["David"] << std::endl;
    } else {
        std::cout << "David's age not found." << std::endl;
    }

    // Iterate through the map
    for (const auto& pair : ages) {
        std::cout << pair.first << "'s age is " << pair.second << std::endl;
    }

    return 0;
}
