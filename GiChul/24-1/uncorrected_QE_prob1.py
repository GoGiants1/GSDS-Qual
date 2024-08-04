class TNode:
    def __init__(self, val = 0, left = None, right = None, depth = 0):
        self.val = val
        self.left = left
        self.right = right
        self.depth = depth


def max_heap_help(T, isheap, nochild):
    if( T.left != None and T.left.val > T.val ): isheap[0] = False
    if( T.right != None and T.right.val > T.val): isheap[0] = False

    if( T.left == None ): nochild.append(T)
    else: 
        T.left.depth = T.depth + 1
        max_heap_help(T.left, isheap, nochild)

    if( T.right == None ): nochild.append(T)
    else: 
        T.right.depth = T.depth + 1
        max_heap_help(T.right, isheap, nochild)

def is_max_heap(T):
    isheap = [True]
    T.depth = 0
    nochild = []
    max_heap_help(T, isheap, nochild)

    ncd = list([ N.depth for N in nochild ])
    max_depth = max(ncd)
    if(min(ncd) < (max_depth-1)): isheap[0] = False

    return isheap[0]

def binary_tree_to_heap_array(T):
    return []
