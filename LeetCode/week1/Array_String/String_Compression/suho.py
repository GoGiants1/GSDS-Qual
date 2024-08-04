class Solution:
    def compress(self, chars: List[str]) -> int:
        s = []
        count = 0
        for i in range(len(chars)):
            count+=1
            if(i==len(chars)-1 or chars[i+1]!=chars[i]):
                s.append(chars[i])
                if(count!=1): 
                    for j in range(len(str(count))): s.append(str(count)[j])
                count = 0

        for i in range(len(s)): chars[i] = s[i]
        return len(s)
