#include <limits.h>
#include <math.h>

int maximumDifference(int* nums, int numsSize)
{
    int res = -1, minimum = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > minimum)
            res = fmax(res, nums[i] - minimum);
        else
            minimum = nums[i];
    }
    return res;
}
