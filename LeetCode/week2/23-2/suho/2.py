def check_palindrome(s):
    if len(s) == 1 : return 1
    else:
        if s[:len(s)//2] == s[::-1][:len(s)//2]: return 1
        else: return 0


def make_palindrome(s, num):
    if(check_palindrome(s)==1): return (num, s)
    else:
        result = (9,'')
        for i in range(len(s)):
            tmp = make_palindrome(s[:i]+s[i+1:],num+1)
            if(tmp[0]<=result[0]): result = tmp
            
        return result
    


s = "apple"
num=0
result = make_palindrome(s,num)
print(result[0], result[1])


