int memo[101][101];

int dp(int i, int j) {
    if (i == 0 || j == 0) {
        return 1;
    }

    if (memo[i][j] != 0) {
        return memo[i][j];
    }

    memo[i][j] = dp(i - 1, j) + dp(i, j - 1);
    return memo[i][j];
}

int uniquePaths(int m, int n) {
    for (int i = 0; i < m; i++){
        memo[i][0] = 0;
    }
    for (int j = 0; j < n; j++){
        memo[0][j] = 0;
    }

    int result = dp(m - 1, n - 1);

    return result;
}


// Bottom-up
// int uniquePaths(int m, int n) {
//     int grid[m][n];

//     // 중학교 수학 문제

//     for(int i = 0; i < m; ++i){
//         grid[i][0] = 1;    
//     }
//     for (int j = 0; j < n; ++j){
//         grid[0][j] = 1;
//     }

//     // The test cases are generated so that the answer will be less than or equal to 2 * 10^9 = 2 * (2^10)^3 = 2^31. -> int32 보장

//     for (int i = 1; i < m; ++i){
//         for (int j = 1; j < n; ++j){
//             grid[i][j] = grid[i-1][j] + grid[i][j-1];
//         }
//     }

// }


// Memoization with double pointer implementation

// int dp(int i, int j, int **memo) {
//     if (i == 0 || j == 0) {
//         return 1;
//     }

//     if (memo[i][j] != 0) {
//         return memo[i][j];
//     }

//     memo[i][j] = dp(i - 1, j, memo) + dp(i, j - 1, memo);
//     return memo[i][j];
// }

// int uniquePaths(int m, int n) {
//     int **memo = (int **)malloc(m * sizeof(int *));
//     for (int i = 0; i < m; i++) {
//         memo[i] = (int *)calloc(n, sizeof(int));
//     }

//     int result = dp(m - 1, n - 1, memo);

//     // 메모리 해제
//     for (int i = 0; i < m; i++) {
//         free(memo[i]);
//     }
//     free(memo);

//     return result;
// }