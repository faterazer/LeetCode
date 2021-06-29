#include <math.h>

int maxProductDifference(int *nums, int numsSize)
{
    int mx1 = fmax(nums[0], nums[1]);
    int mx2 = fmin(nums[0], nums[1]);
    int mn1 = mx2, mn2 = mx1;
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] >= mx1) {
            mx2 = mx1;
            mx1 = nums[i];
        } else if (nums[i] > mx2) {
            mx2 = nums[i];
        }
        if (nums[i] <= mn1) {
            mn2 = mn1;
            mn1 = nums[i];
        } else if (nums[i] < mn2) {
            mn2 = nums[i];
        }
    }
    return mx1 * mx2 - mn1 * mn2;
}
