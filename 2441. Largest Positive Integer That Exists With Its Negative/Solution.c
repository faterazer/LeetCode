#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int findMaxK(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0, j = numsSize - 1; i < j; j--) {
        while (i < j && nums[i] < -nums[j])
            i++;
        if (nums[i] == -nums[j])
            return nums[j];
    }
    return -1;
}
