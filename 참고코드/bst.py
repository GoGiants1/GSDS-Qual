class TreeNode:
    def __init__(self, val=0, parent = None, left=None, right=None):
        self.val = val
        self.parent = parent
        self.left = left
        self.right = right

class Solution:
    def in_order_walk(self, x):
        if x != None:
            self.in_order_walk(x.left)
            print(x.key)
            self.in_order_walk(x.right)

    def search(self, x, key: int):
        while(x != None and x.key != key):
            if(x.key > key): x = x.left
            else: x = x.right
        return x

    def bst_min(self, x):
        while(x.left!=None): x = x.left
        return x

    def bst_max(self, x):
        while(x.right!=None): x = x.right
        return x
    
    def succ(self, x):
        if x.right != None: return self.bst_min(x.right)
        else:
            y = x.p
            while(y != None and x == y.left):
                x = y
                y = y.p
            return y
    
    def pred(self, x):
        if x.leftt != None: return self.bst_max(x.left)
        else:
            y = x.p
            while(y != None and x == y.right):
                x = y
                y = y.p
            return y
    
    def insert(self, root, key):
        z = TreeNode
        z.val = key

        x = root
        y = None
        while(x!=None):
            y = x
            if z.val < x.val: x = x.left
            else: x = x.right
        z.p = y
        # if y == None: T.root = z
        # elif y.val > z.val: y.left = z
        if y.val > z.val: y.left = z
        else: y.right = z
        
    def trans(self, u: Optional[TreeNode],v: Optional[TreeNode]):
        if u.p == None: v.p = u.p
        elif u == u.p.left: u.p.left = v
        else: u.p.right = v
        if v != None: v.p = u.p
    
    def bst_del(self, root, key):
        z = self.search(root, key)

        if z.left == None: self.trans(z, z.right)
        elif z.right == None: self.trans(z, z.left)
        else: 
            y = self.succ(z)
            if y != z.right:
                self.trans(y,y.right)
                y.right = z.right
                y.right.p = y
            self.trans(z, y)
            y.left = z.left
            y.left.p = y


        