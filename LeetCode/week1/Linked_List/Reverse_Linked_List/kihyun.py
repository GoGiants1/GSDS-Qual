# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            pass
        elif head.next.next == None:
            new_head = head.next
            new_head.next = head
            head.next = None
            head = new_head
        else:
            before = head.next
            cur = before.next
            head.next = None
            while cur != None:
                before.next = head
                head = before
                before = cur
                cur = cur.next
            before.next = head
            head = before
        return head
