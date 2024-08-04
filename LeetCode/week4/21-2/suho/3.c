#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GNode GNode;
struct GNode{
    char id;
    int adjlen;
};

typedef struct Dict Dict;
struct Dict{
    GNode **keys;
    GNode ***val;
};
GNode** dictSearch(Dict *dict, GNode *k){
    int i = 0;
    while(1){
        if(dict->keys[i] == k) return dict->val[i];
        else i++;
    }
}


int lexcomp(char *l1, char *l2){
    int res = 2;
    int i = 0;
    while(i < (strlen(l1) > strlen(l2) ? strlen(l2) : strlen(l1))){
        if(l1[i] < l2[i]){
            res = 0;
            break;
        }
        else if(l1[i] > l2[i]){
            res = 1;
            break;
        }
        else i++;
    }

    if(res == 2){
        if(strlen(l1) > strlen(l2)) res = 1;
        else res = 0;
    }
    
    return res;
}


char* dfs(Dict *G, GNode** path, int plen, GNode *v){
    if(path[plen-1] == v){
        char *res = (char*)malloc(sizeof(char)*(plen+1));
        int i = 0;
        for(i = 0; i < plen; i++){
            res[i] = path[i]->id;
        }
        res[i] = '\0';
        return res;
    }
    else{
        char *res = (char*)malloc(sizeof(char)*10000);
        res[0] = '\0';
        for(int i = 0; i < path[plen-1]->adjlen; i++){
            int isin = 0;
            for(int j = 0; j < plen; j++){
                if(path[j] == dictSearch(G, path[plen-1])[i]) isin = 1;
            }

            if(isin == 0){
                GNode **newpath = (GNode**)malloc(sizeof(GNode*)*plen+1);
                for(int j = 0; j < plen; j++) newpath[j] = path[j];
                newpath[plen] = dictSearch(G, path[plen-1])[i];
                char *tmp = dfs(G, newpath, plen+1, v);
                if(res[0] == '\0' || (tmp[0] != '\0' && lexcomp(res, tmp) == 1)) res = tmp;
            }
        }
        return res;
    }
}

char *LexSmallest(Dict *G, GNode *u, GNode *v){
    GNode** p = (GNode**)malloc(sizeof(GNode*));
    p[0] = u;
    char *path = dfs(G, p, 1, v);
    return path;
}

int main(){
    GNode r = {'r',2}, s = {'s',3}, t = {'t',3}, u = {'u',1};
    GNode v = {'v',1}, w = {'w',3}, x = {'x',1}, y = {'y',1};
    GNode **adj1 = (GNode**)malloc(sizeof(GNode*)*2);
    adj1[0] = &w;
    adj1[1] = &v;   
    GNode **adj2 = (GNode**)malloc(sizeof(GNode*)*3);
    adj2[0] = &s;
    adj2[1] = &r;
    adj2[2] = &t;
    GNode **adj3 = (GNode**)malloc(sizeof(GNode*)*3);
    adj3[0] = &s;
    adj3[1] = &x;
    adj3[2] = &w;
    GNode **adj4 = (GNode**)malloc(sizeof(GNode*));
    adj4[0] = &y;
    GNode **adj5 = (GNode**)malloc(sizeof(GNode*));
    adj5[0] = &r;
    GNode **adj6 = (GNode**)malloc(sizeof(GNode*)*3);
    adj6[0] = &w;
    adj6[1] = &t;
    adj6[2] = &x;
    GNode **adj7 = (GNode**)malloc(sizeof(GNode*)*2);
    adj7[0] = &s;
    adj7[1] = &t; 
    GNode **adj8 = (GNode**)malloc(sizeof(GNode*));
    adj8[0] = &u;
    GNode **keys = (GNode**)malloc(sizeof(GNode*)*8);
    keys[0] = &r;
    keys[1] = &w;
    keys[2] = &t;
    keys[3] = &u;
    keys[4] = &v;
    keys[5] = &s;
    keys[6] = &x;
    keys[7] = &y;
    GNode ***vals = (GNode***)malloc(sizeof(GNode**)*8);
    vals[0] = adj1;
    vals[1] = adj2;
    vals[2] = adj3;
    vals[3] = adj4;
    vals[4] = adj5;
    vals[5] = adj6;
    vals[6] = adj7;
    vals[7] = adj8;
    Dict G = {keys,vals};

    char *res1 = LexSmallest(&G, &t, &v);
    char *res2 = LexSmallest(&G, &u, &u);
    char *res3 = LexSmallest(&G, &w, &y);

    for(int i = 0; i < strlen(res1); i++){
        printf("%c ", res1[i]);
    }
    printf("\n");

    for(int i = 0; i < strlen(res2); i++){
        printf("%c ", res2[i]);
    }
    printf("\n");

    for(int i = 0; i < strlen(res3); i++){
        printf("%c ", res3[i]);
    }
    printf("\n");

    return 0;
}

