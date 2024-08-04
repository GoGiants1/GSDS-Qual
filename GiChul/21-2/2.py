class LinkedNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def split(l):
    node = l
    len = 1

    while(node.next != None): 
        node = node.next
        len += 1

    node = l
    for i in range(len//2 - 1): node = node.next
    right = node.next
    node.next = None

    return l, right


def merge(l1, l2):
    lnode = l1
    rnode = l2

    if lnode.val > rnode.val:
        l = lnode
        lnode = lnode.next
    else:
        l = rnode
        rnode = rnode.next
    l.next = None
    l_head = l

    while lnode != None and rnode != None:
        if lnode.val > rnode.val:
            l.next = lnode
            lnode = lnode.next
            l = l.next
            l.next = None
        else:
            l.next = rnode
            rnode = rnode.next
            l = l.next
            l.next = None

    while lnode != None:
        l.next = lnode
        lnode = lnode.next
        l = l.next
        l.next = None

    while rnode != None:
        l.next = rnode
        rnode = rnode.next
        l = l.next
        l.next = None

    return l_head

def sortingLL(l):
    if  l.next != None:
        left, right = split(l)

        left = sortingLL(left)
        right = sortingLL(right)

        l = merge(left, right)
   
    return l


node = LinkedNode(1)
l = node
node.next = LinkedNode(2)
node = node.next
node.next = LinkedNode(3)
node = node.next
node.next = LinkedNode(4)

l = sortingLL(l)

node = l
while(node != None):
    print(node.val)
    node = node.next
