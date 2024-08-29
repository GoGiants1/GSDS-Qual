#include "functions.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// map은 pair를 key로 사용할 수 없음 .... python과 다름.

long coinCombinations(int n, int sum, vector<int>& coins) {
  // n: number of coins
  // sum: target sum
  // coins: coin values
  // 다이나믹 프로그래밍 같아보임.

  // 첫 시도: btm-up -> ? 실패
  // 두번째 시도: top-down -> cache 구현시 array를 사용해야함.
  // map은 pair를 key로 사용할 수 없다.

  vector<long> dp(sum + 1, 0);
  // base case
  dp[0] = 1;

  for (int i = 0; i <= sum; i++) {
    for (int j = 0; j < n; j++) {
      if (coins[j] <= i) {
        dp[i] = (dp[i - coins[j]] + dp[i]) % 2147483647;
      }
    }
  }

  return dp[sum];
}