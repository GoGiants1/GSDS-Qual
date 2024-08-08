from itertools import permutations

def permutation_value(target, n):
    return list(permutations(target, n))

def permutation_index(target, n):
    return list(permutations([i for i in range(0, len(target))], n))

target = "Hello World"


# permutation 해야하는 index를 반환한다.
print(permutation_index(target, 3))

# permutation 해야하는 value를 반환한다.
print(permutation_value(target, 3))