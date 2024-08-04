class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        T = [0,0]
        i = 1
        while(i < len(cost)):
            T.append(min(T[i]+cost[i],T[i-1]+cost[i-1]))
            i += 1

        return T[-1]
