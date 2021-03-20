/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int *nums, int numsSize, int n, int *returnSize)
{
    for (int i = 0; i < numsSize; i++)
        nums[i] <<= 10;
    for (int i = 0, j = n, k = 0; i < n; i++, j++, k += 2) {
        nums[k] |= nums[i] >> 10;
        nums[k + 1] |= nums[j] >> 10;
    }
    for (int i = 0; i < numsSize; i++)
        nums[i] &= 0x3FF;
    *returnSize = numsSize;
    return nums;
}
