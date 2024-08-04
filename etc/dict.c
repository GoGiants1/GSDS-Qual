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