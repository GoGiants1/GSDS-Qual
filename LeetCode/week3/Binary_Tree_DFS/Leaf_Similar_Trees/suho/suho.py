# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, visited, node, leaf):
        if node.val not in visited:
            visited.append(node.val)
            if (node.left==None and node.right==None): leaf.append(node.val)
            elif (node.left != None): self.dfs(visited, node.left, leaf)
            else: self.dfs(visited, node.right, leaf)

    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """

        leaf1, leaf2 = [], []
        visited = []
        self.dfs(visited, root1, leaf1)
        visited = []
        self.dfs(visited, root2, leaf2)

        return leaf1 == leaf2
        
