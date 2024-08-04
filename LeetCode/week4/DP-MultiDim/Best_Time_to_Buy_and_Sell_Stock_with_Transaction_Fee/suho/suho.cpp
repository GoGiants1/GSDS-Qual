class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> bought = {-100000};
        vector<int> sold = {0};
        
        for(int i = 0; i < prices.size(); i++){ 
            bought.push_back(max(bought.back(), sold.back() - prices[i]));
            sold.push_back(max(sold.back(), bought.back() + prices[i] - fee));
        }
        
        return sold.back();
    }
};
