# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, node, p):
        if(node.val == p.val): return 1
        else:
            res = 0
            if(node.left != None): res = self.dfs(node.left, p)
            if(res == 0 and node.right != None): res = self.dfs(node.right, p)
            return res

    def lca(self, node, p, q, lca, lv, lca_lv):
        if(self.dfs(node, p)==1 and self.dfs(node, q)==1 and lv > lca_lv[0]): 
            lca[0] = node
            lca_lv[0] = lv
        print(node.val, self.dfs(node, p), self.dfs(node, q), lca[0].val, lv, lca_lv[0])
        if (node.left != None): self.lca(node.left, p, q, lca, lv+1, lca_lv)
        if (node.right != None): self.lca(node.right, p, q, lca, lv+1, lca_lv)

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        lca = [root]
        self.lca(root, p, q, lca, 0, [0])
        return lca[0]
