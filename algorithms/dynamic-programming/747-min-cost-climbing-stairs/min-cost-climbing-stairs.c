int min(int a, int b){
    return a > b ? b : a;
}

int minCostClimbingStairs(int* cost, int costSize) {

    int before_two_step = 0;
    int before_one_step = 0;
    
    for (int i = 2; i < costSize + 1; ++i){
        int current_cost = min(before_two_step + cost[i - 2], before_one_step + cost[i - 1]);

        before_two_step = before_one_step;
        before_one_step = current_cost;
    }
    
    return before_one_step;

}