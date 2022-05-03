#include <limits.h>
#include <math.h>

int findUnsortedSubarray(int* nums, int numsSize)
{
    int max_val = nums[0], min_val = nums[numsSize - 1], beg = 0, end = -1;
    for (int i = 1; i < numsSize; ++i) {
        max_val = fmax(max_val, nums[i]);
        min_val = fmin(min_val, nums[numsSize - 1 - i]);
        if (nums[i] < max_val)
            end = i;
        if (nums[numsSize - 1 - i] > min_val)
            beg = numsSize - 1 - i;
    }
    return end - beg + 1;
}
