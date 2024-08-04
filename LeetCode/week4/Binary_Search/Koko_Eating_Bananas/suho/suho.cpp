class Solution {
public:
    int hours(vector<int>& piles, int k){
        int t = 0;
        for(int i = 0; i < piles.size(); i++){
            t += (int)ceil((float)piles[i]/k);
        }
        return t;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int a = 1, b = *max_element(piles.begin(), piles.end());
        int k = (a+b)/2;
        int t = hours(piles, k);
        int k2;
        
        while(1){
            if(t > h) a = k+1;
            else b = k;
            k2 = (a+b)/2;
            if(k == k2) break;
            k = k2;
            t = hours(piles, k);
        }
        
        return k;
    }
};
