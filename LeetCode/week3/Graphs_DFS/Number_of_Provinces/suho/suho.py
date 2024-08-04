class Solution:
    def dfs(self, v, node, isConnected):
        if(node not in v):
            v.append(node);
            for i in range(len(isConnected)): 
                if(isConnected[node][i]==1): self.dfs(v, i, isConnected) 

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        v = []
        num = 0

        for i in range(len(isConnected)):
            if(i not in v):
                num += 1
                self.dfs(v, i, isConnected)
        
        return num
        
