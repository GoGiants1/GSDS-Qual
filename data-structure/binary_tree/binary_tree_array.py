"""
- keyword: binary_tree with array
- functions: indexing, search, insert, delete, DFT traversal, BFT traversal, traversal_from_root, traversal_from_leaf

indexing
    find child given parent; parent index: n
        left child: (2 * n + 1)
        right child: (2 * n + 2)

    find parent given child; child index: n
        parent index = (n - 1) // 2

** sanity check 필요
    현재 인덱스가 유효한 인덱스인지 체크
"""

class ArrayBinaryTree:
    def __init__(self, capacity):
        self.tree = [None] * capacity
        self.size = 0

    def root(self):
        return self.tree[0] if self.size > 0 else None

    def left(self, index):
        left_index = 2 * index + 1
        return self.tree[left_index] if left_index < len(self.tree) else None

    def right(self, index):
        right_index = 2 * index + 2
        return self.tree[right_index] if right_index < len(self.tree) else None

    def parent(self, index):
        if index == 0:
            return None
        return self.tree[(index - 1) // 2]
    
    def search(self, value):
        for i in range(self.size):
            if self.tree[i] == value:
                return i
        return None

    def insert(self, value):
        if self.size >= len(self.tree):
            raise Exception("Tree is full")
        self.tree[self.size] = value
        self.size += 1

    def delete(self, value):
        target_idx = self.search(value)
        if target_idx is None:
            return False

        # 삭제할 노드를 마지막 노드와 교체하고 마지막 노드를 삭제
        self.tree[target_idx] = self.tree[self.size - 1]
        self.tree[self.size - 1] = None
        self.size -= 1
        return True

    def preorder(self, index=0):
        if index >= self.size or self.tree[index] is None:
            return
        print(self.tree[index], end=' ')
        self.preorder(2 * index + 1)
        self.preorder(2 * index + 2)

    def inorder(self, index=0):
        if index >= self.size or self.tree[index] is None:
            return
        self.inorder(2 * index + 1)
        print(self.tree[index], end=' ')
        self.inorder(2 * index + 2)

    def postorder(self, index=0):
        if index >= self.size or self.tree[index] is None:
            return
        self.postorder(2 * index + 1)
        self.postorder(2 * index + 2)
        print(self.tree[index], end=' ')

    def level_order(self):
        for i in range(self.size):
            print(self.tree[i], end=' ')
        print()

    def traversal_from_root(self):
        '''
        top-down traversal (finding children)
        '''
        i = 0
        n = len(self.tree)
        while i < n:
            if self.tree[i]:
                print(f"Parent: {self.tree[i]}", end = ", ")
                left = 2 * i + 1
                right = left + 1
                if left < n and self.tree[left] is not None:
                    print(f"Left: {self.tree[left]}", end = ", ")
                if right < n and self.tree[right] is not None:
                    print(f"Right: {self.tree[right]}", end = " ")
                print()
            i += 1

    def traversal_from_leaf(self):
        '''
        bottom-up traversal (finding parent)
        '''
        n = len(self.tree)
        i = n-1
        while i > 0:
            if self.tree[i]:
                print(f"Parent of {self.tree[i]} -> {self.tree[(i-1)//2]}")
            i -= 1



if __name__ == "__main__":
    # tree = ["A", "B", "C", "D", "E", "F", None, "G"]

    tree = ArrayBinaryTree(10)
    tree.insert(1)
    tree.insert(2)
    tree.insert(3)
    tree.insert(4)
    tree.insert(5)
    tree.insert(6)
    # tree.insert(7)

    print("Preorder traversal:")
    tree.preorder()
    print("\nInorder traversal:")
    tree.inorder()
    print("\nPostorder traversal:")
    tree.postorder()
    print("\nLevel-order traversal:")
    tree.level_order()

    print("\nSearching for 5:", "Found" if tree.search(5) is not None else "Not found")
    print("Deleting 3:", "Deleted" if tree.delete(3) else "Not found")
    print("\nLevel-order traversal after deletion:")
    tree.level_order()

    print("\nFinding children given parents.")
    tree.traversal_from_root()
    print("\nFinding parent given child.")
    tree.traversal_from_leaf()
