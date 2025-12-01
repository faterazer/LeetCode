#include <limits.h>
#include <math.h>

long long maxSubarraySum(int* nums, int numsSize, int k)
{
    long long min_f[k];
    min_f[0] = 0;
    for (int i = 1; i < k; ++i)
        min_f[i] = LLONG_MAX / 2;

    long long pre_sum = 0, result = LLONG_MIN;
    for (int j = 0; j < numsSize; ++j) {
        pre_sum += nums[j];
        int i = (j + 1) % k;
        result = fmax(result, pre_sum - min_f[i]);
        min_f[i] = fmin(min_f[i], pre_sum);
    }
    return result;
}
