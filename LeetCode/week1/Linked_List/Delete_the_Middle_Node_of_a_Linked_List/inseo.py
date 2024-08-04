# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        n = 0

        while cur != None:
            n += 1
            cur = cur.next
        
        if n==1:
            return None

        cur_idx = 0
        cur = head

        while cur != None:
            if cur_idx == int(n/2)-1:
                cur.next = cur.next.next if cur.next != None else None
                break
            else:
                cur = cur.next
                cur_idx += 1
        
        return head