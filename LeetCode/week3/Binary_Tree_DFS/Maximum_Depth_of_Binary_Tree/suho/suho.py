# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, visited, node, depth):
        if node.val not in visited:
            visited.append(node.val)
            d = depth
            if (node.left != None):
                tmp = self.dfs(visited, node.left, depth+1)
                d = tmp if tmp > d else d
            if (node.right != None): 
                tmp = self.dfs(visited, node.right, depth+1)
                d = tmp if tmp > d else d
            return d

        else: return depth

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        visited = []
        return self.dfs(visited, root, 1)

        
