#include <math.h>

int maxRotateFunction(int* nums, int numsSize)
{
    int f = 0, sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        f += i * nums[i];
        sum += nums[i];
    }
    int res = f;
    for (int i = numsSize - 1; i > 0; --i) {
        f += sum - numsSize * nums[i];
        res = fmax(res, f);
    }
    return res;
}
