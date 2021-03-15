#include <math.h>

int minStartValue(int *nums, int numsSize)
{
    int sum = 0, min_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        min_sum = fmin(sum, min_sum);
    }
    return 1 - min_sum;
}
