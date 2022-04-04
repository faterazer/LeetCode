#include <math.h>
#include <stdbool.h>

bool valid(int *nums, int numsSize, int m, int sum_limit)
{
    int sum = 0, cnt = 1;
    for (int i = 0; i < numsSize; ++i) {
        if (sum + nums[i] <= sum_limit) {
            sum += nums[i];
        } else {
            sum = nums[i];
            cnt += 1;
        }
    }
    return cnt <= m;
}

int splitArray(int* nums, int numsSize, int m)
{
    int l = 0, r = 0;
    for (int i = 0; i < numsSize; ++i) {
        l = fmax(l, nums[i]);
        r += nums[i];
    }
    while (l < r) {
        int mid = l + ((r - l) >> 1);
        if (valid(nums, numsSize, m, mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
