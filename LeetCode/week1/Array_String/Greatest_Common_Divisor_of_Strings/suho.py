class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        len1, len2 = len(str1), len(str2)

        for n in range(min(len1,len2),0,-1):
            if (len1%n != 0 or len2%n != 0): continue
            if (str1[:n]*(len1//n) == str1 and str1[:n]*(len2//n)==str2): break
            if (n==1): n-=1
        
        return str1[:n]
