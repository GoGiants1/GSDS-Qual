class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        cur = head
        while cur:
            tmp_next = cur.next
            cur.next = prev
            prev = cur
            cur = tmp_next

        return prev
