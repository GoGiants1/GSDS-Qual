class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        D = [[-1 for j in range(len(word2)+1)] for i in range(len(word1)+1)]
        D[0] = list(range(len(word2)+1))
        for i in range(1,len(word1)+1): D[i][0] = i

        for i in range(1,len(word1)+1):
            for j in range(1,len(word2)+1):
                D[i][j] = min(D[i-1][j] + 1, D[i][j-1] + 1, D[i-1][j-1] + (0 if word1[i-1]==word2[j-1] else 1))
        
        return D[-1][-1]
