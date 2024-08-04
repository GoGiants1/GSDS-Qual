#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}
    Node(int data, Node* next): data(data), next(next) {}
};

void print_list(Node *s){
    Node *node = s;
    printf("[");
    while(node!=nullptr){
        printf("%d",node->data);
        if(node->next!=nullptr) printf(", ");
        node = node->next;
    }
    printf("]");
}

int palindrome(Node *s){
    vector<int> slist(0);
    Node *node = s;

    while(node!=nullptr){
        slist.push_back(node->data);
        node = node->next;
    }

    int res = 1;
    for(int i = 0; i<slist.size()/2; i++){
        // cout << "check " << i << " " << slist.size()/2 << endl;
        if(slist[i]!=slist[slist.size()-i-1]){
            res = 0;
            break;
        }
    }
    // cout << "checkend " << res << endl;
    
    return res;
}
    

int sub_list(Node *s, Node *t){
    Node *s_node = s;
    Node *s_save = s;
    Node *t_node = t;

    while(s_node!=nullptr){
        if(s_node->data!=t_node->data){
            s_node = s_save->next;
            s_save = s_node;
            t_node = t;
        }
        else{
            s_node = s_node->next;
            t_node = t_node->next;
            if(t_node==nullptr) return 1;
        }
    }
    return 0;
}
    

void make_sublist(Node *s, Node *t, int start, int end){
    int i = 0;
    Node *node = s;
    Node *sublist = t;

    while(i<end){
        if(i>=start){
            sublist->data = node->data;
            sublist->next = i == end-1 ? nullptr : new Node;
            sublist = sublist->next;
        }
        i++;
        node = node->next;
    }
}


void max_palindrome(Node *s){
    Node *s_node = s;
    Node *s_save = s;
    Node tmp = Node(s->data);
    Node *test = &tmp;
    Node *test_head = test;
    vector<vector<int>> palin_list(0);
    int start = 0;
    int end = 1;

    while(1){
        while(1){
            if(palindrome(test_head)){
                palin_list.push_back(vector<int>{start,end});
            }

            if(s_node->next==nullptr) break;
            else{
                s_node = s_node->next;
                test->next = new Node;
                test = test->next;
                test->data = s_node->data;
                test->next = nullptr;
                end++;
            }
        }

        if(s_save->next==nullptr) break;
        else{
            s_node = s_save->next;
            s_save = s_node;
            Node tmp = Node(s_node->data);
            test = &tmp;
            test_head = test;
            start++;
            end = start+1;
        }
    }

    int i = 0;
    while(i<palin_list.size()){
        for(int j = 0; j < palin_list.size(); j++){
            if(i!=j){
                Node slist;
                make_sublist(s,&slist,palin_list[j][0],palin_list[j][1]);
                Node tlist;
                make_sublist(s,&tlist,palin_list[i][0],palin_list[i][1]);

                if(sub_list(&slist,&tlist)){
                    palin_list.erase(palin_list.begin() + i);
                    i--;
                    break;
                }
            }
        }
        i++;
    }

    printf("[");
    for(int i = 0; i < palin_list.size(); i++){
        Node tmp;
        make_sublist(s,&tmp,palin_list[i][0],palin_list[i][1]);
        print_list(&tmp);
        if(i!=palin_list.size()-1) printf(", ");
    }
    printf("]");
}

void makelist(vector<int> s, Node* head){
    Node* node = head;
    for(int i = 0; i < s.size(); i++){
        node->data = s[i];
        node->next = i == s.size()-1 ? nullptr : new Node;
        node = node->next;
    }
}

int main(){
    vector<int> s = {8,1,2,3,3,2,1,0,4,9,1,2,3,3,2,1,9,1};
    Node head;
    makelist(s, &head);
    print_list(&head);
    printf("\n\n");

    vector<int> s1 = {1, 2, 3, 3, 2, 1, 0, 4, 9};
    Node head1;
    makelist(s1, &head1);
    int i = palindrome(&head1);
    printf("%d %d\n\n",palindrome(&head),palindrome(&head1));
    
    vector<int> t1 = {2,1,0,4,9};
    vector<int> t2 = {2,1,0,4,7};
    Node head2;
    makelist(t1,&head2);
    Node head3;
    makelist(t2,&head3);
    printf("%d %d\n\n", sub_list(&head,&head2), sub_list(&head,&head3));

    max_palindrome(&head);
    printf("\n");

    return 0;
}
