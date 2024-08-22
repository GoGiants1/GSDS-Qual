from functools import cache
from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        import math

        m, n = len(grid), len(grid[0])

        @cache
        def dp(x: int, y: int) -> int | float:
            if not (0 <= x < m and 0 <= y < n):
                return math.inf
            if x == m - 1 and y == n - 1:
                return grid[x][y]

            return min(dp(x + 1, y), dp(x, y + 1)) + grid[x][y]

        return dp(0, 0)
