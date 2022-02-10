#include <limits.h>
#include <math.h>

int maxSubArray(int* nums, int numsSize)
{
    int res = INT_MIN, cur = 0;
    for (int i = 0; i < numsSize; i++) {
        if (cur < 0)
            cur = nums[i];
        else
            cur += nums[i];
        res = fmax(res, cur);
    }
    return res;
}
