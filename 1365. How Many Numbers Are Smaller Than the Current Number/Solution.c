#include <memory.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    memset(ret, 0, sizeof(int) * numsSize);
    int map[101] = {0};
    for (int i = 0; i < numsSize; i++)
        map[nums[i]]++;
    for (int i = 1; i < 101; i++)
        map[i] += map[i - 1];
    for (int i = 0; i < numsSize; i++)
        if (nums[i])
            ret[i] = map[nums[i] - 1];
    return ret;
}
