# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        node_val_list = []
        cur = head
        while cur:
            node_val_list.append(cur.val)
            cur = cur.next
        
        max_twin_sum = 0
        for i in range(len(node_val_list) // 2):
            twin_sum = node_val_list[i] + node_val_list[len(node_val_list) - 1 - i]
            if max_twin_sum < twin_sum:
                max_twin_sum = twin_sum

        return max_twin_sum
            
