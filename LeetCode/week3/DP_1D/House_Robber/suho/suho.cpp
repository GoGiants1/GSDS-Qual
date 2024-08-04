class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> T1 = {nums[0]};
        vector<int> T2 = {0};
        int i = 1;
        while(i < nums.size()){
            T1.push_back(T2[i-1] + nums[i]);
            T2.push_back(max(T1[i-1],T2[i-1]));
            i++;
        }

        return max(T1[i-1], T2[i-1]);
    }
};
