# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        even_head = None
        odd_head = None
        even_last = None

        cur_idx = 0
        cur = head
        even_cur = None
        odd_cur = None
        
        while cur != None:
            if cur_idx % 2 == 0:
                if cur_idx == 0:
                    even_head = ListNode(val=cur.val, next=None)
                    even_cur = even_head
                else:
                    temp = ListNode(val=cur.val, next=None)
                    even_cur.next = temp
                    even_cur = even_cur.next
                even_last = even_cur
            if cur_idx % 2 == 1:
                if cur_idx == 1:
                    odd_head = ListNode(val=cur.val, next=None)
                    odd_cur = odd_head
                else:
                    temp = ListNode(val=cur.val, next=None)
                    odd_cur.next = temp
                    odd_cur = odd_cur.next
            cur_idx += 1
            cur = cur.next
        
        if even_head == None:
            return None
        even_last.next = odd_head
        return even_head