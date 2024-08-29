"""
Q) Implement a function max_palindrome(s) that returns a list of substrings of s that are maximal palindromes.
That is, the list contains palindromes that are not a substring of another palindrome. 

- A string of characters is a palindrome if it is identical to its reversion. 
- A substring is a contiguous sequence of characters within a string.
- Example
    1. s = "kabccbadzdefgfeda" → ["k", "abccba", "dzd", "defgfed"]
    2. s = "kabccba dzabccbaza" → ["k", " ", "d", "zabccbaz", "aza"].
    3. LexSmallest(G,w,y) → []
"""

def palindrome(s):
    """
    String s가 회문인지 판별
    """
    for i in range(len(s)//2):
        if s[i] != s[len(s)-1-i]:
            return False
    return True

def substring(s,t):
    """
    String t가 string s의 substring인지 판별
    """
    if not t:
        return 1
    
    if len(t) > len(s):
        return 0
    
    for i in range(len(s)-len(t)+1):
        if s[i:i+len(t)] == t:
            return 1
    return 0

def max_palindrome(s):
    n = len(s)
    palindromes = []

    # 모든 단위의 substring을 봄 -> 한 문자를 기준으로 몇 개씩 볼 건지 늘려가기
    for i in range(n):
        for j in range(i+1, n+1):       
            sub = s[i:j]         # j가 포함이 안되니까 마지막에 n을 넣어줘야 n-1까지 슬라이싱 가능. 그래서 range에서 n+1
            if palindrome(sub):
                is_substring = False
                for other in palindromes:    # 지금까지 찾은 모든 회문들과 비교
                    if substring(other, sub):     # 새로 찾은 게 substring이면 그냥 추가 x
                        is_substring = True
                        break
                    if substring(sub, other):     # 새로 찾은 게 기존 껄 포함하면
                        palindromes.remove(other)   # max만 남김
                if not is_substring:
                    palindromes.append(sub)
    
    return palindromes



if __name__ == "__main__":
    print(max_palindrome("kabccbadzdefgfeda"))
    print(max_palindrome("kabccba dzabccbaza"))