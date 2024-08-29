"""
a) Implement a function foo(s) that returns a string t in which no 2 adjacent characters
are adjacent in s, and t contains exactly the same number of chars as that of s. When a char
appears in s, t should contain it as often as in s. When there is no such string t, return empty string.
If there are multiple strings that satisfy the conditions, return any of them.

- Example: 
    1. s: "abcde" → "adbec"
    2. s: "abc" → ""
    3. s: "" → ""
    4. s: "abccde" → "cacebd"
    5. s: "abcdcef" → "cacfbed"

b) a랑 동일 except iwhen a char appears in s, t should contain it only once.

- Example: 
    1. s: "abcde" → "adbec"
    2. s: "abc" → ""
    3. s: "" → ""
    4. s: "abccde" → "caebd"
    5. s: "abcdcef" → "cafbed"
"""

import copy

def foo_iter(s,G,n):
    """
    재귀적으로 문자열 s의 가능한 재배열 찾는 함수
    - s: 현재까지 만들어진 부분 문자열
    """
    if len(s) == n:    # 문자 다 사용
        return s
    else:
        if s != '':
            next = G[s[-1]][1:]    # 사용할 수 있는 문자 리스트
        else:
            next = G.keys()    # 아직 만들어진 문자열이 없으니 아무거나 접근 가능
        t = ''
        
        for v in next:
            if G[v][0] > 0:  # 아직 유효한 선택지 있는 상태
                G_copy = copy.deepcopy(G)   # 이전 상태 변경하지 않기 위해 복사본 만듦
                G_copy[v][0] -= 1           # 선택한 문자의 사용 빈도 감소
                tmp = foo_iter(s+v, G_copy, n)
                if tmp != '':   # 재귀가 종료되어 tmp에 값이 반환되었는데 빈 문자가 아니라면
                    t = tmp
                    break
        return t     # t=tmp를 만나지 않으면 t는 빈 문자열로 반환

def foo(s):
    """
    중복 허용
    """
    if len(s) < 3:      # 안 겹치게 만들 수 x
        t = ""
    else:
        blacklist = dict()   # 각 char가 등장하는 횟수 + 다음에 올 수 없는 문자들 저장 (G 초기화용)
        G = dict()           # 각 char가 등장하는 횟수 + 다음에 올 수 있는 문자들 저장
        
        for i, v in enumerate(s):   # 등장 횟수 기록
            if (v in blacklist.keys()): 
                G[v][0] += 1
                blacklist[v][0] += 1
            else:  # 처음 나온 char라면
                G[v] = [1] + list(set(list(s)))    
                blacklist[v] = [1]

            # 인접한 문자들 저장 (이전/다음) -> 이후 G에서 제거
            if (i==0): blacklist[v].append(s[i+1])   
            elif (i==len(s)-1): blacklist[v].append(s[i-1])   
            else: blacklist[v].extend([s[i-1],s[i+1]]) 
        
        for v in G.keys():
            for adjacent in blacklist[v][1:]:
                if adjacent in G[v]: G[v].remove(adjacent)
        
        t = foo_iter('',G,len(s))
    
    return t

def bar(s):
    """
    중복 허용 X
    """
    if len(s) < 3:
        t = ""
    else:
        blacklist = dict()
        G = dict()

        for i, v in enumerate(s):
            if (v in blacklist.keys()): 
                G[v][0] += 1
                blacklist[v][0] += 1
            else:  # 처음 나온 char라면
                G[v] = [1] + list(set(list(s)))    
                blacklist[v] = [1]

            # 인접한 문자들 저장 (이전/다음) -> 이후 G에서 제거
            if (i==0): blacklist[v].append(s[i+1])   
            elif (i==len(s)-1): blacklist[v].append(s[i-1])   
            else: blacklist[v].extend([s[i-1],s[i+1]]) 
        
        for v in G.keys():
            for adjacent in blacklist[v][1:]:
                if adjacent in G[v]: G[v].remove(adjacent)

        t = foo_iter('',G,len(set(s)))   # set(s)를 전달
    
    return t

            
if __name__ == "__main__":
    print("Test cases without same chars: ")
    print("abcde → ", foo('abcde'))
    print("abc → ",foo('abc'))
    print("' ' → ",foo(''))

    print("Test cases with same chars")
    print("Foo: abccde → ", foo('abccde'))
    print("Bar: abccde → ", bar('abccde'))
    print()
    print("Foo: abcdcef → ", foo('abcdcef'))
    print("Bar: abcdcef → ", bar('abcdcef'))
    





