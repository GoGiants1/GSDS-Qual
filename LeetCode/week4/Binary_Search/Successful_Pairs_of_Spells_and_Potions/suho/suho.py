class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        res = []
        for i in range(len(spells)):
            count = 0
            for j in range(len(potions)):
                if spells[i]*potions[j]>=success: count += 1
            res.append(count)
        return res
