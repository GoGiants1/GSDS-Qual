int rob(int* nums, int numsSize) {
    int T1[100], T2[100];
    T1[0] = nums[0];
    T2[0] = 0;
    int i = 1;
    while(i < numsSize){
        T1[i] = T2[i-1] + nums[i];
        T2[i] = T1[i-1] > T2[i-1] ? T1[i-1] : T2[i-1];
        i++;
    }

    return T1[i-1] > T2[i-1] ? T1[i-1] : T2[i-1];
}
