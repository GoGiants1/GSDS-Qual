int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int i, rprod;
    int * res = (int*)malloc(sizeof(int)*numsSize);
    res[0] = 1;
    *returnSize = numsSize;

    for(i=1;i<numsSize;i++){
        res[i] = res[i-1] * nums[i-1];
    }

    rprod = nums[numsSize-1];
    for(i=numsSize-2;i>=0;i--){
        res[i] *= rprod;
        rprod *= nums[i];
    }

    return res;
}
