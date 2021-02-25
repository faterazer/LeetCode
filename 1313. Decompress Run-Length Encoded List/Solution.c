#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int *nums, int numsSize, int *returnSize)
{
    int size = 0;
    for (int i = 0; i < numsSize; i += 2)
        size += nums[i];

    int *ret = (int*)malloc(sizeof(int) * size);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i += 2)
        for (int j = 0; j < nums[i]; j++)
            ret[(*returnSize)++] = nums[i + 1];
    return ret;
}
