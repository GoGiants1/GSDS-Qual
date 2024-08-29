class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.parent = None

class MaxHeap:
    def __init__(self):
        self.root = None
        self.heapsize = 0

    def get_max(self):
        return self.root

    def print_heap(self):
        if not self.root:
            return
        
        queue = [self.root]
        print("MaxHeap:", end=" ")
        while queue:
            node = queue.pop(0)
            print(node.val, end=" ")
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        print()

    def swap(self, a, b):
        a.val, b.val = b.val, a.val

    def enqueue(self, k):
        new_node = Node(k)
        if not self.root:
            self.root = new_node
        else:
            path = self.heapsize + 1
            current = self.root
            for shift in range((path.bit_length() - 2), 0, -1):
                if path & (1 << shift):
                    current = current.right
                else:
                    current = current.left
            if path & 1:
                current.right = new_node
            else:
                current.left = new_node
            new_node.parent = current

            # Heapify up
            while new_node.parent and new_node.val > new_node.parent.val:
                self.swap(new_node, new_node.parent)
                new_node = new_node.parent
        self.heapsize += 1

    def dequeue(self):
        if not self.root:
            return
        if self.heapsize == 1:
            self.root = None
        else:
            # Find the last node
            path = self.heapsize
            current = self.root
            for shift in range((path.bit_length() - 2), 0, -1):
                if path & (1 << shift):
                    current = current.right
                else:
                    current = current.left

            # Replace root value with last node value and remove the last node
            if path & 1:
                last_node = current.right
                current.right = None
            else:
                last_node = current.left
                current.left = None

            self.root.val = last_node.val

            # Heapify down
            node = self.root
            while True:
                largest = node
                if node.left and node.left.val > largest.val:
                    largest = node.left
                if node.right and node.right.val > largest.val:
                    largest = node.right
                if largest != node:
                    self.swap(node, largest)
                    node = largest
                else:
                    break
        self.heapsize -= 1

# MaxHeap 테스트
max_heap = MaxHeap()
max_heap.enqueue(3)
max_heap.enqueue(2)
max_heap.enqueue(1)
max_heap.enqueue(15)
max_heap.enqueue(5)
max_heap.enqueue(4)
max_heap.enqueue(45)

print("Max value:", max_heap.get_max().val)
max_heap.print_heap()
max_heap.dequeue()
print("MaxHeap after dequeue:")
max_heap.print_heap()

