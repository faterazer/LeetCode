#include <math.h>

long long minArraySum(int* nums, int numsSize, int k)
{
    long long min_f[k];
    min_f[0] = 0;
    for (int i = 1; i < k; ++i)
        min_f[i] = -1;

    long long f = 0;
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum = (sum + nums[i]) % k;
        f += nums[i];
        if (min_f[sum] != -1)
            f = fmin(f, min_f[sum]);
        min_f[sum] = f;
    }
    return f;
}
