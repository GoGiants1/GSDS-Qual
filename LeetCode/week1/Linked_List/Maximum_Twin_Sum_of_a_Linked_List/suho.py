# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        beatle = head
        vals = []
        while(beatle != None):
            vals.append(beatle.val)
            beatle = beatle.next
        for i in range(int(len(vals)/2)):
            vals[i]+=vals[len(vals)-i-1]
            
        return max(vals[:int(len(vals)/2)])

        
