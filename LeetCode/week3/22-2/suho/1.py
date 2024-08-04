def perm(incomp, left, res):
    if left == '':
        if(incomp not in res): res.append(incomp)
    
    else:
        for i, letter in enumerate(left):
            incomp2 = incomp+letter
            left2 = left[:i]+left[i+1:]
            perm(incomp2,left2,res)

def str_perm(s):
    res = []
    left = s[:]
    perm('',left,res)
    return res

s1 = "abc"
s2 = "abb"

print(str_perm(s1))
print(str_perm(s2))
