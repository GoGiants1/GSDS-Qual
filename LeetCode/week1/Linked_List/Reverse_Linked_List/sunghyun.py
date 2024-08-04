# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        currptr = head
        prev = None
        
        while(currptr != None):
            nextptr = currptr.next
            currptr.next = prev
            prev = currptr
            if(nextptr == None):
                break
            currptr = nextptr
        
        return currptr
        