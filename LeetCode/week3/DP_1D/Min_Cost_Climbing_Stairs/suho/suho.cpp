class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> T = {0, 0};
        int i = 1;
        while(i < cost.size()){
            T.push_back(min(T[i]+cost[i],T[i-1]+cost[i-1]));
            i++;
        }
        return T[T.size()-1];
    }
};
