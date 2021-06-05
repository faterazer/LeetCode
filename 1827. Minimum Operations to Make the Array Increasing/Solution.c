int minOperations(int *nums, int numsSize)
{
    int res = 0, prev = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= prev)
            res += ++prev - nums[i];
        else
            prev = nums[i];
    }
    return res;
}
