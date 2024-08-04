class Solution:
    def rob(self, nums: List[int]) -> int:
        T1 = nums[0:1]
        T2 = [0]
        i = 1
        while(i < len(nums)):
            T1.append(T2[i-1] + nums[i])
            T2.append(max(T1[i-1],T2[i-1]))
            i += 1

        return max(T1[i-1], T2[i-1])    
