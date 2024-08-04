# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        a, b = 1, n
        ans = (a+b)//2
        res = guess(ans)

        while(res!=0):
            if res == 1: a = ans+1
            else: b = ans-1
            ans = (a+b)//2
            res = guess(ans)
        
        return ans
        
