# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        n = 0
        cur = head
        while cur:
            n += 1
            cur = cur.next
        middle = n // 2
        if n == 1:
            head = None
        elif n == 2:
            head.next = None
        else:
            index = 0
            cur = head
            while index < middle:
                if index == middle-1:
                    cur.next = cur.next.next
                cur = cur.next
                index += 1

        return head
