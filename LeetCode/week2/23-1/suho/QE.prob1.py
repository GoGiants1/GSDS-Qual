import copy

def foo_iter(s,G,n):

    if len(s) == n: 
        return s
    else:
        next = G[s[-1]][1:] if s!='' else G.keys()
        t = ''
        
        for v in next:
            if G[v][0]>0: 
                G1 = copy.deepcopy(G)
                G1[v][0] -= 1
                tmp = foo_iter(s+v,G1,n)
                if tmp!='': 
                    t = tmp
                    break
        return t

def foo(s):
    if len(s) < 3:
        t = ""
    else:
        G1 = dict()
        G = dict()
        for i, v in enumerate(s):
            if(v in G1.keys()): 
                G[v][0] += 1
                G1[v][0] += 1
            else: 
                G[v] = [1]+list(set(list(s)))
                G1[v] = [1]

            if(i==0): G1[v].append(s[i+1])
            elif(i==len(s)-1): G1[v].append(s[i-1])
            else: G1[v].extend([s[i-1],s[i+1]])
        
        for v in G.keys():
            for v1 in G1[v][1:]:
                if v1 in G[v]: G[v].remove(v1)
        
        t = foo_iter('',G,len(s))
    
    return t

def bar(s):
    if len(s) < 3:
        t = ""
    else:
        G1 = dict()
        G = dict()
        for i, v in enumerate(s):
            if(v not in G.keys()):
                G[v] = [1]+list(set(list(s)))
                G1[v] = [1]

            if(i==0): G1[v].append(s[i+1])
            elif(i==len(s)-1): G1[v].append(s[i-1])
            else: G1[v].extend([s[i-1],s[i+1]])
        
        for v in G.keys():
            for v1 in G1[v][1:]:
                if v1 in G[v]: G[v].remove(v1)

        t = foo_iter('',G,len(set(s)))
    
    return t

            

print(foo('abccde'))
print(bar('abccde'))
print(bar('abcde'))





