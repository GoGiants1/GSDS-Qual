#include <stdio.h>
#include <stdlib.h>

typedef struct GNode GNode;

struct GNode{      
    char id;
    int distance;
    GNode** child;
    int cnum;
    int nnum;
    int max_dist;
    int *rlen;
};

GNode** bfs(GNode *s){
    GNode **v = (GNode**)malloc(sizeof(GNode*)*50);
    int vlen = 0;
    GNode **q = (GNode**)malloc(sizeof(GNode*)*50);
    q[0] = s;
    int qlen = 1;

    while(qlen != 0){
        GNode *n = q[0];
        for(int i = 0; i < qlen-1; i++) q[i] = q[i+1];
        qlen--;

        int isin = 0;
        for(int i = 0; i < vlen; i++){
            if(v[i]==n) isin = 1;
        }

        if (isin == 0){
            v[vlen] = n;
            vlen++;

            for(int i = 0; i < n->cnum; i++){ 
                q[qlen] = n->child[i];
                qlen++;
                if(n->child[i]->distance == -1){
                    n->child[i]->distance = n->distance+1;
                    s->max_dist = n->distance+1;
                }
            }
        }
    }
    s->nnum = vlen;
    return v;
}


void dfsVisit(GNode *node, GNode **visited, int *vlen);

GNode** dfs(GNode *start){
    GNode **visited = (GNode**)malloc(sizeof(GNode*) * 50); // Assuming a max of 50 nodes
    int vlen = 0;

    dfsVisit(start, visited, &vlen);

    start->nnum = vlen; // Set the number of visited nodes in the start node's nnum field
    return visited;
}

void dfsVisit(GNode *node, GNode **visited, int *vlen){
    // Check if the node has already been visited to prevent cycles
    for(int i = 0; i < *vlen; i++){
        if(visited[i] == node){
            return; // Node already visited
        }
    }

    // Mark the current node as visited
    visited[*vlen] = node;
    (*vlen)++;

    // Recur for all the vertices adjacent to this vertex
    for(int i = 0; i < node->cnum; i++){
        dfsVisit(node->child[i], visited, vlen);
    }
}


int main(){
    GNode r, s, t, u, v, w, x, y;

    r.id = 'r';
    s.id = 's';
    t.id = 't';
    u.id = 'u';
    v.id = 'v';
    w.id = 'w';
    x.id = 'x';
    y.id = 'y';

    r.distance = -1;
    s.distance = -1;
    t.distance = -1;
    u.distance = -1;
    v.distance = -1;
    w.distance = -1;
    x.distance = -1;
    y.distance = -1;  

    
    r.cnum = 2;
    GNode **childr = (GNode**)malloc(sizeof(GNode*)*r.cnum);
    childr[0] = &s;
    childr[1] = &v;
    r.child = childr;

    s.cnum = 2;
    GNode **childs = (GNode**)malloc(sizeof(GNode*)*s.cnum);
    childs[0] = &r;
    childs[1] = &w;
    s.child = childs;

    t.cnum = 3;
    GNode **childt = (GNode**)malloc(sizeof(GNode*)*t.cnum);
    childt[0] = &w;
    childt[1] = &x;
    childt[2] = &u;
    t.child = childt;

    u.cnum = 3;
    GNode **childu = (GNode**)malloc(sizeof(GNode*)*u.cnum);
    childu[0] = &t;
    childu[1] = &x;
    childu[2] = &y;
    u.child = childu;

    v.cnum = 1;
    GNode **childv = (GNode**)malloc(sizeof(GNode*)*v.cnum);
    childv[0] = &r;
    v.child = childv;

    w.cnum = 3;
    GNode **childw = (GNode**)malloc(sizeof(GNode*)*w.cnum);
    childw[0] = &s;
    childw[1] = &t;
    childw[2] = &x;
    w.child = childw;

    x.cnum = 4;
    GNode **childx = (GNode**)malloc(sizeof(GNode*)*x.cnum);
    childx[0] = &w;
    childx[1] = &t;
    childx[2] = &u;
    childx[3] = &y;
    x.child = childx;

    y.cnum = 2;
    GNode **childy = (GNode**)malloc(sizeof(GNode*)*y.cnum);
    childy[0] = &x;
    childy[1] = &u;
    y.child = childy;

    printf("BFS traverse : \n");

    GNode **visited = bfs(&r);
    for (int i =0; i < r.nnum;i++){
        printf("%c ", visited[i]->id);
    }
    printf("\nDFS traverse : \n");

    GNode **visited2 = dfs(&r);
    for (int i =0; i <r.nnum;i++){
        printf("%c ",visited2[i]->id);
    }

}