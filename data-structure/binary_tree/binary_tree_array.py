"""
implementation of bianary_tree with array

indexing
    find child given parent; parent index: n
        left child: (2 * n + 1)
        right child: (2 * n + 2)

    find parent given child; child index: n
        parent index = (n - 1) // 2

** sanity check 필요
    현재 인덱스가 유효한 인덱스인지 체크
"""

def traversal_from_root(tree):
    i = 0
    n = len(tree)
    while i < n:
        if tree[i]:
            print(f"Parent: {tree[i]}", end = ", ")
            left = 2 * i + 1
            right = left + 1
            if left < n and tree[left] is not None:
                print(f"Left: {tree[left]}", end = ", ")
            if right < n and tree[right] is not None:
                print(f"Right: {tree[right]}", end = " ")
            print()
        i += 1

def traversal_from_leaf(tree):
    n = len(tree)
    i = n-1
    while i > 0:
        if tree[i]:
            print(f"Parent of {tree[i]} -> {tree[(i-1)//2]}")
        i -= 1


if __name__ == "__main__":
    tree = ["A", "B", "C", "D", "E", "F", None, "G"]
    print("Finding children given parents.")
    traversal_from_root(tree)
    print()
    print("Finding parent given child.")
    traversal_from_leaf(tree)
