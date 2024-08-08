#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* list_to_linked_list(int numlist[], int size){
    if(size==0) return NULL;
    ListNode* dummy = (ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    ListNode* dummyptr = dummy;

    for(int i=0; i<size; i++){
        ListNode* temp = (ListNode*)malloc(sizeof(struct ListNode));
        temp->val = numlist[i];
        temp->next = NULL;
        dummyptr->next = temp;
        dummyptr = dummyptr->next;
    }

    return dummy->next;
}

void printnode(ListNode* head){
    ListNode* headptr = head;
    while(headptr){
        printf("%d -> ", headptr->val);
        headptr = headptr->next;
    }
    printf("None\n");
}

void printinner(ListNode* head){
    printf("[");
    ListNode* headptr = head;
    while(headptr->next){
        printf("%d,", headptr->val);
        headptr = headptr->next;
    }
    printf("%d]", headptr->val);
}

ListNode* llcopy(ListNode* head){
    if(head==NULL) return NULL;

    ListNode* dummy = (ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    ListNode* dummyptr = dummy;

    while(head!=NULL){
        ListNode* temp = (ListNode*)malloc(sizeof(struct ListNode));
        temp->val = head->val;
        temp->next = NULL;
        dummyptr->next = temp;
        dummyptr = dummyptr->next;
        head = head->next;
    }
    return dummy->next;
}

// Linked List reverse하는 알고리즘 -> 포인터 하나씩 생각해보면 이해됨
ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = llcopy(head);
    while(curr!=NULL){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool palindrome(ListNode* head){
    if(head==NULL) return true;

    ListNode* reversehead = reverse(head);
    ListNode* headptr = head;
    ListNode* reverseheadptr = reversehead;
    
    while(headptr!=NULL){
        if(headptr->val != reverseheadptr->val){
            return false;
        }
        headptr = headptr->next;
        reverseheadptr = reverseheadptr->next;
    }
    return true;
}

bool substring(ListNode* s, ListNode* t){
    if(t==NULL) return true;
    if(s==NULL) return false;

    ListNode* sPtr = s;
    ListNode* tPtr = t;

    while(sPtr){
        while(tPtr && sPtr && sPtr->val==tPtr->val){
            sPtr = sPtr->next;
            tPtr = tPtr->next;
        }
        if(tPtr==NULL) return true;
        s = s->next;
        sPtr = s;
        tPtr = t;
    }
    return false;
}

ListNode* slicing(ListNode* s, int start, int end){
    ListNode* dummy = (ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    ListNode* sCopy = llcopy(s);    // llcopy 해주는 이유 -> 아래 있음

    for(int i=0; i<start; i++){
        sCopy = sCopy->next;
    }
    dummy->next = sCopy;
    for(int i=start; i<end; i++){
        sCopy = sCopy->next;
    }
    sCopy->next = NULL;        // llcopy없이 포인터로 이렇게 하면 원본이 이거 때매 훼손됨

    return dummy->next;
}

// 두개의 LL이 완전히 일치한지
bool cmpll(struct ListNode* s, struct ListNode* t) {
    struct ListNode* currs = s;
    struct ListNode* currt = t;
    while (currs && currt) {
        if (currs->val != currt->val) {
            return false;
        } else {
            currs = currs->next;
            currt = currt->next;
        }
    }
    if (!currs && !currt) {
        return true;
    } else {
        return false;
    }
}

void max_palindromes(ListNode* head){
    printf("[");
    // 1) head의 총 길이 구함
    int length = 0;
    ListNode* headptr = head;
    while(headptr){
        headptr = headptr->next;
        length++;
    }

    ListNode* result[length+1];
    ListNode* final_result[length+1];
    int index[length+1];    // 누군가의 substring에 해당하면 0, 자기가 젤 큰 거면 1 담은 index array

    // 2) 시작 인덱스마다 최대가 되는 palindrome 구해서 result[]에 저장
    for(int i=0; i<length; i++){
        for(int j=length-1; j>=i; j--){
            ListNode* dummy = slicing(head, i, j);
            if(palindrome(dummy)){
                result[i] = dummy;
                break;
            }
        }
    }
    result[length] = '\0';

    // 3) result[]의 각 palindrome이 진짜 최고인지 확인하는 index[] 생성
    for(int i=0; i<length; i++){
        index[i] = 1;
    }
    index[length] = '\0';
    for(int i=0; i<length; i++){
        for(int j=i+1; j<length; j++){
            if(substring(result[i], result[j])){
                index[j] = 0;
            }
            else if(substring(result[j], result[i])){
                index[i] = 0;
            }
        }
    }

    // 4) index[]에서 1에 해당하는 놈들만 final_result[]에 저장
    int count = 0;
    for(int i=0; i<length; i++){
        if(index[i]){
            final_result[count] = result[i];
            count++;
        }
    }
    final_result[count] = '\0';
    for(int i=0; i<count-1; i++){
        printinner(final_result[i]);
        printf(",");
    }
    printinner(final_result[count-1]);
    printf("]\n");
}

int main() {
    // Initializing an array of integers
    int nums[] = {8, 1, 2, 3, 3, 2, 1, 4, 9, 4, 5, 6, 7, 6, 5, 4, 1};
    int nums2[] = {8, 1, 2, 3, 3, 2, 1, 0, 4, 9, 1, 2, 3, 3, 2, 1, 9, 1};

    int size = sizeof(nums) / sizeof(nums[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    
    // Converting the array to a linked list
    struct ListNode* head = list_to_linked_list(nums, size);
    struct ListNode* head2 = list_to_linked_list(nums2, size2);
    ListNode* reversehead = reverse(head);
    ListNode* slicedhead = slicing(head, 1, 1);
    
    // Printing the initial list
    printf("Initial List: ");
    printnode(head);
    printf("Reversed List: ");
    printnode(reversehead);
    printf("Sliced List: ");
    printnode(slicedhead);
    printf("Initial List: ");
    printnode(head);
    printf("Final Result 1: \n");
    max_palindromes(head);
    printf("Final Result 2: \n");
    max_palindromes(head2);
}