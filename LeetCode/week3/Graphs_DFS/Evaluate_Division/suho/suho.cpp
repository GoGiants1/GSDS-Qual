class Solution {
public:
    vector<string> dfs(string node, string &des, vector<string> &v, vector<string> sq, vector<vector<string>> &equations){
        if(node == des){
            sq.push_back(node);
            return sq;
        }

        else{
            if(find(v.begin(),v.end(),node)==v.end()){
                v.push_back(node);
                sq.push_back(node);

                for(int i = 0; i < equations.size(); i++){
                    if (equations[i][0] == node || equations[i][1] == node){
                        vector<string> sq2 = dfs(equations[i][0] == node ? equations[i][1] : equations[i][0], des, v, sq, equations);
                        if(sq2[sq2.size()-1] == des){
                            sq = sq2;
                            break;
                        }
                    }
                }

                return sq;
            }
            else return sq;
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans(0);
        vector<string> nodes(0);
        for(int i = 0; i < equations.size(); i++){
            nodes.push_back(equations[i][0]);
            nodes.push_back(equations[i][1]);
        }

        for(int i = 0; i < queries.size(); i++){
            if (find(nodes.begin(),nodes.end(),queries[i][0])==nodes.end() || find(nodes.begin(),nodes.end(),queries[i][1])==nodes.end()){
                ans.push_back(-1.);
            }
            else if(queries[i][0] == queries[i][1]) ans.push_back(1.);
            else{
                vector<string> v(0);
                vector<string> sq0 = dfs(queries[i][0], queries[i][1], v, vector<string>{}, equations);
                if (sq0[sq0.size()-1] == queries[i][1]){
                    double prod = 1.;
                    for(int j = 0; j < sq0.size()-1; j++){
                        for(int k = 0; k < equations.size(); k++){
                            if(equations[k][0]==sq0[j] && equations[k][1]==sq0[j+1]){
                                prod *= values[k];
                                break;
                            }
                            else if(equations[k][0]==sq0[j+1] && equations[k][1]==sq0[j]){
                                prod *= 1./values[k];
                                break;
                            }
                        }
                    }
                    ans.push_back(prod);
                }
                else ans.push_back(-1.);
            }
        }
        
        return ans;
    }
};
