import copy

class Solution:
    def dfs(self, v: List[int], n: int, connections: List[List[int]], stepped: List[int], num: List[int]) -> List[int]:
        if(n not in v):
            v.append(n)
            for i in range(len(connections)):
                if(connections[i][1]==n): 
                    stepped.append(i)
                    self.dfs(v, connections[i][0], connections, stepped, num)
                if(connections[i][0]==n and i not in stepped):
                    stepped.append(i)
                    connections[i] = connections[i][::-1]
                    num[0]+=1
                    self.dfs(v, connections[i][0], connections, stepped, num)

    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        num = [0]
        v = []
        stepped = []
        self.dfs(v, 0, connections, stepped, num)
        
        return num[0]
