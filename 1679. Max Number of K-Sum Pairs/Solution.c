#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int maxOperations(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0, j = numsSize - 1;
    int res = 0;
    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum < k)
            ++i;
        else if (sum > k)
            --j;
        else {
            ++res;
            ++i;
            --j;
        }
    }
    return res;
}
