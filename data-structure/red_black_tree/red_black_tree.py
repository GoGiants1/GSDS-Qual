"""
- keyword: red black tree, rb tree, redblacktree, red_black_tree, rbt
- functions: left_rotate, right_rotate, search, insert, delete, inorder_traversal

조건
1. 모든 노드는 red/black의 색을 갖는다
2. 루트 노드는 항상 black이다
**3**. 모든 NIL 노드는 black이다 (= null은 black으로 간주한다)
4. 모든 red는 black 자식을 갖는다 (= red가 red의 부모가 될 수 없다)
**5**. 임의의 노드에서 출발하는 모든 경로는 모두 같은 수의 black 노드가 존재한다

"""

class Node:
	def __init__(self, data, color="red"):
		self.data = data
		assert color in ["red", "black"]
		self.color = color     # "red" or "black"
		self.left = None
		self.right = None
		self.parent = None


class RedBlackTree:
	def __init__(self):
		self.NIL = Node(data=None, color="black")
		self.root = self.NIL

	def left_rotate(self, x):
		"""
		왼쪽 subtree에 black 추가할 때
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
		오른쪽 subtree에 black 추가할 때
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

	def insert(self, data):
		"""
		새로운 노드 삽입: 항상 red로 추가
		"""
		new_node = Node(data)
		new_node.left = self.NIL
		new_node.right = self.NIL

		parent = None       # 최종적으로 삽입할 위치를 가리킬 것 (NIL을 제외한 리프 노드)
		current = self.root

		while current != self.NIL:
			parent = current
			if current.data > new_node.data:
				current = current.left
			else:
				current = current.right

		# 우선 삽입
		new_node.parent = parent    
		if parent is None:      # 빈 트리일 때
			self.root = new_node
		elif parent.data > new_node.data:
			parent.left = new_node
		else:
			parent.right = new_node

		new_node.color = "red"
		self.fix_insert(new_node)


	def fix_insert(self, node):
		"""
		red-red 충돌 시 삼촌 색 확인
		1) 삼촌의 색이 red: 조부모에게 red를 모아서 올려줌, 부모/삼촌은 black (Recolor)
		2) 삼촌의 색이 black: 회전을 통해 해결 (Restructure)
		"""
		while node != self.root and node.parent.color == "red":      # red-red 충돌
			if node.parent == node.parent.parent.left:   
				'''부모가 왼쪽 자식'''
				uncle = node.parent.parent.right
				if uncle.color == "red":       # 1) 삼촌 red
					node.parent.parent.color = "red"
					node.parent.color = "black"
					uncle.color = "black"
					node = node.parent.parent                 # 위로 타고 올라가며 충돌 계속 resolve해야 함
				else:   # 2) 삼촌 black
					"""
					부모 red, 삼촌 black, 새 노드 red
					1) 부모 기준 left rotate    <- 새 노드가 오른쪽 자식일 때만  
					2) 부모 노드 black 처리, 조부모 red 처리
					3) 조부모 기준 right rotate
					"""
					if node == node.parent.right:     
						node = node.parent      # '부모 기준'이니까 node에 부모 일단 넣어줌
						self.left_rotate(node)
					node.parent.color = "black"
					node.parent.parent.color = "red"
					self.right_rotate(node.parent.parent)
			else:
				''' 부모가 오른쪽 자식'''
				uncle = node.parent.parent.left
				if uncle.color == "red":   
					node.parent.parent.color = "red"
					node.parent.color = "black"
					uncle.color = "black"
					node = node.parent.parent
				else:
					"""
					부모 red, 삼촌 black, 새 노드 red
					1) 부모 기준 right rotate    <- 새 노드가 왼쪽 자식일 때만  
					2) 부모 노드 black 처리, 조부모 red 처리
					3) 조부모 기준 left rotate
					"""
					if node == node.parent.left:
						node = node.parent
						self.right_rotate(node)
					node.parent.color = "black"
					node.parent.parent.color = "red"
					self.left_rotate(node.parent.parent)
		self.root.color = "black"             # 항상 root는 검정 유지

	
	def delete(self, data):
		"""
		노드 삭제: 타겟이 red일 경우 그대로 삭제
		"""
		node = self.search(data)   # 삭제할 노드를 찾기
		if node is None:
			return    # 트리에 없으면 return

		target_color = node.color   # 삭제할 노드의 색 (fix 여부 판단할 값)
		
		'''삭제 자체는 BST delete 원리와 동일 (x: 삭제된 노드 자리를 대체하는 애)'''
		if node.left == self.NIL:     # 오른쪽 자식만 있을 때
			x = node.right
			self.__rb_transplant(node, node.right)  
		elif node.right == self.NIL:  # 왼쪽 자식만 있을 때
			x = node.left
			self.__rb_transplant(node, node.left)
		else:
			successor = self.__min_value_node(node.right)    # 삭제될 노드 대체할 애 (얘도 삭제되거나 이동됨)
			target_color = successor.color                   # successor가 red였으면 이동 후 black 처리만 해주면 black 개수 안 바뀜. but, black이었으면 얘를 옮김으로써 black 개수에 변화가 생겼을테니 fix 필요
			x = successor.right                              # successor가 이동한 뒤에 successor 자리를 대체할 애

			if successor.parent == node:    
				x.parent = successor      # x의 조부모가 삭제될 애라면 successor와의 부모-자식 관계 유지
			else:
				self._rb_transplant(successor, successor.right)     # successor 먼저 이동/삭제
				# 기존 노드의 '오른쪽 자식'과 부모-자식 관계 체결
				successor.right = node.right         
				successor.right.parent = successor   
			
			# 기존 노드의 '부모'와 부모-자식 관계 체결
			self._rb_transplant(node, successor)
			# 기존 노드의 '왼쪽 자식'과 부모-자식 관계 체결
			successor.left = node.left
			successor.left.parent = successor

			successor.color = node.color             # 색상 유지
	
		if target_color == "black":
			self.fix_delete(x)

	def __min_value_node(self, node):    
		"""
		Successor 찾기
		"""
		current = node
		while current.left is not None:
			current = current.left
		return current

	def __rb_transplant(self, u, v):
		"""
		u 노드의 부모에 v를 이어붙이기 (u = 삭제될 노드)
		"""
		if u.parent is None:   # u가 root였을 때
			self.root = v
		elif u == u.parent.left:
			u.parent.left = v
		else:
			u.parent.right = v
		v.parent = u.parent

	def fix_delete(self, x):
		"""
		타겟이 black일 경우 black 1개 추가 필요 (5번 조건 만족)
		1) w가 red:
			1. x의 부모 red로, w black으로 recolor
			2. x의 부모 기준으로 left rotate
			
			** 새로운 형제가 black, 부모가 red가 됨 -> case 2,3,4로 넘어갈 수 있음
		2) w가 black, 조카 모두 black:
			- x의 부모가 red: black으로
			- x의 부모가 black:
				1. w를 red로
				2. x의 부모를 새로운 x로 만듦
		3) w가 black, 왼쪽 조카 red, 오른쪽 조카 black
			1. 왼쪽 조카 black으로, w red로 recolor 
			2. w 기준 right rotate -> case 4
		4) w가 black, 오른쪽 조카가 red
			1. x의 부모 black으로, 오른쪽 조카도 black으로, w는 부모 색 물려받기
			2. x의 부모 기준 left rotate

		** x: 삭제된 노드를 대체한 노드 (현재 target 위치에 있어 fix의 기준점이 됨)
		** w: 형제 노드
		"""
		while x != self.root and x.color == "black":
			if x == x.parent.left:       # 타겟이 왼쪽 자식일 때
				w = x.parent.right
				if w.color == "red":                    # CASE 1
					w.color = "black"
					x.parent.color = "red"
					self.left_rotate(x.parent)
					w = x.parent.right       # new w
				
				if w.left.color == "black" and w.right.color == "black":    # CASE 2
					w.color = "red"
					x = x.parent
				else:
					if w.right.color == "black":        # CASE 3
						w.left.color = "black"
						w.color = "red"
						self.right_rotate(w)
						w = x.parent.right      # new w (원래 w의 왼쪽 조카였음, 원래 red)
					
					x.parent.color = "black"            # CASE 4
					w.right.color = "black"
					w.color = x.parent.color    # left rotate 되면서 얘가 부모가 됨. 부모의 색깔 미리 물려받기
					self.left_rotate(x.parent)
					x = self.root     # 계속 위로 타고 올라감
			else:     # 타겟이 오른쪽 자식일 때
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

					x.parent.color = "black"
					w.left.color = "black"
					w.color = x.parent.color
					self.right_rotate(x.parent)
					x = self.root

		x.color = "black"    # 최종 루트는 black으로 유지

	def inorder_traversal(self, node):
		"""
		트리의 키 값들을 오름차순으로 가져오기 (단순 출력 말고 list 반환)
		** 단순 출력은 BST에 있음

		처음 코드 작동 원리:
			1. 왼쪽 아래로 내려가다 끝을 만나면 빈 리스트 반환   (result = [])
			2. 자기 값 더함  (result = [A])
			3. 오른쪽 아래로 내려가다 끝을 만나면 빈 리스트 반환 (result = [A] + [] = [A])
		
		이후:
			1. 왼쪽으로 내려가다 만난 부모 노드로 다시 올라가서
			2. 자기 값 더하고
			3. 오른쪽으로 내려가고 반복
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