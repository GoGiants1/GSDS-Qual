# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        visit = deque()
        queue = deque()
        sum = []
  
        queue.append((root,1))
  
        while queue:
            node, lv = queue.pop()
            if node not in visit:
                visit.append(node)
                if len(sum) < lv : sum.append(node.val)
                else: sum[lv-1] += node.val
                if node.left != None: queue.append((node.left,lv+1))
                if node.right != None: queue.append((node.right,lv+1))
 
        return sum.index(max(sum))+1
