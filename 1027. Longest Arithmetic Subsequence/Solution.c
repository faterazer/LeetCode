#include <limits.h>
#include <math.h>
#include <string.h>

int longestArithSeqLength(int* nums, int numsSize)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        min = fmin(min, nums[i]);
        max = fmax(max, nums[i]);
    }

    int diff = max - min, res = 1;
    for (int d = -diff; d <= diff; d++) {
        int f[max + 1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < numsSize; i++) {
            int prev = nums[i] + d;
            if (prev >= min && prev <= max) {
                f[nums[i]] = fmax(f[nums[i]], f[prev] + 1);
                res = fmax(res, f[nums[i]]);
            }
            f[nums[i]] = fmax(f[nums[i]], 1);
        }
    }
    return res;
}
