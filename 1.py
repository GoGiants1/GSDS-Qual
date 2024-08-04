def smalledt_pos_int( a ):
    hash = list([ 0 for i in range(len(a)+1) ])
    for num in a:
        if num <= len(a): hash[num-1] = 1
    
    return hash.index(0)+1
        
a = [1,1,3,2,-1]
print(smalledt_pos_int(a))