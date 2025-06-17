#include <stdbool.h>
#include <stdlib.h>

bool check(int* nums, int numsSize, int p, int x)
{
    int cnt = 0;
    for (int i = 1; i < numsSize && cnt < p; ++i) {
        if (nums[i] - nums[i - 1] <= x) {
            ++cnt;
            ++i;
        }
    }
    return cnt >= p;
}

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int minimizeMax(int* nums, int numsSize, int p)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int lo = 0, hi = nums[numsSize - 1] - nums[0];
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (check(nums, numsSize, p, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}
