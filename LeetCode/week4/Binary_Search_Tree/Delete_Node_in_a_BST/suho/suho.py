# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def search(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        x = root
        xp = None
        while(x != None and x.val != key): 
            if(x.val > key): 
                xp = x
                x = x.left
            else:
                xp = x
                x = x.right

        return x, xp

    def bst_min(self, root: Optional[TreeNode]):
        p = None
        while(root.left!=None): 
            p = root
            root = root.left
        return root, p
    
    def succ(self, root: Optional[TreeNode]):
        if root.right != None: 
            res, p = self.bst_min(root.right)
            if(p==None): p = root
            return res, p

    def trans(self, up: Optional[TreeNode], u: Optional[TreeNode],v: Optional[TreeNode]):
        if u == up.left: up.left = v
        else: up.right = v

    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        z, zp = self.search(root, key)
        if(root == None or z == None): return root
        elif(zp == None):
            if z.left == None: return z.right
            elif z.right == None: return z.left
            else: 
                y, yp = self.succ(z)
                if y != z.right:
                    self.trans(yp, y, y.right)
                    y.right = z.right
                y.left = z.left
                return y
        else:
            if z.left == None: self.trans(zp, z, z.right)
            elif z.right == None: self.trans(zp, z, z.right)
            else: 
                y, yp = self.succ(z)
                if y != z.right:
                    self.trans(yp, y, y.right)
                    y.right = z.right
                self.trans(zp, z, y)
                y.left = z.left
        
        return root
        
