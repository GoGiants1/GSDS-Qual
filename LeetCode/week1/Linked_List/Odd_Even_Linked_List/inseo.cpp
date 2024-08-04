class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if(!head || !head->next || !head->next->next)    return head;
		ListNode *odd = head, *even = head->next;
		ListNode *e1 = even;
		while(odd->next && even->next)
		{
			odd->next = even->next;
			odd = odd->next;
			even->next = odd->next;
			even = even->next;
		}
		odd->next = e1;
		return head;
	}
};