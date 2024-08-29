"""
- keyword: binary_tree with linked_list
- functions: search, insert, delete, DFT traversal, BFT traversal

** BST와의 차이점: 왼쪽 노드가 반드시 작거나 오른쪽 노드가 반드시 크지 않음
** bottom up traversal 난이도 있음
"""

class TreeNode():
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Tree():
    def __init__(self):
        self.root = None
        self.top_down = True      # top down : recursive version // bottom up : loop version

    def preorder(self):
        """
        DFT Traversal: preorder
        """
        def _preorder_top_down(node):
            if node is None:
                return
            res.append(node.val)
            _preorder_top_down(node.left)
            _preorder_top_down(node.right)

        def _preorder_bottom_up(node):
            if node is None:
                return
            
            stack = [node]

            while stack:
                node = stack.pop()
                if node:
                    res.append(node.val)
                    if node.right:
                        stack.append(node.right)
                    if node.left:   # !! right -> left 순서로 넣어야 스택에서 preorder 유지됨
                        stack.append(node.left)
            return
            
        res = []
        if self.top_down:
            _preorder_top_down(self.root)
        else:
            _preorder_bottom_up(self.root)
        return res

    def inorder(self):
        """
        DFT Traversal: inorder
        """
        def _inorder_top_down(node):
            if node is None:
                return
            _inorder_top_down(node.left)
            res.append(node.val)
            _inorder_top_down(node.right)

        def _inorder_bottom_up(node):
            if node is None:
                return
            
            stack = []
            current = node
            
            while stack or current:
                # 가장 왼쪽 노드까지 탐색
                while current:
                    stack.append(current)   # 탐색하면서 만난 노드들은 다 스택에 넣어두어야 함 (나중에 부모 방문해야 하므로)
                    current = current.left
                
                # 스택에서 노드를 꺼내서 방문
                current = stack.pop()
                res.append(current.val)
                
                # 오른쪽 서브트리를 탐색
                current = current.right
            return

        res = []
        if self.top_down:
            _inorder_top_down(self.root)
        else:
            _inorder_bottom_up(self.root)
        return res

    def postorder(self):
        """
        DFT Traversal: postorder
        """
        def _postorder_top_down(node):
            if node is None:
                return
            _postorder_top_down(node.left)
            _postorder_top_down(node.right)
            res.append(node.val)

        def _postorder_bottom_up(node):
            if node is None:
                return

            stack = []
            current = node
            
            while stack or current:
                # 가장 왼쪽 노드까지 탐색
                while current:
                    stack.append(current)   # 탐색하면서 만난 노드들은 다 스택에 넣어두어야 함 (나중에 부모 방문해야 하므로)
                    current = current.left
                
                current = stack.pop()

                # 현재 노드에 오른쪽 자식이 있는 경우
                if current.right and (not res or res[-1] != current.right.val):     # list가 비어 있거나 이미 방문하지 않았다면
                    stack.append(current)      # 현재 노드 다시 stack에 추가 (오른쪽 먼저 방문해야 하므로)
                    current = current.right    # 오른쪽 자식으로 이동
                else:       # 오른쪽 서브트리가 없는 경우 현재 노드 방문
                    res.append(current.val)
                    current = None
            return

        res = []
        if self.top_down:
            _postorder_top_down(self.root)
        else:
            _postorder_bottom_up(self.root)
        return res
    
    def levelorder(self):
        """
        BFT Traversal: levelorder
        """
        def _level_order_top_down(node, level):
            if node is None:
                return
        
            # len(res): sublist의 개수로 지금까지 방문한 레벨의 수를 나타냄
            # if len(res) == level: 현재 레벨에 해당하는 sublist가 아직 생성되지 않았다는 뜻
            if len(res) == level:      
                res.append([])
             
            res[level].append(node.val)

            _level_order_top_down(node.left, level+1)
            _level_order_top_down(node.right, level+1)

        def _level_order_bottom_up(node):
            if node is None:
                return
            
            queue = [node]

            while queue:
                current = queue.pop(0)
                res.append(current.val)
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
            return

        res = []
        if self.top_down:
            _level_order_top_down(self.root, 0)
            res = [d for sublist in res for d in sublist]      # sublist = level별 리스트
        else:
            _level_order_bottom_up(self.root)
        return res
    
    def search(self, x):
        """
        BFS로 traverse하면서 해당 값을 가진 노드를 찾음
        """
        if self.root is None:
            return None
        
        queue = [self.root]
        while queue:
            node = queue.pop(0)
            if node.val == x:
                return node
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return None
    

    def insert(self, x):
        """
        BFS로 traverse하면서 자식이 비어있는 노드에 붙임
        """
        new_node = TreeNode(x)
        if self.root is None:
            self.root = new_node
        else:
            queue = [self.root]
            while queue:
                node = queue.pop(0)
                if not node.left:
                    node.left = new_node
                    break
                else:
                    queue.append(node.left)

                if not node.right:
                    node.right = new_node
                    break
                else:
                    queue.append(node.right)
    

    def delete(self, x):
        """
        1. BFS로 traverse하면서 해당 값을 가진 노드를 찾음
        2. deepest node와 교체
        3. deepest node를 삭제
        """
        if self.root is None:
            return None

        queue = [self.root]
        target_node = None
        last_node = None      # 가장 마지막에 만나는 leaf node

        while queue:
            last_node = queue.pop(0)
            if last_node.val == x:
                target_node = last_node    # search와 동일, 삭제할 노드를 찾아서 target_node에 넣음; BFS 멈추지 않고 leaf node까지 도달
            if last_node.left:
                queue.append(last_node.left)
            if last_node.right:
                queue.append(last_node.right)

        if target_node:
            target_node.val = last_node.val
            self.__delete_deepest(last_node)

    def __delete_deepest(self, last_node):
        """
        last node 삭제
        """
        queue = [self.root]
        while queue:
            node = queue.pop(0)
            if node is last_node:
                node = None
                return
            if node.right:
                if node.right is last_node:
                    node.right = None
                    return
                else:
                    queue.append(node.right)
            if node.left:
                if node.left is last_node:
                    node.left = None
                    return
                else:
                    queue.append(node.left)


if __name__ == "__main__":
    tree = Tree()
    tree.root = TreeNode("A")
    tree.root.left = TreeNode("B")
    tree.root.right = TreeNode("C")
    tree.root.left.left = TreeNode("D")
    tree.root.left.right = TreeNode("E")
    tree.root.right.left = TreeNode("F")
    tree.root.left.left.left = TreeNode("G")
    tree.root.left.left.left.right = TreeNode("H")

    #           A
    #         /   \
    #        B     C
    #      /  \   /
    #     D    E F
    #    /
    #   G
    #    \
    #     H

    print("=====Traversal=====")
    print("Preorder: ", tree.preorder())
    print("Inorder: ", tree.inorder())
    print("Postorder: ", tree.postorder())
    print("Levelorder: ", tree.levelorder())

    print("\nShifting implementation to bottom_up")
    tree.top_down = False
    print("Preorder: ", tree.preorder())
    print("Inorder: ", tree.inorder())
    print("Postorder: ", tree.postorder())
    print("Levelorder: ", tree.levelorder())

    print("\n=====Manipulation=====")
    tree.insert("I")
    print("Insert I: ", tree.levelorder())
    print("Search B: ", tree.search("B").val)
    tree.delete("B")
    print("Delete B: ", tree.levelorder())
    print("Search B: ", tree.search("B"))

