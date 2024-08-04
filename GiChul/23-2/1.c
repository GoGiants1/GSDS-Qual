#include <stdio.h>
#include <stdlib.h>

struct Node{
    char id;
    struct Node *adj[5];
    int adjlen;
};
    
int bfs(struct Node *start){
    struct Node *queue[6];
    queue[0] = start;
    int qlen = 1;
    char visited[6];
    int vlen = 0;

    while(qlen!=0){
        struct Node *curr_node = queue[qlen-1];
        qlen--;

        for(int i = 0; i < curr_node->adjlen; i++){
            struct Node *next_node = curr_node->adj[i];

            int isin = 0;
            for(int j = 0; j < vlen; j++){
                if(visited[j]==next_node->id) isin=1;
            }

            if(isin==0){
                visited[vlen]=next_node->id;
                vlen++;
                queue[qlen]=next_node;
                qlen++;
            }
        }
    }
    
    return vlen;
}

void find_root(struct Node *G[], int Glen){
    char res[6];
    int reslen = 0;
    for(int i = 0; i < Glen; i++){
        struct Node *start_node = G[i];
        if(bfs(start_node) == Glen){
            res[reslen]=start_node->id;
            reslen++;
        }
    }

    printf("[");
    for(int i = 0; i < reslen; i++){
        printf("%c",res[i]);
        if(i!=reslen-1) printf(", ");
    }
    printf("]\n");
}

int main(){
    struct Node A, B, C, D, E, F;
    A.id = 'A';
    B.id = 'B';
    C.id = 'C';
    D.id = 'D';
    E.id = 'E';
    F.id = 'F';
    A.adj[0] = &C;
    A.adj[1] = &D;
    B.adj[0] = &A;
    B.adj[1] = &F;
    C.adj[0] = &D;
    C.adj[1] = &B;
    D.adj[0] = &E;
    E.adj[0] = &F;
    A.adjlen = 2;
    B.adjlen = 2;
    C.adjlen = 2;
    D.adjlen = 1;
    E.adjlen = 1;
    F.adjlen = 0;

    struct Node *G[6] = {&A,&B,&C,&D,&E,&F};

    find_root(G,6);

    return 0;
}
