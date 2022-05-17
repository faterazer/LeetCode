#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    int *res = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; ++i) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0)
            res[(*returnSize)++] = idx + 1;
        else
            nums[idx] *= -1;
    }
    return res;
}
