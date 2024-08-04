class Solution:
    def numTilings(self, n: int) -> int:
        T = [1]
        i = 1
        while(i <= n):
            if(i <= 1): T.append(T[i-1])
            elif(i <= 2): T.append(T[i-1] + T[i-2])
            elif(i <= 3): T.append(T[i-1] + T[i-2] + T[i-3]*2)
            else: T.append(T[i-1] + T[i-2] + sum(T[:-2])*2)
            i += 1
        
        return T[-1]
