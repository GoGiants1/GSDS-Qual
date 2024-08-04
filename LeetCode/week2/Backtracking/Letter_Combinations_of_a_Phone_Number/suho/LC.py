class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        G = dict()
        G["2"], G["3"], G["4"], G["5"] = ["a","b","c"], ["d","e","f"], ["g","h","i"], ["j","k","l"]
        G["6"], G["7"], G["8"], G["9"] = ["m","n","o"], ["p","q","r","s"], ["t","u","v"], ["w","x","y","z"]
        
        res = []
        if(len(digits)==1): res = G[digits]
        elif(len(digits)==2): 
            for i in G[digits[0]]:
                for j in G[digits[1]]:
                    res.append(i+j)
        elif(len(digits)==3):
            for i in G[digits[0]]:
                for j in G[digits[1]]:
                    for k in G[digits[2]]:
                        res.append(i+j+k)
        elif(len(digits)==4):
            for i in G[digits[0]]:
                for j in G[digits[1]]:
                    for k in G[digits[2]]:
                        for h in G[digits[3]]:
                            res.append(i+j+k)

        return res


        
