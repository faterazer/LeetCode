int pivotIndex(int *nums, int numsSize)
{
    int leftSum = 0, rightSum = 0;
    for (int i = 0; i < numsSize; i++)
        rightSum += nums[i];
    for (int i = 0; i < numsSize; i++) {
        rightSum -= nums[i];
        if (leftSum == rightSum)
            return i;
        leftSum += nums[i];
    }
    return -1;
}
