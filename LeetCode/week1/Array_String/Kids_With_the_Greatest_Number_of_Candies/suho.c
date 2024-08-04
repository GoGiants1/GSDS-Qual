bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int max_can = 0, i;
    *returnSize = candiesSize;
    for(i=0; i<candiesSize; i++) max_can = max_can>candies[i]?max_can:candies[i];

    bool * res = (bool*)malloc(sizeof(bool)*candiesSize);
    for(i=0; i<candiesSize; i++) res[i] = (candies[i]+extraCandies >= max_can);

    return res;
}
