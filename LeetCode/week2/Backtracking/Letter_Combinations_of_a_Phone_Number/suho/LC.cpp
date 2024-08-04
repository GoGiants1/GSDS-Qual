class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> G;
        G.insert({'2', "abc"});
        G.insert({'3', "def"});
        G.insert({'4', "ghi"});
        G.insert({'5', "jkl"});
        G.insert({'6', "mno"});
        G.insert({'7', "pqrs"});
        G.insert({'8', "tuv"});
        G.insert({'9', "wxyz"});

        vector<string> res(0);
        if(digits.length()==1){
            for(int i = 0; i<G[digits[0]].size(); i++){
                res.push_back(G[digits[0]].substr(i, 1));
            }
        }
        else if(digits.length()==2){
            for(int i = 0; i<G[digits[0]].size(); i++){
                for(int j = 0; j<G[digits[1]].size(); j++){
                    res.push_back(G[digits[0]].substr(i, 1) + G[digits[1]].substr(j, 1));
                }
            }
        }
        else if(digits.length()==3){
            for(int i = 0; i<G[digits[0]].size(); i++){
                for(int j = 0; j<G[digits[1]].size(); j++){
                    for(int k = 0; k<G[digits[2]].size(); k++){
                        res.push_back(G[digits[0]].substr(i, 1) + G[digits[1]].substr(j, 1) + G[digits[2]].substr(k, 1));
                    }
                }
            }
        }
        else if(digits.length()==4){
            for(int i = 0; i<G[digits[0]].size(); i++){
                for(int j = 0; j<G[digits[1]].size(); j++){
                    for(int k = 0; i<G[digits[2]].size(); k++){
                        for(int h = 0; j<G[digits[3]].size(); h++){
                            res.push_back(G[digits[0]].substr(i, 1) + G[digits[1]].substr(j, 1) + G[digits[2]].substr(k, 1) + G[digits[3]].substr(h, 1));
                        }
                    }
                }
            }
        }

        return res;

    }
};
