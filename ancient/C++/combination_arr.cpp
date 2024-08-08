#include <iostream>
#include <vector>

void combinationUtil(const std::vector<int>& arr, int start, int end, 
                     int index, int r, std::vector<int>& data, 
                     std::vector<std::vector<int>>& allCombinations) {
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

std::vector<std::vector<int>> printCombination(const std::vector<int>& arr, int r) {
    std::vector<std::vector<int>> allCombinations;
    std::vector<int> data(r); // Temporary array to store current combination
    
    // Generate all combinations
    combinationUtil(arr, 0, arr.size() - 1, 0, r, data, allCombinations);
    
    return allCombinations; // Return all generated combinations
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int r = 3;
    std::vector<std::vector<int>> combinations = printCombination(arr, r);
    
    // Print all combinations
    for (const auto& comb : combinations) {
        for (int num : comb) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}