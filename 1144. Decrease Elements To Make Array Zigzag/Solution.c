#include <limits.h>
#include <math.h>

int movesToMakeZigzag(int* nums, int numsSize)
{
    int s[2] = { 0 };
    for (int i = 0; i < numsSize; i++) {
        int left = i > 0 ? nums[i - 1] : INT_MAX;
        int right = i < numsSize - 1 ? nums[i + 1] : INT_MAX;
        s[i & 1] += fmax(nums[i] - fmin(left, right) + 1, 0);
    }
    return fmin(s[0], s[1]);
}
