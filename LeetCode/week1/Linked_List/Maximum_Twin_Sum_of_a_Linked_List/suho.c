/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    struct ListNode *beatle = head;
    int len = 0, i = 0, max_val = 0;
    while(beatle != NULL){
        len++;
        beatle = beatle->next;
    }
    int *vals = (int*)malloc(sizeof(int)*len/2+1);
    beatle = head;

    for(i = 0; i < len; i++){
        if(i<len/2) vals[i] = beatle->val;
        else{
            vals[len-i-1] += beatle->val;
            max_val = max_val > vals[len-i-1]? max_val : vals[len-i-1];
        }
        beatle = beatle->next;
    }

    return max_val;
}
