#include <math.h>
#include <string.h>

int maxSumAfterPartitioning(int* arr, int arrSize, int k)
{
    int dp[k];
    memset(dp, 0, sizeof(int) * k);
    for (int i = 1; i <= arrSize; i++) {
        int max_val = 0, best = 0;
        for (int j = 1; j <= k && i - j >= 0; j++) {
            max_val = fmax(max_val, arr[i - j]);
            best = fmax(best, dp[(i - j) % k] + max_val * j);
        }
        dp[i % k] = best;
    }
    return dp[arrSize % k];
}
