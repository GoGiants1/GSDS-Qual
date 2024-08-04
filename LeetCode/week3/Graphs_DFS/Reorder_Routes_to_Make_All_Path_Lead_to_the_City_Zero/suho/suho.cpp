class Solution {
public:
    void dfs(vector<int> &v, int n, vector<vector<int>> &connections, vector<int> &stepped, int &num){
        if(find(v.begin(),v.end(),n)==v.end()){
            v.push_back(n);
            for(int i = 0; i < connections.size(); i++){
                if(connections[i][1]==n){ 
                    stepped.push_back(i);
                    dfs(v, connections[i][0], connections, stepped, num);
                }
                if(connections[i][0]==n && find(stepped.begin(),stepped.end(),i)==stepped.end()){
                    stepped.push_back(i);
                    int tmp = connections[i][0];
                    connections[i][0] = connections[i][1];
                    connections[i][1] = tmp;
                    num+=1;
                    dfs(v, connections[i][0], connections, stepped, num);
                }
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        int num = 0;
        vector<int> v(0);
        vector<int> stepped(0);
        dfs(v, 0, connections, stepped, num);
        
        return num;
    }
};
