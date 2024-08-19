"""
keyword: red black tree, rb tree, redblacktree, red_black_tree, rbt

"""

class Node:
    def __init__(self, data, color="red"):
        self.data = data
        assert color in ["red", "black"]
        self.color = color  # "red" or "black"
        self.left = None
        self.right = None
        self.parent = None


class RedBlackTree:
    def __init__(self):
        self.NIL = Node(data=None, color="black")
        self.root = self.NIL

    def insert(self, data):
        # 새로운 노드 만듦
        new_node = Node(data)
        new_node.left = self.NIL
        new_node.right = self.NIL

        # parent는 삽입할 위치 (리프 노드)
        parent = None
        current = self.root

        while current != self.NIL:
            parent = current
            if new_node.data < current.data:
                current = current.left
            else:
                current = current.right

        # 우선 삽입
        new_node.parent = parent
        if parent is None:
            self.root = new_node
        elif new_node.data < parent.data:
            parent.left = new_node
        else:
            parent.right = new_node

        new_node.color = "red"  # 항상 빨강으로 삽입
        # RB 특성에 맞도록 수정
        self.fix_insert(new_node)

    def fix_insert(self, node):
        # 부모가 red인 경우 red-red 충돌 해소
        while node != self.root and node.parent.color == "red":
            # 부모가 왼쪽 자식인 경우
            if node.parent == node.parent.parent.left:
                uncle = node.parent.parent.right
                # 삼촌이 red면 recoloring!
                if uncle.color == "red":
                    node.parent.color = "black"
                    uncle.color = "black"
                    node.parent.parent.color = "red"
                    node = node.parent.parent
                # 삼촌이 black이면 restructuring!
                else:
                    # 노드가 오른쪽 자식이면 부모 기준으로 left rotate 수행, 노드가 왼쪽 자식이면 그대로
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)
                    # 부모는 검정, 조상은 빨강이 되어야 함
                    node.parent.color = "black"
                    node.parent.parent.color = "red"
                    # 조상 기준으로 right rotate
                    self.right_rotate(node.parent.parent)
            else:
                # 부모가 오른쪽 자식인 경우도 동일
                uncle = node.parent.parent.left
                # 삼촌이 red이면 recoloring!
                if uncle.color == "red":
                    node.parent.color = "black"
                    uncle.color = "black"
                    node.parent.parent.color = "red"
                    node = node.parent.parent
                # 삼촌이 black이면 restructuring!
                else:
                    # 현재 노드가 부모의 왼쪽 자식일 경우 right rotate 수행
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)
                    # 부모는 검정, 조상은 빨강이 되어야 함
                    node.parent.color = "black"
                    node.parent.parent.color = "red"
                    # 조상 기준으로 left rotate
                    self.left_rotate(node.parent.parent)
        # 항상 root는 검정 유지
        self.root.color = "black"

    def left_rotate(self, x):
        """
                |               |      
                x               y
               / \             / \
              a   y     ->    x   c
                 / \         / \
                b   c       a   b
        """
        y = x.right
        x.right = y.left
        if y.left != self.NIL:
            y.left.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y

        y.left = x
        x.parent = y

    def right_rotate(self, y):
        """
                |               |      
                x               y
               / \             / \
              y   a     ->    b   x
             / \                 / \
            b   c               c   a
        """
        x = y.left
        y.left = x.right
        if x.right != self.NIL:
            x.right.parent = y

        x.parent = y.parent
        if y.parent is None:
            self.root = x
        elif y == y.parent.right:
            y.parent.right = x
        else:
            y.parent.left = x

        x.right = y
        y.parent = x

    def search(self, data):
        """
        BST와 완벽히 동일함
        """
        current = self.root
        while current != self.NIL:
            if data == current.data:
                return current
            elif data < current.data:
                current = current.left
            else:
                current = current.right
        return None
    
    def delete(self, data):
        # 삭제할 노드를 찾음
        node = self.search(data)
        if node is None:
            return  # 트리에 없는 경우

        # y_original_color: 삭제할 노드의 색 (검정인 경우만 나중에 fix)
        # x: 대체된 노드; fix가 필요한 경우 대체된 노드 x를 기준으로 수정하게 됨
        # y: 삭제될 노드
        y_original_color = node.color
        # 여기는 BST의 삭제 원리와 동일
        if node.left == self.NIL:
            x = node.right
            self._rb_transplant(node, node.right)   # 단순히 node.right를 node의 부모에 붙이는 작업
        elif node.right == self.NIL:
            x = node.left
            self._rb_transplant(node, node.left)
        else:
            y = self._minimum(node.right)
            y_original_color = y.color  # successor를 찾아서 대체하는 경우 삭제할 노드의 색은 successor의 색이 됨!
            x = y.right
            if y.parent == node:   
                x.parent = y
            else:
                self._rb_transplant(y, y.right)
                y.right = node.right
                y.right.parent = y

            self._rb_transplant(node, y)
            y.left = node.left
            y.left.parent = y
            y.color = node.color
            # successor가 삭제된 node의 자리에 들어감
            # y: successor
            # x: successor의 오른쪽 자식! (을 기준으로 뒤에서 수정)

        if y_original_color == "black":
            self.fix_delete(x)

    def _minimum(self, node):
        # node를 루트로 하는 서브트리의 최솟값 찾기
        while node.left != self.NIL:
            node = node.left
        return node

    def _rb_transplant(self, u, v):
        # u의 부모에 v를 붙이기
        if u.parent is None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        v.parent = u.parent

    def fix_delete(self, x):
        # x: 삭제된 노드를 대체하는 노드 혹은 successor의 오른쪽 자식
        while x != self.root and x.color == "black":
            if x == x.parent.left:
                w = x.parent.right
                if w.color == "red":
                    w.color = "black"
                    x.parent.color = "red"
                    self.left_rotate(x.parent)
                    w = x.parent.right
                if w.left.color == "black" and w.right.color == "black":
                    w.color = "red"
                    x = x.parent
                else:
                    if w.right.color == "black":
                        w.left.color = "black"
                        w.color = "red"
                        self.right_rotate(w)
                        w = x.parent.right
                    w.color = x.parent.color
                    x.parent.color = "black"
                    w.right.color = "black"
                    self.left_rotate(x.parent)
                    x = self.root
            else:
                w = x.parent.left
                if w.color == "red":
                    w.color = "black"
                    x.parent.color = "red"
                    self.right_rotate(x.parent)
                    w = x.parent.left
                if w.left.color == "black" and w.right.color == "black":
                    w.color = "red"
                    x = x.parent
                else:
                    if w.left.color == "black":
                        w.right.color = "black"
                        w.color = "red"
                        self.left_rotate(w)
                        w = x.parent.left
                    w.color = x.parent.color
                    x.parent.color = "black"
                    w.left.color = "black"
                    self.right_rotate(x.parent)
                    x = self.root
        x.color = "black"

    def inorder_traversal(self, node):
        """
        트리의 키 값들을 오름차순으로 가져옴
        결국 BST니까 그냥 inorder traverse 하면 됨
        """
        result = []
        if node != self.NIL:
            result = self.inorder_traversal(node.left)
            result.append(node.data)
            result = result + self.inorder_traversal(node.right)
        return result


# 사용 예제
if __name__ == "__main__":
    rbt = RedBlackTree()
    rbt.insert(10)
    rbt.insert(20)
    rbt.insert(30)
    rbt.insert(15)
    rbt.insert(25)
    rbt.insert(5)

    print("Inorder Traversal of the tree:")
    print(rbt.inorder_traversal(rbt.root))

    search_result = rbt.search(15)
    if search_result:
        print(f"Node with data {search_result.data} found with color {search_result.color}")
    else:
        print("Node not found")