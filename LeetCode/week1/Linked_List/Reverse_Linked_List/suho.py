# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            pass
        elif head.next.next == None:
            head.next.next = head
            head = head.next
            head.next.next=None
        else:
            forward = head.next
            save = forward.next
            head.next = None
            while save != None:
                forward.next = head
                head = forward
                forward = save
                save = save.next
            forward.next = head
            head = forward
        return head
