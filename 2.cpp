# include <iostream>
using namespace std;

struct LinkedNode{
        int val;
        LinkedNode *next = nullptr;
        LinkedNode(int val) : val(val) {}
};

LinkedNode* split(LinkedNode *l){
    LinkedNode *node = l;
    int len = 1;

    while(node->next != nullptr){
        node = node->next;
        len++;
    }

    node = l;
    for(int i = 0; i <  len/2 - 1; i++) node = node->next;
    LinkedNode *right = node->next;
    node->next = nullptr;

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
    l->next = nullptr;
    LinkedNode *l_head = l;

    while(lnode != nullptr && rnode != nullptr){
        if(lnode->val > rnode->val){
            l->next = lnode;
            lnode = lnode->next;
            l = l->next;
            l->next = nullptr;
        }
        else{
            l->next = rnode;
            rnode = rnode->next;
            l = l->next;
            l->next = nullptr;
        }
    }
    while(lnode != nullptr){
        l->next = lnode;
        lnode = lnode->next;
        l = l->next;
        l->next = nullptr;
    }
    while(rnode != nullptr){
        l->next = rnode;
        rnode = rnode->next;
        l = l->next;
        l->next = nullptr;
    }

    return l_head;
}

LinkedNode* sortingLL(LinkedNode *l){
    if(l->next != nullptr){
        LinkedNode* right = split(l);

        l = sortingLL(l);
        right = sortingLL(right);

        l = merge(l, right);
    }
   
    return l;
}

int main(){
    LinkedNode node1 = LinkedNode(1);
    LinkedNode node2 = LinkedNode(2);
    LinkedNode node3 = LinkedNode(3);
    LinkedNode node4 = LinkedNode(4);
    LinkedNode node5 = LinkedNode(5);
    
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

    while(l != nullptr){
        printf("%d\n",l->val);
        l = l->next;
    }

    return 0;
}