# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        mid = head
        end = head
        before = mid
        if head.next == None:
            return None
        while (end.next != None):
            if end.next.next != None:
                end = end.next.next
            else:
                end = end.next
            before = mid
            mid = mid.next
        before.next = mid.next
        return head
        