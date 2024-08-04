#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void print_list(struct Node *s){
    struct Node *node = s;
    printf("[");
    while(node!=NULL){
        printf("%d",node->data);
        if(node->next!=NULL) printf(", ");
        node = node->next;
    }
    printf("]");
}

int palindrome(struct Node *s){
    int slist[100];
    int slen = 0;
    struct Node *node = s;

    while(node!=NULL){
        slist[slen] = node->data;
        slen++;
        node = node->next;
    }

    int res = 1;
    for(int i = 0; i<slen/2; i++){
        if(slist[i]!=slist[slen-i-1]){
            res = 0;
            break;
        }
    }
    
    return res;
}
    

int sub_list(struct Node *s, struct Node *t){
    struct Node *s_node = s;
    struct Node *s_save = s;
    struct Node *t_node = t;

    while(s_node!=NULL){
        if(s_node->data!=t_node->data){
            s_node = s_save->next;
            s_save = s_node;
            t_node = t;
        }
        else{
            s_node = s_node->next;
            t_node = t_node->next;
            if(t_node==NULL){
                return 1;
            } 
        }
    }
    return 0;
}
    

void make_sublist(struct Node *s, struct Node *t, int start, int end){
    int i = 0;
    struct Node *node = s;
    struct Node *sublist = t;

    while(i<end){
        if(i>=start){
            sublist->data = node->data;
            sublist->next = i == end-1 ? NULL : (struct Node*)malloc(sizeof(struct Node));
            sublist = sublist->next;
        }
        i++;
        node = node->next;
    }
}


void max_palindrome(struct Node *s){
    struct Node *s_node = s;
    struct Node *s_save = s;
    struct Node tmp = {s->data, NULL};
    struct Node *test = &tmp;
    struct Node *test_head = test;
    int startlist[2000];
    int endlist[2000];
    int palin_num = 0;
    int start = 0;
    int end = 1;

    while(1){
        while(1){
            if(palindrome(test_head)){
                startlist[palin_num] = start;
                endlist[palin_num] = end;
                palin_num++;
            }

            if(s_node->next==NULL) break;
            else{
                s_node = s_node->next;
                test->next = (struct Node*)malloc(sizeof(struct Node));
                test = test->next;
                test->data = s_node->data;
                test->next = NULL;
                end++;
            }
        }

        if(s_save->next==NULL) break;
        else{
            s_node = s_save->next;
            s_save = s_node;
            struct Node tmp = {s_node->data, NULL};
            test = &tmp;
            test_head = test;
            start++;
            end = start+1;
        }
    }

    int i = 0;
    while(i<palin_num){
        for(int j = 0; j < palin_num; j++){
            if(i!=j){
                struct Node slist;
                make_sublist(s,&slist,startlist[j],endlist[j]);
                struct Node tlist;
                make_sublist(s,&tlist,startlist[i],endlist[i]);

                if(sub_list(&slist,&tlist)){
                    int k = i;
                    while(k < palin_num-1){
                        startlist[k] = startlist[k+1];
                        endlist[k] = endlist[k+1];
                        k++;
                    }
                    palin_num--;
                    i--;
                    break;
                }
            }
        }
        i++;
    }

    printf("[");
    for(int i = 0; i < palin_num; i++){
        struct Node tmp;
        make_sublist(s,&tmp,startlist[i],endlist[i]);
        print_list(&tmp);
        if(i!=palin_num-1) printf(", ");
    }
    printf("]");
}

void makelist(int *s, int slen, struct Node* head){
    struct Node* node = head;
    for(int i = 0; i < slen; i++){
        node->data = s[i];
        node->next = i == slen-1 ? NULL : (struct Node*)malloc(sizeof(struct Node));
        node = node->next;
    }
}

int main(){
    int s[] = {8,1,2,3,3,2,1,0,4,9,1,2,3,3,2,1,9,1};
    int slen = sizeof(s) / sizeof(s[0]); 
    struct Node head;
    makelist(s, slen, &head);
    print_list(&head);
    printf("\n\n");

    int s1[] = {1, 2, 3, 3, 2, 1};
    int s1len = sizeof(s1) / sizeof(s1[0]); 
    struct Node head1;
    makelist(s1, s1len, &head1);
    int i = palindrome(&head1);
    printf("%d %d\n\n",palindrome(&head),palindrome(&head1));
    
    int t1[] = {2,1,0,4,9};
    int t2[] = {2,1,0,4,7};
    int t1len = sizeof(t1) / sizeof(t1[0]); 
    int t2len = sizeof(t2) / sizeof(t2[0]); 
    struct Node head2;
    makelist(t1,t1len,&head2);
    struct Node head3;
    makelist(t2,t2len,&head3);
    printf("%d %d\n\n", sub_list(&head,&head2), sub_list(&head,&head3));
    
    max_palindrome(&head);
    printf("\n");

    return 0;
}
