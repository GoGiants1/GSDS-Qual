#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int memo[MAX_LEN][MAX_LEN];
char* s;
int start, maxLen;

int expandAroundCenter(int left, int right) {
  while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
    left--;
    right++;
  }
  return right - left - 1;
}

void updateLongestPalindrome(int newStart, int newLen) {
  if (newLen > maxLen) {
    start = newStart;
    maxLen = newLen;
  }
}

int dp(int i, int j) {
  if (i >= j) return 1;
  if (memo[i][j] != -1) return memo[i][j];

  if (s[i] == s[j] && dp(i + 1, j - 1)) {
    updateLongestPalindrome(i, j - i + 1);
    return memo[i][j] = 1;
  }

  dp(i + 1, j);
  dp(i, j - 1);

  return memo[i][j] = 0;
}

char* longestPalindrome(char* str) {
  s = str;
  int n = strlen(s);
  if (n < 2) return strdup(s);

  start = 0;
  maxLen = 1;

  memset(memo, -1, sizeof(memo));

  dp(0, n - 1);

  for (int i = 0; i < n; i++) {
    int len1 = expandAroundCenter(i, i);
    updateLongestPalindrome(i - len1 / 2, len1);

    int len2 = expandAroundCenter(i, i + 1);
    updateLongestPalindrome(i - len2 / 2 + 1, len2);
  }

  char* result = (char*)malloc((maxLen + 1) * sizeof(char));
  strncpy(result, s + start, maxLen);
  result[maxLen] = '\0';

  return result;
}

// Solution 2

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
  int n = strlen(s);
  if (n < 2) return strdup(s);
  int start = 0, max_len = 1;
  bool dp[1000][1000] = {false};

  // 길이 1인 팰린드롬 초기화
  for (int i = 0; i < n; i++) {
    dp[i][i] = true;
  }

  // 길이 2인 팰린드롬 검사

  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1] = true;

      start = i;

      max_len = 2;
    }
  }

  // 길이 3 이상인 팰린드롬 검사

  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      if (s[i] == s[j] && dp[i + 1][j - 1]) {
        dp[i][j] = true;
        if (len > max_len) {
          start = i;

          max_len = len;
        }
      }
    }
  }

  char* result = (char*)malloc((max_len + 1) * sizeof(char));

  strncpy(result, s + start, max_len);

  result[max_len] = '\0';

  return result;
}