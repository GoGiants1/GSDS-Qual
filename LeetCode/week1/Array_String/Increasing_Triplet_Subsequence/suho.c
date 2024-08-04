bool increasingTriplet(int* nums, int numsSize) {
    int i, j, k;
    bool res = false;
    for(i=0;i<numsSize-2;i++){
        for(j=i+1;j<numsSize-1;j++){
            for(k=j+1;k<numsSize;k++){
                if(nums[i]<nums[j] && nums[j]<nums[k]){
                    res = true;
                    break;
                }
            }
            if(res) break;
        }
        if(res) break;
    }
    
    return res;
}
