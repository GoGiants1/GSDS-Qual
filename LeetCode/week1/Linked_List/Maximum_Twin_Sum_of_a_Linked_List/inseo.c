/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    struct ListNode *temp = NULL;
    struct ListNode *q = NULL;
    struct ListNode *p = head;

    while(p!=NULL){
        struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newnode->val = p->val;
        newnode->next = NULL;

        if(temp == NULL){
            temp = newnode;
            q = newnode;
        
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }

        p = p->next;
    }
    p = head;

    struct ListNode *prev = NULL;
    while(q!=NULL){
        struct ListNode *next_node = q->next;

        q->next = prev;
        prev = q;
        q = next_node;
    }
    q = prev;

    int maxSum = 0;
    while(p!=NULL){
        int sum = p->val + q->val;

        if(sum>maxSum){
            maxSum = sum;
        }
        p = p->next;
        q = q->next;
    }
    
    return maxSum;
}