"""
- keyword: stack
- functions: push, pop, peek, is_empty
"""

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

    def push(self, data):
        if self.top is None:
            self.top = Node(data)
        else:
            node = Node(data)
            node.next = self.top
            self.top = node

    def pop(self):
        if self.top is None:
            return None
        node = self.top
        self.top = self.top.next
        return node.data

    def peek(self):
        if self.top is None:
            return None
        return self.top.data

    def is_empty(self):
        return self.top is None


if __name__ == "__main__":
    s = Stack()

    for i in range(3):
        s.push(chr(ord("A") + i))
        print(f"Push data = {s.peek()}")
    print()

    while not s.is_empty():
        print(f"Pop data = {s.pop()}")
    print()

    print(f"Peek data = {s.peek()}")
