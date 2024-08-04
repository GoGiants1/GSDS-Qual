class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        up = [[-1 for j in range(n)] for i in range(m)]
        up[0][0] = 1

        for i in range(m):
            for j in range(n):
                if(i==0): 
                    if(j==0): up[i][j] = 1
                    else: up[i][j] = up[i][j-1]
                elif(j==0): up[i][j] = up[i-1][j]
                else: up[i][j] = up[i][j-1] + up[i-1][j]
        
        return up[-1][-1]
