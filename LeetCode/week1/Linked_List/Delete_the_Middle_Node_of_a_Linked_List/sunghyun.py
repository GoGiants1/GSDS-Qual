import math
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteMiddle(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        lllen = 0

        curptr = head

        while(curptr != None):
            lllen = lllen + 1
            curptr = curptr.next
        
        delind = math.floor(lllen / 2)

        if (delind == 0):
            return None

        curptr = head

        while(delind > 1):
            curptr = curptr.next
            delind = delind - 1

        curptr.next = curptr.next.next

        return head
        

        