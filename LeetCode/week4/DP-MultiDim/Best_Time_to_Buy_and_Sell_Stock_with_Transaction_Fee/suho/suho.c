int maxProfit(int* prices, int pricesSize, int fee) {
    int *bought = (int*)malloc(sizeof(int)*(pricesSize+1));
    bought[0] = -100000;
    int *sold = (int*)malloc(sizeof(int)*(pricesSize+1));
    sold[0] = 0;
    
    int i;
    for(i = 0; i < pricesSize; i++){ 
        bought[i+1] = bought[i] > sold[i] - prices[i] ? bought[i] : sold[i] - prices[i];
        sold[i+1] = sold[i] > bought[i] + prices[i] - fee ? sold[i] : bought[i] + prices[i] - fee;
    }
    
    return sold[i];
}
