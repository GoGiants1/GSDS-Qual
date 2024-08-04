# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def deleteMiddle(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        middle = int(self.getLength(head)/2)
        node = head
        for i in range(middle):
            if i == (middle-1):
                parent = node
            node = node.next
        parent.next = node
        
    
    def getLength(self, head):
        length = 1
        node = head
        while(node.next):
            length += 1
            node = node.next
        return length
        
        