/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    int *res = (int*)malloc(sizeof(int)*spellsSize);
    for(int i = 0; i < spellsSize; i++){
        int count = 0;
        for(int j = 0; j < potionsSize; j++){
            if(spells[i] * potions[j] >= success) count++;
        }
        res[i] = count;
    }
    *returnSize = spellsSize;
    return res;
}
