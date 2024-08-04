# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node, g_cnt, tmp_cnt, prev):
        if(prev == 'right' or prev == 'root'):
            if (node.left != None): 
                tcnt = tmp_cnt + 1
                if g_cnt[0] < tcnt : g_cnt[0] = tcnt
                self.dfs(node.left, g_cnt, tcnt, 'left')
            if (node.right != None): 
                self.dfs(node.right, g_cnt, 1, 'right')

        if(prev == 'left' or prev == 'root'):
            if (node.right != None): 
                tcnt = tmp_cnt + 1
                if g_cnt[0] < tcnt : g_cnt[0] = tcnt
                self.dfs(node.right, g_cnt, tcnt, 'right')
            if (node.left != None): 
                self.dfs(node.left, g_cnt, 1, 'left')

    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        tmp_cnt = 0
        g_cnt = [0]
        prev = 'root'
        self.dfs(root, g_cnt, tmp_cnt, prev)
        return g_cnt[0]
        
