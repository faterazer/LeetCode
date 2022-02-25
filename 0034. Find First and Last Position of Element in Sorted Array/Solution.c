#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    res[0] = -1;
    res[1] = -1;
    if (!numsSize)
        return res;

    int l = 0, r = numsSize, m;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (nums[m] < target)
            l = m + 1;
        else
            r = m;
    }
    if (l >= numsSize || nums[l] != target)
        return res;
    else
        res[0] = l;
    r = numsSize;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (nums[m] <= target)
            l = m + 1;
        else
            r = m;
    }
    res[1] = l - 1;
    return res;
}
