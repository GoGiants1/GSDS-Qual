from itertools import combinations

def combination_value(target, n):
    return list(combinations(target, n))

def combination_index(target, n):
    return list(combinations([i for i in range(0, len(target))], n))

target = "Hello World"

# combination 해야하는 index를 반환한다.
print(combination_index(target, 3))

# combination 해야하는 value를 반환한다.
print(combination_value(target, 3))