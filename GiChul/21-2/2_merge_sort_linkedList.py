"""
Q) Given the head (first node) of a singly linked list, sort the linked list in a descending order & return the head of the
sorted linked list.

- Run time needs to be <= O(N log N)    <- merge sort
- Memory space needs to be <= O(1)      <- in-place sorting
"""


class LinkedNode:
	def __init__(self, x):
		self.val = x
		self.next = None

def get_middle(head):
	"""
	2-point technique를 이용하여 linked list의 중간점 찾기 (fast가 끝까지 가면 slow는 중간에 가 있을 것)
	"""
	if head is None:
		return head
	
	slow = head
	fast = head.next

	while fast and fast.next:
		slow = slow.next        # 한 칸씩
		fast = fast.next.next   # 두 칸씩

	return slow
	
def merge(left,right):
	if not left:
		return right
	if not right:
		return left

	if left.val >= right.val:
		result = left
		result.next = merge(left.next, right)
	else:
		result = right
		result.next = merge(left, right.next)
	return result

def print_list(head):
	current = head
	while current:
		print(current.val, end=" -> ")
		current = current.next
	print("None")
	

def sortingLL(head):
	if (head is None) or (head.next is None):
		return head
	
	# Step 1: Split the linked list
	middle = get_middle(head)
	next_to_middle = middle.next
	middle.next = None                # head~middle, next_to_middle~end 이렇게 두 개로 나뉨

	# Step 2: Apply merge_sort on both halves
	left = sortingLL(head)
	right = sortingLL(next_to_middle)

	# Step 3: Merge the sorted halves
	sorted_list = merge(left, right)
	return sorted_list



if __name__ == "__main__":
	head = LinkedNode(2)
	head.next = LinkedNode(4)
	head.next.next = LinkedNode(1)
	head.next.next.next = LinkedNode(7)
	
	print("Original linked list:")
	print_list(head)

	head = sortingLL(head)

	print("Head of the new sorted linked list:", head.val)    # descending order
