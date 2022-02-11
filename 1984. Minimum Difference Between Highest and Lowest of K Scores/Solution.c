#include <limits.h>
#include <math.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int minimumDifference(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int res = INT_MAX;
    for (int i = k - 1; i < numsSize; i++)
        res = fmin(res, nums[i] - nums[i - k + 1]);
    return res;
}
