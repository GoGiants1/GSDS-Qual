# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        odd_head = head
        if odd_head.next:
            even_head = odd_head.next
        else:
            even_head = None
        
        odd_node = odd_head
        even_node = even_head
        
        while(even_node.next):
            odd_node.next = even_node.next
            odd_node = odd_node.next 
            if not even_node.next.next:
                break
            even_node.next = even_node.next.next
            even_node = even_node.next
            
        odd_node.next = even_head
            
            
            
            
        