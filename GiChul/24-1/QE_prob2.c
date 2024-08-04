LLNode* split(LLNode *l){
    LLNode *node = l;
    int len = 1;

    while(node->nxt != NULL){
        node = node->nxt;
        len++;
    }

    node = l;
    for(int i = 0; i <  len/2 - 1; i++) node = node->nxt;
    LLNode *right = node->nxt;
    node->nxt = NULL;
    right->prv = NULL;

    return right;
}

void merge(LLNode *l1, LLNode *l2, int rev){
    LLNode *lnode = l1;
    LLNode *rnode = l2;
    LLNode *l;
    LLNode *ltmp = (LLNode*)malloc(sizeof(LLNode));
    ltmp->prv = NULL;

    if((rev == 0 && lnode->val <= rnode->val) || (rev == 1 && lnode->val >= rnode->val)){
        l = lnode;
        lnode = lnode->nxt;
    }
    else{
        ltmp->val = lnode->val;
        ltmp->nxt = lnode->nxt;
        l = lnode;
        lnode = ltmp;
        l->val = rnode->val;
        rnode = rnode->nxt;
    }

    while(lnode != NULL && rnode != NULL){
        if((rev == 0 && lnode->val <= rnode->val) || (rev == 1 && lnode->val >= rnode->val)){
            l->nxt = lnode;
            lnode = lnode->nxt;
            lnode->prv = NULL;
            l->nxt->prv = l;
            l = l->nxt;
        }
        else{
            l->nxt = rnode;
            rnode = rnode->nxt;
            rnode->prv = NULL;
            l->nxt->prv = l;
            l = l->nxt;
        }
    }
    while(lnode != NULL){
        lnode->prv = l;
        l->nxt = lnode;
        lnode = lnode->nxt;
        l = l->nxt;
        l->nxt = NULL;
    }
    while(rnode != NULL){
        rnode->prv = l;
        l->nxt = rnode;
        rnode = rnode->nxt;
        l = l->nxt;
        l->nxt = NULL;
    }
    l->nxt = NULL;
    free(ltmp);
}

void sort_list(LLNode *head){
    LLNode *l = head;
    if(l->nxt != NULL){
        LLNode* right = split(l);

        sort_list(l);
        sort_list(right);
        
        merge(l, right, 0);
    }
}

void sort_list_rev(LLNode *head){
    LLNode *l = head;
    if(l->nxt != NULL){
        LLNode* right = split(l);

        sort_list_rev(l);
        sort_list_rev(right);

        merge(l, right, 1);
    }
}

void sort_each_list(LLNode *head[100], int N){
    for(int i = 0; i < N; i++){
        sort_list(head[i]);
    }
}

LLNode* merge_sorted_lists(LLNode *head[100], int N){
    LLNode *l = (LLNode*)malloc(sizeof(LLNode));
    l->val = head[0]->val;
    l->nxt = NULL;
    l->prv = NULL;
    merge(l,head[0]->nxt,0);


    for(int i = 1; i < N; i++){
        merge(l,head[i],0);
    }

    sort_list_rev(l);

    return l;
}
