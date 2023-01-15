#include <math.h>

int minMaxGame(int* nums, int numsSize)
{
    for (int n = numsSize; n != 1; n >>= 1) {
        for (int i = 0; i < n / 2; i++) {
            if (i & 1)
                nums[i] = fmax(nums[i << 1], nums[i << 1 | 1]);
            else
                nums[i] = fmin(nums[i << 1], nums[i << 1 | 1]);
        }
    }
    return nums[0];
}
