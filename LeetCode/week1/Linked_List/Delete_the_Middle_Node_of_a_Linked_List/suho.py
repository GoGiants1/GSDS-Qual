# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        bf_mid, mid, end = head, head, head
        while(end.next != None):
            end = end.next.next if end.next.next != None else end.next
            bf_mid = mid
            mid = mid.next
        bf_mid.next = mid.next
        del mid
        return head
