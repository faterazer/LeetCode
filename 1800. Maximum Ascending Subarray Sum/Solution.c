#include <math.h>

int maxAscendingSum(int *nums, int numsSize)
{
    int max_sum = nums[0], cur = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= nums[i - 1]) {
            max_sum = fmax(max_sum, cur);
            cur = 0;
        }
        cur += nums[i];
    }
    return fmax(max_sum, cur);
}
