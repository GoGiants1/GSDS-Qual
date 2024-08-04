# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        cur = head

        n = 0
        val_list = []
        while cur != None:
            val_list.append(cur.val)
            cur = cur.next
            n += 1

        answer = 0
        for i in range(int(n/2)):
            answer = max(answer, val_list[i]+val_list[n-i-1])
        return answer