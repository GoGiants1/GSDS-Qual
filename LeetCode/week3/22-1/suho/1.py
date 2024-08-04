def palindrome(s: str) -> bool:
    return s[:len(s)//2]==s[:(len(s)-1)//2:-1]

print(palindrome("ababa"), palindrome("abccba"), palindrome("abadhc"), palindrome("abash"))

def substring(s: str, t: str) -> bool:
    return t in s

print(substring("abcde", "abcde"), substring("abcde", ""), substring("abcde", "abc"), substring("abcde", "abe"))
    
def max_palindrome(s: str) -> list[str]:
    palin_list = []
    for i in range(0,len(s)):
        for j in range(i+1,len(s)+1):
            if(palindrome(s[i:j])): palin_list.append(s[i:j])

    i=0
    while(i<len(palin_list)):
        for j in range(len(palin_list)):
            if(i!=j):
                if(substring(palin_list[j],palin_list[i])):
                    palin_list.pop(i)
                    i-=1
                    break
        i+=1

    return palin_list

print(max_palindrome("kabccbadzdefgfeda"), max_palindrome("kabccba dzabccbaza"))
