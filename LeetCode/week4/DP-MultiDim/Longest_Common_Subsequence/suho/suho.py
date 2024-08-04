class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        sublen = [[-1 for j in range(len(text2)+1)] for i in range(len(text1)+1)]
        
        for i in range(0,len(text1)+1):
            for j in range(0, len(text2)+1):
                if(i == 0 or j == 0): sublen[i][j] = 0
                elif(text1[i-1] == text2[j-1]): sublen[i][j] = sublen[i-1][j-1] + 1
                else: sublen[i][j] = max(sublen[i-1][j], sublen[i][j-1])
        
        return sublen[len(text1)][len(text2)]
