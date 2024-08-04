class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_can = max(candies)
        res = list([ candies[i]+extraCandies >= max_can for i in range(len(candies)) ])
        return res
