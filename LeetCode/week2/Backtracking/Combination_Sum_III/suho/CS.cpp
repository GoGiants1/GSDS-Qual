class Solution {
public:
    void combi(int k, int n, vector<int> l, vector<vector<int>> &agg){
        if(l.size()>=k){
            int sum = 0;
            for(int i = 0; i< k; i++) sum+=l[i];
            if(sum==n) agg.push_back(l);
            return;
        }
        else if (l.back()==9) return;
        else{
            for(int i = l.back()+1;i<10;i++){
                vector<int> l2;
                l2.resize((int)(l.size()));
                copy( l.begin(), l.end(), l2.begin() );
                l2.push_back(i);
                combi(k, n, l2, agg);
            }
            return;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> agg(0);
        for(int i = 1; i<10; i++){
            combi(k, n, vector<int>{i}, agg);
        }
            
        return agg;
    }
};
