# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def pairSum(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: int
        """
        lllen = 0
        temp = head

        while(temp != None):
            lllen = lllen + 1
            temp = temp.next
        
        mid = lllen / 2

        firstptr = head
        midval = 0
        secondptr = head
        maxsum = float('-inf')

        while(midval != mid):
            secondptr = secondptr.next
            midval = midval + 1
        
        prev = None
        currptr = secondptr

        while(True):
            nextptr = currptr.next
            currptr.next = prev
            prev = currptr
            if (nextptr == None):
                break
            currptr = nextptr
        
        reverseptr = currptr

        while(reverseptr != None):
            pairsum = firstptr.val + reverseptr.val
            if (pairsum > maxsum):
                maxsum = pairsum
            firstptr = firstptr.next
            reverseptr = reverseptr.next
        
        return maxsum
            
        