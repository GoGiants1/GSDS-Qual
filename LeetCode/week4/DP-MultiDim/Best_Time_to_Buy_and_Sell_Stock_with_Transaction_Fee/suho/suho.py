class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        bought = [-100000]
        sold = [0]
        
        for price in prices:
            bought.append(max(bought[-1], sold[-1] - price))
            sold.append(max(sold[-1], bought[-1] + price - fee))
        
        return sold[-1]
