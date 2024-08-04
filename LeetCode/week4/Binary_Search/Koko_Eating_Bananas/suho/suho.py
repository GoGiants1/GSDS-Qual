class Solution:
    def hours(self, piles, k):
        t = 0
        for num in piles:
            t += ceil(num/k)
        
        return t

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        a, b = 1, max(piles)
        k = (a+b)//2
        t = self.hours(piles, k)
        
        while(1):
            if(t > h): a = k+1
            else: b = k
            k2 = (a+b)//2
            if k == k2: break
            k = k2
            t = self.hours(piles, k)
        
        return k
