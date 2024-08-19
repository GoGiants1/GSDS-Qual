class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None

class MinHeap:
    def __init__(self):
        self.root = None
        self.heapsize = 0

    def get_min(self):
        return self.root

    def print_heap(self):
        if not self.root:
            return
        
        queue = [self.root]
        print("MinHeap:", end=" ")
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
            while new_node.parent and new_node.val < new_node.parent.val:
                self.swap(new_node, new_node.parent)
                new_node = new_node.parent
        self.heapsize += 1

    def dequeue(self):
        if not self.root:
            return
        if not self.root.left and not self.root.right:
            self.root = None
        else:
            path = self.heapsize
            current = self.root
            for shift in range((path.bit_length() - 2), 0, -1):
                if path & (1 << shift):
                    current = current.right
                else:
                    current = current.left
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
                smallest = node
                if node.left and node.left.val < smallest.val:
                    smallest = node.left
                if node.right and node.right.val < smallest.val:
                    smallest = node.right
                if smallest != node:
                    self.swap(node, smallest)
                    node = smallest
                else:
                    break
        self.heapsize -= 1

# MinHeap 테스트
min_heap = MinHeap()
min_heap.enqueue(3)
min_heap.enqueue(2)
min_heap.enqueue(1)
min_heap.enqueue(15)
min_heap.enqueue(5)
min_heap.enqueue(4)
min_heap.enqueue(45)

print("Min value:", min_heap.get_min().val)
min_heap.print_heap()
min_heap.dequeue()
print("MinHeap after dequeue:")
min_heap.print_heap()
