class Solution:
    def combi(self, k, n, l, agg):
        if len(l)==k:
            if sum(l)==n: agg.append(l)
            return
        elif l[-1]==9: return
        else: 
            for i in range(l[-1]+1,10):
                l2 = l+[i]
                self.combi(k, n, l2, agg)

    def combinationSum3(self, k, n):
        agg=[]
        for i in range(1,10):
            self.combi(k, n, [i], agg)
        
        return agg

a = Solution()
print(a.combinationSum3(3,7))

        