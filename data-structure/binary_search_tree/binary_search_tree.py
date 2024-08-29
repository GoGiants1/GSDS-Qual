"""
- keyword: BST, binary search tree, binary_search_tree
- functions: search, insert, delete, inorder(sort), find_min, find_max, height, count_nodes, print_given_level
"""

class TreeNode():
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
		
class BST():
	def __init__(self):
		self.root = None

	def __searchHelp(self,curNode,x):
		if not curNode:
			return None
		if x == curNode.val:
			return curNode
		elif x < curNode.val:
			return self.__searchHelp(curNode.left,x)
		else:
			return self.__searchHelp(curNode.right,x)
		
	def search(self,x):
		return self.__searchHelp(self.root,x)
	
	def __insertHelp(self,curNode,x):
		if not curNode:
			return TreeNode(x)
		if x < curNode.val:
			curNode.left = self.__insertHelp(curNode.left,x)   # 가지를 연결해줘야 함
		elif x > curNode.val:
			curNode.right = self.__insertHelp(curNode.right,x)
		return curNode
			
	def insert(self,x):
		self.root = self.__insertHelp(self.root,x)

	def __deleteHelp(self, root, x):
		if root is None:
			return root
		if x < root.val:
			root.left = self.__deleteHelp(root.left, x)
		elif x > root.val:
			root.right = self.__deleteHelp(root.right, x)
		else:   # found target node
			
			# One child: 자식을 return 해서 자기 부모랑 이어줌
			if root.left is None:
				return root.right
			elif root.right is None:
				return root.left
			
			# Two child: successor를 찾아서 값 바꾼 후 successor 지우기
			temp = self.__min_value_node(root.right)  # 오른쪽 sub-tree에서 제일 큰 값
			root.val = temp.val
			root.right = self.__deleteHelp(root.right, temp.val)

		return root

	def __min_value_node(self, node):    
		current = node
		while current.left is not None:
			current = current.left
		return current
	
	def delete(self,x):
		self.root = self.__deleteHelp(self.root, x)
	
	
	def __inorderHelp(self, curNode):
		"""
		BST의 키 값들을 오름차순으로 출력
		"""
		if curNode:
			self.__inorderHelp(curNode.left)
			print(curNode.val, end = " ")
			self.__inorderHelp(curNode.right)

	def inorder(self):
		self.__inorderHelp(self.root)
	
	
	def find_min(self):
		"""
		최솟값 찾기
		"""
		return self.__min_value_node(self.root).val if self.root else None
	
	def find_max(self):
		"""
		최댓값 찾기
		"""
		current = self.root
		while current and current.right:
			current = current.right
		return current.val if current else None

	def height(self):
		"""
		트리 높이 계산하기기
		"""
		return self.__height(self.root)
	
	def __height(self, curNode):
		if curNode is None:
			return 0
		left_height = self.__height(curNode.left)
		right_height = self.__height(curNode.right)
		return 1 + max(left_height, right_height)

	def count_nodes(self):
		"""
		트리 내 노드 수 계산
		"""
		return self.__count_nodes(self.root)

	def __count_nodes(self, root):
		if root is None:
			return 0
		return 1 + self.__count_nodes(root.left) + self.__count_nodes(root.right)

	def print_given_level(self, level):
		"""
		주어진 레벨에 해당되는 노드들 출력
		"""
		self.__print_given_level(self.root, level)

	def __print_given_level(self, root, level):
		if root is None:
			return
		if level == 1:    # 원하는 레벨에 도착
			print(root.val, end = " ")
		elif level > 1:
			self.__print_given_level(root.left, level-1)     # 루트 노드에서 시작, 한 단계씩 내려감
			self.__print_given_level(root.right, level-1)


	

if __name__ == "__main__":
	bst = BST()

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
		print("Node found:", node.val)
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

	print("\nMinimum value:", bst.find_min())
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

