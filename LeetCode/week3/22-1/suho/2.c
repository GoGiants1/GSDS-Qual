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

char** level_partition(GNode *s){
    s->distance = 0;
    GNode **v = bfs(s);
    char **res = (char**)malloc(sizeof(char*)*(s->max_dist+1));
    int *rlen = (int*)malloc(sizeof(int)*(s->max_dist+1));
    for(int i = 0; i < s->max_dist+1; i++){
        res[i] = (char*)malloc(sizeof(char)*50);
        rlen[i] = 0;
    }
    for(int i = 0; i < s->nnum; i++){
        res[v[i]->distance][rlen[v[i]->distance]] = v[i]->id;
        rlen[v[i]->distance]++;
    }
    s->rlen = rlen;
    return res;
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

    char **res = level_partition(&s);
    printf("[");
    for(int i = 0; i < s.max_dist+1; i++){
        printf("[");
        for(int j = 0; j < s.rlen[i]; j++){
            printf("'%c'",res[i][j]);
            if(j!=s.rlen[i]-1) printf(", ");
        }
        printf("]");
        if(i!=s.max_dist) printf(", ");
    }
    printf("]\n");


    return 0;
}