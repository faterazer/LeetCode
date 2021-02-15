#include <math.h>

int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int res = 0, count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i])
            count++;
        else {
            res = fmax(res, count);
            count = 0;
        }
    }
    return fmax(res, count);
}
