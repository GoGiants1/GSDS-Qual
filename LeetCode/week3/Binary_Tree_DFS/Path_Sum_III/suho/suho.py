# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, from_root, node, g_cnt, targetSum):
            fr = from_root[:]
            fr.append(node.val)
            for i in range(len(fr)):
                if sum(fr[i:]) == targetSum : g_cnt[0] += 1

            if (node.left != None): self.dfs(fr, node.left, g_cnt, targetSum)
            if (node.right != None): self.dfs(fr, node.right, g_cnt, targetSum)

    def pathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: int
        """
        from_root = []
        g_cnt = [0]
        self.dfs(from_root, root, g_cnt, targetSum)
        return g_cnt[0]
