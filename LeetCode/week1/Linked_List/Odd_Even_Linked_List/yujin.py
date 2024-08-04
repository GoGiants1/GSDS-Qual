# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        odd = True
        odd_list = odd_head = None
        even_list = even_head = None
        cur = head
        while cur:
            if odd:
                if odd_list is None:
                    odd_list = odd_head = cur
                else:
                    odd_list.next = cur                    
                    odd_list = odd_list.next
                odd = False
            else:
                if even_list is None:
                    even_list = even_head = cur
                else:
                    even_list.next = cur
                    even_list = even_list.next
                odd = True
            cur = cur.next
        if odd_list is not None:
            odd_list.next = even_head
        if even_list is not None:
            even_list.next = None

        return head
