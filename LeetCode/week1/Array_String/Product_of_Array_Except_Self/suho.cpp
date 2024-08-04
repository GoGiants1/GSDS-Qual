class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, rprod;
        vector<int> res(nums.size(),1);

        for(i=1;i<nums.size();i++){
            res[i] = res[i-1] * nums[i-1];
        }

        rprod = nums.back();
        for(i=nums.size()-2;i>=0;i--){
            res[i] *= rprod;
            rprod *= nums[i];
        }

        return res;
    }
};
