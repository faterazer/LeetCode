#include <math.h>
#include <stdbool.h>

bool isIdealPermutation_MK1(int* nums, int numsSize)
{
    int cmax = 0, n = numsSize;
    for (int i = 0; i < n - 2; i++) {
        cmax = fmax(cmax, nums[i]);
        if (cmax > nums[i + 2])
            return false;
    }
    return true;
}

bool isIdealPermutation_MK2(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
        if (fabs(nums[i] - i) > 1)
            return false;
    return true;
}
