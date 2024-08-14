class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string,int> freq;
        
        for (string el: arr) {
            freq[el]++;
        }
        int order_cnt = 0;
        for (string el: arr) {
            if (freq[el] == 1){
                order_cnt++;
            }

            if (order_cnt == k){
                return el;
            }
        }

        return "";
    }
};