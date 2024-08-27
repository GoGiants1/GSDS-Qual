# KEYWORD
# Pigeonhole Principle
# pigeonhole_principle
# pigeonholeprinciple

def smallest_pos_int(arr):
    n = len(arr)
    
    for i in range(n):
        if arr[i] <= 0 or arr[i] > n: arr[i] = n + 1
    
    for i in range(n):
        val = abs(arr[i])
        if val <= n: arr[val - 1] = -abs(arr[val - 1])
    
    for i in range(n):
        if arr[i] > 0: return i + 1
    
    return n + 1

if __name__ == "__main__":
    print(smallest_pos_int([4, 7, -1, 1, 2])) # 3
    print(smallest_pos_int([100, 101, 102]))
    print(smallest_pos_int([3, 2, 1, 0, -1]))