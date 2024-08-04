# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        oddlist = ListNode(0)
        evenlist = ListNode(0)
        
        oddhead = oddlist
        evenhead = evenlist

        while(head):
            oddlist.next = head
            evenlist.next = head.next
            
            oddlist = oddlist.next
            evenlist = evenlist.next
            
            if (evenlist):
                head = head.next.next
            else:
                head = None
        
        oddlist.next = evenhead.next

        return oddhead.next

        