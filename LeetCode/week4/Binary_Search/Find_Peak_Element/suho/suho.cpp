class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        else{
            int a = 0, b = nums.size()-1;
            int i = (a+b)/2;
            while(1){
                if(i==0){
                    if(nums[i]>nums[i+1]) break;
                }
                else if(i == nums.size()-1){
                    if(nums[i]>nums[i-1]) break;
                }
                else{
                    if(nums[i]>nums[i+1] and nums[i]>nums[i-1]) break;
                    else if(nums[i-1]<=nums[i+1]) a = i+1;
                    else b = i-1;
                    i = (a+b)/2;
                }
            }
            return i;
        }
    }
};
