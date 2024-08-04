# include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode{
        int val;
        LinkedNode *next;
};


LinkedNode* split(LinkedNode *l){
    LinkedNode *node = l;
    int len = 1;

    while(node->next != NULL){
        node = node->next;
        len++;
    }

    node = l;
    for(int i = 0; i <  len/2 - 1; i++) node = node->next;
    LinkedNode *right = node->next;
    node->next = NULL;

    return right;
}


LinkedNode* merge(LinkedNode *l1, LinkedNode *l2){
    LinkedNode *lnode = l1;
    LinkedNode *rnode = l2;
    LinkedNode *l;

    if(lnode->val > rnode->val){
        l = lnode;
        lnode = lnode->next;
    }
    else{
        l = rnode;
        rnode = rnode->next;
    }
    l->next = NULL;
    LinkedNode *l_head = l;

    while(lnode != NULL && rnode != NULL){
        if(lnode->val > rnode->val){
            l->next = lnode;
            lnode = lnode->next;
            l = l->next;
            l->next = NULL;
        }
        else{
            l->next = rnode;
            rnode = rnode->next;
            l = l->next;
            l->next = NULL;
        }
    }
    while(lnode != NULL){
        l->next = lnode;
        lnode = lnode->next;
        l = l->next;
        l->next = NULL;
    }
    while(rnode != NULL){
        l->next = rnode;
        rnode = rnode->next;
        l = l->next;
        l->next = NULL;
    }

    return l_head;
}

LinkedNode* sortingLL(LinkedNode *l){
    if(l->next != NULL){
        LinkedNode* right = split(l);

        l = sortingLL(l);
        right = sortingLL(right);

        l = merge(l, right);
    }
   
    return l;
}

int main(){
    LinkedNode node1 = {1, NULL};
    LinkedNode node2 = {2, NULL};
    LinkedNode node3 = {3, NULL};
    LinkedNode node4 = {4, NULL};
    LinkedNode node5 = {5, NULL};
    
    LinkedNode *lh = &node1;
    LinkedNode *l = lh;
    l->next = &node2;
    l = l->next;
    l->next = &node3;
    l = l->next;
    l->next = &node4;
    l = l->next;
    l->next = &node5;
 
    l = sortingLL(lh);

    while(l != NULL){
        printf("%d\n",l->val);
        l = l->next;
    }

    return 0;
}
