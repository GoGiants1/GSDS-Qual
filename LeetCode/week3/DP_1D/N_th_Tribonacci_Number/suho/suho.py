class Solution:
    def fib(self, T: List[int], n: int) -> int:
        if(len(T)>n): return T[n]
        else:
            T.append(T[-1]+T[-2]+T[-3])
            return self.fib(T,n)

    def tribonacci(self, n: int) -> int:
        if(n == 0): return 0
        elif(n < 3): return 1
        else: return self.fib([0,1,1],n) 
