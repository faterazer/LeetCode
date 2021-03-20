int maxProduct(int *nums, int numsSize)
{
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= mx1) {
            mx2 = mx1;
            mx1 = nums[i];
        }
        else if (nums[i] > mx2)
            mx2 = nums[i];
    }
    return (mx1 - 1) * (mx2 - 1);
}
