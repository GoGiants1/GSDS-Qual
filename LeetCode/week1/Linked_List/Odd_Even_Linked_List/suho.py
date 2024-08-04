# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        odd_head, even_head, odd, even, beatle, n = head, None, head, None, head.next, 2
        
        while(beatle != None):
            if(n%2 == 0): 
                if(even_head == None): even_head = beatle
                else: even.next = beatle
                even = beatle
            else:
                odd.next = beatle
                odd = beatle
            beatle = beatle.next
            n+=1
            
        odd.next = even_head
        if(even != None): even.next = None

        return head
