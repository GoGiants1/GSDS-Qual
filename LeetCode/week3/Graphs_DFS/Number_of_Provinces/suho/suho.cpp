class Solution {
public:
    void dfs(vector<int> &v, int node, vector<vector<int>>& isConnected){
        if(find(v.begin(),v.end(),node)==v.end()){
            v.push_back(node);
            for(int i = 0; i < isConnected.size(); i++){
                if(isConnected[node][i]==1) dfs(v, i, isConnected);
            } 
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> v(0);
        int num = 0;

        for(int i = 0; i < isConnected.size(); i++){
            if(find(v.begin(),v.end(),i)==v.end()){
                num++;
                dfs(v, i, isConnected);
            }
        }
        
        return num;
    }
};
