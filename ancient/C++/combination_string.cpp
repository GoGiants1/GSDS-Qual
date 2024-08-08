#include <iostream>
#include <vector>
#include <string>

void combinationUtil(const std::string& arr, int start, int end, 
                     int index, int r, std::string& data, 
                     std::vector<std::string>& allCombinations) {
    // Current combination is ready, add it to the list of all combinations
    if (index == r) {
        allCombinations.push_back(data);
        return;
    }
    
    // Replace index with all possible elements to build up combinations
    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combinationUtil(arr, i + 1, end, index + 1, r, data, allCombinations);
    }
}

std::vector<std::string> printCombination(const std::string& arr, int r) {
    std::vector<std::string> allCombinations;
    std::string data(r, ' '); // Temporary string to store current combination
    
    // Generate all combinations
    combinationUtil(arr, 0, arr.length() - 1, 0, r, data, allCombinations);
    
    return allCombinations; // Return all generated combinations
}

int main() {
    std::string arr = "abcde";
    int r = 3;
    std::vector<std::string> combinations = printCombination(arr, r);
    
    // Print all combinations
    for (const auto& comb : combinations) {
        std::cout << comb << std::endl;
    }
    
    return 0;
}