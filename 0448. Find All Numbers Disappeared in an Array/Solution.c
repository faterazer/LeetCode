#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    for (int i = 0; i < numsSize; i++) {
        if (nums[abs(nums[i]) - 1] > 0)
            nums[abs(nums[i]) - 1] *= -1;
    }
    int *ret = (int*)malloc(sizeof(int) * (numsSize / 2));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] > 0)
            ret[(*returnSize)++] = i + 1;
    ret = realloc(ret, sizeof(int) * (*returnSize));
    return ret;
}
