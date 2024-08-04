class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        res = False
        for i in range(0,len(nums)-2):
            for j in range(i+1,len(nums)-1):
                for k in range(j+1,len(nums)):
                    if(nums[i]<nums[j] and nums[j]<nums[k]): 
                        res = True
                        break
                if(res): break
            if(res): break
        return bool
