#include <math.h>

double largestSumOfAverages(int* nums, int numsSize, int k)
{
    double pre_sum[numsSize + 1];
    pre_sum[0] = 0;
    for (int i = 1; i <= numsSize; i++)
        pre_sum[i] = pre_sum[i - 1] + nums[i - 1];

    double dp[numsSize + 1];
    for (int i = 1; i <= numsSize; i++)
        dp[i] = pre_sum[i] / i;
    for (int i = 2; i <= k; i++)
        for (int j = numsSize; j >= i; j--)
            for (int w = 0; w < j; w++)
                dp[j] = fmax(dp[j], dp[w] + (pre_sum[j] - pre_sum[w]) / (j - w));
    return dp[numsSize];
}
