"""
- keyword: queue
- functions: enqueue, dequeue, is_empty

** 추가 구현: reverse(stack, recursive), display
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    def enqueue(self, data):
        if self.front is None:
            self.front = self.rear = Node(data)
        else:
            node = Node(data)
            self.rear.next = node     # 마지막 원소 다음에 연결
            self.rear = node          # 새 노드를 마지막 원소로 만듦

    def dequeue(self):
        if self.front is None:
            return None
        node = self.front
        if self.front == self.rear:
            self.front = self.rear = None
        else:
            self.front = self.front.next      # 나간 원소 다음 노드를 첫 노드로
        return node.data

    def is_empty(self):
        return self.front is None


def using_stack(q):
    """
    Stack을 이용한 reverse (in-place): 넣었다가 뺴기
    """
    s = []
    while not q.is_empty():
        s.append(q.dequeue())
    while s:
        q.enqueue(s.pop())

def using_recursive(q):
    """"
    재귀를 이용한 reverse (in-place): 뺐다가 넣기기
    """
    if not q.is_empty():
        data = q.dequeue()       
        using_recursive(q)
        q.enqueue(data)

def display(q):
    node = q.front
    while node:
        print(node.data, end = " ")
        node = node.next
    print()



if __name__ == "__main__":
    q = Queue()

    for i in range(3):
        q.enqueue(chr(ord("A") + i))
        print(f"Enqueue data = {q.rear.data}")
    print()

    while not q.is_empty():
        print(f"Dequeue data = {q.dequeue()}")

    for i in range(5):
        q.enqueue(i+1)
    print("\nBefore reverse: ", end='')
    display(q)

    print(f"Reverse using stack: ", end='')
    using_stack(q)
    display(q)
    print(f"Reverse again using recursive: ", end='')
    using_recursive(q)
    display(q)
