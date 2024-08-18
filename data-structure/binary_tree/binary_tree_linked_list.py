"""
implementation of binary_tree with linked_list

bottom up traversal은 꽤나 헷갈리므로 스스로 짜보는 것을 추천 ..
"""

class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None
        self.top_down = True # top down : recursive version // bottom up : loop version

    # Traversal
    def preorder(self):
        def _preorder_top_down(node):
            if node is None:
                return
            res.append(node.data)
            _preorder_top_down(node.left)
            _preorder_top_down(node.right)

        def _preorder_bottom_up(node):
            if node is None:
                return
            
            stack = [node]

            while stack:
                node = stack.pop()
                if node:
                    res.append(node.data)
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
        def _inorder_top_down(node):
            if node is None:
                return
            _inorder_top_down(node.left)
            res.append(node.data)
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
                res.append(current.data)
                
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
        def _postorder_top_down(node):
            if node is None:
                return
            _postorder_top_down(node.left)
            _postorder_top_down(node.right)
            res.append(node.data)

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
                
                current = stack.pop()   # 왼쪽 자식이 없는 가장 왼쪽 노드

                # 현재 노드에 오른쪽 자식이 있는 경우
                if current.right and (not res or res[-1] != current.right.data):
                    stack.append(current)  # 현재 노드보다 오른쪽 서브트리를 먼저 방문해야 함
                    current = current.right  # 오른쪽 자식으로 이동
                else:   # 오른쪽 서브트리가 없는 경우 현재 노드 방문
                    res.append(current.data)
                    current = None
    
            return

        res = []
        if self.top_down:
            _postorder_top_down(self.root)
        else:
            _postorder_bottom_up(self.root)
        return res
    
    def levelorder(self):
        def _level_order_top_down(node, level):
            if node is None:
                return

            if len(res) == level:
                res.append([])
            
            res[level].append(node.data)

            _level_order_top_down(node.left, level+1)
            _level_order_top_down(node.right, level+1)

        def _level_order_bottom_up(node):
            # from collections import deque

            if node is None:
                return
            
            # queue = deque([node])     # queue 자료구조 써도 되고 list를 queue처럼 써도 됨
            queue = [node]

            while(queue):
                # current = queue.popleft()
                current = queue.pop(0)
                res.append(current.data)
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
            return

        res = []
        if self.top_down:
            _level_order_top_down(self.root, 0)
            res = [d for sublist in res for d in sublist]
        else:
            _level_order_bottom_up(self.root)

        return res
    

    def insert(self, key):
        """
        BFS로 traverse하면서 자식이 비어있는 노드에 붙임
        """
        new_node = Node(key)
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
    
    def search(self, key):
        """
        BFS로 traverse하면서 해당 값을 가진 노드를 찾음
        """
        if self.root is None:
            return None
        queue = [self.root]
        while queue:
            node = queue.pop(0)
            if node.data == key:
                return node
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return None

    def delete(self, key):
        """
        1. BFS로 traverse하면서 해당 값을 가진 노드를 찾음
        2. deepest node와 교체
        3. deepest node를 삭제
        """
        if self.root is None:
            return None

        queue = [self.root]
        key_node = None
        last_node = None

        while queue:
            last_node = queue.pop(0)
            if last_node.data == key:
                key_node = last_node    # search와 동일, 삭제할 노드를 찾아서 key_node에 넣음; BFS 멈추지 않고 leaf node까지 도달
            if last_node.left:
                queue.append(last_node.left)
            if last_node.right:
                queue.append(last_node.right)
            # last_node: bfs에서 가장 마지막에 처리되는 노드; leaf node

        if key_node:
            key_node.data = last_node.data
            self._delete_deepest(last_node)

    def _delete_deepest(self, d_node):
        """
        leaf node 삭제
        """
        queue = [self.root]
        while queue:
            node = queue.pop(0)
            if node is d_node:
                node = None
                return
            if node.right:
                if node.right is d_node:
                    node.right = None
                    return
                else:
                    queue.append(node.right)
            if node.left:
                if node.left is d_node:
                    node.left = None
                    return
                else:
                    queue.append(node.left)


if __name__ == "__main__":
    tree = Tree()
    tree.root = Node("A")
    tree.root.left = Node("B")
    tree.root.right = Node("C")
    tree.root.left.left = Node("D")
    tree.root.left.right = Node("E")
    tree.root.right.left = Node("F")
    tree.root.left.left.left = Node("G")
    tree.root.left.left.left.right = Node("H")

    #           A
    #         /   \
    #        B     C
    #      /  \   /
    #     D    E F
    #    /
    #   G
    #    \
    #     H

    # Traversal
    print("=====Traversal=====")
    print("Preorder: ", tree.preorder())
    print("Inorder: ", tree.inorder())
    print("Postorder: ", tree.postorder())
    print("Levelorder: ", tree.levelorder())

    print("shifting implementation to bottom_up")
    tree.top_down = False
    print("Preorder: ", tree.preorder())
    print("Inorder: ", tree.inorder())
    print("Postorder: ", tree.postorder())
    print("Levelorder: ", tree.levelorder())

    print("=====Manipulation=====")
    tree.insert("I")
    print("Insert I: ", tree.levelorder())
    print("Search B: ", tree.search("B").data)
    tree.delete("B")
    print("Delete B: ", tree.levelorder())
    print("Search B: ", tree.search("B"))

