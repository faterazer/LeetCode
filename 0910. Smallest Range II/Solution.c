#include <math.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int smallestRangeII(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = nums[numsSize - 1] - nums[0];
    for (int i = 1; i < numsSize; ++i) {
        int mx = fmax(nums[i - 1] + k, nums[numsSize - 1] - k);
        int mn = fmin(nums[0] + k, nums[i] - k);
        ans = fmin(ans, mx - mn);
    }
    return ans;
}
