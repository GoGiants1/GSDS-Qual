# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
g_cnt = 0
class Solution(object):
    def dfs(self, from_root, node, g_cnt):
            fr = from_root[:]
            fr.append(node.val)
            if(len(fr)==1 or max(fr) <= node.val): g_cnt[0] += 1
            if (node.left != None): self.dfs(fr, node.left, g_cnt)
            if (node.right != None): self.dfs(fr, node.right, g_cnt)

    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        from_root = []
        g_cnt = [0]
        self.dfs(from_root, root, g_cnt)
        return g_cnt[0]
        
