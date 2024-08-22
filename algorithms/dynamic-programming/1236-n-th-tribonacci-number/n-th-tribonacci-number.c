#define MAX_LEN 38

int tribonacci(int n) {
  // Brute Force -> Time Limit Exceeded
  // if (n < 2){
  //     return n;
  // }

  // if (n == 2) {
  //     return 1;
  // }

  // return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);

  // int dp[38] = {0}; // 주의할 점: {0} 으로 초기화할 때, 배열의 길이가 compile
  // time에 상수여야힘?
  //                   // 변수 값을 길이로 가지는 경우 선언과 초기화 동시에
  //                   불가능.

  // 그게 아니라면 #define arrSIZE 100 와 같이 preprocess 선언 해주어야함.

  int dp[MAX_LEN] = {0};
  dp[1] = 1;
  dp[2] = 1;

  for (int i = 3; i < n + 1; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }

  return dp[n];
}
