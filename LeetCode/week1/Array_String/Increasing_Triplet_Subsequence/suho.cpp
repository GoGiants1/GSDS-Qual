class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i, j, k;
        bool res = false;
        for(i=0;i<nums.size()-2;i++){
            for(j=i+1;j<nums.size()-1;j++){
                for(k=j+1;k<nums.size();k++){
                    if(nums[i]<nums[j] && nums[j]<nums[k]){
                        res = true;
                        break;
                    }
                }
                if(res) break;
            }
            if(res) break;
        }

        return res;
    }
};
