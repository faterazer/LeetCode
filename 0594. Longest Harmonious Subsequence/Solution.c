#include <math.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int findLHS(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int beg = 0, beg2 = 0, res = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] - nums[beg] > 1)
            beg = beg2;
        if (nums[i] != nums[i - 1])
            beg2 = i;
        if (nums[i] - nums[beg] == 1)
            res = fmax(res, i - beg + 1);
    }
    return res;
}
