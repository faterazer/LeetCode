void reverse(int *nums, int left, int right)
{
    int tmp;
    for (int i = left, j = right; i < j; i++, j--) {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}

void rotate(int *nums, int numsSize, int k)
{
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}
