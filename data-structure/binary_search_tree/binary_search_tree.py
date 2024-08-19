"""
keyword: BST, binary search tree, binary_search_tree


"""

class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert(self.root, key)

    def _insert(self, root, key):
        if key < root.data:
            if root.left is None:
                root.left = Node(key)
            else:
                self._insert(root.left, key)
        elif key > root.data:
            if root.right is None:
                root.right = Node(key)
            else:
                self._insert(root.right, key)
        else:   # 원래 트리에 존재하는 경우 중복을 허용하지 않으므로 아무 것도 하지 않음
            return
        
    def search(self, key):
        return self._search(self.root, key)
    
    def _search(self, root, key):
        if root is None or root.data == key:
            return root
        if key < root.data:
            return self._search(root.left, key)
        return self._search(root.right, key)
    
    def delete(self, key):
        self.root = self._delete(self.root, key)

    def _delete(self, root, key):
        if root is None:
            return root
        
        if key < root.data:
            root.left = self._delete(root.left, key)
        elif key > root.data:
            root.right = self._delete(root.right, key)
        else:   # 삭제할 노드를 찾음
            # 자식이 한쪽이라도 없는 경우 다른쪽 자식으로 이어주기만 하면 됨
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            # 자식이 둘다 있는 경우 successor를 찾아서 이 노드랑 바꾼 후 successor를 지우기
            temp = self._min_value_node(root.right)
            root.data = temp.data
            root.right = self._delete(root.right, temp.data)

        return root
    
    def _min_value_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    def inorder(self):
    # BST의 키 값들을 오름차순으로 출력
        self._inorder(self.root)
    
    def _inorder(self, root):
        if root:
            self._inorder(root.left)
            print(root.data, end = " ")
            self._inorder(root.right)

    ## 추가 유용할 수도 있는 메소드
    def find_min(self):
        return self._min_value_node(self.root).data if self.root else None
    
    def find_max(self):
        current = self.root
        while current and current.right:
            current = current.right
        return current.data if current else None
    
    def height(self):
    # 트리의 높이를 계산
        return self._height(self.root)

    def _height(self, root):
        if root is None:
            return 0
        left_height = self._height(root.left)
        right_height = self._height(root.right)
        return 1 + max(left_height, right_height)
    
    def count_nodes(self):
    # 트리 내 노드 수 계산
        return self._count_nodes(self.root)

    def _count_nodes(self, root):
        if root is None:
            return 0
        return 1 + self._count_nodes(root.left) + self._count_nodes(root.right)

    def print_given_level(self, level):
    # 주어진 레벨에 해당되는 노드들 출력
        self._print_given_level(self.root, level)

    def _print_given_level(self, root, level):
        if root is None:
            return
        if level == 1:
            print(root.data, end = " ")
        elif level > 1:
            self._print_given_level(root.left, level-1)
            self._print_given_level(root.right, level-1)

if __name__ == "__main__":
    bst = BinarySearchTree()

    # 노드 삽입
    bst.insert(50)
    bst.insert(30)
    bst.insert(20)
    bst.insert(40)
    bst.insert(70)
    bst.insert(60)
    bst.insert(80)

    # Inorder traversal 출력
    print("Inorder traversal of the BST:")
    bst.inorder()
    print()

    # 특정 값 검색
    print("\nSearch for 40 in the BST:")
    node = bst.search(40)
    if node:
        print("Node found:", node.data)
    else:
        print("Node not found")

    # 노드 삭제
    print("\nDelete 20 from the BST")
    bst.delete(20)
    print("Inorder traversal after deleting 20:")
    bst.inorder()
    print()

    print("\nDelete 30 from the BST")
    bst.delete(30)
    print("Inorder traversal after deleting 30:")
    bst.inorder()
    print()

    print("\nDelete 50 from the BST")
    bst.delete(50)
    print("Inorder traversal after deleting 50:")
    bst.inorder()
    print()

    print("Minimum value:", bst.find_min())
    print("Maximum value:", bst.find_max())

    # 트리의 높이 출력
    print("Height of the tree:", bst.height())

    # 노드 개수 출력
    print("Total nodes in the tree:", bst.count_nodes())

    # 특정 레벨의 노드 출력
    level = 1
    print(f"Nodes at level {level}: ", end="")
    bst.print_given_level(level)
    print()
    
    level = 2
    print(f"Nodes at level {level}: ", end="")
    bst.print_given_level(level)
    print()

    level = 3
    print(f"Nodes at level {level}: ", end="")
    bst.print_given_level(level)
    print()

