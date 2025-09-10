#include <limits.h>
#include <math.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxValue(int* nums, int numsSize, int* returnSize)
{
    int* pre_max = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    pre_max[0] = nums[0];
    for (int i = 1; i < numsSize; ++i)
        pre_max[i] = fmax(pre_max[i - 1], nums[i]);

    int suf_min = INT_MAX;
    for (int i = numsSize - 1; i >= 0; --i) {
        if (pre_max[i] > suf_min)
            pre_max[i] = pre_max[i + 1];
        suf_min = fmin(suf_min, nums[i]);
    }
    return pre_max;
}
