#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/**
 * Sort
 * Time complexity: O(nlgn)
 * Space complexity: O(1)
 */
int arrayPairSum_MK1(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int res = 0;
    for (int i = 0; i < numsSize; i += 2)
        res += nums[i];
    return res;
}

/**
 * Hash
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
int arrayPairSum_MK2(int *nums, int numsSize)
{
    int hash[20001] = {0};
    for (int i = 0; i < numsSize; i++)
        hash[nums[i] + 10000]++;
    int res = 0, d = 0;
    for (int i = 0; i < 20001; i++) {
        if (hash[i]) {
            res += (hash[i] - d + 1) / 2 * (i - 10000);
            d = (hash[i] - d) % 2;
        }
    }
    return res;
}
