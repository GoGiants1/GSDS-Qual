class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(0);
        for(int i = 0; i < spells.size(); i++){
            int count = 0;
            for(int j = 0; j < potions.size(); j++){
                if(spells[i] * potions[j] >= success) count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
