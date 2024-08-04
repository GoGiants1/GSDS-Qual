# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        store_sum = []
        mid = head
        end = head
        while (end != None):
            store_sum.append(mid.val)
            mid = mid.next
            end = end.next.next
        
        idx = -1
        ans = 0
        while (mid != None):
            store_sum[idx] += mid.val
            if ans <= store_sum[idx]:
                ans = store_sum[idx]

            idx -= 1
            mid = mid.next
        return ans