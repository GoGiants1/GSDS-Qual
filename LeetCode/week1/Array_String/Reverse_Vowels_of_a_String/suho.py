class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ['a','e','i','o','u','A','E','I','O','U']
        index = []
        for i in range(len(s)):
            if(s[i] in vowels): index.append(i)
        
        res = ''
        for i in range(len(s)):
            if i in index: res += s[index[-index.index(i)-1]]
            else: res += s[i]
        print(index)
        return res
