int dominantIndex(int *nums, int numsSize)
{
    int i = 0, j = -1;   // i 是最大值的下标，j 是第二大值的下标
    for (int k = 1; k < numsSize; k++) {
        if (nums[k] > nums[i]) {
            j = i;
            i = k;
        }
        else if (j == -1 || nums[k] > nums[j])
            j = k;
    }
    return (j == -1 || nums[i] >= nums[j] * 2) ? i : -1;
}
