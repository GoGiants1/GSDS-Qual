#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GNode GNode;

struct GNode{
    char id;
    GNode **adj;
    int adjlen;
};

void expo(GNode **path, int plen, GNode *t, char **pathlists, int *pathlistslen){
    if(path[plen-1] == t) {
        char *plist = (char*)malloc(sizeof(char)*(plen+1));
        int i;
        for(i = 0; i < plen; i++){
            plist[i] = path[i]->id;
        }
        plist[i] = '\0';
        pathlists[*pathlistslen] = plist;
        (*pathlistslen)++;
    }
    else{
        for(int i = 0; i < path[plen-1]->adjlen; i++){
            int isin = 0;
            for(int j = 0; j < plen; j++){
                if(path[i] == path[plen-1]->adj[i]) isin = 1;
            }
            if(isin == 0){
                GNode **newpath = (GNode**)malloc(sizeof(GNode*)*(plen+1));
                int j;
                for(j = 0; j < plen; j++) newpath[j] = path[j];
                newpath[j] = path[plen-1]->adj[i];
                expo(newpath, plen+1, t, pathlists, pathlistslen);
            }
        }
    }
}

char** paths(GNode *s, GNode *t){
    char **pathlists = (char**)calloc(1000,sizeof(char*));
    int pathlistslen = 0;
    GNode **path = {&s};
    expo(path, 1, t, pathlists, &pathlistslen);

    return pathlists;
}

int main(){
    GNode a, b, c, d;

    a.id = 'a';
    b.id = 'b';
    c.id = 'c';
    d.id = 'd';

    a.adjlen = 2;
    b.adjlen = 1;
    c.adjlen = 0;
    d.adjlen = 1;

    GNode **adja = (GNode**)malloc(sizeof(GNode*)*a.adjlen);
    GNode **adjb = (GNode**)malloc(sizeof(GNode*)*b.adjlen);
    GNode **adjc = (GNode**)malloc(sizeof(GNode*)*c.adjlen);
    GNode **adjd = (GNode**)malloc(sizeof(GNode*)*d.adjlen);

    adja[0] = &b;
    adjb[0] = &d;
    adjd[0] = &c;
    adja[1] = &c;

    a.adj = adja;
    b.adj = adjb;
    c.adj = adjc;
    d.adj = adjd; 

    char** res = paths(&a, &c);

    int reslen = 0;
    while(res[reslen]!=NULL) reslen++;

    for(int i = 0; i < reslen; i++){
        for(int j = 0; j < strlen(res[i]); j++){   
            printf("%c ",res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
