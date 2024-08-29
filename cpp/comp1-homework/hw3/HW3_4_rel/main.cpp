#include <algorithm>
#include <iostream>
#include <vector>

#include "functions.hpp"

using namespace std;

int main() {
  int n = 3, x = 24;
  vector<int> coins = {3, 2, 1};

  std::cout << coinCombinations(n, x, coins) << std::endl;

  return 0;
}
