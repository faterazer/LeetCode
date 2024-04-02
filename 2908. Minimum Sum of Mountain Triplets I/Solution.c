#include <limits.h>
#include <math.h>
#include <string.h>

int minimumSum(int* nums, int numsSize)
{
    int suf[numsSize];
    memset(suf, 0, sizeof(suf));
    suf[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i > 1; i--)
        suf[i] = fmin(nums[i], suf[i + 1]);

    int res = INT_MAX, pre = nums[0];
    for (int i = 1; i < numsSize - 1; i++) {
        if (pre < nums[i] && nums[i] > suf[i + 1])
            res = fmin(res, pre + nums[i] + suf[i + 1]);
        pre = fmin(pre, nums[i]);
    }
    return res == INT_MAX ? -1 : res;
}
