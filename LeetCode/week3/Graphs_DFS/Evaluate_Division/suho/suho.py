class Solution:
    def dfs(self, node: str, des: str, v: List[str], sq: List[str], equations: List[List[str]]) -> List[int]:
        if node == des: 
            sq2 = sq[:]
            sq2.append(node)
            return sq2

        else:
            if node not in v:
                v.append(node)
                sq2 = sq[:]
                sq2.append(node)

                for path in equations:
                    if (path[0] == node or path[1] == node):
                        sq2 = self.dfs(path[1] if path[0] == node else path[0], des, v, sq2, equations)
                        if sq2[-1] == des: break
                    
                return sq2
            else: return sq

    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        ans = []
        nodes = set(itertools.chain(*equations))

        for q in queries:
            if (q[0] not in nodes or q[1] not in nodes): ans.append(-1)
            elif q in equations: ans.append(values[equations.index(q)])
            elif q[0] == q[1]: ans.append(1)
            else:
                v = []
                sq0 = self.dfs(q[0], q[1], v, [], equations)
                if sq0[-1] == q[1]:
                    prod = 1
                    for i in range(len(sq0[:-1])):
                        if [sq0[i],sq0[i+1]] in equations: prod *= values[equations.index([sq0[i],sq0[i+1]])]
                        else: prod *= 1/values[equations.index([sq0[i+1],sq0[i]])]
                    ans.append(prod)
                else:
                    ans.append(-1)
        
        return ans
