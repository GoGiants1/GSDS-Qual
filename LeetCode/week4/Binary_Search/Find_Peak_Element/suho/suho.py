class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums)==1 : return 0
        else:
            a, b = 0, len(nums)-1
            i = (a+b)//2
            while(1):
                if i==0:
                    if nums[i]>nums[i+1]: break
                elif i == len(nums)-1:
                    if nums[i]>nums[i-1]: break
                else:
                    if(nums[i]>nums[i+1] and nums[i]>nums[i-1]): break
                    elif(nums[i-1]<=nums[i+1]): a = i+1
                    else: b = i-1
                    i = (a+b)//2
            
            return i
